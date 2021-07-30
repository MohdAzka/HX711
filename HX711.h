

#ifndef HX711_h
#define HX711_h

#include <arduino.h>
#define NOP 1

enum sensitivity
{
    SEN_HIGH = 10,
    SEN_MED  = 20,
    SEN_LOW  = 30
};

class HX711
{
private:

    byte DAT;
    byte CLK;
    byte GAIN;
    uint32_t _preVal;

public:

    HX711(/* args */);
    ~HX711();
    void begin(char pinData, char pinClock, char gain);
    bool isReady();
    uint32_t read();
    bool isObj(uint8_t itr, uint8_t threshold, sensitivity sen);
    bool trueWeight( );

};

#endif