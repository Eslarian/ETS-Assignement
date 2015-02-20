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

typedef enum datatype
{
	EQUIPMENT, MEMBER, LOAN ,INVALID

} DATA_TYPE;

BOOLEAN load_data(struct ets * ets,
	const char * equip_fname,
	const char * member_fname,
	const char * loan_fname);
BOOLEAN check_equipment(char * firstToken, char * secondToken, char * thirdToken, struct list * equipment);
BOOLEAN check_members(char * firstToken, char * secondToken, char * thirdToken, struct list * members);
BOOLEAN check_loans(char * firstToken, char * secondToken, char * thirdToken, struct list * loans);
BOOLEAN is_valid_string(char * token);
DATA_TYPE check_type(char * firstToken, char * thirdToken);
