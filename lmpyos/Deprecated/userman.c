/* User Manager for LmpyOS */

#include "common.h" /* Include the common header */

short loginprompt(short isroot, char hostname[])
{
	puts("LmpyOS RPC - Version 0. Logging in to  ");
	/* If the hostname field is blank, print "Missing Hostname" */
	if (hostname == NULL)
	{
		puts("Missing Hostname \n");
	}
	else /* Otherwise, print the hostname, then a newline. We don't use concatenation to save memory. */
	{
		puts(hostname);
		puts("\n");
	}

	usernameprompt:
	puts("Username: ");
	gets(puser.username);
	if (puser.username == NULL)
		goto usernameprompt;
	passwordprompt:
	puts("Password: ");
	gets(puser.password);
	if(puser.password == NULL)
		goto passwordprompt;
	
	return 0;
}


