extern "C" {
    #include "Arduino_Pins.h"
    #include "ZRX543.h"
}

void setup()
{
    ADIP__Configure_Pin( &Arduino_DIP_6 );
    ADIP__Configure_Pin( &Arduino_DIP_7 );
    ADIP__Configure_Pin( &Arduino_DIP_8 );
    ADIP__Configure_Pin( &Arduino_DIP_9 );

    ADOP__Configure_Pin( &Arduino_DOP_2 );
    ADOP__Configure_Pin( &Arduino_DOP_3 );
    ADOP__Configure_Pin( &Arduino_DOP_4 );
    ADOP__Configure_Pin( &Arduino_DOP_5 );

    ZRX543__Initialize( &ZRX543 );

    Serial.begin(9600);
    while (!Serial) {
    }
    Serial.println("Serial communication ready");
}

void loop()
{
    static uint32_t last_time = 0;
    uint32_t current_time;
    
    current_time = micros();
    if( current_time - last_time > 10000 )
    {
        last_time = current_time;

        ZRX543__Cyclic( &ZRX543 );
    }
    
    char read_char = '-';
    ZRX543__Keystroke_Peripheral.Get_Key( &read_char );
    if( read_char != 0 )
    {
        Serial.println(read_char);
    }
}