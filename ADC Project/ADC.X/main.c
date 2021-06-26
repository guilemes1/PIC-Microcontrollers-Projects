/*
 * File:   main.c
 * Author: 20185189
 *
 * Created on 25 de Junho de 2021, 15:59
 */

#include "delay.h"
#include "config.h"
#include <xc.h>
#include "dispLCD4vias.h"
#include "adc.h"

void main(void) 
{
    dispLCD_init();
    adc_init();
    
    dispLCD(0,0,"ADC:            ");
    while(1)
    {
        dispLCD_num(0,10, adc(), 5);
    }    
    
    return;
}
