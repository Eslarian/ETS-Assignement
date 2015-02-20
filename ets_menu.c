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
#include "ets_menu.h"

/* initialises the menu */
void menu_init(struct menu_item * menu)
{
  	char * menu_item_names[NUM_MENU_ITEMS] = {"Loan Equipment","Return Equipment", "Query Equipment ID", "Query Member ID", "Display Equipment List", "Display Member List",
						"Display Loan List", "Save and Exit", "Add New Equipment", "Change Equipment Amount", "Add Member", "Delete Member", "Abort"}; 

	BOOLEAN (*func_ptrs[NUM_MENU_ITEMS])(struct ets *) = {loan_equipment,return_equipment,query_equip_ID,query_member_ID,display_equipment,display_member,display_loans,
						save_and_exit,add_equipment,change_equipment,add_member,delete_member,abort_ets};
	
	int i;

	for(i = 0;i < NUM_MENU_ITEMS;i++)
	{
		strcpy(menu[i].name,menu_item_names[i]);
		menu[i].func=func_ptrs[i];
	} 


}
