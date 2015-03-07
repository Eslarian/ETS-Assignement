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
	char * string;
	/*structs used to dereference the void pointers*/
	struct member * firstMem;
	struct member * secondMem;
	struct loan * firstLoan;
	struct loan * secondLoan;
	struct equipment * firstEquip;
	struct equipment * secondEquip;



	switch(type)
	{
		
		case SEARCHING_MEMBER:	firstMem = aData;
					string = (char*)bData;
					return strcmp(firstMem->ID,string);
										
		case SEARCHING_EQUIPMENT: firstEquip = aData;
					  string = (char*)bData;
					  return strcmp(firstEquip->equipID,string);

		case SEARCHING_LOAN_MEM: firstLoan = aData;
				         string = (char*)bData;
				         return strcmp(firstLoan->memID,string);

		case ADDING_NODE_MEMBER: firstMem = aData;
					 secondMem = bData;
					 return strcmp(firstMem->fName,secondMem->fName);

		case ADDING_NODE_EQUIPMENT: firstEquip = aData;
					    secondEquip = bData;
					    return strcmp(firstEquip->equipName,secondEquip->equipName);

		case ADDING_NODE_LOAN: firstLoan = aData;
				       secondLoan = bData;
				       return strcmp(firstLoan->memID,secondLoan->memID);

		default: fprintf(stderr,"%sInvalid operations type argument%s",COLOR_TITLE,COLOR_ERROR);
			 break;
	} 

	return 0;
} 
