void stopwatch()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of hours since reset:
  lcd.print(millis() / 3600000);
  if (millis()>3600000)
  lcd.print(":");
  // print the number of minutes since reset
  lcd.print(millis() / 60000%60);
  lcd.print(":");
  // print the number of seconds since reset
  lcd.print(millis() / 1000%60);
}
