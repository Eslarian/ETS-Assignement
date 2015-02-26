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

#include "compare.h"

int comparison(void * aData, void * bData, OPERATIONS type)
{	
	char * aString;
	char * bString;
	struct member * memDereference = aData;


	switch(type)
	{
		
		case SEARCHING_MEMBER:  aString = memDereference->fName;
					bString = (char *)bData;
					break;

		case SEARCHING_EQUIPMENT: break;


		case SEARCHING_LOAN: break;

		case ADDING_NODE_MEMBER: break;

		case ADDING_NODE_EQUIPMENT: break;

		case ADDING_NODE_LOAN:   break;

		default: fprintf(stderr,"%sInvalid operations type argument%s",COLOR_TITLE,COLOR_ERROR);
			 break;
	} 

	return 0;
} 
