
#include "HX711.h"


HX711::HX711(/* args */)
{
}

HX711::~HX711()
{
}

void HX711::begin(char pinData, char pinClock, char gain)
{
    DAT  = pinData;
    CLK = pinClock;
    GAIN  = gain;

    pinMode(DAT,  INPUT);
    pinMode(CLK, OUTPUT);

    digitalWrite(CLK,LOW);
}

bool HX711::isReady()
{
    return digitalRead(DAT) == LOW;
}

uint32_t HX711::read()
{
    while( !isReady() );   

    uint32_t value = 0;
    for ( byte i=0; i<24; i++ )
    {
        digitalWrite(CLK, HIGH);                   
        value=value<<1;
        digitalWrite(CLK, LOW);     

        if( digitalRead(DAT) ) value++;
    }
    
    for(char i = 0; i < GAIN; i++ )
    {
        digitalWrite(CLK, HIGH);
        digitalWrite(CLK, LOW);
    }
            
    value=value^0x800000;
    
    return value;

}

bool HX711::isObj(uint8_t itr, uint8_t threshold, sensitivity sen) //enum for sensitivity 
{
    uint32_t _newVal =  read();

    sen > threshold ? Serial.print("WARNING: sen cant be greater than threshold"):NOP;
    
    if( _newVal > _preVal + sen )
    {
        uint8_t counter = 0;
        for(uint8_t i = 0; i < itr; i++)
        {
            uint32_t val = read();
            if(val > _preVal + threshold || val < _preVal - threshold)
                counter++;
        }
        uint16_t percent = (counter*100)/itr;
        return percent > 75? true:false;
    }

    _preVal = _newVal;

}

bool HX711 :: trueWeight(  )
{
    if(isObj(100, 20, SEN_HIGH))
    {

        
    }

}
