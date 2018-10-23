//Program to implement the linked list
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node*link;
};
//To create the linked list for first time
struct node* create(int newdata)
{
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    nn->data=newdata;
    nn->link=NULL;

    return nn;
}

void append(struct node*root,int newdata)
{
    
    struct node*nn=create(newdata);
   
   if(root==NULL)
   {
       printf("First call create function and then call append functino\n");
   }
   else
   {
    while(root->link!=NULL)
    {
        root=root->link;
        
    }
     root->link=nn;
     
   }
}


struct node* del_by_pos(struct node*root,int pos)
{
    int count=1;
//Deleting the first node
if(pos==1)
{
    struct node* newroot=root->link;
    free(root);
    return newroot;
}

else if(root==NULL)
{
    printf("Noughting to delete");
    return NULL;
}
else
{
    struct node* rootcpy=root,*previousnodelink=NULL;
    while(count!=pos&&(rootcpy->link)==NULL)
    {
        previousnodelink=rootcpy;
        rootcpy=rootcpy->link;
        i++;
    }
	//If the position is a invalid position 
    if(i!=pos)
    {
        printf("Could not find the position %d in the list\n",pos);
        
    }
    else
    {
        previousnodelink->link=rootcpy->link;
        
    }

    return root;
}

}

void disp(struct node*root)
{
    while(root!=NULL)
    {
        printf("%d ",root->data);
        root=root->link;
    }
    printf("\n");
}


int main()
{
    struct node* root=create(1);
    append(root,2);
    append(root,3);
    append(root,4);
    disp(root);

    return 0;
}
