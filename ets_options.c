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

	
	printf("%sLOAN EQUIPMENT\n---------------\n%s",COLOR_TITLE,COLOR_RESET);

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
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN query_member_ID(struct ets * ets)
{
	UNUSED(ets);
	return FALSE;
} 
BOOLEAN display_equipment(struct ets * ets)
{
         int i;
	 struct equipment * equipItems;
	struct node * searchNode = ets->equipment->head;


	 printf("\n%sEquipment List\n--------------%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->equipment->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			equipItems = searchNode->data;
			printf("\n%s\t%s\t%i",equipItems->equipID,equipItems->equipName,equipItems->amount);
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


	 printf("\n%sLoan List\n--------------%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->loans->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			loanItems = searchNode->data;
			printf("\n%s\t%s\t%i",loanItems->memID,loanItems->equipID,loanItems->equipAmt);
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


	 printf("\n%sMember List\n--------------%s",COLOR_TITLE,COLOR_RESET);
	
	for(i = 0; i < ets->members->count;i++)
	 {
	 	 if(searchNode != NULL)
		{
			
			memberItems = searchNode->data;
			printf("\n%s\t%s\t%s",memberItems->ID,memberItems->fName,memberItems->lName);
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
	free_list(ets);
	exit(0);
	
	return FALSE;
} 
