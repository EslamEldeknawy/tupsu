#include <neotimer.h>
Neotimer mytimer = Neotimer(1000); // 1 second timer
#include <ResponsiveAnalogRead.h>


#include <Button.h>
//-------------------------------------------- battery symbol ---------------------------------------------------
byte bat0[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte bat20[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};
byte bat40[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111
};
byte bat60[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat80[8] = {
  B01110,
  B11011,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111

};
byte bat90[8] = {
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat100[8] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte batx[8] = {
  B01110,
  B11011,
  B10101,
  B10101,
  B10101,
  B10001,
  B10101,
  B11111
};
//----------------------------------------------- end of battery symbol -------------------------------------------------------------

#include <LiquidCrystalISP.h>
LiquidCrystal lcd(9);
Button up = 7;
Button down = 4;
Button left  (10);
Button right = 6;
int relay = 2; //this relay cuts off Ac from power transformers in safety coditions
int relay_state;
#define fan  5
int menu1 = 1;
//int upState = 0;
//int downState = 0;
//int leftState = 0;
//int rightState = 0;
//int lastup = LOW;
//int lastdown = LOW;
//int lastleft = LOW;
//int lastright = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


int updown = 0; //counter for up down switches increases by 1 for values adjust
int menu = 0; // counter for left right switches increases by 1
const byte speakerPin = 3; // alarma Buzzer
unsigned long lastPeriodStart;
const int onDuration = 500;
const int periodDuration = 200;


//------------------------------------------- temp reading -------------------------------------------------------
int ThermistorPin = A0;
ResponsiveAnalogRead t(ThermistorPin, true);

int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
bool ht = false;
float t_limit = 70;
int fan_speed ;
//-------------------------------------------- volt reading ----------------------------------------------------------
int voltsense = A2;
ResponsiveAnalogRead v(voltsense, true);
float rawvolts  ;
float volts;
float vfactor = 55 ;
float R11 = 85000;
float R22 = 9400;
float v_limit  = 0;
bool vd = false;



int voltin = A3;
ResponsiveAnalogRead vin(voltin, true);
float rawvoltsin  ;
float voltsin;
float vinfactor = 55 ;
float R111 = 85000;
float R222 = 9400;
// ---------------------------------------------------- amp reading ----------------------------------------------------------------
int currentsense = A7;
ResponsiveAnalogRead i(currentsense, true);

float rawcurrent ;
float current;
float ifactor = 0.0048076923076923 ;
bool hc = false;
float i_max = 40;
float i_limit = 1;
float batt_current = 0;
float calc_batt_current = 0;
long batt_time_start;
long batt_time_stop;
long batt_time;
// -----------------------------------------------------  ------------------------------------------------------------------


void setup() {


  pinMode(7, INPUT);
  pinMode(4, INPUT);
  //  pinMode(10, INPUT);
  pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(fan, HIGH); // fan always on
  digitalWrite (relay, LOW); //relay always conducting ac unless safety condition is active
  // analogReference( INTERNAL );



  lcd.begin(16, 2);
  lcd.print("  Ultimate PSU");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("   Eslam's Lab");
  alarm();
  delay(500);


  Serial.begin(9600);

  //  up.begin();
  //  down.begin();
  //  right.begin();
  //   left.begin();
mytimer.stop();
  SPI.begin(); digitalWrite(SS, LOW); // important you should use my modified spi library

   lcd.createChar(0, bat0);
  lcd.createChar(1, bat20);
  lcd.createChar(2, bat60);
  lcd.createChar(3, bat80);
  lcd.createChar(4, bat90);
  lcd.createChar(5, bat100);
  lcd.createChar(6, batx);
}
void loop() {


  
  //  while ( ( (ADCSRA & (1 << ADSC)) != 0 ) );
  v.update();
  i.update();
  t.update();
  vin.update();

  //  upState = digitalRead(up);
  //  downState = digitalRead(down);
  //  leftState = digitalRead(left);
  //  rightState = digitalRead(right);


  Vo = t.getValue();
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;

  rawvolts =  v.getValue();
  volts = (rawvolts / 1024) * vfactor ;

  rawvoltsin =  vin.getValue();
  voltsin = (rawvoltsin / 1024) * vinfactor ;


  rawcurrent = i.getValue();
  current = ((rawcurrent) * ifactor - .019); //this multiplyer works well for me with 1 ohm res
  if (current < 0) {
    current = 0;
  }

  relay_state = digitalRead(relay);

  Menu(); //this controles what showing on the screen
  safety();// safety conditions like maximum allowed current and temprature
  fan_speed = map (Tc, 0, 70, 0, 70);
 analogWrite(fan, fan_speed);
   delay(30);
}


