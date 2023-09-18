#include <stdio.h>
void readin();
void readout();
struct Employee
{
	int roll_no;
	char grade;
	float marks[3];	
	//int *prime=(int *) malloc(x*sizeof(int));	
};

void readin(struct Employee *student)  //use pointer * if that variable is declared not in the main and in a function
{
	
	printf("\n\nEnter Details:: ");
	printf("\n\nRoll No of student: ");
	scanf("%d",&student->roll_no);  // start.hour can be used but since its a pointer it needs -> 
	printf("\n\nGrade of student: ");
	fflush(stdin);
	scanf("%c",&student->grade);+
	printf("\n\nMarks of student: ");
	scanf("%f %f %f",&student->marks[0],&student->marks[1],&student->marks[2]);
//	printf("\n\nCheck-in mins: ");
//	scanf("%d",&start->minutes);	
}

void display(struct Employee *student)
{
	printf("Roll No of student: %d\n",student->roll_no);
	printf("Grade of student: %c\n",student->grade);
	printf("Marks of student: %.2f %.2f %.2f\n",student->marks[0],student->marks[1],student->marks[2]);
//	printf("Difference time- %d:%d:%d\n",diff->hours,diff->minutes,diff->seconds);
}


int main()
{	
	//struct TIME startTime, stopTime, diff;
	struct Employee student[30];
	readin(&student[0]);
	//readin(&student[1]);
	display(&student[0]);
}


