#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char *data;
    int top;
    int maxsize;
}STACK;
void push(STACK *s,char n)
{
    s->top++;
   *(s->data+s->top)=n;
}
char pop(STACK *s)
{
    return *(s->data+(s->top--));
}
int isFull(STACK s)
{
    if(s.top==s.maxsize-1)
    return 1;
    else 
    return 0;
}
int isEmpty(STACK s)
{
    if(s.top==-1)
    return 1;
    else return 0;
}
char peep(STACK s)
{
    return *(s.data+s.top);
}
int main()
{
    char ar[30];
    printf("Enter the string\n");
    scanf("%s",ar);
    int n=strlen(ar),i=0;
    STACK *s;
    s=(STACK*)malloc(sizeof(STACK));
    s->top=-1;
    s->maxsize=n;
    s->data=(char*)malloc(sizeof(char)*n);
if(n%2==0)
{
    while(i<n/2)
    {
       push(s,ar[i++]);
    }
    while(i<n)
    {
            if(peep(*s)!=ar[i])
            {
                break;
            }
            else
	    {
                pop(s);
            }
        i++;

    }
    if(isEmpty(*s))
    {
        printf("The given string is palindrome\n");
    }

    else{
         printf("The given string is not palindrome\n");
    }
 }
else{
         printf("The given string is not palindrome\n");
    }
    return 0;
}
