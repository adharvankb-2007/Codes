//in order to obtain the value of the factorial of a number just enter the desired number in the input dialog box of the IDE.
//the program to obtain the value of the factorial by just using while iteration control statement(also counter controlled iteration).
#include <stdio.h>
int main()
{
    long long int a=0;
    int c=0;
    scanf("%d",&a);
    c=a;
    int b=0;
    b=a;
    int counter=1;
    while (counter<=(c-1))
       {
        b=b-1;
        a=a*b;
        counter=counter+1;
        }
      printf("the factorial is %d",a);
  }
