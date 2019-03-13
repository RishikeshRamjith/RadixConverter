//********************************************************************
//*                    EEE2046F/EEE2050F C template                  *
//*==================================================================*
//* WRITTEN BY:    	                 		             *
//* DATE CREATED:                                                    *
//* MODIFIED:                                                        *
//*==================================================================*
//* PROGRAMMED IN: Eclipse Luna Service Release 1 (4.4.1)            *
//* TARGET:    PC or STM32F0?                                        *
//*==================================================================*
//* DESCRIPTION:                                                     *
//*                                                                  *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include <stdio.h>
#include <math.h>
//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Rishikesh"
#define YEAR "2019"
//====================================================================
// GLOBAL VARIABLES
//====================================================================

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char* Dec2RadixI(int decValue, int radValue){
	char radix[80];
	int counter = 0;
	while (decValue > 0){
		if(radValue<10){
			decValue = decValue%radValue;
			radix[counter] = decValue;
			counter++;
		}
	}
	char* ptr = &(radix[0]);
	return ptr;


}
//====================================================================
// MAIN FUNCTION
//====================================================================
int main (void)
{
	printf("*****************************\n");
	printf("%s \n",TITLE);
	printf("Written by: %s \n",AUTHOR);
	printf("Date: %s \n",YEAR);
	printf("*****************************\n");
	int num = 1;

	while (num > 0) {
		printf("%s","Enter a decimal number: ");
		scanf("%d", &num);
		if(num < 0){break;}
		else{
			printf("%s %d \n", "The number you have entered is",num);
			int radix;
			printf("%s ", "Enter a radix for the converter between 2 and 16:");
			scanf("%d", &radix);
			printf("%s %d \n", "The radix you have entered is",radix);
			printf("%s %0.2f \n","The log2 of the number is", log2(num));
		}
	}
	printf("%s\n", "EXIT");
}
// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
