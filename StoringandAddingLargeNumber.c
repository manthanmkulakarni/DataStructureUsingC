//Storing two large which cant be stored in basic datatype in linked list 
// and addition operation is performed on them

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* llink;
    struct node* rlink;
};
typedef struct node node;

//The number is stored in reversed order

node* insertf(node*root,int num)
{
    node *nn=(node*)malloc(sizeof(node));
    if(root==NULL)
    {
        nn->data=num;
        nn->llink=nn->rlink=NULL;
    }
    else{
    nn->data=num;
    nn->rlink=root;
    root->llink=nn;
    nn->llink=NULL;
    }
    return nn;
}
//Addition is performed for given two number
node* add(node *root1,node *root2)
{
    int carry=0,sum=0;
    node *res=NULL;
	//If any of the number is zero
    if(root1==NULL&&root2!=NULL)
    {
        return root2;
    }
	//If any of the number is zero
    else if(root2==NULL)
    {
        return root1;
    }
    else
    {
        while(root1!=NULL&&root2!=NULL)
        {
            sum=root1->data+root2->data+carry;
            carry=sum/10;
            sum=sum%10;
            printf("%d\n",sum);
            res=insertf(res,sum);
            root1=root1->rlink;
            root2=root2->rlink;
        }
	//If the first number is shorter than second one
        if(root1==NULL)
        {
            while(root2!=NULL)
            {
            sum=root2->data+carry;
            carry=sum/10;
            sum=sum%10;
            res=insertf(res,sum);
            root2=root2->rlink;
            }
        }
	//If the second number is shorter than first one
        else{
            while(root1!=NULL){
            sum=root1->data+carry;
            carry=sum/10;
            sum=sum%10;
            res=insertf(res,sum);
            root1=root1->rlink;
            }
        }

        if(carry!=0)
        {
            res=insertf(res,carry);
        }
        return res;
    }
}
//This is to display the input number
void dispr(node*root)
{
    
    while(root->rlink!=NULL)
    {
        root=root->rlink;
    }
   
    while(root!=NULL)
    {
        printf("%d",root->data);
        root=root->llink;
    }
}
//This is to display the ouput number
void disp(node*root)
{
    while(root!=NULL)
    {
        printf("%d",root->data);
        root=root->rlink;
    }
}

int main()
{
    int num;
    node *root1=NULL,*root2=NULL,*ans=NULL;
   
        printf("Enter the 1st number to be added or press 99 to end entering the number\n");
        while(1)
        {
            
            scanf("%d",&num);
            if(num==99)
            break;

            root1=insertf(root1,num);

        }
         printf("Enter the 2st number to be added or press 99 to end entering the number\n");
        while(1)
        {
            
            scanf("%d",&num);
            if(num==99)
            break;

            root2=insertf(root2,num);

        }
    
    ans=add(root1,root2);
    printf("\n");
    dispr(root1);
    printf("+");
    dispr(root2);
    printf("\n");
    disp(ans);
    printf("\n");
    return 0;
}
