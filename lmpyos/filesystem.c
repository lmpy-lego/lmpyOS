/* filesystem.c: LmpyOS filesystem module
*  This module contains functions to modify the virtual LmpyOS filesystem.
*  Unlike most other filesystems, this system is based mostly on human-readable files.
*  It is not meant to run a standalone system.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *rootfs;

char mountfs(char isrootfs, char style)
{
	if(isrootfs)
	{
		rootfs = fopen("/.losfs", "r");
		if (fs == NULL)
		{
			puts("losfs: mountfs: [FYI] Cannot access root filesystem. It might not exist yet.\n");
		}
		fclose(rootfs);
		rootfs = fopen("/.losfs", "r+");
		if (fs == NULL)
		{
			puts("[SEVERE ERROR] Cannot access or create root filesystem.  This is bad news.\n");
			return 1;
		}
		else
		{
			puts("losfs: mountfs: [FYI] Root filesystem loaded (or created).\n");
			return 0;
		}
	}
}

char chkfs(char isrootfs)
{
	if(isrootfs)
	{
		rewind();
		if(getc(rootfs)== EOF || getc == NULL)
		{
			puts("[WARNING] Root filesystem record is empty.  It will have to be reinitialized.\n");
			initfs(1);
			return 1;
		}
	}
}

char initfs(char isrootfs)
{
	if(isrootfs)
	{
		rewind();
		puts("losfs: initfs: [FYI] Reinitializing Root Filesystem\n");
		fputs("#l#\n/:\n");
		fputs("config.los\n");
	}
}
