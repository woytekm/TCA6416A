//
// TCA6416A I2C GPIO routines
// (c) woytekm
//
//
//


#include <stdio.h>
#include <stdint.h>

#include "tca6416a.h"



uint8_t tca6416a_read_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio)
 {

   unsigned char in_bank, out_bank, current_bank_state;

   if((gpio > 7) && (gpio < TCA6416A_MAX_GPIO)) // bank 1
    {
     gpio -= 8; // shift GPIO number for bank 1
     in_bank = TCA6416A_INPUT_BANK_1;
    }
   else if((gpio > 0) && (gpio < 8))
    {
     in_bank = TCA6416A_INPUT_BANK_0;
    }
   else
    return -1;

  get_i2c_register(i2cdev, ic_addr, in_bank, &current_bank_state);
  
  if(current_bank_state & (1 << gpio))
   return 1;
  else 
   return 0;

 }



uint8_t tca6416a_out_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio, uint8_t state)
 {
   unsigned char in_bank, out_bank, *current_bank_state;

   if((gpio > 7) && (gpio < TCA6416A_MAX_GPIO)) // bank 1
    {
     gpio -= 8; // shift GPIO number for bank 1
     out_bank = TCA6416A_OUTPUT_BANK_1;
     current_bank_state =  &input_regs_bank_1;
    }
   else if((gpio > 0) && (gpio < 8))
    {
     out_bank = TCA6416A_OUTPUT_BANK_0;
     current_bank_state = &input_regs_bank_0;
    }
   else
    return -1;

   if(state == 1)
    {
     *current_bank_state |= (1 << gpio);
     set_i2c_register(i2cdev, ic_addr, out_bank, *current_bank_state);
    }
   else
    {
     *current_bank_state &= ~(1 << gpio);
     set_i2c_register(i2cdev, ic_addr, out_bank, *current_bank_state);
    }

 return 0;

 }


uint8_t tca6416a_set_gpio(int i2cdev, uint8_t ic_addr, uint8_t gpio, uint8_t mode)
 {
   unsigned char in_bank, out_bank, *current_bank_state;

   if((gpio > 7) && (gpio < TCA6416A_MAX_GPIO)) // bank 1
    {
     gpio -= 8; // shift GPIO number for bank 1
     out_bank = TCA6416A_CONFIG_BANK_1;
     current_bank_state =  &input_regs_bank_1;
    }
   else if((gpio > 0) && (gpio < 8))
    {
     out_bank = TCA6416A_CONFIG_BANK_0;
     current_bank_state =  &input_regs_bank_0;
    }
   else
    return -1;

   if(mode == TCA6416A_GPIO_IN)
    {
     *current_bank_state |= (1 << gpio);
     set_i2c_register(i2cdev, ic_addr, out_bank, *current_bank_state);
    }
   else if(mode == TCA6416A_GPIO_OUT)
    {
     *current_bank_state &= ~(1 << gpio);
     set_i2c_register(i2cdev, ic_addr, out_bank, *current_bank_state);
    }

 return 0;

 }


uint8_t tca6416a_init(int i2cdev, uint8_t ic_addr)
 {

   get_i2c_register(i2cdev, ic_addr, TCA6416A_INPUT_BANK_0, &output_regs_bank_0);
   get_i2c_register(i2cdev, ic_addr, TCA6416A_INPUT_BANK_1, &output_regs_bank_1);
   get_i2c_register(i2cdev, ic_addr, TCA6416A_POLARITY_BANK_0, &polarity_regs_bank_0);
   get_i2c_register(i2cdev, ic_addr, TCA6416A_POLARITY_BANK_1, &polarity_regs_bank_1);
   get_i2c_register(i2cdev, ic_addr, TCA6416A_CONFIG_BANK_0, &config_regs_bank_0);
   get_i2c_register(i2cdev, ic_addr, TCA6416A_CONFIG_BANK_1, &config_regs_bank_1);

   return 0;

 }


