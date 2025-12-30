\\program to obtain character chat based on ASCII.
#include <stdio.h>
int main(void){
    for(int i=0;i<13;i++){
        int x=i;
        printf("\n");
        for(int i=1;i<=10;i++){
            if(((10*x)+i)==128){
                break;
            }
            int num=(10*x)+i;
            char n=(char)((10*x)+i);
            printf("%c\t",n);
            
        }
    }
}
