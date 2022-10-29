#include <stdio.h>
#include <stdlib.h>
void calculator()
{
  char op;
  double first, second;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);
  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);

  switch (op) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }
}
	
int sum (int num)
{
    if (num != 0)
    {
        return (num % 10 + sum (num / 10));
    }
    else
    {
       return 0;
    }
}

float poly(float a[], int deg, float x)
{
    float p;
    int i;

    p = a[deg];

    for (i = deg; i >= 1; i--) {
        p = (a[i - 1] + x * p);
    }

    return p;
}
  
float poly(float a[], int, float);
float deriv(float a[], int, float);
void calculator();
int sum();
int main()
{
	int i,a=0,t=1;
	int num, result;
	float x, b[10], y1, dy1;
	int deg, j;
	while(t==1)
	{
		printf("\n1. find the sum of digits of a number \n2.calculator\n3.solve polynomial and differential equations\n4.Exit");
		printf("\n\nEnter Your Choice:: ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
    			printf("Enter the number: ");
    			scanf("%d", &num);
    			result = sum(num);
    			printf("Sum of digits in %d is %d\n", num, result);
		        fflush(stdin);
				break;
			
			case 2:
				calculator();
				break;
			
			case 3:
			    printf("Enter the degree of polynomial equation: ");
			    scanf("%d", &deg);
			
			    printf("Ehter the value of x for which the equation is to be evaluated: ");
			    scanf("%f", &x);
			
			    for (j = 0; j <= deg; j++) {
			        printf("Enter the coefficient of x to the power %d: ", j);
			        scanf("%f", &b[j]);
			    }

			    y1 = poly(b, deg, x);
			    dy1 = deriv(b, deg, x);
			
			    printf("The value of polynomial equation for the value of x = %.2f is: %.2f", x, y1);
			    printf("\nThe value of the derivative of the polynomial equation at x = %.2f is: %.2f", x, dy1);
				break;
			
			case 4:
				t == 0;
			
			default:
				printf("Invalid");
				fflush(stdin);			
		}
	}
	return 0;
}
	