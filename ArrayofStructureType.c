//This program to is to represent the array of userdefined data structure

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[30];
    char usn[10];
    int marks[3];
    float avg;

}student;

void append(student*ar,int *n)
{
    int j=*n,sum=0,i=0;
    printf("Enter the name and  usn\n");
    scanf("%s%s",(ar+j)->name,(ar+j)->usn);
    for(i=0;i<3;i++)
    {
        printf("Enter marks in test %d\n",i+1);
        scanf("%d",&((ar+j)->marks[i]));
        sum+=(ar+j)->marks[i];
    }
    (ar+j)->avg=sum/3.0;
    (*n)=(*n)+1;
    
}

void insert(student *ar,int *n,int pos)
{
    int i=*n,sum=0;
    for(;i>=pos;i--)
    {
        strcpy((ar+i)->name,(ar+i-1)->name);
        strcpy((ar+i)->usn,(ar+i-1)->usn);
        (ar+i)->avg=(ar+i-1)->avg;

    }
    printf("Enter the name and usn\n");
    scanf("%s%s",(ar+i)->name,(ar+i)->usn);
    for(int j=0;j<3;j++)
    {
        printf("Enter %d marks\n",j+1);
        scanf("%d",&(ar+i)->marks[j]);
        sum+=(ar+i)->marks[j];
    }
    (ar+i)->avg=sum/3.0;
    (*n)=(*n)+1;


}

void del(student *ar,int *n,int pos)
{
    int i;
    //If there is only one element in the array
    if((*n)==1)
    {
        free(ar);
        
    }
    else
    {
    for(i=pos-1;i<*n;i++)
    {
        strcpy((ar+i)->name,(ar+1+i)->name);
        strcpy((ar+i)->usn,(ar+1+i)->usn);
        (ar+i)->avg=(ar+i+1)->avg;
    }
    
    ar=(student*)realloc(ar,sizeof(student)*(*n));
    }
    (*n)=(*n)-1;
}

void disp(student *ar,int n)
{
    if(n==0)
    {
        printf("Empty list\n");
    }
    else{
        for(int i=0;i<n;i++)
        {
            printf("Student %d details\n",i+1);
            printf("Name : %s\nUsn : %s\n",(ar+i)->name,(ar+i)->usn);
            printf("Average marks : %.2f\n",(ar+i)->avg);
    
        }
        printf("\n");
    }
}

int main()
{
    int c,i=0,pos;
    student *ar;
    //Here i is used to count the number of cells in the array
    printf("1 Append\n2 Insert\n3 Delete\n4 Display\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        if(i==0)
        {
            ar=(student*)malloc(sizeof(student));
            append(ar,&i);
        }

        else
        {
            ar=(student*)realloc(ar,sizeof(student)*i+1);
            append(ar,&i);
        }
        
        break;

        case 2:
        printf("Enter the position to insert\n");
        scanf("%d",&pos);
        if(pos>i+1||pos<1)
        printf("Invalid position");


        else
        {
		//This is to add very first element to the array
            if(pos==1&&i==0)
            {
                ar=(student*)malloc(sizeof(student));
                append(ar,&i);
            }
            else
            {
                ar=(student*)realloc(ar,sizeof(student)*i+1);
                insert(ar,&i,pos);
            }
            
        }
        break;

        case 3:
        printf("Enter  the position\n");
        scanf("%d",&pos);

        if(pos<1||pos>i)
        {
            printf("Invalid position\n");
        }
        
        else
        {
            del(ar,&i,pos);
        }
        break;

        case 4:
        disp(ar,i);
        break;

        default:
        exit(0);
        }
    }
    return 0;
}
