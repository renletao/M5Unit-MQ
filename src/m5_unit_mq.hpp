/*
 *SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 *SPDX-License-Identifier: MIT
 */

#ifndef __M5_UNIT_MQ_H
#define __M5_UNIT_MQ_H

#include "Arduino.h"
#include "Wire.h"

// #define UNIT_MQ_DEBUG Serial // The corresponding serial port must be
// initialized before use This macro definition can be annotated without sending
// and receiving data prints Define the serial port you want to use, e.g.,
// Serial1 or Serial2
#if defined UNIT_MQ_DEBUG
#define serialPrint(...) UNIT_MQ_DEBUG.print(__VA_ARGS__)
#define serialPrintln(...) UNIT_MQ_DEBUG.println(__VA_ARGS__)
#define serialPrintf(...) UNIT_MQ_DEBUG.printf(__VA_ARGS__)
#define serialFlush() UNIT_MQ_DEBUG.flush()
#else
#endif

/**
 * @brief Default address of the device.
 */
#define UNIT_MQ_BASE_ADDR (0x11)

/**
 * @brief Minimum valid I2C address.
 */
#define UNIT_MQ_I2C_ADDR_MIN (0x08)

/**
 * @brief Maximum valid I2C address.
 */
#define UNIT_MQ_I2C_ADDR_MAX (0x77)

/**
 * @brief MQ configuration register address.
 */
#define UNIT_MQ_CFG_REG_ADDR (0x00)

/**
 * @brief LED configuration register address.
 */
#define UNIT_MQ_LED_CFG_REG_ADDR (0x01)

/**
 * @brief MQ heating high pluse configuration register address.
 */
#define UNIT_MQ_HEATING_HIGH_PLUSE_CFG_REG_ADDR (0x10)

/**
 * @brief MQ heating low pluse configuration register address.
 */
#define UNIT_MQ_HEATING_LOW_PLUSE_CFG_REG_ADDR (0x11)

/**
 * @brief MQ 8-bit ADC register address.
 */
#define UNIT_MQ_8B_ADC_REG_ADDR (0x20)

/**
 * @brief MQ 12-bit ADC register address.
 */
#define UNIT_MQ_12B_ADC_REG_ADDR (0x30)

/**
 * @brief MQ ADC valid tags register address.
 */
#define UNIT_MQ_ADC_VALID_TAGS_REG_ADDR (0x40)

/**
 * @brief Internal temperature 8-bit ADC register address.
 */
#define UNIT_MQ_INT_8B_ADC_REG_ADDR (0x50)

/**
 * @brief Internal temperature 12-bit ADC register address.
 */
#define UNIT_MQ_INT_12B_ADC_REG_ADDR (0x60)

/**
 * @brief Internal temperature value register address.
 */
#define UNIT_MQ_INT_TEMP_VAL_REG_ADDR (0x70)


#define INTERNALT_REFERENCE_VOLTAGE_REG_ADDR (0x80)
#define MQ_CHANNEL_VOLTAGE_REG_ADDR (0x82)
#define NTC_CHANNEL_VOLTAGE_REG_ADDR (0x84)

/**
 * @brief Software version register address.
 */
#define UNIT_MQ_SW_VER_REG_ADDR (0xFE)

/**
 * @brief I2C address register address.
 */
#define UNIT_MQ_I2C_ADDR_REG_ADDR (0xFF)

/**
 * @brief Enum for heart operation modes.
 *
 * This enum defines different modes for heart operation.
 */
typedef enum {
  HEART_MODE_OFF = 0,        /**< @brief 0: OFF mode (default on power-up) */
  HEART_MODE_CONTINUOUS = 1, /**< @brief 1: Continuous heating mode */
  HEART_MODE_PIN_SWITCH = 2  /**< @brief 2: Pin level switch mode */
} heating_mode_t;

/**
 * @brief Enum for LED work status.
 *
 * This enum defines the different work status of the LED.
 */
