#include<stdio.h>
#include<math.h>
#include <stdio.h>
#include<strings.h>

union employee
{
	char ename[20];
	char cou[20];
    char id[20];
    int pf;
    int bpay;
    int hra;
    int npay;
}emp;

void getval()
{    
        int totalmark=0;
        printf("Enter Employee Name:");
        fflush(stdin);
        gets(emp.ename);
        printf("Employee Name: %s", emp.ename);
        
        printf("\n\nEnter Department:");
        fflush(stdin);
        gets(emp.cou);
        printf("Department: %s", emp.cou);
        
        printf("\n\nEnter the Id:");
        fflush(stdin);
        gets(emp.id);
        printf("Id: %s\n", emp.id);
        
        printf("\nEnter Provident Fund:");
        scanf("%d", &emp.pf);
        totalmark=totalmark+emp.pf;
        
        printf("\nEnter Basic Salary:");
        scanf("%d", &emp.bpay);
        totalmark=totalmark+emp.bpay;
        
        printf("\nEnter Research Allowance:");
        scanf("%d", &emp.hra);
        totalmark=totalmark+emp.hra;
        
        emp.npay = totalmark;
        printf("\n\nNet pay: %d", emp.npay);
}
int btw()
{
 	int a = 9, b = 65, x=1;
	int no,n,i,y,p;
	char ch;
	do
	{
		printf("\nEnter a number:\n");
		scanf("%d",&n);
		printf("Enter the number of bits to shift to left:\n");
		scanf("%d",&no);
		p = pow(2,n);
		for(i=15;i>=0;i--)
		{
			y=(n<<no);
			printf("%d\n",y);
		}
		printf("After Shifting:\n");
		printf("%d",y);
		printf("\n%d*(2^%d)=%d",n,no,n*p);
		printf("\nDo you want to continue(Y/N):\n");
		fflush(stdin);
		scanf("%c",&ch);
	}	while(ch=='y'|| ch=='Y');
	
	
 printf(" AND a&b = %d \n", a & b);  //AND Operation = a & b,   0001001 & 1000001 = 0000001 = 1
 printf(" OR a|b = %d \n", a | b);  //OR Operation = a || b,    0001001 || 1000001 = 1001001 = 73
 printf(" EXCLUSIVE OR a^b = %d \n", a ^ b);  //Next, Exclusive OR Operation = a ^ b,  0001001 ^ 1000001 = 1001000 = 72
 printf(" NOT ~X  %d \n", ~x); // NOT ~X, 00000001 ~ 11111110, -128-64-32-16-8-4-2 = -2
 printf(" LEFT SHIFT a<<1 = %d \n", b << 1); // Left Shift Operation = a << 1,  1000001 << 1 = 00000101 = 
 printf(" RIGHT SHIFT b>>1 = %d \n", b >> 1);  //Right Shift Operation = b >> 1,  1000001 >> 1 = 0100000 = 32

 return 0;
}                                  

void main()
{
    int cho;
    do
    {
    
    printf("\n**********Employee Details**********");
    printf("\n Choose an option\n1.Employee data\n2.Bitwise Operators\n0.exit\n");
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:
            getval();
            break;
        case 2:
            btw();
            break;
        deafult:
             printf("Invalid input");
    }
    
   }while(cho!=0);
    
}


//#include<stdio.h>
////#include<iostream>
////using namespace std;
///* typedef a function pointer for a function returning int and taking argument as int.
//*/
//typedef int(*pt2Func)(int);
// 
///* function performing square */
//int sqr(int x)
//{
// return(x*x);
//}
///* function returning function pointer pt2Func */
//pt2Func GetPtr(const char Code)
//{
// printf("%c\n",Code);	
// return (*sqr);
//}  
// 
//int main()
//{
//    pt2Func xyz = GetPtr('j');\
//    printf("%d\n",(*xyz)(5));
//    return 0;
//}