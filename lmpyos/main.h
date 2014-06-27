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
	char username[16];
	char password[16];
	char loginclass[16];
	char description[128];
	char uid;
} cuser;

/* Struct for the proposed user.  For user matching use only. */

struct
{
	char username[16];
	char password[16];
} puser;
