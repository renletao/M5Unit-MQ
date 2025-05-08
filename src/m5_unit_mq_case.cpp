#include "m5_unit_mq_case.hpp"
#include <math.h>

void unit_mq_test_case_1(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 1\r\n");
    heating_mode_t heading_mode = HEARTING_MODE_OFF;
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
            // Serial.printf("Heating Mode: %d\r\n ", readByte);
            Serial.printf(".");
        }
        switch (heading_mode) {
            case HEARTING_MODE_OFF:
                heading_mode = HEARTING_MODE_CONTINUOUS;
                break;
            case HEARTING_MODE_CONTINUOUS:
                heading_mode = HEARTING_MODE_PIN_SWITCH;
                break;
            case HEARTING_MODE_PIN_SWITCH:
                heading_mode = HEARTING_MODE_OFF;
                break;
        }
        // delay(1);
    }
}

void unit_mq_test_case_2(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 2\r\n");
    led_status_t led_status = LED_WORK_STATUS_OFF;
    led_status_t readByte;
    // unitMQ.setHeatingMode(HEARTING_MODE_OFF);
    unitMQ.setHeatingMode(HEARTING_MODE_CONTINUOUS);
    //   unitMQ.setHeatingMode(HEARTING_MODE_PIN_SWITCH);
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
            // Serial.printf(".");
        }
        switch (led_status) {
            case LED_WORK_STATUS_OFF:
                led_status = LED_WORK_STATUS_ON;
                break;
            case LED_WORK_STATUS_ON:
                led_status = LED_WORK_STATUS_OFF;
                break;
            default:
                break;
        }
        delay(5);
    }
}

void unit_mq_test_case_3(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 3\r\n");
    uint8_t writeByte[2][2] = {{30, 10}, {30, 5}};
    uint8_t index           = 0;
    uint8_t readByte[2]     = {0};
    unitMQ.setHeatingMode(HEARTING_MODE_PIN_SWITCH);
    unitMQ.setLEDState(LED_WORK_STATUS_ON);
    while (1) {
        unitMQ.setPulseLevelTime(writeByte[index][0], writeByte[index][1]);
        unitMQ.getPulseLevelTime(&readByte[0], &readByte[1]);
        if (readByte[0] != writeByte[index][0] || readByte[1] != writeByte[index][1]) {
            while (1) {
                Serial.printf("unit_mq_test_case_3 error(Pulse Level Time Test)\r\n");
                delay(1000);
            }
        } else {
            Serial.printf("highLevelTime : %d  lowLevelTime : %d \r\n", readByte[0], readByte[1]);
            // Serial.printf(".");
        }
        index = 1 - index;
        delay(5*60*1000);
        // delay(1);
    }
}

void unit_mq_test_case_4(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 4\r\n");
    while (1) {
        Serial.printf("MQ ADC 8bit  : %d \r\n", unitMQ.getMQADC8bit());
        Serial.printf("MQ ADC 12bit : %d \r\n", unitMQ.getMQADC12bit());
    }
}

void unit_mq_test_case_5(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 5\r\n");
    unitMQ.setHeatingMode(HEARTING_MODE_PIN_SWITCH);
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
    Serial.printf("Starting Test Case 6\r\n");
    while (1) {
        Serial.printf("NTC ADC 8bit  : %d \r\n", unitMQ.getNTCADC8bit());
        Serial.printf("NTC ADC 12bit : %d \r\n", unitMQ.getNTCADC12bit());
    }
}

void unit_mq_test_case_7(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 7\r\n");
    uint16_t ntcResistance = 0;
    float ntcTemperature   = 0;
    while (1) {
        ntcResistance  = unitMQ.getNTCResistance();
        ntcTemperature = unitMQ.getNTCTemperature(ntcResistance);
        Serial.printf("NTC Resistance : %d \r\n", ntcResistance);
        Serial.printf("NTC Temperature : %.2f C \r\n", ntcTemperature);
        delay(1000);
    }
}

