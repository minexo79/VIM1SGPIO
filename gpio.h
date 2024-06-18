#include "utils.h"

#define SYSFS_GPIO_DIR          "/sys/class/gpio"
#define SYSFS_GPIO_EXPORT       SYSFS_GPIO_DIR "/export"
#define SYSFS_GPIO_UNEXPORT     SYSFS_GPIO_DIR "/unexport"

#define OUTPUT  "out"
#define INPUT   "in"

#define LOW     0
#define HIGH    1

/**
 * @brief 
 * Export a pin to the sysfs GPIO directory
 * @param pin the pin number to export
 * @return int 0 on success, -1 on failure
 */
int pinExport(int pin);

/**
 * @brief 
 * Unexport a pin to the sysfs GPIO directory
 * @param pin the pin number to export
 * @return int 0 on success, -1 on failure
 */
int pinUnexport(int pin);

/**
 * @brief 
 * Set the pin mode of a pin
 * @param pin the pin number to set the mode
 * @param mode the mode to set the pin to
 * @return int 0 on success, -1 on failure
 */
int pinMode(int pin, std::string mode);

/**
 * @brief 
 * Read a value from a pin
 * @param pin the pin number to read from
 * @return int the value read from the pin, -1 on failure
 */
int digitalRead(int pin);

/**
 * @brief 
 * Write a value to a pin
 * @param pin the pin number to write to
 * @param value the value to write to the pin
 * @return int 0 on success, -1 on failure
 */
int digitalWrite(int pin, int value);