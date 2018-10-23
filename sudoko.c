//This program varifies the given solution for sudoko of n by n size

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i,j,k,l,p,m,n,c,f=1,nsq;
    printf("Enter the size of square\n");
    scanf("%d",&n);
     nsq=sqrt(n);
    int *ar=(int*)malloc(sizeof(int)*n*n);
    //Taking the solution to need to be varified
    for(i=0;i<n*n;i++)
    {
        scanf("%d",(ar+i));
    }
    //This block varifies the along the row
    for(k=0;k<n;k++)
    {
        
            for(j=0,c=0;j<n;j++)
            {
                c=c+(*(ar+j+k*n));
          
            }
           
            if(c!=(n*(n+1)/2))
            {
                f=0;
                
                goto end;
            }
        
    }
     //This block varifies the along the column
    for(k=0;k<n;k++)
    {
       
            for(j=0,c=0;j<n;j++)
            {
                c=c+(*(ar+j*n+k));
                
            }
           
            if(c!=(n*(n+1)/2))
            {
                f=0;
                
                goto end;
            }

        
    }
     //This block varifies the along the each inner block
    for(p=0;p<nsq;p++)
    {
        for(m=0;m<nsq;m++)
        {
           
            
                for(j=0,c=0;j<nsq;j++)
                {
                    for(l=0;l<nsq;l++)
                    {
                        c=c+(*(ar+l+(n*j)+(m*nsq+(p*nsq*n))));

                    }
                }
                if(c!=(n*(n+1)/2))
                {
                    f=0;
                     goto end;
                }
            
        }
    }
end:
if(f)
{
    printf("ok\n");
}
else
{
    printf("no\n");
}

return 0;
}
