/* LmpyOS RPC Common Header */

/* The basic headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define some constants and stuff like that. */
#define TRUE  1
#define FALSE 0

/* Struct about the current user */

struct
{
	char username[];
	char password[];
	char loginclass[];
	char description[];
} cuser;

/* Struct for the proposed user.  For user matching use only. */

struct
{
	char username[];
	char password[];
} puser;
