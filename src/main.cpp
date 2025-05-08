#include <M5Unified.h>
#include "m5_unit_mq.hpp"
#include "m5_unit_mq_case.hpp"

M5UnitMQ unitMQ;

void setup()
{
    M5.begin();
    Serial.begin(115200);
    delay(100);
    while (!unitMQ.begin(&Wire1, UNIT_MQ_BASE_ADDR, 21, 22, 100000)) {
        Serial.printf("Module FAN Init faile\r\n");
        delay(500);
    }
    M5.Display.setTextFont(&fonts::efontCN_16);
    M5.Display.fillScreen(BLACK);
    M5.Display.setTextScroll(true);
    M5.Display.printf("UNIT_MQ Test\n");
    unitMQ.setHeatingMode(HEARTING_MODE_CONTINUOUS);

    unitMQ.setLEDState(LED_WORK_STATUS_ON);
}

void loop()
{
    // unit_mq_test_case_1(unitMQ); // 写入MQ工作状态，并读取校验
    // unit_mq_test_case_2(unitMQ); // 写入LED工作状态，并读取校验
    // unit_mq_test_case_3(unitMQ); // 设置高低引脚电平，并读取校验，示波器抓取测试
    // unit_mq_test_case_4(unitMQ); // 循环读取MQ的ADC（8bit 12bit）
    // unit_mq_test_case_5(unitMQ); // 循环读取Valid tags
    // unit_mq_test_case_6(unitMQ); // 循环读取NTC的ADC (8bit 12bit)
    // unit_mq_test_case_7(unitMQ); // 循环读取NTC Resistance
    // unit_mq_test_case_8(unitMQ); // 循环读取内部参考电压
    // unit_mq_test_case_9(unitMQ); // 循环读取MQ Channel 电压
    // unit_mq_test_case_10(unitMQ); // 循环读取NTC Channel 电压
    // unit_mq_test_case_11(unitMQ); // 循环读取软件版本高
    // unit_mq_test_case_12(unitMQ); // I2C地址测试
    // unit_mq_test_case_13(unitMQ); // 压力测试
}