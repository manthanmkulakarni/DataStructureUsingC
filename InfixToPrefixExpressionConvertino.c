		// Program to convert infix expression to prefix form

/*

While we use infix expressions in our day to day lives. Computers have trouble understanding this format because they need to keep in mind rules of operator precedence and also brackets. Prefix and Postfix expressions are easier for a computer to understand and evaluate. 

infix form: A * B + C / D
postfix form : + * A B/ C D 

infix form: (A - B/C) * (A/K-L)
postfix form : *-A/BC-/AKL


*/




#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int maxsize=50;
typedef struct stack1
{
    char data[50];
    int top;
   
}STACK1; //   This stack is to hold the operands

typedef struct stack2
{
    char data[50][50];                     // 20 strings each of size 20 bits
    int top;
    
}STACK2; //   This stack is to hold the partial expressino

//In below push and pop function uncomment the printf function to trace the content of stack in each level
//operations for stack 1
void push1(STACK1*s,char c)
{
    s->top++;
    s->data[s->top]=c;
   //printf("%c push\n",s->data[s->top]);
}
char pop1(STACK1*s)
{
    
   char c=s->data[s->top];
   s->top--;
  // printf("%c popped\n",c);
   return c;
}
int isEmpty1(STACK1 s)
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}
int isFull1(STACK1 s)
{
    if(s.top==maxsize-1)
    return 1;
    else
    return 0;

}
char peep(STACK1 s)
{
    return s.data[s.top];
}
//operations for stack2
void push2(STACK2*s,char*c)
{
    
    s->top++;
    strcpy(s->data[s->top],c);
   // printf("%s pushed\n",c);
}

char *pop2(STACK2*s)
{
   //printf("%s popped\n",s->data[s->top]);
    char *c=s->data[s->top];
    s->top--;
    return c;
}
int isEmpty2(STACK2 s)
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}
int isFull2(STACK2 s)
{
    if(s.top==maxsize-1)
    return 1;
    else
    return 0;
}


int stackPriority(char c)
{
    if(c=='+'||c=='-')
    return 2;
    else if(c=='*'||c=='/')
    return 4;
    else if(c=='$'||c=='^')
    return 6;
    else
    return 0;
}
int outsidePriority(char c)
{
    if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 3;
    else if(c=='$'||c=='^')
    return 5;
    else if(c=='(')
    return 7;
    else 
    return 0;

}
int isOperator(char c)
{
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^'||c=='$'||c=='('||c==')')
    return 1;
    else 
    return 0;
}
int main()
{
    int i,n;
    STACK1 *s1=(STACK1*)malloc(sizeof(STACK1));
    STACK2 *s2=(STACK2*)malloc(sizeof(STACK2));
    s1->top=-1;
    s2->top=-1;
    char input[50],*str1,*str2,c;
    
    
    printf("Enter the expresion within 50 charecters\n");
    scanf("%s",input);

    n=strlen(input);
    for(i=0;i<n;)
    {
        char s[2];
    if(isOperator(input[i]))
    {
        if(input[i]==')')
        {
            while(1)
            {
                
                char temp[50];
                c=pop1(s1);
                s[0]=c;
                s[1]='\0';
                
                if(s[0]=='(')
                {
                    break;
                }
                else
                {   str2=pop2(s2);
                    str1=pop2(s2);
		    temp[0]='\0';
                    strcat(temp,s);
                    strcat(temp,str1);
                    strcat(temp,str2);
                    push2(s2,temp);
                }

            }
            i++;
        }
        else
        {
            if(isEmpty1(*s1))
            {
                push1(s1,input[i]);
                i++;
            }
            else if((outsidePriority(input[i])>stackPriority(peep(*s1))))
            {
                push1(s1,input[i]);
                i++;
            }
            else
            {
                char temp[50];
                c=pop1(s1);
                s[0]=c;
                s[1]='\0';
                str2=pop2(s2);
                str1=pop2(s2);
		temp[0]='\0';
                strcat(temp,s);
                strcat(temp,str1);
                strcat(temp,str2);
                push2(s2,temp);
               
            }
        }
    }

    //If the scanned one is not operand
    else
    {
       c=input[i];
       s[0]=c;
       s[1]='\0';
        i++;
        push2(s2,s);
       
    }
   
    }
    //If operator stack is not empty
    while(!isEmpty1(*s1))
    {
        char temp[50],s[2];
        c=pop1(s1);
        s[0]=c;
        s[1]='\0';
        str2=pop2(s2);
        str1=pop2(s2);
	temp[0]='\0';
        strcat(temp,s);
        strcat(temp,str1);
	strcat(temp,str2);
        push2(s2,temp);
       
    }

    printf("The resultant prefix form of the equation is : %s\n",s2->data[0]);
    
    
    return 0;
}
