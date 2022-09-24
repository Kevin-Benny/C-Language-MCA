#include<stdio.h>
#include<string.h>
#include<conio.h>

char sentence[200],word[100];
int i,n;

void enter_sen()
{
	printf("enter the sentence: ");
	fflush(stdin);
	fgets(sentence, 500, stdin);
	printf("%s",sentence);
}

void sen_length()
{
	n=0;
	for (i=0;i<200;i++)
	{
		if (sentence[i]!='\0' && sentence[i]!=' ')
		{
			n++;
		}
	}	
	printf("there are %d characters in the sentence.\n",(n-1));
}

void sen_words()
{
	int count=0;
	n=0;
	for (i=0;i<200;i++)
	{
		if (sentence[i]!='\0')
		{
			n++;
		}
	}
	
	for (i=0;i<n;i++)
	{
		if (sentence[i]==' ')
		{
			count++;
		}
	}
	printf("there are %d words in the sentence.\n",(count+1));
}

int word_present(char* sentence, char* word) {

	int i=0, j, flag, s_len, w_len;
	s_len = strlen(sentence);
	w_len = strlen(word);

	if ( w_len> s_len)
		return 0; //word length cannot be more than string length

	while (i < s_len) {

		// checking if the current word in sentence
		// is equal to word or not
		j = 0;
		while (i < s_len && j < w_len && sentence[i] == word[j]) {
			++i;
			++j;
		}

		// j == w_len signifies that current word is equal to word
		// Therefore, word is present in sentence, thus we return 1 (true)
		if (( i == s_len || sentence[i] == ' ') && j == w_len)
			return 1;

		// if j != m then the current word in sentence is not
		// equal to word
		// thus, we move to the next word
		while (i < s_len && sentence[i] != ' ') {
			++i;
		}
		++i;

	}

	// reaching this step means 
	// no match was found 
	// return false
	return 0;

}

void vowel_count()
{
	n=0;
	int count=0;
	for (i=0;i<200;i++)
	{
		if (sentence[i]!='\0')
		{n++;
		//printf("there are %d alphabets in the sentence.",n);
		}
	}
	
	for (i=0;i<n;i++)
	{
		if (sentence[i]=='a' || sentence[i]=='A'
		|| sentence[i]=='e' || sentence[i]=='E'
		|| sentence[i]=='i' || sentence[i]=='I'
		|| sentence[i]=='o' || sentence[i]=='O'
		|| sentence[i]=='u' || sentence[i]=='U')
		{
			count++;
		}
	}
	printf("there are %d vowels in the sentence.",count);
}

int word_count()
{
   int i, j, ls, lw, temp, countW=0, chk;
   printf("Enter a Word: ");
   fflush(stdin);
   fgets(word, 500, stdin);
   ls = strlen(sentence);
   lw = strlen(word);
   for(i=0; i<ls; i++)
   {
      temp = i;
      for(j=0; j<lw; j++)
      {
         if(sentence[i]==word[j])
            i++;
      }
      chk = i-temp;
      if(chk==lw)
         countW++;
      i = temp;
   }
   printf("\nnumber of occurrence = %d", countW);
   getch();
   return 0;
}

void main()
{
	{ int choice, choice1;
	printf("\n_______________________________________________________________________________\n");
	printf("***		1) Find the length of the sentence                          ***\n");
	printf("***		2) Find number of words in the sentence                     ***\n");
	printf("***		3) To check whether a given word is present in the sentence ***\n");
	printf("***		4) To display the count of vowels in the sentence           ***\n");
	printf("***		5) To display the count of each word in the sentence        ***\n");
	printf("***		6) Exit                                                     ***\n");
	printf("_______________________________________________________________________________\n");
	scanf("\n%d",&choice);
	
	switch(choice){
		
		case 1:
			{
				enter_sen();
				sen_length();
				
				printf("\nWould you like to continue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();} //if user wishes to continue, go back to main function
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
			
		case 2:
			{
				enter_sen();
				sen_words();
				
				printf("\nContinue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}

		case 3:
			{
				enter_sen();
				printf("enter the word to be checked for: ");
				fflush(stdin);
				fgets(word, 500, stdin);
				if (word_present(sentence,word))
				{
					printf("%s is in the sentence",word);
				}
				else{
					printf("%s is not in the sentence",word);
				}
				
				
				printf("\nContinue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
		case 4:
			{
				enter_sen();
				vowel_count();
				
				printf("\nContinue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
			
		case 5:
			{   
				enter_sen();
				word_count();
				
				printf("\nContinue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
			
			
		case 6:
			{
				printf("\nExit? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==0)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
		default:
			{
				printf("\nEnter a valid choice.");
				printf("\nContinue? (1/0): ");
				scanf("%d",&choice1);
				
				if (choice1==1)
				{main();}
				else
				{
				printf("\nSee you soon!");
				break;}
				break;
			}
	}
}
}