typedef enum {
  LED_WORK_STATUS_OFF = 0, /**< @brief 0: LED OFF (default on power-up) */
  LED_WORK_STATUS_ON = 1   /**< @brief 1: LED ON */
} led_status_t;

/**
 * @brief Valid tags for MQ ADC value.
 *
 * This enum defines whether the MQ ADC value is valid or not.
 */
typedef enum {
  VALID_TAG_INVALID =0, /**< @brief Invalid value (0): The MQ ADC value is invalid. */
  VALID_TAG_VALID = 1 /**< @brief Valid value (1): The MQ ADC value is valid. */
} valid_tags_t;

class M5UnitMQ {
public:
  /**
   * @brief Initializes the device with optional I2C settings.
   *
   * This function configures the I2C communication settings, allowing the user
   * to specify custom SDA and SCL pins as well as the I2C speed. If no
   * parameters are provided, default values are used. The device is initialized
   * using the provided I2C settings, and it returns a success flag.
   *
   * @param wire   Pointer to the TwoWire object for I2C communication (default
   * is &Wire).
   * @param addr   The I2C address of the device (default is -1, meaning use the
   * default address).
   * @param sda    The SDA pin number (default is -1, meaning use the default
   * SDA pin).
   * @param scl    The SCL pin number (default is -1, meaning use the default
   * SCL pin).
   * @param speed  The I2C bus speed in Hz (default is 4000000L).
   *
   * @return True if initialization was successful, false otherwise.
   */
  bool begin(TwoWire *wire = &Wire, uint8_t addr = -1, uint8_t sda = -1,
             uint8_t scl = -1, uint32_t speed = 4000000L);

  /**
   * @brief Sets the heating mode.
   *
   * This function sets the heating mode of the device.
   *
   * @param mode The desired heating mode to be set.
   */
  void setHeatingMode(heating_mode_t mode);

  /**
   * @brief Gets the current heating mode.
   *
   * This function retrieves the current heating mode of the device.
   *
   * @return The current heating mode.
   */
  heating_mode_t getHeatingMode(void);

  /**
   * @brief Sets the LED power state.
   *
   * This function sets the power state of the LED.
   *
   * @param status The desired LED power state to be set.
   */
  void setLEDState(led_status_t status);

  /**
   * @brief Gets the current LED power state.
   *
   * This function retrieves the current power state of the LED.
   *
   * @return The current LED power state.
   */
  led_status_t getLEDState(void);

  /**
   * @brief Sets the pulse level time.
   *
   * This function sets the high and low level pulse times for the device.
   *
   * @param highLevelTime The high level pulse time in milliseconds.
   * @param lowLevelTime The low level pulse time in milliseconds.
   */
  void setPulseLevelTime(uint8_t highLevelTime, uint8_t lowLevelTime);

  /**
   * @brief Gets the pulse level time.
   *
   * This function retrieves the high and low level pulse times for the device.
   *
   * @param highLevelTime Pointer to the variable where the high level time will
   * be stored.
   * @param lowLevelTime Pointer to the variable where the low level time will
   * be stored.
   */
  void getPulseLevelTime(uint8_t *highLevelTime, uint8_t *lowLevelTime);

  /**
   * @brief Gets the 8-bit ADC value from the MQ sensor.
   *
   * This function retrieves the 8-bit ADC value from the MQ sensor.
   *
   * @return The 8-bit ADC value from the MQ sensor.
   */
  uint8_t getMQADC8bit(void);

  /**
   * @brief Gets the 16-bit ADC value from the MQ sensor.
   *
   * This function retrieves the 16-bit ADC value from the MQ sensor.
   *
   * @return The 16-bit ADC value from the MQ sensor.
   */
  uint16_t getMQADC12bit(void);

  /**
   * @brief Retrieves the valid tags.
   *
   * This function returns the valid tags that are currently available.
   *
   * @return The valid tags as a valid_tags_t type.
   */
  valid_tags_t getValidTags(void);

