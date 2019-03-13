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
	char lookup[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while (decValue > 0){

		int mod = decValue%radValue;
		//printf("%d",mod);
		//printf("%c", lookup[mod]);
		radix[counter] = lookup[mod];
		decValue = floor(decValue/radValue);
		counter++;
		// if(radValue<10){
		// 	radix[counter] = decValue%radValue;
		// 	decValue = floor(decValue/radValue);
		// 	counter++;
		// }
		// else{
		//
		// 	int mod = decValue%radValue;
		// 	if(mod < 10){
		// 		radix[counter] = decValue%radValue;
		// 		decValue = floor(decValue/radValue);
		// 		counter++;
		// 	}
		// 	else{
		// 		if(mod == 10){
		// 			radix[counter] = 'A';
		// 		}
		// 		if(mod == 11){
		// 			radix[counter] = 'B';
		// 		}
		// 		if(mod == 12){
		// 			radix[counter] = 'C';
		// 		}
		// 		if(mod == 13){
		// 			radix[counter] = 'D';
		// 		}
		// 		if(mod == 14){
		// 			radix[counter] = 'E';
		// 		}
		// 		if(mod == 15){
		// 			radix[counter] = 'F';
		// 		}
		// 		//radix[counter] = decValue%radValue;
		// 		decValue = floor(decValue/radValue);
		// 		counter++;
		// 	}
		// }
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
			ans_ptr = Dec2RadixI(num,radix);
			//int i = 0;
			//int max = 0;
			//printf("%s  %s  %s  %s  \n","Iteration", "Countervalue","memory address","i-value");
			printf("%s%d %s ","The radix-",radix,"value is");
			for(int i = counter - 1 ; i >= 0; i--){
				printf("%c",*(ans_ptr+i));
				// DEBUGGING STATEMENTS --- printf("%d  %d  %d  %d \n",max,counter, *(ans_ptr+i), i);
				//max++;
			}
			printf("\n");
			//printf("%d \n",max);

		}
	}
	printf("%s\n", "EXIT");
}
// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
