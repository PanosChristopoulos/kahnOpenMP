#include "fopen.h"

void create_graph()
{
        int max_edges,origin,destin;
        fileImport("Tina_AskCal.mtx");
        printM();
        max_edges = rowNum;
        int j,k;
//	int zeroCount=0;
	for (int j = 0 ; j < rowNum; j++) {
//		zeroCount=0;
    for (int k = 0; k < columnNum; k++) {
		if(M[j][k]==1){
//			zeroCount++;
			adj[j+1][k+1]=1;
            printf("\nAkmh %d %d = 1",(j+1) ,(k+1));
		}
    }
//	int	z=i+1;
//	printf("column number %d has %d zeros\n",z,zeroCount);
//		if(zeroCount==columnNum){
//			enqueue(z);
//		}
//}
}
 /*       for(i=1; i<=max_edges; i++)
        {
                printf("\nEnter edge %d(-1 -1 to quit): ",i);
                scanf("%d %d",&origin,&destin);
 
                if((origin == -1) && (destin == -1))
                        break;
 
                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                        adj[origin][destin] = 1;
        }*/
}