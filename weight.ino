
#include "HX711.h"

const int _data  = 19;
const int _clock = 18;
const int _gain  = 2;

HX711 imran;

void setup()
{
    Serial.begin(9600);
    imran.begin(_data, _clock, _gain);
}

void loop()
{
    uint32_t data = imran.read();
    Serial.println("weight = ");
    Serial.print( data );
    delay(200);
}