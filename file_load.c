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
#include "file_load.h"



/* loads data from the .dat files into memory. */
BOOLEAN load_data(struct ets * ets, const char * equip_fname, const char * member_fname, const char * loan_fname)
{
	
        FILE * files[NUM_ARGS-1]; /*An array of file streams, used to  iterate through all the fiels to create tokens*/
        int i, count;
	char * token;
        char line[LINE_LEN];	
	char firstToken[NAME_LEN];
	char secondToken[NAME_LEN];
	char thirdToken[NAME_LEN];

	char linecpy[LINE_LEN];
	struct equipment * equip;


        files[0] = fopen(equip_fname,"r");
        files[1] = fopen(member_fname,"r");
        files[2] = fopen(loan_fname,"r");
    
        for(i = 0;i < (NUM_ARGS-1);i++)
        {
       		
    	 while(fgets(line,LINE_LEN,files[i]) != NULL)
	 {
	 	strcpy(linecpy,line);
	 	count = 0;
		token = strtok(line,"|");
		while(token != NULL)
		{ 
		
		 /*Since all files have the same delimeter, files are opened one by one and tokenized the same way, and then the tokens are checked*/
		 switch(count)
		 {
		 	case 0: strcpy(firstToken, token);
				break;
			case 1: strcpy(secondToken, token);
				break;
			case 2: strcpy(thirdToken, token);
				break;
			default: fprintf(stderr,"Invalid line in file: %s",linecpy);
				 return FALSE;
		} 
		count++;
		token = strtok(NULL,"|\n");

		} 
		if(count != 3)
		{
			fprintf(stderr,"Invalid line in file: %s",linecpy);
			 return FALSE;
		}


		switch(check_type(firstToken,thirdToken))
		{
			case EQUIPMENT:	if(check_equipment(firstToken,secondToken,thirdToken,ets->equipment) == FALSE)
					{
					fprintf(stderr,"Invalid line in file: %s",linecpy);
					return FALSE;
					}break;
	
			case MEMBER: if(check_members(firstToken,secondToken,thirdToken,ets->members) == FALSE)
				      {
					fprintf(stderr,"Invalid line in file: %s",linecpy);
					return FALSE;
				      }break;

			case LOAN: if(check_loans(firstToken,secondToken,thirdToken,ets->loans) == FALSE)
				    {
				     	fprintf(stderr,"Invalid line in file: %s",linecpy);
				    	return FALSE;
				    }break;
			
			case INVALID:fprintf(stderr,"Invalid line in file: %s",linecpy);
				     break;
		} 

	} 
      
}
	fclose(files[0]);
	fclose(files[1]);
	fclose(files[2]);
	equip = ets->equipment->head->next->next->data;
	printf("Equip: %s\n",equip->equipName);
	return TRUE;
} 


BOOLEAN check_equipment(char * firstToken, char * secondToken, char * thirdToken, struct list * equipment)
{	
	
	struct equipment * equipmentData; 
	int i;

	if(strlen(firstToken) == ID_LEN)
	{
		if(firstToken[0] == 'E')
		{
			for(i = 1; i < strlen(firstToken);i++)
			{
				if(isdigit((int)firstToken[i]) == 0)
				{
					return FALSE;
				} 
			} 
			
			if(is_valid_string(secondToken) == FALSE)
			{
				return FALSE;
			} 

			for(i = 0; i<strlen(thirdToken);i++)
			{
				if(isdigit((int)thirdToken[i]) == 0)
				{
					return FALSE;
				} 
			} 
			
			
			equipmentData = malloc(sizeof(struct equipment));
			strcpy(equipmentData->equipID,firstToken);
			strcpy(equipmentData->equipName,secondToken);
			equipmentData->amount = strtol(thirdToken,NULL,10);
			add_node(equipment,equipmentData);
			return TRUE;
		} 
	} 
					
					

	return FALSE;
}

BOOLEAN check_members(char * firstToken, char * secondToken, char * thirdToken, struct list * members)
{
	struct member * memberData;
	int i;
	
	if(strlen(firstToken) == ID_LEN)
	{
		if(firstToken[0] == 'M') 
		{
			
			for(i = 1; i < strlen(firstToken);i++)
			{
				if(isdigit((int)firstToken[i]) == 0)
				{
					return FALSE;
				} 
			} 
			if(is_valid_string(secondToken) == FALSE)
			{
				return FALSE;
			} 
			if(is_valid_string(secondToken) == FALSE)
			{
				return FALSE;
			} 
			
			memberData = malloc(sizeof(struct member));
			strcpy(memberData->ID,firstToken);
			strcpy(memberData->lName,secondToken);
			strcpy(memberData->fName,thirdToken);
			add_node(members,memberData);
			return TRUE;
			
		}
	}
	return FALSE;
} 

BOOLEAN check_loans(char * firstToken, char * secondToken, char * thirdToken, struct list * loans)
{
	struct loan * loanData;
	int i;

	if(strlen(firstToken) == ID_LEN)
	{

		if(firstToken[0] == 'M')
		{ 
			for(i = 1; i < strlen(firstToken);i++)
			{
				if(isdigit((int)firstToken[i]) == 0)
					return FALSE;
			}
			if(strlen(secondToken) == ID_LEN)
			{
				if(secondToken[0] == 'E')
				{
					for(i = 1; i < strlen(secondToken);i++)
					{
						if(isdigit((int)secondToken[i]) == 0)
							return FALSE;
					}
					for(i = 0; i<strlen(thirdToken);i++)
					{
						if(isdigit((int)thirdToken[i]) == 0)
							return FALSE;
					}


					loanData = malloc(sizeof(struct loan));
					strcpy(loanData->memID,firstToken);
					strcpy(loanData->equipID,secondToken);
					loanData->equipAmt = strtol(thirdToken,NULL,10);
					add_node(loans,loanData);
					return TRUE;



				} 
			} 
		}
	} 

	return FALSE;
} 

	
BOOLEAN is_valid_string(char * token)
{
	int i;

	if(strlen(token) <= NAME_LEN)
	{
		for(i = 0;i < strlen(token);i++)
		{
			switch(token[i])
			{
				case ' ':
				case '-':
				case '(':
				case ')': 
					   break;
			
				default: if(isalpha((int)token[i]) == 0)
					 return FALSE;
					 break;
			} 
		} 
	}else 
	{
		return FALSE;
	} 

	return TRUE;
} 
					
DATA_TYPE check_type(char * firstToken, char * thirdToken)
{
	
	if(firstToken[0] == 'E' && isdigit((int)thirdToken[0]) != 0)/*Check to see if it is an equipment file*/
	{	
		return EQUIPMENT;
	}
	if(firstToken[0] == 'M' && isalpha((int)thirdToken[0]) != 0)/*Check to see if it is a members file*/
	{
		return MEMBER;
	}
	if(firstToken[0] == 'M' && isdigit((int)thirdToken[0]) != 0)/*Check to see if it is a loans file*/
	{
		return LOAN;
	}


	return INVALID;
} 
