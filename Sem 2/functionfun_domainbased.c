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
}det[6];
FILE *fp,*ft;
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
	fp=fopen("emp.txt","aw");
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
	fprintf(fp," %s %s %d %.2f %.2f %.2f %d %d %d %d",det[i].ename,det[i].eno,det[i].bpay,det[i].da,det[i].hra,det[i].pf,det[i].tax,det[i].gsal,det[i].tded,det[i].npay);
	calc(i);
	fclose(fp);
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
int searchfromfile()
{
	int count = 0;
	fp=fopen("emp.txt","r");
	ft=fopen("temp.txt","w");
	char n[10],a;
	char c=' ';
	printf("Enter the name to be searched:: ");
	scanf("%s",&n);
	fflush(stdin);
	printf("Do you want to modify the data?(Y/N):");
	scanf("%c",&a);
	fflush(stdin);

	while(c!=EOF)
	{
		count++;
		fscanf(fp," %s %s %d %.2f %.2f %.2f %d %d %d %d",&det[5].ename,&det[5].eno,&det[5].bpay,&det[5].da,&det[5].hra,&det[5].pf,&det[5].tax,&det[5].gsal,&det[5].tded,&det[5].npay);
		if(strcmp(det[5].ename,n)==0)
		{
			printf("\nName found in data - %d\n",count);
			if(strcmp(det[5].ename,n)==0&&(a=='y'||a=='Y'))
			{
				printf("Enter New data\n");
				printf("Enter Employee Name:: ");
				gets(det[5].ename);
				printf("\nEnter Employee No.:: ");
				gets(det[5].eno);
				printf("\nEnter Basic Salary:: ");
				scanf("%d",&det[5].bpay);
				fflush(stdin);
				printf("\nEnter DA:: ");
				scanf("%f",&det[5].da);
				fflush(stdin);
				printf("\nEnter HRA:: ");
				scanf("%f",&det[5].hra);
				fflush(stdin);
				printf("\nEnter PF:: ");
				scanf("%f",&det[5].pf);
				fflush(stdin);
				printf("\nEnter Income Tax:: ");
				scanf("%d",&det[5].tax);
			}
		}
		else
		{
			printf("\nName not found in data - %d\n",count);
		}
		fprintf(ft," %s %s %d %.2f %.2f %.2f %d %d %d %d",det[5].ename,det[5].eno,det[5].bpay,det[5].da,det[5].hra,det[5].pf,det[5].tax,det[5].gsal,det[5].tded,det[5].npay);
		c=fgetc(fp);
		remove("emp.txt");
		rename("temp.txt","emp.txt");
		fclose(fp);
		fclose(ft);
	}
	calc(5);
	return 0;
}
int search()
{
	char n[10],a;
	int arraysize = 0,found=0;
	char c=' ';
	printf("Enter the name to be searched:: ");
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
	return 0;
}
void main()
{
	char ch='Y';
	int n;
	printf("1.Enter Data\n2.Search\n3.Display\n4.search from file\n5.exit");
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
				//(*add_calc)(5);
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
			searchfromfile();
			main();
			break;
		case 5:
			break;	
			
		default:
			printf("Invalid entry\n");	
			main();
	}
}

