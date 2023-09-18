#include<stdio.h>
#include <limits.h>/* For INT_MIN */
int main()
{
	short a, n, i, c, posOfFirst, posOfSecond, posOfThird;
	char name[20][20];
	int score[50];
	int first, second, third;
	do
	{
		printf("\n\n1.Enter Scores\n2.Display Score\n3.Find the Top 3 Winners \n4.Exit");
		printf("\n\nEnter Your Choice:: ");
		scanf("%d",&a);
		fflush(stdin);
		switch(a)
		{
			case 1:
				printf("Enter number of elements in the array\n");
    			scanf("%d", &n);
    			fflush(stdin);
    			for (c = 0; c < n; c++)
    			{
					printf("enter Name:");
					for(i=0;(name[c][i]=getchar())!='\n';i++);
					fflush(stdin);		
					name[c][i]='\0'; 
					printf("Enter Score of the candidate %s:",name[c]);
					scanf("%d", &score[c]);
					fflush(stdin);
				}
				break;

			case 2:
				for (c = 0; c < n; c++)
    			{
    				printf("\nName=%s",name[c]);
    				printf("	Score=%d",score[c]);
    			}
				break;
				
			case 3:
				
				if (n < 3) 
				{
        			printf(" Not enough participants ");
        			continue;
        			
    			}
    			third = first = second = INT_MIN;
			    for (i = 0; i < n; i++) 
				{
			        /* If current element is greater than first*/
			        if (score[i] > first) 
					{
			            third = second;
			            second = first;
			            first = score[i];
			            posOfFirst = i;
			        }
			        /* If arr[i] is in between first and second then update second  */
			        else if (score[i] > second) 
					{
			            third = second;
			            second = score[i];
			            posOfSecond = i;
			        }
			        else if (score[i] > third)
			            third = score[i];
			            posOfThird = i;
			    }
			    printf("First place scored by %s securing score of %d\n",name[posOfFirst], first);
			    printf("Second place scored by %s securing score of %d\n",name[posOfSecond], second);
			    printf("Third place scored by %s securing score of %d\n",name[posOfThird], third);
				break;
				
			case 4:
				goto EXIT;
				
			default:
				printf("Invalid");
				fflush(stdin);
				break;
		}
	}while(1);
	EXIT:return 0;
}

