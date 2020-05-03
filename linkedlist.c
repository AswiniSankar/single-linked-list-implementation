/*IMPLEMENTATION OF LINKED LIST OPERATIONS*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* next;
};
struct node* root=NULL;
void insertatbegin();
void insertatend();
void insertatmiddle();
void display();
void deleteatbegin();
void deleteatend();
void deleteatmiddle();
void search();
void reverse();
int len;
int lenght();
void nodeswap();
int main()
{ int ch;
  while(1)
  {
    printf("1.insertatbegin\n2.insertatend\n3.insertatmiddle\n4.display\n5.lenght\n6.deleteatbegin\n7.deleteatend\n8.deleteatmiddle\n9.search\n10.reverse\n11.nodeswap\n12.exit\nyour choice\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:insertatbegin();break;
      case 2:insertatend();break;
      case 3:insertatmiddle();break;
      case 4: display();break;
      case 5:
         len=lenght();
         printf("%d\n",len);
         break;
      case 6:deleteatbegin();break;
      case 7:deleteatend();break;
      case 8:deleteatmiddle();break;
      case 9:search();break;
      case 10:reverse();break;
      case 11:nodeswap();break;
      case 12:exit(1);
      default:printf("invalid choice\n\n");
    }
  }
  printf("\n");
  return 0;
}
void insertatbegin()
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&temp->data);
  temp->next=NULL;
   if(root==NULL)
     root=temp;
  else
  {struct node* p;
    p=root;
    temp->next=p;
     root=temp;
  }
}
void insertatend()
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&temp->data);
   temp->next=NULL;
  if(root==NULL)
    root=temp;
   else
    {
    struct node* p;
    p=root;
    while(p->next!=NULL)
    {p=p->next;
    }
    p->next=temp;
    }

}
void insertatmiddle()
{ int pos,i=1;
  struct node* temp, *p;
  printf("enter the position\n");
  scanf("%d",&pos);
   
  len=lenght();
  if(pos>len)
   printf("invalid location\nthe available nodes are %d\n",len);
  else
  {p=root;   
  while(i<pos)
    {
     p=p->next;
     i++;
    }
   temp=(struct node*)malloc(sizeof(struct node));
   printf("enter the data\n");
   scanf("%d",&temp->data);
   temp->next=NULL;
   temp->next=p->next;
   p->next=temp;
  }
  
}
int lenght()
{ int c=0;
  struct node* temp;
  temp=root;
  while(temp!=NULL)
  {c++;
    temp=temp->next;
  }
  return c;
}
void display()
{
  struct node* temp;
  temp=root;
  if(temp==NULL)
     printf("the list is empty\n");
  else
  {
    while(temp!=NULL)
  {
   printf("%d-->",temp->data);
   temp=temp->next;
  }
 }
  printf("\n");
}
void deleteatbegin()
{
  struct node* temp;
   temp=root;
    len=lenght();
   if(len==0)
     printf("list is empty\n");
   else
   {
    root=temp->next;
    temp->next=NULL;
     free(temp);
   } 
}
void deleteatend()
{ int i=1;
 
   struct node* p;
   struct node* q;
   p=root;
   len=lenght();
   if(len==0)
     printf("list is empty\n");
   else if(len==1)
      deleteatbegin();
   else
   {
     while(i<len-1)
    { p=p->next;
     i++;
    }
    q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
   }
}
void deleteatmiddle()
{ int pos,i=1;
  struct node* temp;
  printf("enter the position\n");
  scanf("%d",&pos);
  len=lenght();
 
  if(pos>len)
     printf("invalind position\navaliable positions are %d\n",len);
  else if(pos==1)
  {
   deleteatbegin();
  }
  else if(pos==len)
   deleteatend();
  else
  {  struct node* p;
     struct node* q;
      p=root;
   while(i<pos-1)
    { p=p->next;
     i++;
    }
    q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
   }

}
void search()
{
 int element,pos=1;
 struct node* temp;
 temp=root;
 printf("enter the element\n");
 scanf("%d",&element);
 while(temp->data!=element)
 {temp=temp->next;
   pos++;
 }
    
 printf("the element %d is present in the %d position in list\n",element,pos);
}
void reverse()
{ int i,j,k;
  struct node* temp,*p,*q;
  p=q=root;
  len=lenght();
  i=0;
  j=len-1;
  while(i<j)
  {
      k=0;
      while(k<j)
      {q=q->next;
       k++;
      }
     temp->data=p->data;
     p->data=q->data;
     q->data=temp->data;
     p=p->next;
     q=root;
     i++;
     j--;
  }
  display();
  printf("\n");
}
void nodeswap()
{int i=1,loc;
 struct node* p,*q,*r;
 printf("enter the location\n");
 scanf("%d",&loc);
 p=root;
 while(i<loc-1)
 {p=p->next;
  i++;
 }
 q=p->next;
 r=q->next;
 q->next=r->next;
 r->next=q;
 p->next=r;
 display();
}
