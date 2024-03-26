//sjf(non preemptive)
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int pid,bt,wt,tt;
}sp;

int main(){
	int i,j,n,towt=0,tott=0,tbm=0;
	sp *p,t;
	printf("SJF scheduling..\n");
	printf("enter the no. of processes: ");
	scanf("%d",&n);
	p=(sp *)malloc(n*sizeof(sp));
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		printf("\nenter the bt of process id %d: ",p[i].pid);
		scanf("%d",&p[i].bt);
	}
	//sort processes acc  to their bt
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].bt>p[j].bt){
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	
	//print & calc
	printf("\nscheduling...\n");
	printf("process\tburst\twaiting\tturnaround\n");
	for(i=0;i<n;i++){
		tbm+=p[i].bt;
		p[i].tt=tbm;
		p[i].wt=tbm-p[i].bt;
		towt+=p[i].wt;
		tott+=p[i].tt;
		printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("avg wt:%.2f\n",(float)towt/n);
	printf("avg tt:%.2f\n",(float)tott/n);
	free(p);
	return 0;
}
