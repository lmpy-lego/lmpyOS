/*
* LmpyOS RedPowerControl (RPC)
* All source code and binary packages are bound by the GNU GPLv3 License, which is in the file named LICENSE.
* Just in case it has not been packaged with this source code, the license can be found at
* http://lpower.org.uk/licenses
* This source code, any derivative works, and any binary packages compiled from either the original work or from derivatives,
* are bound by this license.
* Copyright Logan Power, 2014.
*/

/* For anyone revising this code for the good of all: 
* Remember that this software is primarily intended to run on a simulated machine with very little RAM.  Be efficient.
* Adhere to at least c99.  Thanks.
*/

/* The common header */
#include "main.h"
/* For some reason, cc65 doesn't like headers in headers, so the important ones go here. */
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Defines so values can be changed */
#define SUPPORTS_ENCRYPTION 0
/* Pointers for various files */
FILE *config;
/* A few global variables, because we care. */
char issingleuser;
/* Prototypes for external functions */
extern char prompt();
/* We don't like confusion, so here we make a new data type for returns. */
typedef char funcretern;

char openconfig()
{	
	char returnval = 0;
	if( (config= fopen("config.los", "r")) == NULL)
	{
		printf("[WARNING] No system configuration file is present.  Creating one now.\n");
		returnval = 1;
		fclose(config);
		config = fopen("config.los", "w");
		fclose(config);
	}
		
	config = fopen("config.los", "r+");
	return returnval;
}
char login()
{
	char loginreturn = 0;
	
	if(SUPPORTS_ENCRYPTION == 0)
		puts("Notice: This version of LmpyOS does not support password encryption.\n");
	puts("Login: ");
	gets(puser.username);
	puts("Password: ");
	gets(puser.password);
	if(puser.username == NULL || puser.password == NULL)
		loginreturn = 1;
	return loginreturn;
}
char uman(char isroot)
{
	char uid;
	if(isroot == 1)
	{
		uid = 0;
		strcpy(cuser.username, "root");
		strcpy(cuser.password, "giglaflem");
	}
	else
	{
		login();
		puts("[ERROR] Something went wrong.\n");
		uid = NULL;
	}
	return uid;
}


int main()
{
	char overrideroot = 1;
	printf("	LmpyOS/RPC(65816): Version BETA 1.0.0\n");
	printf("	LmpyOS is starting.  Please wait a moment.\n");
	if(openconfig() >= 1)
		printf("[WARNING] Something went wrong when loading the system configuration file.  It's probably ok.\n");
	else
		printf("[NOTICE] System configuration file(s) loaded.\n");
	/* We have no way of dealing with multiple consoles yet, so we don't need to implement login. */
	printf("[NOTICE] You're most likely  on the primary console.  Logging you in as root.\n");
	/* Log user in as root */
	if (overrideroot)
		cuser.uid = uman(1);
	else
		cuser.uid = uman(0);
	prompt();
}
