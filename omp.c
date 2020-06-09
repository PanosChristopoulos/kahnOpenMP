  
#include<stdio.h>
#include<stdlib.h>
#include "fopeno.h"
#include <omp.h>
#include <time.h>
#define MAX 10000
 
int n;    /*Number of vertices in the graph*/
void create_graph();
int queue[MAX], front = -1,rear = -1;

 

void insert_queue(int vertex)
{
        if (rear == MAX-1)
                printf("\nQueue Overflow\n");
        else
        {
                if (front == -1)  
                        front = 0;
                rear = rear+1;
                queue[rear] = vertex ;
                printf("\nVertex %d inserted to queue",vertex+1);
        }
}
 
int isEmpty_queue()
{
        if(front == -1 || front > rear )
                return 1;
        else
                return 0;
}
 
int delete_queue()
{
        int del_item;
        if (front == -1 || front > rear)
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        else
        {
                del_item = queue[front];
                front = front+1;
                return del_item;
                printf("\nVertex %d deleted from queue",del_item);
        }
}
 
int indegree(int v)
{
        int i,in_deg = 0;
        for(i=0; i<n; i++)
                if(M[i][v] == 1)
                        in_deg++;
        return in_deg;
}
 

void addnodes(int origin, int destin, int n ){

                if((origin == -1) && (destin == -1))
 
                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        //i--;
                }
                else
                        M[origin][destin] = 1;
        }



void create_graph()
{
        int i,max_edges,origin,destin;
        
        char file[50];
        printf("\n Please type .mtx file to import: ");
        scanf("%s",file);
        fileImport(file);
        if(rowNum<30){
        printM();}
        n=rowNum;
        max_edges = rowNum*columnNum;
        printf("\nMaximum number of edges are %d",max_edges);
        for (int i = 0 ; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
		        if(M[i][j]==1){
                    printf("\nEdge from %d to %d", i+1,j+1);
                   origin=i;
                   //printf("origin is %d",origin);
                   destin=j;
                   //printf("destin is %d",destin);
                   addnodes(origin,destin,max_edges);


}               
		}
    }
}

int main()
{
        double thread_start,thread_end;
        int getfunction();
        int counter=0,id,i,v,count,topo_order[MAX],indeg[MAX],a;
	printf("number of threads?\n");
	scanf("%d", &a);
	omp_set_num_threads(a);
	create_graph();
        int numofelements,chunk;
        struct timeval start_time,end_time;
        double thread_time,total_time;

        gettimeofday(&start_time,NULL);
        numofelements=getfunction();
	#pragma omp parallel private(i,id) shared(counter,count,topo_order,indeg,v)

{
        thread_start= omp_get_wtime();
 	id=omp_get_thread_num();
        numofelements=getfunction();
        chunk=numofelements/a;
	#pragma omp for schedule(dynamic,chunk) 
        /*Find the indegree of each vertex*/
        for(i=0;i<n;i++)
        {
	#pragma omp task
                indeg[i] = indegree(i);
                if( indeg[i] == 0 )
                        insert_queue(i);
        }
        #pragma omp barrier
  




 while(  !isEmpty_queue( ) && count < n )
        { 
               #pragma omp critical
               {
                v = delete_queue();
		//#pragma omp task
                topo_order[++count] = v; /*Add vertex v to topo_order array*/
                /*Delete all edges going fron vertex v */
                for(i=0; i<n; i++)
                {
                        if(M[v][i] == 1)
                        {
                                M[v][i] = 0;
                                indeg[i] = indeg[i]-1;
                                
                                if(indeg[i] == 0)
                                        insert_queue(i);
                        
               }}
        }}
        //#pragma omp barrier
                thread_end = omp_get_wtime();
                thread_time = (thread_end - thread_start);
                 printf("\nTime for thread %d = %13.6f sec", id ,thread_time);

	}
        gettimeofday(&end_time,NULL);
 if( count < n )
        {
                printf("\nNo topological ordering possible, graph contains cycle\n");
                exit(1);
        }

        printf("\nVertices in topological order are :\n");
        for(i=1; i<=count; i++)
                printf( "%d ",topo_order[i]+1 );
        printf("\n");


	   total_time = ((end_time.tv_sec - start_time.tv_sec) * 1000000.0 + (end_time.tv_usec - start_time.tv_usec));
        printf("Time for calculations = %13.6f sec\n", (total_time / 1000000.0));


return 0;

 }
