#include "Arduino_Pins.h"

/* Arduino_DOP_2 */
const Arduino_Digital_Output_Pin Arduino_DOP_2 =
{
    .Arduino_Pin_Id = 2
};

static void Arduino_DOP_2__Digital_Output_Set_Level( E_IO_Level level )
{
    ADOP__Digital_Pin__Set_Level( &Arduino_DOP_2, level );
}

const Digital_Output Arduino_DOP_2__Digital_Output = 
{
    .Set_Level = Arduino_DOP_2__Digital_Output_Set_Level
};

/* Arduino_DOP_3 */
const Arduino_Digital_Output_Pin Arduino_DOP_3 =
{
    .Arduino_Pin_Id = 3
};

static void Arduino_DOP_3__Digital_Output_Set_Level( E_IO_Level level )
{
    ADOP__Digital_Pin__Set_Level( &Arduino_DOP_3, level );
}

const Digital_Output Arduino_DOP_3__Digital_Output = 
{
    .Set_Level = Arduino_DOP_3__Digital_Output_Set_Level
};

/* Arduino_DOP_4 */
const Arduino_Digital_Output_Pin Arduino_DOP_4 =
{
    .Arduino_Pin_Id = 4
};

static void Arduino_DOP_4__Digital_Output_Set_Level( E_IO_Level level )
{
    ADOP__Digital_Pin__Set_Level( &Arduino_DOP_4, level );
}

const Digital_Output Arduino_DOP_4__Digital_Output = 
{
    .Set_Level = Arduino_DOP_4__Digital_Output_Set_Level
};

/* Arduino_DOP_5 */
const Arduino_Digital_Output_Pin Arduino_DOP_5 =
{
    .Arduino_Pin_Id = 5
};

static void Arduino_DOP_5__Digital_Output_Set_Level( E_IO_Level level )
{
    ADOP__Digital_Pin__Set_Level( &Arduino_DOP_5, level );
}

const Digital_Output Arduino_DOP_5__Digital_Output = 
{
    .Set_Level = Arduino_DOP_5__Digital_Output_Set_Level
};

/* Arduino_DIP_6 */
const Arduino_Digital_Input_Pin Arduino_DIP_6 =
{
    .Arduino_Pin_Id = 6,
    .Pin_Has_Pull_Up = 1
};

static void Arduino_DIP_6__Digital_Input_Get_Level( E_IO_Level* level )
{
    ADIP__Digital_Pin__Get_Level( &Arduino_DIP_6, level );
}

const Digital_Input Arduino_DIP_6__Digital_Input = 
{
    .Get_Level = Arduino_DIP_6__Digital_Input_Get_Level
};

/* Arduino_DIP_7 */
const Arduino_Digital_Input_Pin Arduino_DIP_7 =
{
    .Arduino_Pin_Id = 7,
    .Pin_Has_Pull_Up = 1
};

static void Arduino_DIP_7__Digital_Input_Get_Level( E_IO_Level* level )
{
    ADIP__Digital_Pin__Get_Level( &Arduino_DIP_7, level );
}

const Digital_Input Arduino_DIP_7__Digital_Input = 
{
    .Get_Level = Arduino_DIP_7__Digital_Input_Get_Level
};

/* Arduino_DIP_8 */
const Arduino_Digital_Input_Pin Arduino_DIP_8 =
{
    .Arduino_Pin_Id = 8,
    .Pin_Has_Pull_Up = 1
};

static void Arduino_DIP_8__Digital_Input_Get_Level( E_IO_Level* level )
{
    ADIP__Digital_Pin__Get_Level( &Arduino_DIP_8, level );
}

const Digital_Input Arduino_DIP_8__Digital_Input = 
{
    .Get_Level = Arduino_DIP_8__Digital_Input_Get_Level
};

/* Arduino_DIP_9 */
const Arduino_Digital_Input_Pin Arduino_DIP_9 =
{
    .Arduino_Pin_Id = 9,
    .Pin_Has_Pull_Up = 1
};

static void Arduino_DIP_9__Digital_Input_Get_Level( E_IO_Level* level )
{
    ADIP__Digital_Pin__Get_Level( &Arduino_DIP_9, level );
}

const Digital_Input Arduino_DIP_9__Digital_Input = 
{
    .Get_Level = Arduino_DIP_9__Digital_Input_Get_Level
};