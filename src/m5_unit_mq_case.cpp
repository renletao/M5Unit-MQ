#include "m5_unit_mq_case.hpp"

void unit_mq_test_case_1(M5UnitMQ unitMQ) {
  heating_mode_t heading_mode = HEART_MODE_OFF;
  heating_mode_t readByte;
  while (1) {
    unitMQ.setHeatingMode(heading_mode);
    readByte = unitMQ.getHeatingMode();
    if (readByte != heading_mode) {
      while (1) {
        Serial.printf("unit_mq_test_case_1 error(heading mode Test)\r\n");
        delay(1000);
      }
    } else {
      Serial.printf("Heating Mode: %d\r\n ", readByte);
    }
    switch (heading_mode) {
    case HEART_MODE_OFF:
      heading_mode = HEART_MODE_CONTINUOUS;
      break;
    case HEART_MODE_CONTINUOUS:
      heading_mode = HEART_MODE_PIN_SWITCH;
      break;
    case HEART_MODE_PIN_SWITCH:
      heading_mode = HEART_MODE_OFF;
      break;
    }
    delay(1);
  }
}

void unit_mq_test_case_2(M5UnitMQ unitMQ) {
  led_status_t led_status = LED_WORK_STATUS_OFF;
  led_status_t readByte;
  unitMQ.setHeatingMode(HEART_MODE_OFF);
  //   unitMQ.setHeatingMode(HEART_MODE_CONTINUOUS);
  //   unitMQ.setHeatingMode(HEART_MODE_PIN_SWITCH);
  while (1) {
    unitMQ.setLEDState(led_status);
    readByte = unitMQ.getLEDState();
    if (readByte != led_status) {
      while (1) {
        Serial.printf("unit_mq_test_case_2 error(LED Status Test)\r\n");
        delay(1000);
      }
    } else {
      Serial.printf("LED Status: %d\r\n ", readByte);
    }
    delay(1);
  }
}

void unit_mq_test_case_3(M5UnitMQ unitMQ) {

  uint8_t writeByte[2][2] = {{30, 10}, {40, 20}};
  uint8_t index = 0;
  uint8_t readByte[2] = {0};
  while (1) {
    unitMQ.setPulseLevelTime(writeByte[index][0], writeByte[index][1]);
    unitMQ.getPulseLevelTime(&readByte[0], &readByte[1]);
    if (readByte[0] != writeByte[index][0] ||
        readByte[1] != writeByte[index][1]) {
      while (1) {
        Serial.printf("unit_mq_test_case_3 error(Pulse Level Time Test)\r\n");
        delay(1000);
      }
    } else {
      Serial.printf("highLevelTime : %d  lowLevelTime : %d \r\n", readByte[0],
                    readByte[1]);
    }
    index = 1 - index;
    // delay(3*160*1000);
    delay(1);
  }
}

void unit_mq_test_case_4(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("MQ ADC 8bit  : %d \r\n", unitMQ.getMQADC8bit());
    Serial.printf("MQ ADC 12bit : %d \r\n", unitMQ.getMQADC12bit());
  }
}

void unit_mq_test_case_5(M5UnitMQ unitMQ) {
  uint8_t readByte;
  while (1) {
    readByte = unitMQ.getValidTags();
    if (readByte) {
      Serial.printf(" Valid Tags Enable\r\n");
    } else {
      Serial.printf(" Valid Tags Disable\r\n");
    }
    delay(1);
  }
}

void unit_mq_test_case_6(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("NTC ADC 8bit  : %d \r\n", unitMQ.getNTCADC8bit());
    Serial.printf("NTC ADC 12bit : %d \r\n", unitMQ.getNTCADC12bit());
  }
}

void unit_mq_test_case_7(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("Temperature : %d", unitMQ.getTemperature());
    delay(1);
  }
}

void unit_mq_test_case_8(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("Reference Voltage: %d \r\n",unitMQ.getReferenceVoltage());
    delay(1);
  }
}

void unit_mq_test_case_9(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("MQ Channel Voltage : %d \r\n",unitMQ.getMQChannelVoltage());
    delay(1);
  }
}

void unit_mq_test_case_10(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("NTC Channel Voltage : %d \r\n",unitMQ.getNTCChannelVoltage());
    delay(1);
  }
}

void unit_mq_test_case_11(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("Firmware Version : %d", unitMQ.getFirmwareVersion());
    delay(1);
  }
}

void unit_mq_test_case_12(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("I2C Address : %d", unitMQ.getI2CAddress());
    delay(1);
  }
}

void unit_mq_test_case_13(M5UnitMQ unitMQ) {
  while (1) {
    Serial.printf("Temperature : %d", unitMQ.getTemperature());
    delay(1);
  }
}

void unit_mq_test_case_14(M5UnitMQ unitMQ) {}
