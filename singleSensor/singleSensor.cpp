#include "mbed.h"
#include "VL53L0X.h"
 
//DigitalOut pp(PA_1);
//Serial pc(PB_10,PB_11);
//I2C i2c(PB_9,PB_8);
 
//VL53L0X sensor(PB_9,PB_8);
uint16_t dist;
int main() {
    //float dist;
    //wait(1);
    //pc.baud(9600);
    //pc.printf("Chegou aqui\r\n");
    printf("Chegou aqui\r\n");
    VL53L0X* sensor = new VL53L0X(PB_9,PB_8);
    sensor->init(true);
    sensor->startContinuous();
    //pc.printf("db1\r\n");
    printf("db1\r\n");
    while(1){
        //pc.printf("db2\r\n");
        printf("db2\r\n");
        dist=sensor->readRangeContinuousMillimeters();
        //pc.printf("%d\r\n",dist);
        printf("%d\r\n",dist);
        wait(1);
    }
}