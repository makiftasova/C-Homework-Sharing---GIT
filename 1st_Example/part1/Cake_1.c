/* **************************************************************** */
/*  PROJECTNAME: Aritmethic Operations                              */
/*  FILENAME: Cake_1.c                                              */
/*  Created on 27.02.2012 by Mehmet Akif TASOVA                     */
/*----------------------------------------------------------------- */
/*  This program licensed unger GPL v3                              */
/*  For more information, please read README.txt file               */
/*----------------------------------------------------------------- */
/* This program calculates sum, difference, multiplititon           */
/*    and division of two different number                        	*/
/* **************************************************************** */

/* ****************************************************************	*/
/*                            INCLUDES            			        */
/* **************************************************************** */
#include <stdio.h>

/* **************************************************************** */
/*                           DEFINITIONS        		            */
/* **************************************************************** */

/* **************************************************************** */
/*               		FUNCTION PROTOTYPES                         */
/* **************************************************************** */
int zeroDivisionErrorCheck(double number1, double number2); 
/* This fuctions checks zero division error before division operation */

/* **************************************************************** */
/*       				     MAIN FUNCTION       			  	    */
/* **************************************************************** */
int main(void)
{
    double number1, number2; /* Numbers to use in calculations */

    double sum,                         /* Final valule of addition */
                substraction,           /* Final value of substraction */
                multiplication,         /* Final value of multiplication */
                division;               /* Final value of division */

    int zeroDivErr;     /* Variable for preventing from Zero Division Error */

    printf("\n\n\a\a\a\a***Press [CTRL] + [C] keys at same time to quit program***");
	printf("\n----------------------------------------------------------\n");

    do
    {
        /* Read first number from user */
        printf("\nEneter 1st number: ");
        scanf("%lf", &number1);
        printf("\n");

        /* Read second number from user */
        printf("Eneter 2nd number: ");
        scanf("%lf", &number2);
        printf("\n------------------------------\n");

		/* calculate sum of numbers and print final value to screen */        
		sum = number1 + number2;      
        printf("\n %.3lf + %.3lf = %.3lf\n",number1, number2, sum);
        
		/* calculate difference between numbers and print final value to screen */		
		substraction = number1 - number2;                                      
        printf("\n %.3lf - %.3lf = %.3lf\n",number1, number2, substraction); 

        /* calculate multiplication of numbers and print final value to screen */
        multiplication = number1 * number2;
        printf("\n %.3lf * %.3lf = %.3lf\n",number1, number2, multiplication);

        /* Begining of the divion operation */

        /*Check for zero division error */
        zeroDivErr = zeroDivisionErrorCheck(number1, number2);

        if (zeroDivErr == 1)
        {
            printf("\nZero Division Error: %.3lf cannot divide by 0!!! \n",number1);
            printf("It will casue a Zero Division Error and crashes the program\n");
        }
        else
        {
            /* calculate division of number1 to number2 and print final value to screen */
            division = number1 / number2;                                   
            printf("\n %.3lf / %.3lf = %.3lf\n",number1, number2, division);   
        };

        /* End of the division operation */

    }while(1);


    return 0;
}

/* **************************************************************** */
/*                     FUNCTION DEFINITIONS                         */
/* **************************************************************** */


int zeroDivisionErrorCheck(double number1, double number2)
{
    /* Variable "number1" is dividend, Variable "numer2" is divisor */
    /*If there is a zero division error, function return 1 else function returns 0 */

    if (number2 == 0) /* this means zero division */
    {
        return 1;  /* return 1 if there is a zero division */
    }
    else
    {
        return 0;   /* if there is not a zero division return 0 */
    };
}

/* **************************************************************** */
/*                           END OF main.c                          */
/* **************************************************************** */

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
