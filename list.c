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


struct list * init_list(void)
{
	struct list * list;
	list = malloc(sizeof(struct list));
	list->head = NULL;
	list->count = 0;
	return list;
} 


BOOLEAN add_node(struct list * list,void * data)
{
	struct node * newNode = malloc(sizeof(struct node));
	struct node * searchNode;
	int i;


	newNode->next = NULL;
	newNode->data = data;

	if(list->head == NULL)
	{

		list->head = newNode;
		list->count++;
		return TRUE;

	}else 
	{
	     searchNode = list->head;

             for(i = 1;i < list->count;i++)
	     {
	     	searchNode = searchNode->next; 
	     }

	     searchNode->next = newNode;
	     list->count++;
	     return TRUE;
	} 
	
	return FALSE;

} 

BOOLEAN remove_node(struct node *  prevNode,struct node * removeNode,struct list * list)
{
	
	prevNode->next = removeNode->next;
	free(removeNode->data);
	free(removeNode);
	list->count--;

	return TRUE;

}

void ets_free(struct list * list)
{
	struct node * curr = NULL;
	struct node * next = NULL;

	curr = list->head;
	
	while(!curr)
	{
		next = curr->next;
		free(curr->next);
		free(curr->data);
		free(curr);
		curr = next;
	} 
} 

int search(struct list * list, char * string, int (*func)(struct node * node, char * string))
{
	struct node * searchnode;
	int result;	
	searchnode = list->head;

	while(!searchnode || result!= 1)
	{

		searchnode=searchnode->next;
		result=func(searchnode,string);
	} 
	
	return result;
}

