#include<stdio.h>
void main(){
int first,second,sum,n,counter=0;
    printf("enter number of terms\n");//for number for terms in series
    scanf("%d",&n);
    printf("enter first number\n");//first number inseries if its not starting with zero
    scanf("%d",&first);
    printf("enter second number\n");// second number
    scanf("%d",&second);
    printf("fibonacci series: %d %d\t",first,second);
    while(counter<n){
        sum=first+second;
        printf("%d",sum);
        first=second;
        second=sum;
        counter++;
    }
}

