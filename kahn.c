 #include <stdio.h>
 #include <stdlib.h>
 #include "fopen.h"
 #include "queue.h"

int main(int argc, char *argv[]) {
	int k;
	if (argc<2) {
		printf("Give an input file..\n");
		exit(1);
	}

	fileImport(argv[1]);
	
	//processing M Matrix....
	printM();
	
	for (k=0;k<rowNum;k++)
		free(M[k]);
	free(M);
}
