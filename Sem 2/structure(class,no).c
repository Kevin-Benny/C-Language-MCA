#include<stdio.h>
#include<conio.h>
#include<string.h>
struct stud
{
    int rollno, s1, s2, s3, total ;
    char name[10],clas[10] ;
    float avg ;
} s[5] ;
void search(int n)
{
	int i,f=0;
	char choice[20];
	printf("\n\nNAME TO BE SEARCHED:");
	fflush(stdin);
	gets(choice);
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].name,choice)==0)
		{
			printf("\n\nSEARCH FOUND");
			printf("\nCLASS    ROLL.NO         NAME           SUB1    SUB2    SUB3    TOTAL    AVERAGE\n\n") ;
			printf("%s \t %d \t %s \t\t %d \t %d \t %d \t %d \t %.2f \n",
         s[i].clas,s[i].rollno,s[i].name,s[i].s1,s[i].s2,s[i].s3,s[i].total,s[i].avg);
 //        f=1;
		}
	}
//	if(f==0)
	else
	{
		printf("SEARCH NOT FOUND....");
	}


}
void main()
{
    int i, n ;
   system("cls");
   system("color 6");
    printf("ENTER THE NUMBER OF STUDENTS: ") ;
    scanf("%d", &n) ;
    for(i = 0 ; i < n ; i++)
    {
    	printf("\n\nENTER THE CLASS:");
    	fflush(stdin);
    	gets(s[i].clas);
        printf("\n\nENTER THE ROLL.NO : ") ;
        scanf("%d", &s[i].rollno) ;
        printf("\n\nENTER THE NAME: ") ;
        fflush(stdin);
        gets(s[i].name);
        printf("\n\nENTER THE MARKS OF 1 SUBJECT: ") ;
        scanf("%d", &s[i].s1);
        printf("\n\nENTER THE MARKS OF 2 SUBJECT: ") ;
		scanf("\n%d",&s[i].s2);
		printf("\n\nENTER THE MARKS OF 3 SUBJECT: ") ;
		scanf("\n%d",&s[i].s3);
        s[i].total = s[i].s1 + s[i].s2 + s[i].s3 ;
        s[i].avg = s[i].total / 3.0 ;
        system("cls");
    }
    printf("************************************************************************************************************************");
    printf("\nCLASS    ROLL.NO         NAME           SUB1    SUB2    SUB3    TOTAL    AVERAGE\n\n") ;
    for(i = 0 ; i < n ; i++)
    {
        printf("%s \t %d \t %s \t\t %d \t %d \t %d \t %d \t %.2f \n",
         s[i].clas,s[i].rollno,s[i].name,s[i].s1,s[i].s2,s[i].s3,s[i].total,s[i].avg);
    }
    search(n);

    getch() ;
}
