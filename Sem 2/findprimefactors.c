#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
 
int main()
{
    int x,div=2;
 
 
    int i=0,j=0;
    printf("Enter Number X : ");
    scanf("%d",&x);
    int num=x;
    int *prime=(int *) malloc(x*sizeof(int));
    printf("\n Allocated \n");
    getch();
    if (x==1 || x==0)
    { printf(" Number %d have no prime Factors",x);
    *prime=0;
    }
    else
    { while(x>1)
    {  if ((x%div)==0)
        { *(prime+i)=div;x=x/div;i++;printf("\n Prime Factor\n");
 
        }
        else
        { div++; }
 
    }
 
 
    }
 
    printf("\n The Prime Factors for Number %d are  :\n",num);
 
    for(j=0;j<i;j++)
 
    { printf (" %d ",*(prime+j));   }
 
    return(0);
}