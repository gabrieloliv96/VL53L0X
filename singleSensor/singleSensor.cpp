/*
 *   Q0000
 *   AUTOR:   Gabriel Oliveira
 *   SKETCH:  Módulo do sensor unico VL53L0X para BluePill(Nucleo STM32F103)
 *   OBJETIVO: Monitoramento de distancias
 *   DATA:    26/02/2020
*/

#include "mbed.h"
#include "VL53L0X.h"
 

uint16_t dist;
int main() {
    // Criando o objeto para chamada do sensor
    VL53L0X* sensor = new VL53L0X(PB_9,PB_8);
    // Ligando
    sensor->init(true);
    sensor->startContinuous();
    
    while(1){
        // Iniciando a medição
        dist=sensor->readRangeContinuousMillimeters();
        printf("%d\r\n",dist);
        wait(1);
    }
}
