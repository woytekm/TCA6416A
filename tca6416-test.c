//
// TCA6416 test program
// 
//


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "i2c_lib.h"
#include "tca6416.h"


#define I2C_FILE_NAME "/dev/i2c-1"


int main(int argc, char **argv) {
    int i2c_dev;
    int counter = 0;

    // Open a connection to the I2C userspace control file.
    if ((i2c_dev = open(I2C_FILE_NAME, O_RDWR)) < 0) {
        perror("Unable to open i2c control file");
        exit(1);
    }

  tca6416_set_gpio(i2c_dev,TCA6416_I2C_ADDR_LO,TCA6416_GPIO13, TCA6416_GPIO_OUT);

  while (counter < 10)
   {

     tca6416_out_gpio(i2c_dev,TCA6416_I2C_ADDR_LO,TCA6416_GPIO13,0);
     sleep(1);
     tca6416_out_gpio(i2c_dev,TCA6416_I2C_ADDR_LO,TCA6416_GPIO13,1);
     sleep(1);
     counter++;
  }


  close(i2c_dev);


  return 0;
}

