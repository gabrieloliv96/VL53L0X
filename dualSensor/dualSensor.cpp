/*
 *   Q0000
 *   AUTOR:   Gabriel Oliveira
 *   SKETCH:  Módulo do sensor duplo VL53L0X para BluePill(Nucleo STM32F103)
 *   OBJETIVO: Monitoramento de distancias
 *   DATA:    26/02/2020
*/


#include "mbed.h"
#include "VL53L0X.h"
// Endereços
#define range1_addr (0x56)
#define range2_addr (0x60)
// Pinos de reset 
#define range1_XSHUT   PA_2
#define range2_XSHUT   PA_3
// Pinos de dados
#define VL53L0_I2C_SDA   PB_9
#define VL53L0_I2C_SCL   PB_8  
// Serial
#define SERIAL_TX PB_10
#define SERIAL_RX PB_11
 
 //Def serial
Serial pc(SERIAL_TX, SERIAL_RX);
 //Def pinos de dados
static DevI2C devI2c(VL53L0_I2C_SDA,VL53L0_I2C_SCL); 
 
int main()
{   
    pc.baud(9600);
    
    // Contrutores 
    // O pino desliga para receber o endereço 
    // VL53L0X -> Recebendo SDA/SLC,pino de reset
    static DigitalOut shutdown1_pin(range1_XSHUT);
    static VL53L0X range1(&devI2c, &shutdown1_pin, NC);
    static DigitalOut shutdown2_pin(range2_XSHUT);
    static VL53L0X range2(&devI2c, &shutdown2_pin, NC);
    
    // Ligando os sensores com novo endereço   
    
    range1.init_sensor(range1_addr);
    range2.init_sensor(range2_addr);
   
    // Variaveis de dados    
    uint32_t distance1;
    uint32_t distance2;
 
    // Error NULL
    int status1;
    int status2;
    
    
    while(1){
        
        status1 = range1.get_distance(&distance1);
        if (status1 == VL53L0X_ERROR_NONE) {
            pc.printf("Range1 [mm]:            %6ld\r\n", distance1);
        } else {
            pc.printf("Range1 [mm]:                --\r\n");
        }
        
        status2 = range2.get_distance(&distance2);
        if (status2 == VL53L0X_ERROR_NONE) {
            pc.printf("Range2 [mm]:            %6ld\r\n", distance2);
        } else {
            pc.printf("Range2 [mm]:                --\r\n");
        }
      
        wait(0.5);                 
    }
 
}
