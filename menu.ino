void Menu()
{
  if (menu == 0)
  {
    volt();
    temp();
    curr();
    lr();
    voltinput();
    //    lcd.setCursor(0,1);
    //    lcd.print("No Limit");
  }
  if (menu == 1)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    volts1 ();
    lcd.setCursor(0, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);

  }
  if (menu == 2)
  {
    volt();
    temp();
    curr();
    lr();
    limits();

    volts1_1 ();
    lcd.setCursor(2, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 3)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    volts1_1_1 ();
    lcd.setCursor(3 , 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 4)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1 ();
    lcd.setCursor(8, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 5)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1_1 ();
    lcd.setCursor(10, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 6)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1_1_1 ();
    lcd.setCursor(11, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 7)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    volts1 ();
     charger();
    lcd.setCursor(0, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 8)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    volts1_1 ();
     charger();
    lcd.setCursor(2, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 9)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    volts1_1_1 ();
    charger();
    lcd.setCursor(3 , 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 10)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1 ();
    charger();
    lcd.setCursor(8, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 11)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1_1 ();
    charger();
    lcd.setCursor(10, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);
  }
  if (menu == 12)
  {
    volt();
    temp();
    curr();
    lr();
    limits();
    amp1_1_1 ();
    charger();
    lcd.setCursor(11, 1);
    lcd.cursor();
    delay(50);
    lcd.noCursor();
    delay(50);

  }
  else if (menu == 13)
    menu = 0;
}

