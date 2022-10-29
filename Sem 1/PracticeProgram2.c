#include<stdio.h>
void main()
{
    //P1
        int a,b,c;
    printf("Enter the 3 no\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a==c)
            printf("\n%d is the largest and %d is the second largest",a,b);
        else if (b>c)
            printf("\n%d is the largest and %d is the second largest",a,b);
        else
        {
            if(a>c)
                printf("\n%d is the largest and %d is the second largest",a,c);
            else if(c>a)
                printf("\n%d is the largest and %d is the second largest",c,a);
        }
    }
    else
    {
        if((a==b)&&(c!=a)&&(c<a))
            printf("\n%d is the largest and %d is the second largest",b,c);
        else if((b==c)&&(c!=a))
            printf("\n%d is the largest and %d is the second largest",b,a);
        else if((a>c)&&(b!=a))
            printf("\n%d is the largest and %d is the second largest",b,a);
        else
        {
            if(b>c)
                printf("\n%d is the largest and %d is the second largest",b,c);
            else if(a<b)
                printf("\n%d is the largest and %d is the second largest",c,b);
            else if(c>a)
                printf("\n%d is the largest and %d is the second largest",c,a);
            else if(a=b=c)
                printf("\n%d is the largest",c);
        }
    }

    //P2
    int n,se,so,u,cc;
	 printf("\n\nEnter the number : ");
     scanf("%d",&n);
     se=0;
     so=0;
     while(n!=0)
    {
	   u=n%10;

      if(cc%2==0)
      se=se+u;

      else
      so=so+u;

      n=n/10;
      cc++;
	}
      printf("\nThe sum of odd values are : %d",so);
      printf("\nThe sum of even values are : %d",se);
    if(so>se)
      printf("\nSum of odd digits is greater than sum of even digits");
    else if(se>so)
      printf("\nSum of even digits is greater than sum of odd digits");
    else
     printf("\nSum of odd digits is equal to sum of even digits");

    //P3
    int p=10,q=20;
    printf("\n\nBefore a=%d b=%d",p,q);
    p=p+q;
    q=p-q;
    p=p-q;
    printf("\nAfter swap a=%d b=%d",p,q);
    
	//P4
    int phy, chem, bio, math, comp; 
    float per; 

    /* Input marks of five subjects from user */
    printf("\n\nEnter five subjects marks: ");
    scanf("%d%d%d%d%d", &phy, &chem, &bio, &math, &comp);


    /* Calculate percentage */
    per = (phy + chem + bio + math + comp) / 5.0;
	
    printf("Percentage = %.2f\n", per);


    /* Find grade according to the percentage */
    if(per > 90)
    {
        printf("Grade A");
    }
    else if(per >= 70)
    {
        printf("Grade B");
    }
    else if(per >= 50)
    {
        printf("Grade C");
    }
    else
    {
        printf("Grade F");
    }
    
    getch();
}
