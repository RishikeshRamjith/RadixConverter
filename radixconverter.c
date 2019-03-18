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
int counter = 0;
//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char* Dec2RadixI(int decValue, int radValue){
	char radix[80];
	counter = 0;
	char lookup[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //Lookup array
	while (decValue > 0){
		int mod = decValue%radValue;
		radix[counter] = lookup[mod]; //Our values are stored in reverse order in array
		decValue = floor(decValue/radValue);
		counter++;
	}
	char* ptr = &(radix[0]);
	return ptr; //returns a pointer
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
	char* ans_ptr;
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
			printf("%s %d %s %d \n","The integer result of the number divided by",radix,"is",num/radix);
			printf("%s %d \n","The remainder is",num%radix);
			ans_ptr = Dec2RadixI(num,radix);
			printf("%s%d %s ","The radix-",radix,"value is");
			for(int i = counter - 1 ; i >= 0; i--){ // Prints the necessary chars from the array, goes in reverse order in order to display in correct order
				printf("%c",*(ans_ptr+i));
			}
			printf("\n");
		}
	}
	printf("%s\n", "EXIT");
}
// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
