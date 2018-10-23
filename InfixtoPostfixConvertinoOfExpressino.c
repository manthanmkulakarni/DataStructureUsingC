
	//	Program to convert infix expression to postfix

/*

Infix expression:The expression of the form a op b. When an operator is in-between every pair of operands. Eg: (a+b)*c/d-(e+f)^g 

Postfix expression:The expression of the form a b op. When an operator is followed for every pair of operands. Eg: ab+c*d/ef+g^-



*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char *data;
    int top;
    int max;
}stack;

char peep(stack s)
{
    return *(s.data+s.top);
}

//Remove the comments for printf in push and pop function to trace the content of stack
void push(stack *s,char c)
{
    (s->top)++;
    *(s->data+s->top)=c;
    //printf("%c pushed\n",*(s->data+s->top));
}
char pop(stack *s)
{
    char c=*(s->data+s->top);
   // printf("%c popped\n",c);
    (s->top)--;
    return c;

}
int isFull(stack s)
{
    if(s.top==s.max-1)
     return 1;

    else
        return 0;
}

int isEmpty(stack s)
{
    if(s.top==-1)
        return 1;

    else
        return 0;
}

int stackPriority(stack s)
{
    char c=*(s.data+s.top);
    if(c=='+'||c=='-')
        return 2;
    else if(c=='/'||c=='*')
        return 4;
    else if(c=='^'||c=='$')
        return 6;
    else if(c=='(')
        return 0;
    
}

int outsidePriority(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if(c=='/'||c=='*')
        return 3;
    else if(c=='^'||c=='$')
        return 5;
    else if(c=='(')
        return 7;
    else
        return -1;
}
int isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='$'||c=='('||c==')')
        return 1;
    else
        return 0;
}

int main()
{
    int i,n,j;
    char c[50],temp,ans[50];
    stack *s=(stack*)malloc(sizeof(stack));
    s->max=10;
    s->top=-1;
    s->data=(char*)malloc(sizeof(char)*(s->max));
    printf("Enter the equation\n");
    scanf("%s",c); 
	// Here  string is c is infix equation
   
    n=strlen(c);
    i=0;
    j=0;
    while(i<n)
    {
	// Only operands are pushed into the stack

        if(isOperator(c[i]))
        {
            if(isFull(*s))
            {
                printf("Stack is full\n");
            }
	    else
		{
			//  When right parenthesis is encounter
			//  all operand staring after correseponding left parenthesis is popped and applied to the postfix expression

			if(c[i]==')')
			{
				while(1)
				{
					temp=pop(s);
					if(temp=='(')
					{
					break;
					}
					else
					{
					ans[j++]=temp;
					
					}
				}
				i++;
			}


			else if(stackPriority(*s)<outsidePriority(c[i])||isEmpty(*s))
			{
				push(s,c[i++]);

			}

			else
			{
				temp=pop(s);
				ans[j++]=temp;
			}
		}


         }  

        else
        {
            
            ans[j++]=c[i++];
        }
    }
	//  If operator is present in stack after reading the complete string is poped inorder and applied to the expression

    while(!isEmpty(*s))
    {
        temp=pop(s);
        if(temp!='(')
        {
            ans[j]=temp;
            j++;
        }
    }

    printf("%s in postfix form is :%s\n",c,ans);

    return 0;

}
