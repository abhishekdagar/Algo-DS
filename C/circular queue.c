#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define MAX 100
typedef struct{
		int n;
		int f,r,a[MAX];
}cqueue;
cqueue enqu(cqueue cq,int val)
{
    cq.r=(cq.r+1)%(cq.n);
	if(cq.r==cq.f){            //-1 distinguish start from end
		printf("\nqueue full\n");
		if(cq.r==0) cq.r=cq.n-1;
        else cq.r=cq.r-1;
        return;
	}
	cq.a[cq.r]=val;
    return cq;
}
cqueue deq(cqueue cq)
{
	if(cq.f==cq.r){
		printf("\nqueue empty\n");
		return;
	}
	printf("\nDeleted element val:%d\n",(cq.a[(cq.f++)%(cq.n)]));
    return cq;
}
void display(cqueue cq){
	int i=cq.f;
	if(cq.f==cq.r){
		printf("\nqueue empty\n");
		return;
	}
	printf("\nQueue:\n");
	while(i!=cq.r){
	printf("%d\t",cq.a[(i++)%(cq.n)]);
	}
}
int main(){
    cqueue cq[10];
    int nq,i=0,ch,val;
    char ch1='1';
    printf("\nEnter no. of queues:");
    scanf("%d",&nq);
    while(i!=nq)
    {
        cq[i].f=0;
        cq[i].r=0;
        printf("\nEnter size for cqueue[%d]:",i);
        scanf("%d",&val);
        cq[i].n=val+1;
        printf("%d\t%d\t%d\n",cq[i].f,cq[i].r,cq[i].n);
        i++;
    }
    do{
        for(i=0;i<nq;i++){
                            printf("\nQueue[%d]\nEnter your choice\n1.Enqueue\n2.Dequeu\n3.Display\nAny other number to skip\n",i);
                            scanf("%d",&ch);
                            if(ch==1)
                            {
                                printf("\nEnter value to enqueu:");
                                scanf("%d",&val);
                                cq[i]=enqu(cq[i],val);
                            }
                            else if(ch==2)
                            {
                                cq[i]=deq(cq[i]);
                            }
                            else if(ch==3)
                            {
                                display(cq[i]);
                            }
                         }
                         printf("\n Do you want to continue? 1 to continue , anything else to quit\n");
                         ch1=getch();
    }while(ch1=='1');
	
}
