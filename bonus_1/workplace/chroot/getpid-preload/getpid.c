/*
	Generate a random pid using /dev/urandom. 
	If the MAGICPID environment is set, use that integer value.
	H D Moore <hdm[at]metasploit.com>
*/

#include <stdio.h>
#include <stdlib.h>

int magicpid = 0;

pid_t getpid(void)
{
	FILE *fd;
	unsigned int seed;
	
	if(magicpid) return magicpid;	

	if(getenv("MAGICPID")) {
		magicpid = atoi(getenv("MAGICPID"));
		return magicpid;
	}
	
	fd = fopen("/dev/urandom", "rb");
	fread(&seed, sizeof(seed), 1, fd);
	fclose(fd);
	
	magicpid = seed % 32768;
	return magicpid;
}
