#include<stdio.h>
#include<stdlib.h>
void main()
{
    int loop = 1, sw;
    do
    {
    printf("\n1.sum of digits of a given integer until the sum yields a single digit and check whether the resulting single digit is an even or an odd number");
    printf("2.Accept a number and print the sum of the given and Reverse number");
    printf("3. Exit\n_");
    scanf("%d",&sw);
    switch(sw)
    {
    case 1:
        {
            int n, value=1, sum=0;
            printf("Enter the numbers, -1 to exit:");
            while(value!=-1){
                scanf("%d",&value);
                sum=sum+value;
            }
            printf("Sum is:");
            scanf("%d",&sum);
            //while(n>0){d=n%10;}
            break;
        }
    case 2:
        {
            int r=0,n,sum=0,d;
            printf("Enter the number:");
            scanf("%d",&n);
            while(n>0)
            {
            d=n%10;
            sum=sum+d;
            r=(r*10)+d;
            n=n/10;
            }
            printf("\n sum of digits= %d",sum);
            printf("\n Reverse=%d",r);
            printf("\n");
            break;
        }
    case 3:
        {
            loop = 0;
            break;
        }
    default:
        {
            printf("Caught you");
        }
    }
    }while(loop==1);
}

