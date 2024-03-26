//fcfs 
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int pid,bt,wt,tt;     //can consider all struct array
}sp;  //sp=stack pointer(header)

int main(){
	int i,j,n,tott=0,towt=0,tbm=0;
	sp *p,t; //p ,t=ptr(for which space is allocated)
	printf("FCFS scheduling\n");
	printf("enter the no of processes: ");
	scanf("%d",&n);
	p=(sp *)malloc(n * sizeof(sp));  //
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		printf("\nenter burst time of process id %d: ",p[i].pid);
		scanf("%d",&p[i].bt);
	}
	//calculation
	printf("\nprocess scheduling\n");
	printf("process\tburst\twaiting\tturnaround\n");
	for(i=0;i<n;i++){
	    tbm+=p[i].bt;
	    p[i].tt=tbm;
	    p[i].wt=tbm-p[i].bt;
	    towt+=p[i].wt;
	    tott+=p[i].tt;
	    printf("%d\t\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("avg waiting time:%.2f\n",(float)towt/n);
	printf("avg turn around time:%.2f\n",(float)tott/n);
	free(p);
}

