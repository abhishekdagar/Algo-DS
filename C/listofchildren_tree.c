#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int data;
    struct Node* link;
}Node;
typedef struct 
{
    char name;
    struct loc* parent;
    Node* ptr;
}loc;
loc* makelocele(char val)
{
    loc* temp;
    temp=(loc*)malloc(sizeof(loc));
    temp->name=val;
    temp->parent=NULL;
    temp->ptr=NULL;
    return temp;
}
Node* makenode(int val)
{
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->link=NULL;
    return temp;
}
Node* insertlist(loc* ele,int index)
{
    Node* temp=makenode(index);
    ele->ptr=temp;
    return temp;
}
loc* insert(loc* ele,char name,int index)
{
    ele->ptr=insertlist(ele,index);
    return ele;
}
void display(loc list[],int n,int a);
void displaynode(loc list[],int n,Node* head)
{
    while(head->link!=NULL)
    {
       display(list,n,head->data);
    }
}
void display(loc list[],int n,int a)
{
      printf("\n%c\t",list[a].name);
      displaynode(list,n,list[a].ptr);
}
void main()
{
    loc* list[10];
    list[0]=insert(list[0],'R',0);
    printf("\n%c",list[0]->name);
}

