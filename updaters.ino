void updateCurrent() {
  for (int i = 0; i < 3; i++)
  {
    tcaSelect(i);
    battery[i * 4 + 0].setCurrent(abs(sense1.getCurrent_mA()) * currentMultiplier);
    battery[i * 4 + 1].setCurrent(abs(sense2.getCurrent_mA()) * currentMultiplier);
    battery[i * 4 + 2].setCurrent(abs(sense3.getCurrent_mA()) * currentMultiplier);
    battery[i * 4 + 3].setCurrent(abs(sense4.getCurrent_mA()) * currentMultiplier);
  }
}
void updateVoltage() {
  for (int i = 0; i < 3; i++)
  {
    tcaSelect(i);
    battery[i * 4 + 0].setVoltage(abs(sense1.getBusVoltage_V()) * currentMultiplier);
    battery[i * 4 + 1].setVoltage(abs(sense2.getBusVoltage_V()) * currentMultiplier);
    battery[i * 4 + 2].setVoltage(abs(sense3.getBusVoltage_V()) * currentMultiplier);
    battery[i * 4 + 3].setVoltage(abs(sense4.getBusVoltage_V()) * currentMultiplier);
  }
}
void updateHue() {
  for (int i = 0; i < numberOfBatteries; i++)
  {
    if (battery[i].getCurrent() > (blueThreshold+50))
      battery[i].setHue(85 - map(battery[i].getCurrent(), 0, 6000, 0, 85));
    else if(battery[i].getCurrent() < (blueThreshold-50))
      battery[i].setHue(171);
  }
}
void updateLeds() {
  for (int i = 0; i < numberOfBatteries; i++)
  {
    if (debug) Serial.println("LEDUPDATE: Battery:" + String(i));
    changeLedRange(battery[i].getStart(), battery[i].getEnd(), battery[i].getHue());
  }
  FastLED.show();
  if (debug) Serial.println("LEDUPDATE: FastLED.show()");
}
void changeLedRange(int first, int last, byte hue)
{
  for (int i = first; i < last; i++ ) {
    leds[i].setHSV(hue, 255, brightness);
  }
}