  /**
   * @brief Gets the 8-bit ADC value from the NTC sensor.
   *
   * This function retrieves the 8-bit ADC value from the NTC sensor.
   *
   * @return The 8-bit ADC value from the NTC sensor.
   */
  uint8_t getNTCADC8bit(void);

  /**
   * @brief Gets the 16-bit ADC value from the NTC sensor.
   *
   * This function retrieves the 16-bit ADC value from the NTC sensor.
   *
   * @return The 16-bit ADC value from the NTC sensor.
   */
  uint16_t getNTCADC12bit(void);

  /**
   * @brief Gets the current temperature.
   *
   * This function retrieves the current temperature measured by the device.
   *
   * @return The current temperature in degrees Celsius.
   */
  void getTemperature(uint8_t *integerValue,uint8_t *decimalValue);

  uint16_t getReferenceVoltage(void);

  uint16_t getMQChannelVoltage(void);

  uint16_t getNTCChannelVoltage(void);


  /**
   * @brief Gets the firmware version number.
   *
   * This function retrieves the current software version number of the device's
   * firmware.
   *
   * Please note that this operation involves writing to the device's flash
   * memory, which may take more than 20ms to complete.
   *
   * @return The current firmware version number.
   */
  uint8_t getFirmwareVersion(void);

  /**
   * @brief Sets the I2C device address.
   *
   * This function allows the user to set the I2C address for the device.
   * It returns the newly set I2C address. The valid I2C address range is from
   * 0x08 to 0x77. If the provided address is greater than the maximum (0x77),
   * it will be set to 0x77. If the provided address is less than the minimum
   * (0x08), it will be set to 0x08.
   *
   * Please note that this operation involves writing to the device's flash
   * memory, which may take more than 20ms to complete.
   *
   * @param addr The new I2C address to be set for the device.
   *                The address should be within the range 0x08 to 0x77.
   *                If it is outside this range, the closest valid address will
   * be used.
   *
   * @return The newly set I2C address.
   */
  uint8_t setI2CAddress(uint8_t addr);

  /**
   * @brief Gets the current I2C device address.
   *
   * This function retrieves the current I2C address of the device.
   *
   * @return The current I2C address of the device.
   */
  uint8_t getI2CAddress(void);

private:
  TwoWire *_wire;
  uint8_t _addr;
  uint8_t _scl;
  uint8_t _sda;
  uint32_t _speed;

  // Mutex flag for indicating whether the mutex is locked.
  bool mutexLocked = false; // Mutex semaphore.

  /**
   * @brief Writes multiple bytes to a specified register.
   *
   * This function writes a sequence of bytes from the provided buffer
   * to the device located at the specified I2C address and register.
   *
   * @param addr   The I2C address of the device.
   * @param reg    The register address where the data will be written.
   * @param buffer A pointer to the data buffer that contains the bytes to be
   * written.
   * @param length The number of bytes to write from the buffer.
   */
  void writeBytes(uint8_t addr, uint8_t reg, uint8_t *buffer, uint8_t length);

  /**
   * @brief Reads multiple bytes from a specified register.
   *
   * This function reads a sequence of bytes from the device located at
   * the specified I2C address and register into the provided buffer.
   *
   * @param addr   The I2C address of the device.
   * @param reg    The register address from which the data will be read.
   * @param buffer A pointer to the data buffer where the read bytes will be
   * stored.
   * @param length The number of bytes to read into the buffer.
   */
  void readBytes(uint8_t addr, uint8_t reg, uint8_t *buffer, uint8_t length);

  /**
   * @brief Acquires a mutex lock.
   *
   * This function attempts to acquire a mutex lock to ensure thread-safe access
   * to shared resources. It should be paired with a corresponding call to
   * releaseMutex() to prevent deadlocks.
   */
  void acquireMutex();

  /**
   * @brief Releases a mutex lock.
   *
   * This function releases a previously acquired mutex lock, allowing other
   * threads to access shared resources. It should only be called after
   * successfully acquiring the mutex with acquireMutex().
   */
  void releaseMutex();
};

#endif