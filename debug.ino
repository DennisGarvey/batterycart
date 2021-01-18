void batteryStats() {
  for (int i = 0; i < 12; i++)
  {
    Serial.println("BATTERYSTATS: Battery " + String(i) + ": " + "V=" + String(battery[i].getVoltage()) + " I=" + String(battery[i].getCurrent()) + " hue=" + String(battery[i].getHue()));
  }
}
