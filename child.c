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


int main(int argc, char *argv[]) {

	char line[100];
	int fp;
	int fc;
	fp = open("FromParent", O_RDONLY);
	fc = open("FromChild", O_WRONLY);
	while(1) {
		read(fp,line,sizeof(line));
		int counter;
		for(counter = 0; counter < strlen(line); counter++) {
			line[counter] = toupper(line[counter]);
		}
		write(fc, line, sizeof(line));
		close(fp);
		close(fc);
	}
	return 0;
}
