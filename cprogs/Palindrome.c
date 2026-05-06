/*CHECKING WHETHER A NUMBER IS PALINDROME OR NOT WITHOUT CONVERTING TO STRING.*/
#include <stdio.h>
int main(void){
    printf("Please enter a number to check whether it is a palindrome :\n");
    int n=0;
    scanf("%d",&n);
    //always make sure that you dont involve the stupid whitespace characters in the double quotes within the scanf function in C.
    int arr[10];
    int counter=0;
    while(n!=0){
        arr[counter] = n%10;
        n=n/10;
        counter++;
    }
    counter--;
    for(int i=0; i != (counter-i) || i == (counter-i) ;i++){


        if( i < (counter-i) && arr[i] == arr[counter-i]  ){
            continue;
        }else if( i < (counter-i) && arr[i] != arr[counter-i]){
            printf("Its not a palindrome.\n");
            break;
        }else if(i > (counter - i) ){
            printf("yaa , it is a Palindrome.\n");
            break;
        }else if(i == (counter-i)){
            printf("Its a Palindrome.\n");
            break;
        }


    }

    return 0;
}