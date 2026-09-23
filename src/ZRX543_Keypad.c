#include "ZRX543_Keypad.h"

#include <stdint.h>

/*============================================================================*/
/* Constants */
/*============================================================================*/
static const char KEYS[NB_ROWS][NB_COLUMNS] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' } };


/*============================================================================*/
/* Attributes access */
/*============================================================================*/
#define My_Keypad_Is_Released Me->Var_Attr->Keypad_Is_Released
#define My_Last_Key_Pressed Me->Var_Attr->Last_Key_Pressed
#define My_Current_Key_Pressed Me->Var_Attr->Current_Key_Pressed

/*============================================================================*/
/* Private methods declaration */
/*============================================================================*/
char Read_Key( const ZRX543_Keypad* Me );


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void ZRX543__Initialize( const ZRX543_Keypad* Me )
{
    uint8_t row_index = 0;
    for(row_index = 0; row_index < NB_ROWS; row_index++)
    {
        Me->Row_Pins[row_index]->Set_Level(IO_LEVEL_HIGH);
    }
}
/*---------------------------------------------------------------------------*/
void ZRX543__Cyclic( const ZRX543_Keypad* Me )
{
    char current_key_pressed = Read_Key(Me);
    
    if( true==My_Keypad_Is_Released )
    {
        if( current_key_pressed != 0 )
        {
            if( current_key_pressed == My_Last_Key_Pressed )
            {
                My_Current_Key_Pressed = current_key_pressed;
                My_Keypad_Is_Released = false;
            }
        }
        else
        { /* current_key_pressed == 0 */
            /* keypad remains RELEASED state */
            My_Current_Key_Pressed = current_key_pressed;
        }
    }
    else
    { /* My_Keypad_Is_Released == false */
        if( My_Last_Key_Pressed == 0 && current_key_pressed == 0 )
        {
            My_Keypad_Is_Released = true;
        }
    }
    My_Last_Key_Pressed = current_key_pressed;
}


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void ZRX543__Key__Get_Key( const ZRX543_Keypad* Me, char* key )
{
    *key = My_Current_Key_Pressed;
}


/*============================================================================*/
/* Private methods definition */
/*============================================================================*/
char Read_Key( const ZRX543_Keypad* Me )
{
    uint8_t row_index = 0;
    uint8_t column_index = 0;

    for(row_index = 0; row_index < NB_ROWS; row_index++)
    {
        Me->Row_Pins[row_index]->Set_Level(IO_LEVEL_LOW);
        for(column_index = 0; column_index < NB_COLUMNS; column_index++)
        {
            E_IO_Level column_level = IO_LEVEL_LOW;
            Me->Column_Pins[column_index]->Get_Level(&column_level);
            if( IO_LEVEL_LOW==column_level )
            {
                Me->Row_Pins[row_index]->Set_Level(IO_LEVEL_HIGH);
                return KEYS[row_index][column_index];
            }
        }
        Me->Row_Pins[row_index]->Set_Level(IO_LEVEL_HIGH);
    }
    return 0; 
}