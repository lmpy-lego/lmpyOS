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
#include "common.h"

/* Pointers for various files */
FILE *config;

int main()
{
	puts("	LmpyOS/RPC(6502): Version 1\n");
	puts("	LmpyOS is starting.  Please wait a moment.\n");
	
	if(openconfig() >= 1)
		puts("[WARNING] Something went wrong when loading the system configuration file.  It's probably ok.");
	else
		puts("[NOTICE] System configuration file(s) loaded.");
	/* We have no way of dealing with multiple consoles yet, so we don't need to implement login. */
	puts("[NOTICE] You're most likely  on the primary console.  Logging you in as root.");
	
char openconfig()
{	
	char returnval = 0;
	if( (config= fopen("config.los", "r")) == NULL)
	{
		puts("[WARNING] No system configuration file is present.  Creating one now.");
		returnval = 1;
		fclose(config);
		config = fopen("config.los", "w");
		fclose(config);
	}
		
	config = fopen("config.los", "r+");
	return returnval;
}
