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
#ifndef ETS_TYPE
#define ETS_TYPE

#define NUM_ARGS 4
#define ID_LEN 5 
#define NAME_LEN 31 

/* this will remove warnings on unused variables in the skeleton code */
#define UNUSED(var) (void)var



/* This is the ets structure you will pass to many functions */


/*Sturct ets holds pointers to the three different list of data*/
struct ets 
{
	struct list * equipment;
	struct list * members;
	struct list * loans;

};

/*Data struct for loan information*/
struct loan
{
	char memID[ID_LEN+2];
	char equipID[ID_LEN+1];
	int equipAmt;
}; 

/*Data struct for equipment information*/
struct equipment
{
	char equipID[ID_LEN+2];
	char equipName[NAME_LEN+1];
	int amount;
}; 

/*Data struct for member information*/
struct member
{
	char ID[ID_LEN+2];
	char fName[NAME_LEN+1];
	char lName[NAME_LEN+1];
}; 

#endif
