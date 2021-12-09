#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define READ 0
#define WRITE 1

int main(int argc, char *argv[]) {

	char line[100];
	int fp;
	int fc;
	while(1) {
		fp = open("FromParent", O_RDONLY);
		read(fp,line,sizeof(line));
		close(fp);
		int counter;
		for(counter = 0; counter < strlen(line); counter++) {
			line[counter] = toupper(line[counter]);
		}
		fc = open("FromChild", O_TRUNC | O_WRONLY);
		write(fc, line, sizeof(line));
		close(fc);
	}
	return 0;
}
