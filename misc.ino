void initializeINA219() {
  for (int i = 0; i < 3; i++)
  {
    tcaSelect(i);
    delay(100);
    if (! sense1.begin()) {
      Serial.println("Failed to find INA219 chip (Sense 1 Multiplex:" + String(i) + ")");
    }
    if (! sense2.begin()) {
      Serial.println("Failed to find INA219 chip (Sense 2 Multiplex:" + String(i) + ")");
    }
    if (! sense3.begin()) {
      Serial.println("Failed to find INA219 chip (Sense 3 Multiplex:" + String(i) + ")");
    }
    if (! sense4.begin()) {
      Serial.println("Failed to find INA219 chip (Sense 4 Multiplex:" + String(i) + ")");
    }
  }
}
void tcaSelect(uint8_t i) {
  if (i > 7) return;
  if (debug) Serial.println("TCA:" + String(i));
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
  if (debug) Serial.println("TCA success");
}
