#include "m5_unit_mq_case.hpp"
#include <math.h>

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
      // Serial.printf("Heating Mode: %d\r\n ", readByte);
      Serial.printf(".");

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
    // delay(1);
  }
}

void unit_mq_test_case_2(M5UnitMQ unitMQ) {
  led_status_t led_status = LED_WORK_STATUS_OFF;
  led_status_t readByte;
  // unitMQ.setHeatingMode(HEART_MODE_OFF);
    unitMQ.setHeatingMode(HEART_MODE_CONTINUOUS);
  //   unitMQ.setHeatingMode(HEART_MODE_PIN_SWITCH);
  delay(100);
  unitMQ.setLEDState(LED_WORK_STATUS_ON);
  while(1){
    Serial.printf("Heating Mode: %d\r\n ", (uint8_t)unitMQ.getHeatingMode());
    Serial.printf("LED Status: %d\r\n ", (uint8_t)unitMQ.getLEDState());
    delay(1000);
  }
  // while (1) {
    // unitMQ.setLEDState(led_status);
  //   readByte = unitMQ.getLEDState();
  //   if (readByte != led_status) {
  //     while (1) {
  //       Serial.printf("unit_mq_test_case_2 error(LED Status Test)\r\n");
  //       delay(1000);
  //     }
  //   } else {
  //     // Serial.printf("LED Status: %d\r\n ", readByte);
  //     // Serial.printf(".");
  //   }
  //   delay(1);
  // }
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


const float Rp=10000.0; //10K
const float T2 = (273.15+25.0);//T2
const float Bx = 3950.0;//B
const float Ka = 273.15;
	
double my_log(double x) {
  // 确保 x > 0
  if (x <= 0) {
      return -1;  // 返回一个错误值，表示计算失败
  }

  // 使用泰勒级数近似计算ln(x)的值
  double result = 0.0;
  double term = (x - 1) / (x + 1);  // 这里我们采用 ln(1 + x) 的变形

  // 计算ln(x)时，使用泰勒级数展开
  double numerator = term;
  double denominator = 1.0;

  for (int i = 1; i <= 20; i++) {
      result += numerator / denominator;
      numerator *= term * term;  // 每次乘以x^2
      denominator += 2;          // 分母逐渐增加
  }

  return 2 * result;  // 乘2是因为我们用的是 ln((1+x)/(1-x)) 的形式
}

float Get_Temp(uint16_t byte)
{
	float Rt;
	float temp;
	Rt = byte;
	//like this R=5000, T2=273.15+25,B=3470, RT=5000*EXP(3470*(1/T1-1/(273.15+25)),  
	temp = Rt/Rp;
  
	temp = log(temp);//ln(Rt/Rp)

  // float log_test = 10;
  // Serial.printf("my log : %.2f    %.2f \r\n", log_test,my_log(log_test));
  // Serial.printf("sy log : %.2f    %.2f \r\n", log_test,log(log_test));

	temp/=Bx;//ln(Rt/Rp)/B
	temp+=(1/T2);
	temp = 1/(temp);
	temp-=Ka;
	return temp;
} 



void unit_mq_test_case_7(M5UnitMQ unitMQ) {
  uint8_t integerValue;
  uint8_t decimalValue;
  while (1) {
    unitMQ.getTemperature(&integerValue,&decimalValue);
    // Serial.printf("Temperature : %d.%d C \r\n", integerValue,decimalValue);
    // Serial.printf("my log Temperature : %.2f C \r\n", my_log(integerValue << 8 |decimalValue));
    Serial.printf("Temperature : %.2f C \r\n", Get_Temp(integerValue << 8 |decimalValue));
    Serial.printf("Temperature : %d C \r\n", integerValue << 8 |decimalValue);
    delay(1000);
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
    delay(1000);
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
    // Serial.printf("Temperature : %d", unitMQ.getTemperature());
    delay(1);
  }
}

void unit_mq_test_case_14(M5UnitMQ unitMQ) {}
