#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//float si(int i);
//float ci(int i);
void arms();
void strreverse();
int main()
{
	int i=0,a=0,t=1;
	char ch='Y';
	while(t)
	{
	printf("\n1.Armstrong no. \n2.Print reversal of given string and number\n3.Exit");
	printf("\n\nEnter Your Choice:: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:{
			arms();
	        fflush(stdin);
			break;
		}
		case 2:{
			strreverse();
			break;
		}
		case 3:{
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

void arms()
{
	int l, h, i, c1, c2, remainder, n = 0, result = 0;
        printf("Enter two numbers(intervals): ");
        scanf("%d %d", &l, &h);
        printf("Armstrong numbers between %d an %d are: ", l, h);
        // why is 153 not a displaying, refer armstrong
        for(i =l; i < h; ++i)
        {
            c2 = i;
            c1 = i;
            while (c1 != 0)
            {
                c1 = c1/10;
                n++;
            }
            while (c2 != 0)
            {
                remainder = c2 % 10;
                result =result+pow(remainder, n);
                c2 /= 10;
            }
            if (result == i) {
                printf("%d ", i);
            }
            n = 0;
            result = 0;
        }
	fflush(stdin);
}
void strreverse()
{
	//string reverse
	char str[100],outstr[10];
	int ii=0,jj=0,flag=0;
	do
	{
	fflush(stdin);
	printf("enter char:");
	str[jj]=getchar();
	}
	while(str[jj++]!='\n');
	str[jj-1]='\0'; 
	printf("\n string=%s",str);
	do
	{
    outstr[ii]=str[jj-2];
    jj--;
    ii++;
	}
	while(jj!=0);
	outstr[ii-1]='\0'; 
	printf("\n string=%s",outstr);
	
	//number reverse
	int i,d,rev=0,a;
	printf("\nENTER A NUMBER ");
	scanf("%d",&a);
	for(i=a;i!=0;i=i/10)
	{
		d=i%10;
		rev=rev*10+d;
	}
	d=125/10;
	printf("REVERSE OF ");
	printf("%d",a);
	printf(" is ");
	printf("%d",rev);
	printf("\n%d",d);
	fflush(stdin);
}
