#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct emp
{
	char ename[20];
	char eno[10];
	int bpay;
	float da;
	float hra;
	float pf;
	float pt;
	float ra;
	int tax;
	int all;
	int gsal;
	int tded;
	int npay;
}det[5];
static int arrayno = 0;
int calc(int i)
{
	int d,h,pfpt,a;
	d=(det[i].da/100)*det[i].bpay;
	h=(det[i].hra/100)*det[i].bpay;
	a= h + d + det[i].ra;
	pfpt=det[i].pf+det[i].pt;
	det[i].all = a;
	det[i].gsal=det[i].bpay+d+h+det[i].ra;
	det[i].tded=pfpt+det[i].tax;
	det[i].npay=det[i].gsal-det[i].tded;
	return 0;
}
typedef int(*pt2Func)(int); 
pt2Func add(int i)
{
	printf("Enter New data\n");
	fflush(stdin);
	printf("Enter Employee Name:: ");
	gets(det[i].ename);
	fflush(stdin);
	printf("\nEnter Department:: ");
	gets(det[i].eno);
	printf("\nEnter Basic Salary:: ");
	scanf("%d",&det[i].bpay);
	printf("\nEnter Dearness Allowance(Default:15%):: ");
	scanf("%f",&det[i].da);
	printf("\nEnter House rent allowance(Default:10%):: ");
	scanf("%f",&det[i].hra);
	printf("\nEnter Research Allowance(Default:2700):: ");
	scanf("%f",&det[i].ra);
	printf("\nEnter Provident Fund(Default:2000):: ");
	scanf("%f",&det[i].pf);
	printf("\nEnter Professional Tax(Default:300):: ");
	scanf("%f",&det[i].pt);
	printf("\nEnter Income Tax(Default:100):: ");
	scanf("%d",&det[i].tax);
	return (*calc);
}
void display(int i)
{
	printf("Employee Data->");
	printf("\nEmployee Name:: %s",det[i].ename);
	printf("\nEmployee Department:: %s",det[i].eno);
	printf("\nSalary:: %d",det[i].bpay);
	printf("\nTotal Allowance:: %d",det[i].all);
	printf("\nTotal Deductions:: %d",det[i].tded);
	printf("\nTotal pay(Basic pay+Allowance):: %d",det[i].gsal);
	printf("\nNet pay(Basic pay+Allowance-Deduction):: %d\n",det[i].npay);
}
void search()
{
	char n[10],a;
	int arraysize = 0,found=0;
	
	printf("Enter the id to be searched:: ");
	scanf("%s",&n);
	fflush(stdin);
	printf("Do you want to modify the data?(Y/N):");
	scanf("%c",&a);
	fflush(stdin);
	while(arraysize != arrayno+1)
	{
		if(strcmp(det[arraysize].ename,n)==0)
		{
			if(a=='y'||a=='Y')
			{
				add(arraysize);
			    calc(arraysize);
			    found=1;
			    
			}
			display(arraysize);//pass n
		}
		else if(found==1&&arraysize == arrayno)
		{
			printf("Name not found!");
		}
		arraysize++;
	}
}
void main()
{
	char ch='Y';
	int n;
	printf("\n1.Enter Data\n2.Search and Display, Modify\n3.display All\n4.exit");
	printf("\nEnter your choice::");
	scanf("%d",&n);
	fflush(stdin);
	switch(n)
	{
		case 1:
			if(arrayno<5)
			{
				pt2Func add_calc = add(arrayno);
				//add(arrayno);
				(*add_calc)(arrayno);
				arrayno++;
			}
			else
			{
				printf("All structure array full\n");
			}
			main();
		break;
		case 2:
			search();
			main();
			break;
		case 3:
			for(int i=0;i<arrayno;i++)
			{
				display(i);
			}
			main();
		case 4:
			break;
			
		default:
			printf("Invalid entry\n");	
			main();
	}
}



