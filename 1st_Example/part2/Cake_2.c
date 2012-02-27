/* ****************************************************************** */
/*  PROJECTNAME: Aritmethic Operations                                */
/*  FILENAME: main.c                                                  */
/*  Created on 27.02.2012 by Mehmet Akif TAŞOVA                       */
/*------------------------------------------------------------------- */
/*  This program licensed unger GPL v3                                */
/*  For more information, please read README.txt file                 */
/*------------------------------------------------------------------- */
/* -----------------------------------------------------------------  */
/* This program calculates sum, difference, multiplititon and         */
/*  division of two different number after read them from a txt file  */
/* ------------------------------------------------------------------ */
/*  References                                                        */
/*    1) http://www.cprogramming.com/tutorial/cfileio.html            */
/*    2) http://www.java2s.com/Code/C/File/fscanffprintfexample.htm   */
/* ****************************************************************** */

/* ****************************************************************** */
/*                            INCLUDES                                */
/* ****************************************************************** */
#include <stdio.h>

/* ****************************************************************** */
/*                           DEFINITIONS                              */
/* ****************************************************************** */

/* ****************************************************************** */
/*                         FUNCTION PROTOTYPES                        */
/* ****************************************************************** */

/* This fuctions checks zero division error before division operation */
int zeroDivisionErrorCheck(double number1, double number2); 

/* ****************************************************************** */
/*                          MAIN FUNCTION                             */
/* ****************************************************************** */
int main(void)
{
    double number1, number2; /* Numbers to use in calculations */

    double sum,                         /* Final valule of addition */
                substraction,           /* Final value of substraction */
                multiplication,         /* Final value of multiplication */
                division;               /* Final value of division */

    int zeroDivErr;      /* Variable for preventing from Zero Division Error */

    FILE * inputFile, * outputFile; /* Variables for input and output files */


    printf("\a\a\a\a"); /*Beep for 4 times. It is Just For Fun =) */

    inputFile = fopen("input.txt", "r");

    /* Read numbers from inputFile */
    fscanf(inputFile, "%lf", &number1);
    fscanf(inputFile, "%lf", &number2);

    fclose(inputFile); /*close input.txt file after its ingredents has been read */

    outputFile = fopen("output.txt", "w");

    /* calculate sum of numbers and write final value in outputFile */
    sum = number1 + number2;  
    fprintf(outputFile, "\n %.3lf + %.3lf = %.3lf\n",number1, number2, sum);

    /* calculate difference between numbers and write final value in outputFile */
    substraction = number1 - number2;    
    fprintf(outputFile, "\n %.3lf - %.3lf = %.3lf\n",number1, number2, substraction);   

    /* calculate multiplication of numbers and write final value in outputFile */
    multiplication = number1 * number2;           
    fprintf(outputFile, "\n %.3lf * %.3lf = %.3lf\n",number1, number2, multiplication);   

    
    /* Begining of the divion operation */

    /*Check for zero division error */
    zeroDivErr = zeroDivisionErrorCheck(number1, number2);

    if (zeroDivErr == 1)
    {
         /*Write Error Message into output file */
        fprintf(outputFile, "\nZero Division Error: %.3lf cannot divide by 0!!!", number1);
        fprintf(outputFile, "\nIt will casue a Zero Division Error and crashes the program\n");
        
        /* Print Error Message to screen */
        printf("\nZero Division Error: %.3lf cannot divide by 0!!!", number1); 
        printf("\nIt will casue a Zero Division Error and crashes the program\n");  
    }
    else
    {
        /* calculate division of number1 to number2 and write final value in outputFile */
        division = number1 / number2;   
        fprintf(outputFile, "\n %.3lf / %.3lf = %.3lf\n",number1, number2, division); 
    };

    /* End of the division operation */
    
    fclose(outputFile); /*close output.txt file after its ingredents has been written */

    printf("\nCalculations Successfuly completed\n");
    printf("Final values of calculations written into \"output.txt\" file\n");

    return 0;
}

/* ****************************************************************** */
/*                         FUNCTION DEFINITIONS                       */
/* ****************************************************************** */


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
        return 0;   /* if there is not a zero divion return 0 */
    };
}

/* ****************************************************************** */
/*                           END OF main.c                            */
/* ****************************************************************** */
