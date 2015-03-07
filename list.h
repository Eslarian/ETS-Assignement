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

#include "ets_utility.h"

struct list
{
	struct node * head;
	unsigned count;
}; 


struct node
{
	struct node * next;
	void *  data;
};


struct list * init_list(void);
BOOLEAN add_node(struct list * list, void * data);
BOOLEAN remove_node(struct node *  prevNode,struct node * removeNode,struct list * list);
void free_list(struct list * list);
int search(struct list * list, char * string, int (*func)(struct node * node, char * string));

