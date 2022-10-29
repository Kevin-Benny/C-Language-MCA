#include <stdio.h>

void readin();
void readout();
void minsThours();
int hoursTmins();
void minsThours();
void display();
void diffrence();
void differenceBetweenTimePeriod();
struct TIME{
   int seconds;
   int minutes;
   int hours;
};



                                 
void readin(struct TIME *start)  //use pointer * if that variable is declared not in the main and in a function
{
	
	printf("\n\nEnter check-in hours and mins:: ");
	printf("\n\nCheck-in hours: ");
	scanf("%d",&start->hours);  // start.hour can be used but since its a pointer it needs -> 
	printf("\n\nCheck-in mins: ");
	scanf("%d",&start->minutes);
	printf("\n\nCheck-in secs: ");
	scanf("%d",&start->seconds);	
}
void readout(struct TIME *stop)
{
	printf("\n\nEnter check-out hours and mins:: ");
	printf("\n\nCheck-out hours: ");
	scanf("%d",&stop->hours);
	printf("\n\nCheck-out mins: ");
	scanf("%d",&stop->minutes);
	printf("\n\nCheck-out secs: ");
	scanf("%d",&stop->seconds);
}

void minsThours(int min)
{
	int h,minute;
	h=min/60;
    minute=min%60;
    printf("\n Hours=%d and Minutes=%i",h,minute);
}
int hoursTmins(struct TIME *diff)
{
	int minutes;
	minutes = diff->hours*60;
	minutes = minutes + diff->minutes;
	return minutes;
}

void display(struct TIME *start,struct TIME *stop,struct TIME *diff)
{
	printf("Check-in time - %d:%d:%d\n",start->hours,start->minutes,start->seconds);
	printf("Check-out time- %d:%d:%d\n",stop->hours,stop->minutes,stop->seconds);
	printf("Difference time- %d:%d:%d\n",diff->hours,diff->minutes,diff->seconds);
}

void diffrence()
{
	
}

void differenceBetweenTimePeriod(struct TIME *start,struct TIME *stop,struct TIME *diff) 
{
   while (stop->seconds > start->seconds) 
   {
      --start->minutes;
      start->seconds += 60;
   }
   diff->seconds = stop->seconds - start->seconds;
   while (stop->minutes > start->minutes) 
   {
      --start->hours;
      start->minutes += 60;
   }
   diff->minutes = stop->minutes - start->minutes;
   diff->hours = stop->hours - start->hours;
   
   //if diffrence comes in negative, below code corrects it
   if(diff->seconds<0)
   {
   	diff->seconds = 60 + diff->seconds;
   	diff->minutes = diff->minutes -1;
   }
   if(diff->minutes<0)
   {
   	diff->minutes = 60 + diff->minutes;
   	diff->hours = diff->hours -1;
   }
   if(diff->hours<0)
   {
   	diff->hours = diff->hours + 24;
   }
}

int main()
{
	struct TIME startTime, stopTime, diff;
	
	int i=0,t=1,a; //menu needed variables
	int minutes = 0;
	while(t==1)
	{
		printf("\n1.Read Login time and Log out time\n2.convert the time in hh and mm format to minutes\n3.convert the minutes into hh and mm format\n4.display\n5.Exit");
		printf("\n\nEnter Your Choice:: ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				readin(&startTime);
				readout(&stopTime);
				differenceBetweenTimePeriod(&startTime, &stopTime, &diff);
//				printf("\n\nEnter check-in hours and mins:: ");
//				printf("\n\nCheck-in hours: ");
//				scanf("%d",&startTime.hours);  // start.hour can be used but since its a pointer it needs -> 
//				printf("\n\nCheck-in mins: ");
//				scanf("%d",&startTime.minutes);
//				printf("\n\nEnter check-out hours and mins:: ");
//				printf("\n\nCheck-in hours: ");
//				scanf("%d",&stopTime.hours);
//				printf("\n\nCheck-in mins: ");
//				scanf("%d",&stopTime.minutes);
				break;
					
			case 2:
				minutes = hoursTmins(&diff);
				printf("To time in minutes:",minutes);
				break;
				
			case 3:
				minsThours(minutes);
				break;
				
			case 4:
				display(&startTime,&stopTime,&diff);
				break;
					
			case 5:
				t=0;
				break;
				
			default:
				printf("Invalid");
				fflush(stdin);			
			
		}
	}
	return 0;
}

