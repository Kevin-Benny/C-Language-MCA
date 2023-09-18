#include<stdio.h>
#include<conio.h>
int j,a[15],i,temp,n;
void main()
{
	//clrscr();
	void createheap(int);
	printf("Enter number of elements\n(Not more than 15)");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=n;i>=2;i--)
	createheap(i);
	for(i=n-1;i>=1;i--)
	{
		temp=a[1];
		a[1]=a[i+1];
		a[i+1]=temp;
		for(j=i;j>=2;j--)
		createheap(j);
	}
	printf("The sorted elements are :\n");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	getch();
}
void createheap(int y)
{
	if(y>1)
	{
		if(a[y]>a[y/2])
		{
			temp=a[y];
			a[y]=a[y/2];
			a[y/2]=temp;
			createheap(y/2);
		}
	}
}