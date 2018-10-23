#include<stdio.h>
#include<stdlib.h>
typedef struct node node ;
struct node
{
	int data;
	struct node *link;
};

void insertFront(node** root,int num)
{
	node *nn=(node*)malloc(sizeof(node));
	nn->data=num;
	node *next;
	nn->link=NULL;
  	//Inserting the node into a empty list
	if(*root==NULL)
	{
		nn->link=nn;
		*root=nn;
	}
	else
	{	next=*root;
		while(next->link!=*root)
		{
			next=next->link;
		}
		nn->link=*root;
		next->link=nn;
	}

}

void insert(node** root,int num,int pos)
{
	int count=1;
	node* nn=(node*)malloc(sizeof(node));
	node*next,*pre=*root;
	nn->data=num;
	//if position is 1 and list is empty
	if(pos==1&&*root==NULL)
	{
		*root=nn;
		nn->link=nn;
	}
	//For empty list with position other than 1
	else if(*root==NULL&&pos!=1)
	{
		printf("Invalid position\n");
	}
	
	else
	{
	next=(*root)->link;
	while(next->link!=*root&&count!=pos-1)
	{
		pre=next;
		next=next->link;
		count++;
	}
	if(count==pos-1)
	{
		//For first postion insertion
		if(pos==1)
		{
			insertFront(root,num);
		}
		else
		{
			pre->link=nn;
			nn->link=next;
		}
	}
	//If the position is greater thant the number of nodes
	else
	{printf("Invalid pos\n");}

	}

}

void disp(node* root)
{
	node* first;
	if(root==NULL)
		printf("Empty list\n");
	else
	{
		first=root;
		do
		{
			printf("%d ",first->data);
			first=first->link;
		}while(first!=root);
		printf("\n");
	}
}

int main()
{
	int num,pos,ch;
	node *root=NULL;
	
	while(1)
	{
		printf("1 to Insertfront\n2 Insert by position\n3 Display\n4 to quit\n");
		scanf("%d",&ch);
		switch(ch)
		{ 
		case 1:
			printf("Enter the element to insert\n");
			scanf("%d",&num);
			insertFront(&root,num);
			break;
		case 2:

			printf("Enter position to insert and the number\n");
			scanf("%d%d",&pos,&num);
			insert(&root,num,pos);
			break;
		case 3:
			disp(root);
			break;

		
		default:
			exit(0);
		}

	}

return 0;
}
