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
	int tax;
	int gsal;
	int tded;
	int npay;
}det;
FILE *fp,*ft;
void calc()
{
	int d,h,p;
	d=(det.da/100)*det.bpay;
	h=(det.hra/100)*det.bpay;
	p=(det.pf/100)*det.bpay;
	det.gsal=det.bpay+d+h;
	det.tded=p+det.tax;
	det.npay=det.gsal-det.tded;
}
void add()
{
	fp=fopen("emp.txt","aw");
	printf("Enter New data\n");
	printf("Enter Employee Name:: ");
	gets(det.ename);
	printf("\nEnter Employee No.:: ");
	gets(det.eno);
	printf("\nEnter Basic Salary:: ");
	scanf("%d",&det.bpay);
	fflush(stdin);
	printf("\nEnter DA:: ");
	scanf("%f",&det.da);
	fflush(stdin);
	printf("\nEnter HRA:: ");
	scanf("%f",&det.hra);
	fflush(stdin);
	printf("\nEnter PF:: ");
	scanf("%f",&det.pf);
	fflush(stdin);
	printf("\nEnter Income Tax:: ");
	scanf("%d",&det.tax);
	calc();
	fprintf(fp," %s %s %d %.2f %.2f %.2f %d %d %d %d",det.ename,det.eno,det.bpay,det.da,det.hra,det.pf,det.tax,det.gsal,det.tded,det.npay);
	fclose(fp);
}
void search()
{
	char n[10],a;
	char c=' ';
	printf("Enter the id to be searched:: ");
	scanf("%s",&n);
	fflush(stdin);
	printf("Do you want to modify the data?(Y/N):");
	scanf("%c",&a);
	fflush(stdin);
	fp=fopen("emp.txt","r");
	ft=fopen("temp.txt","w");
	while(c!=EOF)
	{
		fscanf(fp," %s %s %d %.2f %.2f %.2f %d %d %d %d",&det.ename,&det.eno,&det.bpay,&det.da,&det.hra,&det.pf,&det.tax,&det.gsal,&det.tded,&det.npay);
		if(strcmp(det.eno,n)==0)
		{
			printf("found");
			if(strcmp(det.eno,n)==0&&(a=='y'||a=='Y'))
			{
				printf("Enter New data\n");
				printf("Enter Employee Name:: ");
				gets(det.ename);
				printf("\nEnter Employee No.:: ");
				gets(det.eno);
				printf("\nEnter Basic Salary:: ");
				scanf("%d",&det.bpay);
				fflush(stdin);
				printf("\nEnter DA:: ");
				scanf("%f",&det.da);
				fflush(stdin);
				printf("\nEnter HRA:: ");
				scanf("%f",&det.hra);
				fflush(stdin);
				printf("\nEnter PF:: ");
				scanf("%f",&det.pf);
				fflush(stdin);
				printf("\nEnter Income Tax:: ");
				scanf("%d",&det.tax);
			    calc();
			}
		}
		fprintf(ft," %s %s %d %.2f %.2f %.2f %d %d %d %d",det.ename,det.eno,det.bpay,det.da,det.hra,det.pf,det.tax,det.gsal,det.tded,det.npay);
		c=fgetc(fp);
	}
	remove("emp.txt");
	rename("temp.txt","emp.txt");
	fclose(fp);
	fclose(ft);
}
void main()
{
	char ch='Y';
	int n;
	printf("1.Enter Data\n2.Search\n3.Add");
	printf("\nEnter your choice::");
	scanf("%d",&n);
	fflush(stdin);
	switch(n)
	{
		case 1:
		while(ch=='y'||ch=='Y')
		{
			printf("Enter Employee Name:: ");
			gets(det.ename);
			printf("\nEnter Employee No.:: ");
			gets(det.eno);
			printf("\nEnter Basic Salary:: ");
			scanf("%d",&det.bpay);
			fflush(stdin);
			printf("\nEnter DA:: ");
			scanf("%f",&det.da);
			fflush(stdin);
			printf("\nEnter HRA:: ");
			scanf("%f",&det.hra);
			fflush(stdin);
			printf("\nEnter PF:: ");
			scanf("%f",&det.pf);
			fflush(stdin);
			printf("\nEnter Income Tax:: ");
			scanf("%d",&det.tax);
		    calc();
			fp=fopen("emp.txt","aw");
			//fwrite(&det,sizeof(det),1,fp);
			fprintf(fp," %s %s %d %.2f %.2f %.2f %d %d %d %d",det.ename,det.eno,det.bpay,det.da,det.hra,det.pf,det.tax,det.gsal,det.tded,det.npay);
			fclose(fp);
			fflush(stdin);
			printf("\nDo you want to continue(Y/N):");
			scanf("%c",&ch);
			fflush(stdin);
		}
		break;
		case 2:
			search();
			break;
		case 3:
			add();
		default:
			break;	
	}
}
