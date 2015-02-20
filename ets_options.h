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

#ifndef ETS_OPTIONS
#define ETS_OPTIONS

/* This an example of one of the menu functions.
 * You will need to write one for each option.
 * Each one can only take one argument, a pointer to struct ets
 * Each returns a BOOLEAN, which indicates a success or not
 */
BOOLEAN loan_equipment(struct ets * ets);
BOOLEAN return_equipment(struct ets * ets);
BOOLEAN query_equip_ID(struct ets * ets);
BOOLEAN query_member_ID(struct ets * ets);
BOOLEAN display_equipment(struct ets * ets);
BOOLEAN display_loans(struct ets * ets);
BOOLEAN display_member(struct ets * ets);
BOOLEAN save_and_exit(struct ets * ets);
BOOLEAN add_equipment(struct ets * ets);
BOOLEAN change_equipment(struct ets * ets);
BOOLEAN add_member(struct ets * ets);
BOOLEAN delete_member(struct ets * ets);
BOOLEAN abort_ets(struct ets * ets);
/* you will need to define many more! */

#endif
