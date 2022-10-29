#include<stdio.h>
int fact(int x){
int i,fact=1;
for (i=1;i<=x;i++)
fact*=i;
return fact;
}
int odd(int x){
if(x%2!=0)
return 1;
return 0;
}
int main(){
int op,n,res;
char ch='y';
while(ch=='y'||ch=='Y'){
printf("\n\nMAIN MENU");
printf("\n1) Factorial");
printf("\n2) Check Odd");
printf("\nEnter your Option: ");
scanf("%d",&op);
switch(op){
case 1:
printf("\nEnter a number: ");
scanf("%d",&n);
res=fact(n);
printf("\nFactorial is %d",res);
break;
case 2:
printf("\nEnter a number: ");
scanf("%d",&n);
res=odd(n);
(res==1)?printf("\nOdd number"):printf("\nEven Number");
break;
default:printf("\nWrong Option");
}
printf("\nDo you want to Continue(y/n): ");
scanf(" %c",&ch);
}

return 0;

}

