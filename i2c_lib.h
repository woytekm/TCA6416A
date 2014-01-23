//
// i2c_lib header
//

#include <stdint.h>

#define I2C_FILE_NAME "/dev/i2c-1"

int i2c_debug;
int i2c_dev;

uint8_t set_i2c_register(int file, unsigned char addr, unsigned char reg, unsigned char value);
uint8_t get_i2c_register(int file, unsigned char addr, unsigned char reg, unsigned char *val); 
