/*
 *SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 *SPDX-License-Identifier: MIT
 */

#ifndef __M5_UNIT_MQ_CASE_H
#define __M5_UNIT_MQ_CASE_H

#include <stdint.h>
#include <stdbool.h>
#include "m5_unit_mq.hpp"

void unit_mq_test_case_1(M5UnitMQ unitMQ);  // 写入MQ工作状态，并读取校验

void unit_mq_test_case_2(M5UnitMQ unitMQ);  // 写入LED工作状态，并读取校验

void unit_mq_test_case_3(M5UnitMQ unitMQ);  // 设置高低引脚电平，并读取校验，示波器抓取测试

void unit_mq_test_case_4(M5UnitMQ unitMQ);  // 循环读取MQ的ADC（8bit 12bit）

void unit_mq_test_case_5(M5UnitMQ unitMQ);  // 循环读取Valid tags

void unit_mq_test_case_6(M5UnitMQ unitMQ);  // 循环读取NTC的ADC (8bit 12bit)

void unit_mq_test_case_7(M5UnitMQ unitMQ);  // 循环读取温度

void unit_mq_test_case_8(M5UnitMQ unitMQ);  // 循环读取内部参考电压

void unit_mq_test_case_9(M5UnitMQ unitMQ);  // 循环读取MQ Channel 电压

void unit_mq_test_case_10(M5UnitMQ unitMQ);  // 循环读取NTC Channel 电压

void unit_mq_test_case_11(M5UnitMQ unitMQ);  // 循环读取软件版本高

void unit_mq_test_case_12(M5UnitMQ unitMQ);  // I2C地址测试

void unit_mq_test_case_13(M5UnitMQ unitMQ);  // 压力测试

void unit_mq_test_case_14(M5UnitMQ unitMQ);  
 

#endif