#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
FILE *fptr;
struct dish{
	char d_name[30];
	int count;
	char ing[20][30];
	int ing_qty[20];
	char desp[100];
}d[10];
void get_data(){
	int i,j;
	for(i=0;i<n;i++){
		printf("\nName: ");
		scanf(" ");
		gets(d[i].d_name);
		printf("\nIngredients count: ");
		scanf("%d",&d[i].count);
		printf("\nIngredients Details: \n");
		for(j=0;j<d[i].count;j++)
		{
			printf("\nIngredients %d: ",j+1);
			scanf(" ");
			gets(d[i].ing[j]);
		}
		for(j=0;j<d[i].count;j++)
		{
			printf("\nQuantity of %s: ",d[i].ing[j]);
			scanf("%d",&d[i].ing_qty[j]);
		}
		printf("\nDescription: ");
		scanf("  ");
		gets(d[i].desp);
	}
}
void put_file(){
	fptr = fopen("dishes.txt","w");
	if(fptr == NULL)
	{
		printf("\nFile not opened");
		exit(0);	
	}
	fwrite(&d,sizeof(struct dish),n,fptr);
	if(fwrite){
		printf("\nSuccessful!");
	}
	else
	{
		printf("\nNot Successful");
	}
	fclose(fptr);
}
void sort_data(){
	int i,j;
	fptr = fopen("dishes.txt","r");
	fread(&d,sizeof(struct dish),n,fptr);
	struct dish temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(d[i].d_name,d[j].d_name)>0){
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
	fclose(fptr);
	fptr = fopen("dishes2.txt","w");
	fwrite(&d,sizeof(struct dish),n,fptr);
	fclose(fptr);
	print_data();
}
void print_data(){
	int i,j;
	fptr = fopen("dishes2.txt","r");
	fread(&d,sizeof(struct dish),n,fptr);
	for(i=0;i<n;i++){
		printf("\n\nDish %d details",i+1);
		printf("\n\nDish Name: %s",d[i].d_name);
		printf("\nIngredients:");
		for(j=0;j<d[i].count;j++)
		{
			printf("\nIngredients %d is %s: ",j+1,d[i].ing[j]);
		}
		for(j=0;j<d[i].count;j++)
		{
			printf("\nQuantity of %s is : %d",d[i].ing[j],d[i].ing_qty[j]);
		}
		printf("\nDescription: %s",d[i].desp);
	}
	fclose(fptr);
}
void sum_qty(){
	int i,j,sum=0;
	fptr = fopen("dishes2.txt","r");
	fread(&d,sizeof(struct dish),n,fptr);
	for(i=0;i<n;i++){
		sum=0;
		for(j=0;j<d[i].count;j++){
			sum+=d[i].ing_qty[j];
		}
		printf("\nSum of Quantity of %s is %d",d[i].d_name,sum);
	}
	fclose(fptr);
}
int main(){
	int op;
	char ch='y';
	printf("\nEnter total no. of Dishes: ");
	scanf("%d",&n);
	while(ch=='y'){
		system("cls");
		printf("\n1) Enter Dish Details");
		printf("\n2) Store in File");
		printf("\n3) Sort the Dish");
		printf("\n4) Sum the quantity");
		printf("\n5) Print Dishes");
		printf("\n6) Exit");
		printf("\nEnter your option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				get_data();
				break;	
			case 2:
				put_file();
				break;
			case 3:
				sort_data();
				break;
			case 5:
				print_data();
				break;
			case 4:
				sum_qty();
				break;
			case 6: exit(0);
			default:printf("\nWrong Option");
		}
		printf("\nGo back to main menu?(y/n): ");
		scanf(" %c",&ch);
	}
}
