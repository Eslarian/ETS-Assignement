/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Summer 2015 Assignment #2
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1076_1500
 * Program Code     : BP096
 * Start up code provided by David Shaw
 * Based on 2014 code by Paul Miller and Virginia King
 **********************************************************************/
#include "ets_utility.h"

/* clears the input buffer. */
void read_rest_of_line(void)
{
        int ch;
        while(ch = getc(stdin), ch!='\n' && ch != EOF) 
                ;
        clearerr(stdin);
}

/* initialises the ets data structure to safe initial values. */
BOOLEAN ets_init(struct ets * ets)
{
        /* The UNUSED() function is designed to prevent warnings while
         * your code is only partially complete. Delete this function
         * call once you are using your own code */
        UNUSED(ets);
        return FALSE;
}


