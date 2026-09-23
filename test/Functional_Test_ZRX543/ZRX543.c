#include "ZRX543.h"

#include "Arduino_Pins.h"

ZRX543_Keypad_Var ZRX543_Var = {
    .Last_Key_Pressed = 0,
    .Current_Key_Pressed = 0,
    .Keypad_Is_Released = true
};

const ZRX543_Keypad ZRX543 = {
    .Var_Attr = &ZRX543_Var,

    .Column_Pins = {
        &Arduino_DIP_6__Digital_Input,
        &Arduino_DIP_7__Digital_Input,
        &Arduino_DIP_8__Digital_Input,
        &Arduino_DIP_9__Digital_Input },
    .Row_Pins = {
        &Arduino_DOP_2__Digital_Output,
        &Arduino_DOP_3__Digital_Output,
        &Arduino_DOP_4__Digital_Output,
        &Arduino_DOP_5__Digital_Output }

};

static void ZRX543__Get_Key( char* key )
{
    ZRX543__Key__Get_Key(
        &ZRX543,
        key );
}
    
const Keystroke_Peripheral ZRX543__Keystroke_Peripheral =
{
    .Get_Key = ZRX543__Get_Key
};