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

#include "list.h"

typedef enum operations
{
	SEARCHING_MEMBER, SEARCHING_EQUIPMENT, SEARCHING_LOAN_EQUIP, SEARCHING_LOAN_MEM, 
	ADDING_NODE_MEMBER, ADDING_NODE_EQUIPMENT, ADDING_NODE_LOAN
}OPERATIONS;



int comparison(void * aData, void * bData, OPERATIONS type);
