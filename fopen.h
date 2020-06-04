 #include <stdio.h>
 #include <stdlib.h>


 int rowNum;
 int columnNum;
 int edgesNum;
 int** M;


void fileImport(char * fileName){
    // αρχικοποίηση μεταβλητών
    int u,v,k;

    //αρχικοποίηση buffer
    char line[100];

    // file input
    FILE* in = fopen (fileName, "rt");
	if (in==NULL) {
		printf("Unable to open file %s\n", fileName);
		exit(1);
	}
	fgets(line, 100, in);
    // αποφυγή γραμμών με σχόλια
    while (line[0] == '%')
		fgets(line, 100, in);
    // πρώτη σημαντική γραμμή (αριθμός γραμμών, στηλών, ακμών)
    sscanf (line, "%d %d %d \n",&rowNum,&columnNum,&edgesNum);
	
	//Dynamic memory allocation for M: rowNum x columnNumquit
	M = (int**) calloc(rowNum,sizeof(int*));
	for (k=0;k<rowNum;k++)
		M[k]=(int*)calloc(columnNum,sizeof(int));
	
	//reading the rest of the file (edges)
    while(fgets(line, 100, in) != NULL) {
		sscanf (line, "%d %d",&u,&v); 
		M[u-1][v-1] = 1;
	}
	fclose(in);
} 

void printM() {
	int k,n;
	printf("   ");
	for (k=1;k<=rowNum;k++)
		printf("%3d", k);
	
	printf("\n--------------------------------------\n");
	for (k=0;k<rowNum;k++) {
		printf("%2d|", k+1);
		for (n=0;n<columnNum;n++)
			printf("%3d", M[k][n]);
		printf("\n");
	}
}
/*
void edges(){
	int i,j;
//	int zeroCount=0;
	for (int i = 0 ; i < rowNum; i++) {
//		zeroCount=0;
    for (int j = 0; j < columnNum; j++) {
		if(M[j][i]==1){
//			zeroCount++;
			origin=j;
			destin=i;
		}
    }
	int	z=i+1;
//	printf("column number %d has %d zeros\n",z,zeroCount);
//		if(zeroCount==columnNum){
//			enqueue(z);
//		}
//}
}}



//		for (b=0;b<=rowNum;b++){
//			if(M[b][a]==0){
//				zeroscount++;
//			}
//		}

	for (a=0;a<=columnNum;a++){
		while(M[][a]==0)
			{
			zeroscount++;
		}
	if(zeroscount == columnNum){
		printf("Column %d is full of zeros",a);
	}	}
}}
 */