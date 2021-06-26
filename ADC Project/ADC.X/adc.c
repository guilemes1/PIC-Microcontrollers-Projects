/*
 * File:   adc.c
 * Author: 20185189
 *
 * Created on 25 de Junho de 2021, 13:50
 */


#include <xc.h>

unsigned int adc_read;

void adc_init(void)
{
    TRISAbits.TRISA0 = 1;              //CONFIGURA O CANAL COMO ENTRADA
    ANSEL = 1;
    
    ADCON0bits.CHS = 0;                //SELECIONA O CANAL DE ENTRADA
    ADCON0bits.ADCS = 0;               //OSLICLADOR / 2
    ADCON0bits.GO_nDONE = 1;
    ADCON0bits.ADON = 1;               //PERMITE QUE O ADC SEJA USADO (HABILITA/DESABILITA)
    
    ADCON1bits.ADFM = 1;               //AJUSTA PARA DIREITA
    ADCON1bits.VCFG0 = 0;              //ALIMENTAÇÃO DE REFERENCIA
    ADCON1bits.VCFG1 = 0;              //ALIMENTAÇÃO DE REFERENCIA
}

int adc(void)
{
    ADCON0bits.GO = 1;                 //VAI
    
    while ( ADCON0bits.GO_nDONE )      //CONVERSÃO ENQUANTO FAZ NADA 
    {
    
    }

        adc_read = ADRESH << 8;
        adc_read += ADRESL;
        
        return(adc_read);
}

