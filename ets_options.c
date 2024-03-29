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
	printf("Please enter a member ID: \n");
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
	char  input[ID_LEN+2];
	int i;
	struct node * searchNode;
	struct equipment * equipment;
	BOOLEAN valid = FALSE;

	printf("\n%sQuery Equipment\n%s",COLOR_TITLE,COLOR_RESET);

	do{

	printf("Please enter an Equipment ID to search for:\n");
	fgets(input,ID_LEN+2,stdin);

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
	searchNode = ets->equipment->head;
	for(i = 0; i < ets->equipment->count;i++)
	{
	
		if(comparison(searchNode->data,input,SEARCHING_EQUIPMENT) == 0)
		{
			valid = TRUE;
			equipment = searchNode->data;
			printf("%s%s\t%s\t%i\n%s",COLOR_RESULTS,equipment->equipID,equipment->equipName,equipment->amount,COLOR_RESET);
			break;
		} 
		if((i == ets->equipment->count-1) && (comparison(searchNode->data,input,SEARCHING_EQUIPMENT) != 0)) 
		{
			fprintf(stderr,"%sError: ID not found%s\n",COLOR_ERROR,COLOR_RESET); 
			return FALSE;
		} 
		searchNode = searchNode->next;
	} 

	
	}while(!valid);	
	
	return TRUE;
} 
BOOLEAN query_member_ID(struct ets * ets)
{
	char  input[ID_LEN+2];
	int i;
	struct node * searchnode;
	struct member * member;
	struct loan * loan;
	struct equipment * equipment;
	BOOLEAN valid = FALSE;

	printf("\n%sQuery Members\n%s",COLOR_TITLE,COLOR_RESET);

	do{

	printf("Please enter a member ID to search for:\n");
	fgets(input,ID_LEN+2,stdin);

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
	for(i = 0; i < ets->members->count+1;i++)
	{
		
		if(searchnode != NULL)
		{ 
			if(comparison(searchnode->data,input,SEARCHING_MEMBER) == 0)
			{
				member = searchnode->data;
				break;
			} 
		} 
		else 	
		{
			fprintf(stderr,"%sError: ID not found%s\n",COLOR_ERROR,COLOR_RESET); 
			return FALSE;
		}
		searchnode = searchnode->next;

	} 

	/*Searching through loan list to print relevant member's loan data*/
	searchnode = ets->loans->head;
	for(i = 0; i < ets->loans->count+1;i++)
	{
			
		if(searchnode != NULL)
		{
			
			if(comparison(searchnode->data,member->ID,SEARCHING_LOAN_MEM) == 0)
			{
				valid = TRUE;
				loan = searchnode->data;
				printf("%s%s\t%s\t%s\t%i\n%s",COLOR_RESULTS,loan->memID,member->fName,member->lName,loan->equipAmt,COLOR_RESET);
				break;
			} 
		} 
		else
		{
			printf("%s%s\t%s\t%s%s\n",COLOR_RESULTS,member->ID,member->fName,member->lName,COLOR_RESET);
			printf("This members doesn't have any items on loan");	
			return FALSE;
		}
		searchnode = searchnode->next;

	} 

	/*Searching through equipment list to print relevant equipment data of the loan*/
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
	/*ID has to have extra spaces for newline otherwise a string that is too long could be cut off and still be read 'correcty'*/
	struct equipment * equip = malloc(sizeof(struct equipment));
	int i;
	struct node * searchNode;
	/*Used to contain up to 3 digit INT for conversion*/
	char amount[4];
	char * endptr;
	BOOLEAN valid;

	do{

		valid = TRUE;
		printf("Please enter the new equipment ID\n");
		fgets(equip->equipID,ID_LEN+2,stdin); 

		if(RROL(equip->equipID) != '\n')
			read_rest_of_line();

		if(!check_equip_ID(equip->equipID)) 
		{
			fprintf(stderr,"%sError: Invalid ID, please enter correct format%s\n",COLOR_ERROR,COLOR_RESET); 
 			valid = FALSE;
		}
		
		searchNode = ets->equipment->head;
		for(i = 0; i < ets->equipment->count;i++)
		{
	
			if(comparison(searchNode->data,equip->equipID,SEARCHING_EQUIPMENT) == 0)
			{
				valid = FALSE;
				fprintf(stderr,"%sError: ID alrady in use, please enter a different one%s\n",COLOR_ERROR,COLOR_RESET); 
			}		
			searchNode = searchNode->next;
		} 
			
	}while(!valid);

	do{
		
		valid = TRUE;
		printf("Please enter new equipment name\n");
		fgets(equip->equipName,NAME_LEN+1,stdin);

		if(RROL(equip->equipName) != '\n')
			read_rest_of_line();

		if(equip->equipName[0] == '\n')
		{
			fprintf(stderr,"%sError: No name entered, please enter a new equipment name%s\n",COLOR_ERROR,COLOR_RESET);
			valid = FALSE;
		} 

	}while(!valid);

	do{
		
		valid = TRUE;
		endptr = NULL;
		printf("Please enter new equipment amount\n");
		fgets(amount,4,stdin);
		
		if(RROL(amount) != '\n')
			read_rest_of_line();

		equip->amount = strtol(amount,&endptr,10);
		
		if(endptr[0] != '\n')
		{
			valid = FALSE;
			fprintf(stderr,"%sError: invalid amount entered, integers only up to three digits%s\n",COLOR_ERROR,COLOR_RESET);
		} 

	}while(!valid);	
	
	add_node(ets->equipment,equip);


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
