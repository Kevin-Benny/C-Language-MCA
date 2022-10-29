#include<stdio.h>
struct candi
{
	int roll_no;
	char grade;
	float marks[4];		
//}st[3]; global declaration does work
};
void display(struct candi a1)
{
	printf("Roll number:%d\n",a1.roll_no);
	printf("grade:%c\n",a1.grade);
	int len = sizeof(a1.marks)/sizeof(float);
	int i;
	printf("Marks=");
	for(i=0;i<len;i++)
	{
		printf("subject %d:%.2f\n",i+1,a1.marks[i]);
	}
}
int main()
{
	struct candi st[3];
	int i;
	for(i=0;i<3;i++)
	{    
		st[i]={1,'A',98.5, 77,88.5,78.5};
	}
	display(st[1]);
	return 0;
}



//struct candi
//{
//	int roll_no;
//	char grade;
//	float marks[4];	
//};
//
//void display(struct candi a1)
//{
//	printf("Roll number:%d\n",a1.roll_no);
//	printf("grade:%c\n",a1.grade);
//	int len = sizeof(a1.marks)/sizeof(float);
//	int i;
//	printf("Marks=");
//	for(i=0;i<len;i++)
//	{
//		printf("subject %d:%.2f\n",i+1,a1.marks[i]);
//	}
//}
//int main()
//{
//	struct candi A={1,'A',{98.5, 77,88.5,78.5}};
//	display(A);
//	return 0;
//}



