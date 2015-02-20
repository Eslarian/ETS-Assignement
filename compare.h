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
	SEARCHING, ADDING_NODE
}OPERATIONS;



int member_cmp(struct node * node, char * string);
int equipment_cmp(struct node * node, char * string);
int loan_cmp(struct node * node, char * string);
