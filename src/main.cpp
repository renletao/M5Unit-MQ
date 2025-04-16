#include <M5Unified.h>
#include "m5_unit_mq.hpp"

M5UnitMQ unitMq;

void setup() {
  M5.begin();
  Serial.begin(115200);
  delay(100);
  while (!unitMq.begin(&Wire1, UNIT_MQ_BASE_ADDR, 21, 22, 100000)) {
    Serial.printf("Module FAN Init faile\r\n");
    delay(500);
  } 
  M5.Display.setTextFont(&fonts::efontCN_16);
  M5.Display.fillScreen(BLACK);
  M5.Display.setTextScroll(true);
  M5.Display.printf("UNIT_MQ Test\n");
  unitMq.setHeatingMode( HEART_MODE_CONTINUOUS);
  delay(10);
  unitMq.setLEDPowerState(LED_WORK_STATUS_ON);
  delay(10);
}

void loop() {
  Serial.printf(".........................................\r\n");
  Serial.printf("LEDPowerState %d \r\n",unitMq.getLEDPowerState());
  Serial.printf("MQ12 ADC %d \r\n",unitMq.getMQADC12bit());
  Serial.printf("NTC12 ADC %d \r\n",unitMq.getNTCADC12bit());

  Serial.printf("ReferenceVoltage %d \r\n",unitMq.getReferenceVoltage());
  Serial.printf("ChannelVoltage %d \r\n",unitMq.getMQChannelVoltage());
  Serial.printf("NTChannelVoltage %d \r\n",unitMq.getNTCChannelVoltage());

  M5.Display.printf("ReferenceVoltage %d \r\n",unitMq.getReferenceVoltage());
  M5.Display.printf("ChannelVoltage %d \r\n",unitMq.getMQChannelVoltage());
  M5.Display.printf("ReferenceVoltage %d \r\n",unitMq.getReferenceVoltage());
  delay(1000);
}