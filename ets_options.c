
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
#include "ets_options.h"
#define AMOUNT_LEN 2

/* an example of a menu function you will need to fully define */
BOOLEAN loan_equipment(struct ets * ets)
{
	char memID[ID_LEN+2];
	char equipID[ID_LEN+2];
	char qtyString[AMOUNT_LEN+2];
	void * aData = ets->members->head->data;
	/*int quantity;
	struct member * member;*/  
	char * string = "String";	
	void * bData = string;

	
	printf("%sLOAN EQUIPMENT\n%s",COLOR_TITLE,COLOR_RESET);

	do{

	comparison(aData,bData,SEARCHING_MEMBER);
	printf("Please enter a memmber ID: \n");
	fgets(memID,ID_LEN+2,stdin);
	if(RROL(memID) != '\n')
	{
		read_rest_of_line();
	} 
		
	/*printf mem info here*/
	printf("Please enter an equipment ID: \n");
	fgets(equipID,ID_LEN+2,stdin);
	if(RROL(equipID) != '\n')
	{
		read_rest_of_line();
	} 
	/*printf equip info here*/
	printf("Please enter an amount: \n");
	fgets(qtyString,AMOUNT_LEN+2,stdin);
	if(RROL(qtyString) != '\n')
	{
		read_rest_of_line();
	}

	}while(1);
	
	
	return FALSE;
} 
BOOLEAN return_equipment(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN query_equip_ID(struct ets * ets)
{
	char  input[ID_LEN+1];
	int i;
	struct node * searchnode;
	struct equipment * equipment;
	BOOLEAN valid = FALSE;

	printf("\n%sQuery Equipment\n%s",COLOR_TITLE,COLOR_RESET);

	do{

	printf("Please enter an Equipment ID to search for:\n");
	fgets(input,ID_LEN+1,stdin);

	if(RROL(input) != '\n')
	read_rest_of_line();

	/*Check if the entered ID is in correct format*/
	if(!check_equip_ID(input)) 
	{
		fprintf(stderr,"%sError: Invalid ID, please enter correct format%s\n",COLOR_ERROR,COLOR_RESET); 
		valid = FALSE;
		continue;
	} 

	/*Search through the equipment list to check if the equipment exists*/
	searchnode = ets->equipment->head;
	for(i = 0; i < ets->equipment->count;i++)
	{
		searchnode = searchnode->next;
		if(comparison(searchnode->data,input,SEARCHING_EQUIPMENT) == 0)
		{
			valid = TRUE;
			equipment = searchnode->data;
			printf("%s%s\t%s\t%i\n%s",COLOR_RESULTS,equipment->equipID,equipment->equipName,equipment->amount,COLOR_RESET);
			break;
		} 
		if((i == ets->equipment->count) && (comparison(searchnode,input,SEARCHING_EQUIPMENT) != 0)) 
		{
			fprintf(stderr,"%sError: ID not found%s\n",COLOR_ERROR,COLOR_RESET); 
			return FALSE;
		} 
	} 

	
	}while(!valid);	
	
	return TRUE;
} 
BOOLEAN query_member_ID(struct ets * ets)
{
	char  input[ID_LEN+1];
	int i;
	struct node * searchnode;
	struct member * member;
	struct loan * loan;
	struct equipment * equipment;
	BOOLEAN valid = FALSE;

	printf("\n%sQuery Members\n%s",COLOR_TITLE,COLOR_RESET);

	do{

	printf("Please enter a member ID to search for:\n");
	fgets(input,ID_LEN+1,stdin);

	if(RROL(input) != '\n')
	read_rest_of_line();

	/*Check if the entered ID is in correct format*/
	if(!check_member_ID(input)) 
	{
		fprintf(stderr,"%sError: Invalid ID, please enter correct format%s\n",COLOR_ERROR,COLOR_RESET); 
		valid = FALSE;
		continue;
	} 

	/*Searching through member list to check if member exist*/
	searchnode = ets->members->head;
	for(i = 0; i < ets->members->count;i++)
	{
		searchnode = searchnode->next;
		if(searchnode != NULL)
		{ 
		if(comparison(searchnode->data,input,SEARCHING_MEMBER) == 0)
		{
			member = searchnode->data;
			break;
		} 
		if((i == ets->members->count) && (comparison(searchnode,input,SEARCHING_MEMBER) != 0)) 
		{
			fprintf(stderr,"%sError: ID not found%s\n",COLOR_ERROR,COLOR_RESET); 
			return FALSE;
		} 
		} 
		else if(searchnode = NULL)
		{
			fprintf(stderr,"%sError: ID not found%s\n",COLOR_ERROR,COLOR_RESET); 
			return FALSE;
		} 

	} 

	/*Searching through loan list to print relevant member's loan data*/
	searchnode = ets->loans->head;
	for(i = 0; i < ets->loans->count;i++)
	{
			
		if(searchnode->next != NULL)
		{
			searchnode = searchnode->next;


			if(comparison(searchnode->data,member->ID,SEARCHING_LOAN_MEM) == 0)
			{
				valid = TRUE;
				loan = searchnode->data;
				printf("%s%s\t%s\t%s\t%i\n%s",COLOR_RESULTS,loan->memID,member->fName,member->lName,loan->equipAmt,COLOR_RESET);
				break;
			} 
			if((i == ets->loans->count) && (comparison(searchnode,input,SEARCHING_LOAN_MEM) != 0))  
			{
				printf("This members doesn't have any items on loan");	
				break;
			} 
		} 
		else
		{
			printf("This members doesn't have any items on loan");	
			break;
		} 
	} 

	/*Searching through equipment list to print relevant equipment data of the loan*/
	if(searchnode != NULL)
	{ 
		searchnode = ets->equipment->head;
		for(i = 0; i < ets->equipment->count;i++)
		{
			searchnode = searchnode->next;
			if(comparison(searchnode->data,loan->equipID,SEARCHING_EQUIPMENT) == 0)
			{
						
				equipment = searchnode->data;
				printf("%s\t%s\t%s\t%i\n%s",COLOR_RESULTS,equipment->equipID,equipment->equipName,loan->equipAmt,COLOR_RESET);
				break;
			} 
		} 
	} 

	}while(!valid);	
	
	return TRUE;



} 
BOOLEAN display_equipment(struct ets * ets)
{
         int i;
	 struct equipment * equipItems;
	struct node * searchNode = ets->equipment->head;


	 printf("\n%sEquipment List\n%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->equipment->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			equipItems = searchNode->data;
			printf("%s\n%s\t%s\t%i%s",COLOR_RESULTS,equipItems->equipID,equipItems->equipName,equipItems->amount,COLOR_RESET);
			searchNode = searchNode->next;
		} 
	} 

	return FALSE;
}
BOOLEAN display_loans(struct ets * ets) 
{
	int i;
	struct loan * loanItems;
	struct node * searchNode = ets->loans->head;


	 printf("\n%sLoan List\n%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->loans->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			loanItems = searchNode->data;
			printf("%s\n%s\t%s\t%i%s",COLOR_RESULTS,loanItems->memID,loanItems->equipID,loanItems->equipAmt,COLOR_RESET);
			searchNode = searchNode->next;
		} 
	} 

	return FALSE;
} 
BOOLEAN display_member(struct ets * ets)
{

	int i;
	struct member * memberItems;
	struct node * searchNode = ets->members->head;


	 printf("\n%sMember List\n%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->members->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			memberItems = searchNode->data;
			printf("%s\n%s\t%s\t%s%s",COLOR_RESULTS,memberItems->ID,memberItems->fName,memberItems->lName,COLOR_RESET);
			searchNode = searchNode->next;
		} 
	} 


	return FALSE;
} 
BOOLEAN save_and_exit(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN add_equipment(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN change_equipment(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN add_member(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN delete_member(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN abort_ets(struct ets * ets)
{
	free_list(ets->equipment);
	free_list(ets->members);
	free_list(ets->loans);
	exit(0);
	
	return FALSE;
} 
