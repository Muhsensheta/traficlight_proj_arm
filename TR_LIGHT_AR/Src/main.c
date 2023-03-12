#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_int.h"
#include  "SSD_init.h"



u8 i,j,k;
int	main(void)
{

	MRCC_voidSysClkInit();

	/*	Initialization Part		*/
	

	/*	System Clk init			*/
	

	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);
	/*	1- Enable Per Clk "RCC" Port B		*/
	MRCC_voidEnablePerClk(RCC_APB2,3);
	/*	1- Enable Per Clk "RCC" Port C	*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	H_SSD_void_init();

	M_GPIO_void_SetPinDir(PORTB_ID, PIN8_ID, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(PORTB_ID, PIN9_ID, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(PORTB_ID, PIN10_ID, OUT_2MHZ_PP);
	//M_GPIO_void_SetPinDir(PORTA_ID, PIN15_ID,OUT_2MHZ_PP);
	//M_GPIO_void_SetPinValue(PORTA_ID, PIN15_ID,HIGH);
	// _delay_ms(500);
	// M_GPIO_void_SetPinValue(PORTA_ID, PIN15_ID,LOW);

	/*	Direction for C13 is output Push Pull */
	//M_DIO_void_setPinDir(PORTA_ID, PIN0, OUT_2MHZ_PP);
	

	while(1)
	{

		for(i=60;i>0;i--)
			{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN8_ID,HIGH);
				H_SSD_void_DisplayNumber(i);



			}
		M_GPIO_void_SetPinValue(PORTB_ID, PIN8_ID,LOW);

			for(j=60;j>0;j--)
			{
				M_GPIO_void_SetPinValue(PORTB_ID, PIN9_ID,HIGH);
				H_SSD_void_DisplayNumber(j);



			}
			M_GPIO_void_SetPinValue(PORTB_ID, PIN9_ID,LOW);
			for(k=60;k>0;k--)
			{
				M_GPIO_void_SetPinValue(PORTB_ID, PIN10_ID,HIGH);
				H_SSD_void_DisplayNumber(k);



			}
			M_GPIO_void_SetPinValue(PORTB_ID, PIN10_ID,LOW);


	}
	return 0;
}
