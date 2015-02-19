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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "ets_type.h"

#ifndef ETS_UTILITY
#define ETS_UTILITY

#define LINE_LEN 60
#define COLOR_TITLE	"\x1b[0;31m"	/* red */
#define COLOR_RESET     "\x1b[0m"
#define COLOR_BLUE     "\x1b[2;34m"    /* blue */
#define INPUT_LEN 2
#define RROL(x) x[strlen(x)-1]  /* Macro used to check last characther of a string */


/* type definition for our boolean type */
typedef enum truefalse
{
	FALSE, TRUE
} BOOLEAN;

void read_rest_of_line(void);

#endif

