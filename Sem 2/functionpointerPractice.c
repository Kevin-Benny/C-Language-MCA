#include<stdio.h>
//#include<iostream>
//using namespace std;
/* typedef a function pointer for a function returning int and taking argument as int.
*/


typedef char(*pt2Func)(char);  //first char is return type of pointed function return type and second int is 
 
/* function performing square */
char sqr(char x)
{
	//char a = x;
 //return(x*x);
 return x;
}
/* function returning function pointer pt2Func */
pt2Func GetPtr(const int Code)
{
 printf("%d\n",Code);
 printf("%c\n",sqr('a'));
 return (*sqr);
} 

 
int main()
{
    pt2Func xyz = GetPtr(5);  //run just first function
    //printf(*xyz);
    //cout << (*xyz)(5) << endl;
    printf("%c\n",(*xyz)('a'));  //run second function
    return 0;
}


/*
//orginal code
#include<stdio.h>
//#include<iostream.h>
//using namespace std;
//typedef a function pointer for a function returning int and taking argument as int.
typedef int(*pt2Func)(int);
 
//function performing square
int sqr(int x)
{
 return(x*x);
}
//function returning function pointer pt2Func 
pt2Func GetPtr(const char Code)
{
 printf("%c\n",Code);
// return 0;	
 return (*sqr);
}  
 
int main()
{
    pt2Func xyz = GetPtr('j');
    //cout << (*xyz)(5) << endl;
    printf("%d\n",(*xyz)(5));
    return 0;
}

*/