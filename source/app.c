
/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#include "config.h"
#include "board.h"
#include "timer.h"
#include "communication.h"
#include "string.h"
#include "eep.h"


//#define SIMULATION
/*
*------------------------------------------------------------------------------
* Structures
*------------------------------------------------------------------------------
*/																	

typedef struct _APP
{
	UINT8 data[10];  				//array store for scanned card number
	UINT8 inputRecieved_1;			// flag indicaation for card scanned
	UINT8 inputRecieved_2;			// flag indicaation for card scanned

}APP;																			



/*
*------------------------------------------------------------------------------
* Variables
*------------------------------------------------------------------------------
*/
#pragma idata APP_DATA
APP app = {0};
#pragma idata


/*------------------------------------------------------------------------------
* Private Functions
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* void APP-init(void)
*------------------------------------------------------------------------------
*/

void APP_init(void)
{

}




/*
*------------------------------------------------------------------------------
* void APP-task(void)
*------------------------------------------------------------------------------
*/
void APP_task(void)
{

	if( app.inputRecieved_1 == TRUE)
	{
		app.inputRecieved_1 = FALSE;	

	}

	if( app.inputRecieved_2 == TRUE)
	{
		app.inputRecieved_2 = FALSE;	

	}
	
	

}


UINT8 APP_comCallBack_1( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{
	UINT8 i;
	UINT8 length = 0;

	//copy data rxbuffer to app buffer
	for(i = 0 ; i < 6 ; i++)
	{
		app.data[i] = rxPacket[i];
	}

	app.data[i] = '\0';
	app.inputRecieved_1 = TRUE;

	return length;


}
UINT8 APP_comCallBack_2( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{
	UINT8 i;
	UINT8 length = 0;

	//copy data rxbuffer to app buffer
	for(i = 0 ; i < 6 ; i++)
	{
		app.data[i] = rxPacket[i];
	}

	app.data[i] = '\0';
	app.inputRecieved_2 = TRUE;

	return length;


}

	
		