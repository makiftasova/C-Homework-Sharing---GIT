/* ************************************************************************* */
/*  FILENAME: GCD_LCM.c                                      				 */
/*  Created on 29.02.2012 by Mehmet Akif TASOVA                				 */
/*  ------------------------------------------------------------------------ */
/*  This program calcualtes G.C.D. and L.C.M. values of given two integer    */
/*                                                                  		 */
/*  -----------------------------------------------------------------------  */
/*  References                                                               */
/*                    														 */
/*                            				                                 */
/* ************************************************************************* */

/* ************************************************************************* */
/*               				 INCLUDES    		                         */
/* ************************************************************************* */
#include <stdio.h>

/* ************************************************************************* */
/*                     		 	 DEFINITIONS  			   		             */
/* ************************************************************************* */

/* ************************************************************************* */
/*                         FUNCTION PROTOTYPES	                             */
/* ************************************************************************* */
	 /* function to swap integer numbers */
void swap(int *number1, int *number2);
	/* function to calculate Greatest Common Divisor */
int gcd(int number1, int number2); 
	 /* function to calculate Largest Common Multipler*/
int lcm(int number1, int number2);


int main(void)
{
    int number1 = 0, number2 = 0; /* Variables to store numbers */
	int greatestCommonDivisor = 0, /* variable to ssign G.C.D. value */
		LargestCommonMultipler = 0; /* variable to ssign L.C.M. value */
		
	printf("\nThis Program will calculate G.C.D. and L.C.M. of given two numbers\n\n");
	
	/* Get numbers from user*/	
	/* First number */
	printf("Enter the first number: ");
	scanf("%d",&number1);
	/* Second number */
	printf("Enter the second number: ");
	scanf("%d",&number2);
	
	/* Calcualtion part of G.C.D. and L.C.M. */
	
	/* if number1 >= number2 there is no problem	*/
	/* if not, number1 and number2 must bu swapped 	*/
	/*     for calcualte G.C.D. and L.C.M. 			*/
	if (number1 >= number2) 
	{
		greatestCommonDivisor = gcd(number1, number2);
		LargestCommonMultipler = lcm(number1, number2);
	}
	else
	{
		swap(&number1, &number2);
		greatestCommonDivisor = gcd(number1, number2);
		LargestCommonMultipler = lcm(number1, number2);
	};
	/* End of Calculation part */
	
	/* Print Results to screen */
	printf("\nG.C.D.(%d, %d) = %d\n",number1, number2, greatestCommonDivisor);
	printf("\nL.C.M.(%d, %d) = %d\n",number1, number2, LargestCommonMultipler);
	
    return 0;
}

/* ************************************************************************* */
/*                          FUNCTION DEFINITIONS                   			 */
/* ************************************************************************* */
void swap(int *number1, int *number2)
{
	int temporaryStack;
	temporaryStack = *number1;
	*number1 = *number2;
	*number2 = temporaryStack;
}

int gcd(int number1, int number2)
{
	int remainder = 0, /* variable for storing reainder of "number1 % number2" */
		returnValue = 0; /* variable for storing return value of function */
	
	/* if remainder equals to 0, then G.C.D. equals to number2 */
	/* if remainder not equals to 0, then do calculations below */
	/*		until remainder becomes 0						    */			
	
	
    while(1)
	{
		remainder = number1 % number2;
		if (remainder != 0)
		{
			number1 = number2;
			number2 = remainder;
			continue;
	    }
	    
		if(remainder == 0)
		{
			returnValue = number2;
			break;
		};
		break;
    };
	
	return returnValue;
}

int lcm(int number1, int number2)
{
	int greatestCommonDivisor = 0, /* this will be use in calculating L.C.M. */
		returnValue = 0; /* variable for storing return value of function */
		
	
	/* we know "lcm = number1 * number2 / gcd" equation from our math lessons */
	/*		then we can use this equation to calculate L.C.M. of the numbers  */
	greatestCommonDivisor = gcd(number1, number2);
	returnValue = (number1 * number2) / greatestCommonDivisor;
	
	return returnValue;
}



/* ************************************************************************* */
/*                         END OF GCD_LCM.c                      	 */
/* ************************************************************************* */
