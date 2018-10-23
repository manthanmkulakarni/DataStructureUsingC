#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node* pre;
}node;

node* insertf(node* f)
{
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	node* nn=(node*)malloc(sizeof(node));
	nn->data=num;
	nn->next=NULL;
	nn->pre=NULL;
	if(f!=NULL)
	{
		f->pre=nn;
		nn->next=f;
	}
	return nn;
}
node* insert(node*f)
{
	int pos,num,c;
	node *nn=(node*)malloc(sizeof(node)),*cf;
	nn->next=NULL;
	nn->pre=NULL;
	printf("Enter the position\n");
	scanf("%d",&pos);
	if(f==NULL)
	{
		if(pos==1)
		{
			printf("Enter the number\n");
			scanf("%d",&num);
			nn->data=num;
			nn->pre=nn;
			return nn;
		}
		else
		{
			printf("Invalid position\n");
			return f;
		}
	}
	else
	{
		if(pos==1)
		{
			printf("Enter the number\n");
			scanf("%d",&num);
			nn->data=num;
			f->pre=nn;
			nn->next=f;
			return nn;
		}
		else
		{
			c=1;
			cf=f;
			
			while(c!=pos&&f->next!=NULL)
			{
				f=f->next;
				c++;
			}
			if(c==pos)
			{
				printf("Enter the number\n");
				scanf("%d",&num);
				nn->data=num;
				nn->pre=f->pre;
				nn->next=f;
				nn->pre->next=nn;
				f->pre=nn;
			}
			else if(c==pos-1)
			{
				printf("Enter the number\n");
				scanf("%d",&num);
				nn->data=num;
				f->next=nn;
				nn->pre=f;

			}
			else
			{
				printf("Invalid position\n");
			}
		}
		return cf;
	}
}
void disp(node *f)
{
	if(f==NULL)
		printf("Empty list\n");
	else
	{
		while(f!=NULL)
		{
		printf("%d \t",f->data);
		f=f->next;
		}
		printf("\n");
	}

}
int main()
{
	node *f=NULL;
	int ch;
	printf("1 insertfront\n2 insert\n3 disp\n");
	while(1)
	{
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			f=insertf(f);
			break;

			case 2:
			f=insert(f);
			break;

			case 3:
			disp(f);
			break;

			default:
			return 0;
		}
	}
	return 0;
}
