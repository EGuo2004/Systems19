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
#include <sys/stat.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

	mkfifo("FromParent", 0644);
	mkfifo("FromChild" , 0644);
	int fp;
	int fc;
	fp = open("FromParent", O_TRUNC | O_WRONLY);
	fc = open("FromChild", O_RDONLY);
	char line[100];
	printf("check\n");
	while(1) {
		printf("What do you want?\n");
		fgets(line, sizeof(line), stdin);
		write(fp, line, sizeof(line));
		read(fp,line,sizeof(line));
		printf("Here:%s\n", line);
		close(fp);
		close(fc);
	}
	return 0;
}
