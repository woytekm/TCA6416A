//
// global variables and constants for TCA6416A I2C GPIO access driver
// (c) woytekm
//

#include <stdint.h>

#define TCA6416A_I2C_ADDR_HI 0x20
#define TCA6416A_I2C_ADDR_LO 0x21

#define TCA6416A_GPIO0 0
#define TCA6416A_GPIO1 1
#define TCA6416A_GPIO2 2
#define TCA6416A_GPIO3 3
#define TCA6416A_GPIO4 4
#define TCA6416A_GPIO5 5
#define TCA6416A_GPIO6 6
#define TCA6416A_GPIO7 7
#define TCA6416A_GPIO8 8
#define TCA6416A_GPIO9 9
#define TCA6416A_GPIO10 10
#define TCA6416A_GPIO11 11
#define TCA6416A_GPIO12 12
#define TCA6416A_GPIO13 13
#define TCA6416A_GPIO14 14
#define TCA6416A_GPIO15 15

#define TCA6416A_INPUT_BANK_0 0x0
#define TCA6416A_INPUT_BANK_1 0x1
#define TCA6416A_OUTPUT_BANK_0 0x2
#define TCA6416A_OUTPUT_BANK_1 0x3
#define TCA6416A_POLARITY_BANK_0 0x4
#define TCA6416A_POLARITY_BANK_1 0x5
#define TCA6416A_CONFIG_BANK_0 0x6
#define TCA6416A_CONFIG_BANK_1 0x7

#define TCA6416A_GPIO_IN 1
#define TCA6416A_GPIO_OUT 0

#define TCA6416A_MAX_GPIO 15

uint8_t input_regs_bank_0;
uint8_t input_regs_bank_1;

uint8_t output_regs_bank_0;
uint8_t output_regs_bank_1;

uint8_t polarity_regs_bank_0;
uint8_t polarity_regs_bank_1;

uint8_t config_regs_bank_0;
uint8_t config_regs_bank_1;


uint8_t tca6416a_init(int i2cdev, uint8_t ic_addr);
uint8_t tca6416a_read_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio);
uint8_t tca6416a_out_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio, uint8_t state);
uint8_t tca6416a_set_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio, uint8_t mode);

