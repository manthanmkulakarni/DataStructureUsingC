// Program to print spiral pattern of n numbers

/*
	To print pattern of this type
	Pattern size =5
			1  2  3  4  5  
			16  17  18  19  6  
			15  24  25  20  7  
			14  23  22  21  8  
			13  12  11  10  9 

*/

#include<stdio.h>
int main()
{
	int n,i=1,j,r=0,c=0,k=0;
	printf("Enter the size of the circular pattern\n");
	scanf("%d",&n);
	int elmnum=n*n;
	
	int max=n;
	int ar[n][n];

    do	
	{
	// To assign number along the column from top to bottom
	   while(c<n&&i<=elmnum)
	    {
	        ar[r][c]=i;
	        c++;
	        i++;
	    }
	    r+=1;
	    c-=1;
	//  To assign the numbers along the row from right to left
	    while(r<n&&i<=elmnum)
	    {
	        ar[r][c]=i;
	        i++;
	        r++;
	    }
	    r-=1;
	    c-=1;
	// To assign number along the column from  bottom  to top
	    while(c>=k&&i<=elmnum)
	    {
	        ar[r][c]=i;
	        i++;
	        c--;
	    }
	    r-=1;
	    c+=1;
	//  To assign the numbers along the row from left to right
	    while(r>k&&i<=elmnum)
	    { 
	        ar[r][c]=i;
	        i++;
	        r--;
	    }
	    c+=1;
	    r+=1;
	    n-=1;
	    k+=1;
	    
	   
	  
	}while(i<=elmnum);
	printf("PATTERN IS:\n");
	
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("%d  ",ar[i][j]);
        }
        printf("\n");
    }
	
	return 0;
}