void unit_mq_test_case_8(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 8\r\n");
    while (1) {
        Serial.printf("Reference Voltage: %d \r\n", unitMQ.getReferenceVoltage());
        Serial.printf("MQ ADC 12bit : %d \r\n", unitMQ.getMQADC12bit());
        delay(100);
    }
}

void unit_mq_test_case_9(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 9\r\n");
    while (1) {
        Serial.printf("MQ Voltage : %d \r\n", unitMQ.getMQVoltage());
        delay(100);
    }
}

void unit_mq_test_case_10(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 10\r\n");
    while (1) {
        Serial.printf("NTC Voltage : %d \r\n", unitMQ.getNTCVoltage());
        delay(1);
    }
}

void unit_mq_test_case_11(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 11\r\n");
    while (1) {
        Serial.printf("Firmware Version : %d\r\n", unitMQ.getFirmwareVersion());
        delay(1);
    }
}

void unit_mq_test_case_12(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 12\r\n");
    unitMQ.setI2CAddress(0x18);
    delay(100);
    while (1) {
        Serial.printf("I2C Address : 0x%02X\r\n", unitMQ.getI2CAddress());
        delay(10);
    }
}

void unit_mq_test_case_13(M5UnitMQ unitMQ) {
    Serial.printf("Starting Test Case 13\r\n");
    heating_mode_t heading_mode = HEARTING_MODE_OFF;
    heating_mode_t readByte1;
    led_status_t led_status = LED_WORK_STATUS_OFF;
    led_status_t readByte2;
    uint8_t writeByte3[2][2] = {{30, 10}, {40, 20}};
    uint8_t index            = 1;
    uint8_t readByte3[2]     = {0};
    while (1) {
        unitMQ.setHeatingMode(heading_mode);
        readByte1 = unitMQ.getHeatingMode();
        if (readByte1 != heading_mode) {
            Serial.printf("unit_mq_test_case_1 error(heading mode Test)\r\n");
        }
        switch (heading_mode) {
            case HEARTING_MODE_OFF:
                heading_mode = HEARTING_MODE_CONTINUOUS;
                break;
            case HEARTING_MODE_CONTINUOUS:
                heading_mode = HEARTING_MODE_PIN_SWITCH;
                break;
            case HEARTING_MODE_PIN_SWITCH:
                heading_mode = HEARTING_MODE_OFF;
                break;
        }
        unitMQ.setLEDState(led_status);
        readByte2 = unitMQ.getLEDState();
        if (readByte2 != led_status) {
            Serial.printf("unit_mq_test_case_2 error(LED Status Test)\r\n");
        }
        switch (led_status) {
            case LED_WORK_STATUS_OFF:
                led_status = LED_WORK_STATUS_ON;
                break;
            case LED_WORK_STATUS_ON:
                led_status = LED_WORK_STATUS_OFF;
                break;
            default:
                break;
        }
        unitMQ.setPulseLevelTime(writeByte3[index][0], writeByte3[index][1]);
        unitMQ.getPulseLevelTime(&readByte3[0], &readByte3[1]);
        if (readByte3[0] != writeByte3[index][0] || readByte3[1] != writeByte3[index][1]) {
            Serial.printf("unit_mq_test_case_3 error(Pulse Level Time Test)\r\n");
        }
        index = 1 - index;
        unitMQ.getMQADC8bit();
        unitMQ.getMQADC12bit();
        unitMQ.getValidTags();
        unitMQ.getNTCADC8bit();
        unitMQ.getNTCADC12bit();
        unitMQ.getNTCResistance();
        unitMQ.getReferenceVoltage();
        unitMQ.getMQVoltage();
        unitMQ.getNTCVoltage();
        unitMQ.getFirmwareVersion();
        unitMQ.getI2CAddress();
        // delay(3000);
        // Serial.printf(".");
    }
}
