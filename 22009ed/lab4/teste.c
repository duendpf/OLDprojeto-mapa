#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int
main(int argc, char **argv) {
	struct timeval start, end, elap;
	int i = 0;

	gettimeofday(&start, NULL);

	sleep(30);
	for(i; i < 10000000; i++) {
		char *c = (char*) malloc(sizeof(char));
		*c = 128;
		free(c);
	}

	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	printf("\n%f\n", (double)((elap.tv_sec) + (elap.tv_usec/1000000.0) ));

	return(0);
}

