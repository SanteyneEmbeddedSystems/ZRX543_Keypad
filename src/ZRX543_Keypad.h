#ifndef ZRX543_KEYPAD_H
#define ZRX543_KEYPAD_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdbool.h>

/* Realized interfaces */
#include "Keystroke_Peripheral.h"

/* Required interfaces */
#include "Digital_Output.h"
#include "Digital_Input.h"


/*============================================================================*/
/* Types, interfaces and macros */
/*============================================================================*/
#define NB_ROWS 4
#define NB_COLUMNS 4


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    char Last_Key_Pressed;
    char Current_Key_Pressed;
    bool Keypad_Is_Released; 
} ZRX543_Keypad_Var;

typedef struct {
    
    /* Variable attributes */
    ZRX543_Keypad_Var* Var_Attr;
    
    /* Required interfaces */
    /* Pin_4, Pin_3, Pin_2, Pin_1 */
    const Digital_Input* Column_Pins[NB_COLUMNS];
    /* Pin_8, Pin_7, Pin_6, Pin_5 */
    const Digital_Output* Row_Pins[NB_ROWS]; 
    
} ZRX543_Keypad;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void ZRX543__Initialize( const ZRX543_Keypad* Me );
void ZRX543__Cyclic( const ZRX543_Keypad* Me );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void ZRX543__Key__Get_Key( const ZRX543_Keypad* Me, char* key );

#endif