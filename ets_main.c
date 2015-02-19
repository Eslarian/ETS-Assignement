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



int main(int argc, char * argv[])
{
	struct ets ets;
	struct menu_item menu_items[NUM_MENU_ITEMS];
	char input[INPUT_LEN+2];
	int i, selected;
	char * endptr = NULL;


      	if(argc != NUM_ARGS)  
	{
		fprintf(stderr,"Error: invalid command line arguments\n");
		return EXIT_SUCCESS;
	} 

	ets.equipment=init_list();
	ets.members=init_list();
	ets.loans=init_list();
	load_data(&ets,argv[1],argv[2],argv[3]); 
 
	menu_init(menu_items);

	do{
		printf("\n%sEQUIPMENT TRACKING SYSTEM\n--------------------------\n%s",COLOR_TITLE,COLOR_RESET);
 		for(i = 0; i < NUM_MENU_ITEMS;i++)
		{
			printf("%i. %-5s\n",i+1,menu_items[i].name);
		}
		printf("Select option (1-13): ");
		fgets(input,INPUT_LEN+2,stdin);
		
		if(RROL(input) != '\n')
			read_rest_of_line();
		
		selected = strtol(input,&endptr,10);

    		if(endptr[0]!= '\n')
		{
			fprintf(stderr,"%sYou entered an invalid option!%s\n",COLOR_BLUE,COLOR_RESET);
			continue;
		} 
	
		if(selected >= 1 && selected <= 13)
		{
			menu_items[selected-1].func(&ets);
		} 

	}while(1);



        
    /* List of things to do in this function: */
    /* check command line arguments */
    /* initialise data structures */
    /* load data */
    /* if the data is valid and has loaded correctly then
     * display menu and allow interaction */
    /* each menu option should be processed and then you will 
     * return to the main menu unless the user selects the "Quit" option. 
     * Note that you should not be implementing the requirements in this
     * function. You are encouraged to do as little as possible in this 
     * function and delegate the tasks to functions called from here.
     */
    return EXIT_SUCCESS;
 }


