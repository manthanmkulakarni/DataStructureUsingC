#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node node;

int flg=0;
int pflg=0;
node *parent=NULL;
node *del=NULL;

node* insert(node *r,int num)
{
    if(r==NULL)
    {
        r=(node*)malloc(sizeof(node));
        r->data=num;
        r->llink=NULL;
        r->rlink=NULL;
        return r;
    }
    else{
        node *nn=(node*)malloc(sizeof(node)),*cr=r,*parent;
        nn->data=num;
        nn->llink=NULL;
        nn->rlink=NULL;
        parent=r;
        while(r!=NULL)
        {
            parent=r;
            if(r->data>num)
            {
                r=r->llink;
            }
            else{
                r=r->rlink;
            }
        }
        if(parent->data>num)
        {
            parent->llink=nn;
        }
        else{
            parent->rlink=nn;
        }
        return cr;
    }
}
void search(node *r,int num)
{
    if(r==NULL)
    return;

    if(r->data==num)
    {
        flg=1;
        pflg=1;
        del=r;
    }
    
    if(flg!=1){
        search(r->llink,num);
        if(pflg==1){
            parent=r;
            pflg=0;
        }
    }
    if(flg!=1)
    {
        search(r->rlink,num);
        if(pflg==1){
            pflg=0;
            parent=r;
        }
    }
    return;
}
node* delete(node *r,int num)
{
    if(r==NULL)
    {
        printf("Tree is empty\n");
        return r;
    }
    else{
        search(r,num);
        if(flg==1){
            //for deleteing leaf nodes
            if(del->llink==NULL&&del->rlink==NULL)
            {
                printf("%d deleted\n",del->data);
                if(parent->llink==del)
                {
                    parent->llink=NULL;
                }
                else{
                    parent->rlink=NULL;
                }
                free(del);
            }
            //for deletion of nodes with only one child
            else if(del->rlink!=NULL&&del->llink==NULL)
            {
                printf("case 2\n");
                if(parent->llink==del)
                {
                    parent->llink=del->rlink;
                }
                else{
                    parent->rlink=del->rlink;
                }

            }
            //for deletion of nodes with only one child
            else if(del->llink!=NULL&&del->rlink==NULL)
            {
                printf("case 2\n");
                if(parent->llink==del)
                {
                    parent->llink=del->llink;
                }
                else{
                    parent->rlink=del->llink;
                }
            }
            
        //for deletion of nodes with two child
        else if(del->rlink!=NULL&&del->llink!=NULL)
        {
            printf("case 3\n");
            node *temp=del->rlink,*tempp=del;
            while(temp->llink!=NULL)
            {
                tempp=temp;
                temp=temp->llink;
            }
            if(tempp->rlink==temp){
                 del->data=temp->data;
                tempp->rlink=temp->rlink;
                free(temp);
            }
            else{
                del->data=temp->data;
                tempp->llink=temp->rlink;
                free(temp);
            }

        }
        }
        else{
            printf("Node not found\n");
            return r;
        }
        return r;
    }


}
void disp(node *r)
{
    if(r==NULL)
    return ;

    else{
        disp(r->llink);
        printf("%d ",r->data);
        disp(r->rlink);
    }
}
int main()
{
    int num,ch;
    node *r=NULL;
    printf("1 Insert\n2 Disp\n3 Delete\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the number\n");
            scanf("%d",&num);
            r=insert(r,num);
            break;
            case 2:
            disp(r);
            printf("\n");
            break;

            case 3:
            del=r;
            parent=r;
            printf("Enter the node to be deleted\n");
            scanf("%d",&num);
            delete(r,num);
            del=NULL;
            parent=NULL;
            flg=0;
            pflg=0;
            break;

            default:
            exit(0);
        }
    }
    return 0;
}
