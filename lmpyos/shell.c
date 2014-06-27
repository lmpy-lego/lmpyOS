/* shell.c: The module for BlueShell, LmpyOS's shell. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char blueshell_query(char input[])
{
	if (input == "help")
        help();
    if (input == "who am i")
        whoami();
}
char prompt()
{
	char promptchar = "|"; /* Initialize the prompt character as a bar (|) */
	char commandstring[];
	char exitvalue = 0;	/* Initialize exitvalue as 0 so the prompt runs at least once. */
	char linekill = "@";	/* Initialize the line kill character as @. */
	char scroll;
	blueshellprompt:
	while (!exitvalue)
	{
		putchar(promptchar);	/* Print the prompt character */
		putchar(" ");		/* Print a space after the prompt character for readability */
		gets(commandstring);	/* Gets the entire string typed at the terminal, arguments and all. */
		if(strchr(commandstring, linekill) != NULL || commandstring == NULL)	/* If line contains line kill or is blank, start over. */
			goto blueshellprompt;
		if (commandstring == "stty")
		{
			puts("LineKill= ");
			getchar(linekill);
			if(!ispunct(linekill))
				{
					linekill = "@";
					puts("Invalid.  Reverting.");
					break;
				} 
		}
		else
		{
			blueshell_query(commandstring);
		}

}
