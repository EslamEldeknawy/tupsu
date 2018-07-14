void volt()
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(volts, 3);
  lcd.setCursor(6, 0);
  lcd.print("V");
  Serial.println(fan_speed);
//  Serial.println(batt_current);
//  Serial.println(batt_time);

}
void voltinput()
{

  lcd.setCursor(0, 1);
  lcd.print(voltsin, 2);
  lcd.setCursor(6, 1);
  lcd.print("V");
}

void curr()
{
  lcd.setCursor(8, 0);
  lcd.print(current, 3);
  lcd.setCursor(13, 0);
  lcd.print("A");

}
void temp()
{
  Vo = (analogRead, A0);

  lcd.setCursor(13, 1);
  lcd.print(Tc, 0);
  lcd.setCursor(15, 1);
  lcd.print("C");

}


void alarm()
{
  {
    if (millis() - lastPeriodStart >= periodDuration)
    {
      lastPeriodStart += periodDuration;
      tone(speakerPin, 3500, onDuration); // play 550 Hz tone in background for 'onDuration'
    }
  }

}

void high_temp()
{

  digitalWrite(relay, HIGH);


  alarm();
  lcd.clear();
  lcd.print("HIGH TEMP!!!");
  lcd.setCursor(0, 1);
  lcd.print(" <<   HEAT   >>");      delay(1000);
  alarm();
  lcd.clear();
  lcd.print("Cooling Down");
  lcd.setCursor(0, 1);
  lcd.print("    <<HEAT>>");      delay(1000);
  if (Tc < 35)
  {
    lcd.clear();
    lcd.print ("   Now Reset");
    delay(3000);

  }
}


void max_current()
{

  digitalWrite(relay, HIGH);
  alarm();
  lcd.clear();
  lcd.print("  MAX CURRENT ");
  lcd.setCursor(0, 1);
  lcd.print("   REACHED");
  delay(1000);
  alarm();
  lcd.clear();
  lcd.print("   Remove Load");
  delay(1000);
  lcd.clear();
  lcd.print ("Hold UP Button");
  delay(3000);
  if (up.released())
    hc = false;
digitalWrite(relay, LOW);
}

void charger()
{
  if (current > batt_current)
  {
    batt_current = current;
    batt_time_start = millis();
  }
  if (batt_current - current >= 0.100)
  {
    calc_batt_current = current;
  
    batt_time_stop = millis();
  }
  if (current < 0.002 && batt_current > 0 || volts >= v_limit)
  {
    digitalWrite(relay, HIGH);
    alarm();
  }
if (up.released())
    digitalWrite(relay, LOW);
  
  lcd.setCursor(15, 0);
  lcd.write(byte(5));
 
  batt_time = batt_time_stop - batt_time_start;
}

void limits()
{
  lcd.setCursor(0, 1);
  lcd.print(v_limit);
  lcd.setCursor(8, 1);
  lcd.print(i_limit);
  if (current >= i_limit)
  {
    hc = true;
  }
  if (volts < v_limit)
  {
    vd = true;
  }
}

void safety()
{
  if (Tc >= t_limit)
  {
    ht = true;
  }

  if (current >= i_max)
  {
    hc = true;
  }
  while (hc == true)
  {
    max_current();
  }
  while (ht == true)
  {
    high_temp();
  }
}


