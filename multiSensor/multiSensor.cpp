#include "mbed.h"
#include "VL53L0X.h"
//Multi-sensor 
#define range1_addr (0x56)
#define range2_addr (0x60)
#define range3_addr (0x64)
#define range4_addr (0x68)
//Preciso dar mesmo um pino de reset pra cada sensor?
#define range1_XSHUT   PA_2
#define range2_XSHUT   PA_3
#define range3_XSHUT   PA_4
#define range4_XSHUT   PA_5

#define VL53L0_I2C_SDA   PB_9
#define VL53L0_I2C_SCL   PB_8  
#define SERIAL_TX PB_10
#define SERIAL_RX PB_11
 
 //Def serial
Serial pc(SERIAL_TX, SERIAL_RX);
 //Def pinos de dados
static DevI2C devI2c(VL53L0_I2C_SDA,VL53L0_I2C_SCL); 
 
int main()
{   
    pc.baud(9600);
    //Debug1
    //pc.printf("Debug1\r\n");
    /*Contruct the sensors*/
    //O pino desliga pra receber o endereço 
    //VL53L0X -> Recebendo SDA/SLC,pino de reset, Não sei o que é NC
    static DigitalOut shutdown1_pin(range1_XSHUT);
    static VL53L0X range1(&devI2c, &shutdown1_pin, NC);
    static DigitalOut shutdown2_pin(range2_XSHUT);
    static VL53L0X range2(&devI2c, &shutdown2_pin, NC);
    static DigitalOut shutdown3_pin(range3_XSHUT);
    static VL53L0X range3(&devI2c, &shutdown3_pin, NC);
    static DigitalOut shutdown4_pin(range4_XSHUT);
    static VL53L0X range4(&devI2c, &shutdown4_pin, NC);
    
    /*Initial all sensors*/   
    //O endereço fica salvo? Precisa teste
    range1.init_sensor(range1_addr);
    range2.init_sensor(range2_addr);
    range3.init_sensor(range3_addr);
    range4.init_sensor(range4_addr);
    //printf("AddrDebug: %hhX", range1_addr);
    //printf("AddrDebug: %hhX", range2_addr);
    /*Get datas*/
    uint32_t distance1;
    uint32_t distance2;
    uint32_t distance3;
    uint32_t distance4;
    //Status qualify
    int status1;
    int status2;
    int status3;
    int status4;
    //Debug2
    //pc.printf("Debug2\r\n");
    
    while(1){
        //Debug3
        //pc.printf("Debug3-laco\r\n");
        status1 = range1.get_distance(&distance1);
        if (status1 == VL53L0X_ERROR_NONE) {
            pc.printf("Range1 [mm]:            %6ld\r\n", distance1);
        } else {
            pc.printf("Range1 [mm]:                --\r\n");
        }
        //Debug4
        //pc.printf("Debug4-laco\r\n");
        status2 = range2.get_distance(&distance2);
        if (status2 == VL53L0X_ERROR_NONE) {
            pc.printf("Range2 [mm]:            %6ld\r\n", distance2);
        } else {
            pc.printf("Range2 [mm]:                --\r\n");
        }
        status3 = range3.get_distance(&distance3);
        if (status3 == VL53L0X_ERROR_NONE) {
            pc.printf("Range3 [mm]:            %6ld\r\n", distance3);
        } else {
            pc.printf("Range3 [mm]:                --\r\n");
        }
        status4 = range4.get_distance(&distance4);
        if (status4 == VL53L0X_ERROR_NONE) {
            pc.printf("Range2 [mm]:            %6ld\r\n", distance4);
        } else {
            pc.printf("Range2 [mm]:                --\r\n");
        }
        //Debug5
        //pc.printf("Debug5-EOF\r\n");
        wait(0.5);                 
    }
 
}