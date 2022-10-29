#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float a[20],t[20];
int n=0;
float si(int i);
float ci(int i);
void cdet();
void disp();
int main()
{
	int i=0,a=0,t=1;
	char ch='Y';
	printf("Enter array size:: ");
	scanf("%d",&n);
	while(t)
	{
	printf("\n1.Enter the values\n2.Display Deatails\n3.Do multiplication\n4.Exit");
	printf("\n\nEnter Your Choice:: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:{
			input();
	        fflush(stdin);
			break;
		}
		case 2:{
			disp();
			break;
		}
		case 3:{
			for(i=0;i<n;i++)
			{
			printf("Subration of the two arrays %d = %.2f",i+1,c[i]-s[i]);
			}
			fflush(stdin);
			break;
		}
		case 4:{
			exit(0);
		}
		default:{
			printf("Invalid");
			fflush(stdin);
			break;
		}
	}
	printf("\n\nDo you want to continue(1/0):: ");
	scanf("%d",&t);
}
	return 0;
}
float si(int i)
{
	return (p[i]*t[i]*r[i])/100;
}
float ci(int i)
{
	return (p[i]*(pow((1+r[i]/100),t[i])));
}
void input()
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("\n\n\nEnter value of  %d position:: ",i+1);
	    scanf("%d",&a[i]);
	    printf("\nEnter Principle Amount:: ");
	    scanf("%f",&p[i]);

	    s[i]=si(i);
	    c[i]=ci(i);
	    printf("\nSimple Interest:: %.2f",s[i]);
	    printf("\n\nCompound Interest:: %.2f",c[i]);
	}
	fflush(stdin);
}
void disp()
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("\n\n__________________________________");
		printf("\nCustomer %d Number:: %d",i+1,cn[i]);
	    printf("\nPrinciple Amount:: %.2f",p[i]);
	    printf("\nNumber of Years:: %.2f",t[i]);
	}
	fflush(stdin);
}
