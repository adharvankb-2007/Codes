//in order to obtain the value of the factorial of a number just enter the desired number in the input dialog box of the IDE.
#include <stdio.h>
int main()
{
    int a=0;
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
