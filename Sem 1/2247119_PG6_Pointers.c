#include <string.h>
#include <stdio.h>
#include <conio.h>
void concat(char *first_string, char* second_string)
{
	int i;
	for(i=0;first_string[i]!='\0';i++);   //since indexed no pointer required like while (*first_string){*(first_string++) == '0'};
    for(int j=0;second_string[j]!='\0';j++)  
    {  
        first_string[i]=second_string[j];  
        i++;  
    }  
    first_string[i]='\0';  
//    for (size_t i = 0; i < strlen(first_string); i++) 
//	{
//    	printf("myString[%lu] = %c\n", i, first_string[i]);
//  	}
//    printf("After concatenation, the string would look like: %s", first_string);  
    //return *first_string;  thiss step is not required because of pointer string
}
char enterAlphabets(char* str)
{
	printf("Enter String\n");
	int j=0;
	char word[100];	
    fflush(stdin);
	fgets(str, 500, stdin);
	strcpy(word,str);
	return *word;    //IF char* enterAlphabet() used then use return word;
	//return *str;   //returning a string this is not required since its pointer to str in main but if function defined then cant
}
char countVandC(char* str)
{
	printf("String: %s\n", str);
	int i,j;
	char *p, c;
    int  vCount=0,cCount=0,sCount = 0;
    p=str;
    char first_string[100]="Result:";
    while(*p!='\0')                         
    {
        if(*p=='A' ||*p=='E' ||*p=='I' ||*p=='O' ||*p=='U' ||*p=='a' ||*p=='e' ||*p=='i' ||*p=='o' ||*p=='u')
        {
          vCount++;
          c = *p;
          concat(first_string," V-");
          strcat(first_string,&c); 
    	}
    	
    	else if(*p==' ' ||*p==',' ||*p=='.'||*p=='%' ||*p=='&' ||*p=='!' ||*p=='?' ||*p=='@' ||*p=='-' ||*p=='_')
    	{
    		sCount++;
    		c = *p;
    		strcat(first_string," S-");
          	concat(first_string,&c); 
          	fflush(stdin);
		}
        else
        {
        	cCount++;
        	c = *p;
        	concat(first_string," C-");
          	concat(first_string,&c); 
    	}
        //increase the pointer, to point next character
        p++;
        
    }
    printf("%s\n", first_string);
    printf("Number of Vowels in String: %d\n",vCount);
    printf("Number of Consonants in String: %d\n",cCount-1);
    printf("Number of Special char in String: %d\n",sCount);
    return 0;  //doesnt work  
}
          

int printalpha()
{
	char alph[27];
	int x;
	char *ptr;
	printf("\n Pointer : Print all the alphabets:\n");
	printf("----------------------------------------\n");
	ptr = alph;    
	for(x=0;x<26;x++)
	{
		*ptr=x+'A';
		ptr++;
	}
	ptr = alph;
	printf(" The Alphabets are : \n");
	for(x=0;x<26;x++)
	{
		printf(" %c ", *ptr);
		ptr++;
	}
	return 0;
}

int rev_string()
{
	int len = 0,i = 0;
	char str[100],strev[100];
	char *sptr;
	char *rsptr;
	sptr = str;
	rsptr = strev;
	printf("\n------------------String reverse-------------------\n");
	printf("\nEnter a string: ");
	fflush(stdin);
	gets(str);
	while(*sptr!='\0')
	{
	    len++;
	    sptr++;
	}
	sptr = sptr-1;
	while(len>=0)
	{
	    *rsptr = *sptr;
	    sptr--;
	    rsptr++;
	    len--;
	}
	sptr = str;
	rsptr = strev;
	printf("reversed string is\n%s",strev);
	return 0;
}

int main()
{
	int choice;
	char str[100] = "hello";
	char str2[100];
	
	char(*ptr[2])(char*) = {enterAlphabets,countVandC}; 
	do{
		printf("\n\n--------Menu-------------");
		printf("\n1.Printing Alphabets\n2.Printing Vowels and Consonents\n3.Reverse of String\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printalpha();
				break;
			case 2:
				//i=(*ptr[0])(); //first funtion call
				*str2 = (*ptr[0])(str); //dont have to do  str[100] = (*ptr[0])(str); even tho for the next line we need the new str from this function
				(*ptr[1])(str);
				printf("Result: %s\n", str2);  //only first letter will be displayed because function return one char of string. best is pass pointer of string that is in main
				break;        
			case 3:        
				rev_string();
				break;
			default:
			printf("\nExiting");
		}
	}while(choice != 4);
}





//#include <stdio.h>
//char enterAlphabets()
//{
//	char str[100];
//	printf("Enter any string: ");
//    fgets(str, 100, stdin);
//	return str;
//}
//int countVandC(int (*ptr)(char str))
//{
//	char *p;
//    int  vCount=0,cCount=0;
//    p=str;
//    while(*p!='\0')
//    {
//        if(*p=='A' ||*p=='E' ||*p=='I' ||*p=='O' ||*p=='U'
//        		||*p=='a' ||*p=='e' ||*p=='i' ||*p=='o' ||*p=='u')
//            vCount++;
//        else
//            cCount++;
//        //increase the pointer, to point next character
//        p++;
//    }
//	return (*ptr)(vCount);
//}
//
//int main()
//{
//	printf("Number of Vowels in String: %c",countVandC(printAlphabets()));
//	return 0;	
//}