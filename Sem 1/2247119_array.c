#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	char c;
	int j,i,size=0;
	int *ptr;
	do{
		system("cls");
		printf("/********************/\n");
		printf("/ 1. Read\t     /\n/ 2. Display\t     /\n/ 3. Highest Number  /\n/ 4. Smallest Number /\n/ 5. IsRepeated      /\n/ 6. Repeated Count  /\n/ 7. Repeated \t     /\n/ 8. Exit \t     /");
		printf("\n/********************/");
		printf("\n\nEnter your choice : ");
		c = getche();
		switch(c){
			case '1':{
				printf("\n\nEnter size of array : ");
    			scanf("%d",&size);
    			if(ptr==NULL){
    				ptr = (int*)malloc(size * sizeof(int));
				}
				else{
					ptr = realloc(ptr, size * sizeof(int));
				}
    			if (ptr == NULL) {
			        printf("Memory not allocated. An error occured.\n");
			        exit(0);
			    }
			    else {
			        for(i=0;i<size; i++) {
			            printf("\nEnter %d element : ",i+1);
			            scanf("%d",&ptr[i]);
			        }
			    }
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '2':{
				if(size!=0){
					printf("\n\nThe elements of the array are: ");
					printf("[ %d",ptr[0]);
				    for (i=1; i<size; i++) {
				        printf(", %d", ptr[i]);
				    }
				    printf(" ]");
				}
			    else {
			    	printf("\nArray is empty. Please input first.");
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '3':{
				if(size!=0){
					int max=0;
				    for (i=0; i<size; i++) {
				        if(ptr[i]>max){
				        	max=ptr[i];
						}
				    }
				    printf("\n\nHighest Number : %d",max);
				}
			    else {
			    	printf("\nArray is empty. Please input first.");
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '4':{
				if(size!=0){
					int min=ptr[0];
				    for (i=1; i<size; i++) {
				        if(ptr[i]<min){
				        	min=ptr[i];
						}
				    }
				    printf("\n\nSmallest Number : %d",min);
				}
			    else {
			    	printf("\nArray is empty. Please input first.");
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '5':{
				if(size!=0){
					int a;
					printf("\n\nEnter the element to be checked : ");
					scanf("%d",&a);
					for (i=0; i<size; i++) {
				        if(a==ptr[i]){
				        	printf("\nYes %d is repeated.",a);
				        	break;
						}
				    }
				}
			    else {
			    	printf("\nArray is empty. Please input first.");
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '6':{
				if(size!=0){
					int a,ctr=0;
					printf("\n\nEnter the element to be checked : ");
					scanf("%d",&a);
					for (i=0; i<size; i++) {
				        if(a==ptr[i]){
				        	ctr++;
						}
				    }
				    printf("\nCount of %d : %d",a,ctr);
				}
			    else {
			    	printf("\nArray is empty. Please input first.");
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '7':{
				int *temp;
  				int count = 0;
  				if(temp==NULL){
    				temp = (int*)malloc(size * sizeof(int));
				}
				else{
					temp = realloc(ptr, size * sizeof(int));
				}
				for(i=0; i<size; i++) {         
				  int element = ptr[i];
				  int flag = 0;
				  int c=0;
				  // check current element is already 
				  // checked or not
				  for(j=0; j<count; j++) {
				    if(temp[j] == element) {
				      flag = 1;
				      break;
				    }
				  }      
				  // if already exist then don't check
				  if(flag) {
				    continue;
				  }   
				  // check occurrence of element
				  for(j=i+1; j<size; j++) {
				    if(ptr[j] == element) {
				      temp[count++] = element;
				      c++;
				    }
				  }
				  if(c>0)
				  printf("\n%d is repeated %d times.",element,c+1);
				}
				printf("\n\nPress any key to continue.");
				getch();
				break;
			}
			case '8':{
				printf("\n\n Exiting");
				for(j=0;j<5;j++)
				{
					Sleep(300);
					printf(".");
				}
				printf("Thank You");
				break;
			}
			default:{
				printf("Invalid Choice. Please try again.");
				break;
			}
		}
	}while(c!='8');
	free(ptr);
	return 0;
}
