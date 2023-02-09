#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild,*rchild;
}*ptr,*root=NULL,*par;
int h1=0,h2=0,n=0;
void createsub(int item,struct node *ptr)
{
int i;
char ch;
printf("\nDO YOU WANT TO CREATE A LEFT SUBTREE OF %d(y/n)",item);
scanf("%c",&ch);
if(ch=='y')
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT TO INSERT : ");
  scanf("%d",&i);
  newnode->data=i;
  newnode->rchild=NULL;
  newnode->lchild=NULL;
  ptr->lchild=newnode;
  create(newnode->data,newnode);
}
printf("\nDO YOU WANT TO CREATE A RIGHT SUBTREE OF %d(y/n)",item);
scanf("%c",&ch);
if(ch=='y')
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT TO INSERT : ");
  scanf("%d",&i);
  newnode->data=i;
  newnode->rchild=NULL;
  newnode->lchild=NULL;
  ptr->rchild=newnode;
  create(newnode->data,newnode);
}
}
void createtree()
{
int item;
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("DO YOU WANT INSERT:");
sacnf("%d",&item);
newnode->data=item;
newnode->rchild=NULL;
newnode->lchild=NULL;
root=newnode;
createsub(root->data,root);
}
void Height(struct node *pr)
{
   if(pr!=NULL)
   {
     ptr=pr;
     if(ptr->lchild!=NULL)
     {
      h1=h1+1;
      Height(ptr->lchild);
     }
     if(ptr->rchild!=NULL)
     {
      h1=h1+1;
      Height(ptr->rchild);
     }
     if(h1>h2)
     {
     h2=h1;
     h1=0;
     }
     Height(pr->lchild);
     Height(pr->rchild);
}}
void Number_of_nodes(struct node *ptr)
{
if(ptr!=NULL)
{
n=n+1;
 Number_of_nodes(ptr->lchild);
 Number_of_nodes(ptr->rchild);
 
}
}
void Traversal(struct node *ptr)
{
   if(ptr!=NULL)
   {
     Traversal(ptr->lchild);
     printf("%d",ptr->data);
     Traversal(ptr->rchild);
   }

}
int main()
{
int ch;
while(1)
{
printf("\nMenu\n1.Create tree\n2.Find height\n3.FindNumber\n4.Traversal\n5.Exit\nEnter choice");
scanf("%d",&ch);
		switch(ch)
		{
			case 1:Createtree();
			break;
			case 2:
			h1=0;
			h2=0;
			Height(root);
			printf("Height of tree = %d ",h2+1);
			break;
			case 3:
			n=0;
			Number_of_nodes(root);
			printf("Number of nodes = %d ",n);
			break;
			case 4:
			printf("Tree : ");
			Traversal(root);
			break;
			case 5:exit(0);
			default:printf("Enter valid choice");
		}
}
}
