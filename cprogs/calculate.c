#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void calculate(void) {
    char s[1000];

    double p=1000000;
    puts("Please enter a valid expression.");
    scanf("%s",s);
    char*sPtr=&s[0];//here spaces are allowed, that is one thing.
    /****************Checking if expression is valid*******************/
    for(int i=0; (int)s[i] != '\0';i++){

        if(i==0){/*The first character*/
            if((int)s[i] == (int)' ' || isdigit((int)s[i]) != 0 || (int)s[i] == (int)'('){
                sPtr++;
                continue;
            }else{
                puts("Invalid expression1.Please enter a valid expression");
                return calculate();
            }
        }else  if( s[i+1] == '\0' ){/*The last character*/
                if( isdigit((int)s[i]) != 0 || (int)(s[i]) == (int)' ' || (int)(s[i]) == (int)')'){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression2.Please enter a valid expression");
                    return calculate();
                }
            }else if(i!= 0 ||  s[i+1] != '\0'){/*The middle ones*/     

            if( isdigit((int)s[i]) != 0 ){/* digit */
                if((int)s[i+1] == (int)' ' ||(int)s[i+1] == (int)'+' || (int)s[i+1] == (int)'-' || 
                (int)(s[i+1]) == (int)')' || isdigit((int)s[i+1]) != 0 || (int)s[i+1] == (int)'.'){
                    sPtr++;
                    continue;
                }else{
                puts("Invalid expression3.Please enter a valid expression");
                return calculate();
            }
            }else 


            if((int)s[i] == (int)' '){
                sPtr++;
                continue;
            }else           

              if((int)(s[i]) == (int)'+'){/*  +  */
                if( (int)(s[i+1]) == (int)' ' || (int)(s[i+1]) == (int)'(' || isdigit((int)s[i+1]) != 0 ){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression4.Please enter a valid expression");
                    return calculate();
                }
            }else


            if((int)(s[i]) == (int)'-'){/*  -  */
                if( (int)(s[i+1]) == (int)' ' || (int)(s[i+1]) == (int)'(' || isdigit((int)s[i+1]) != 0){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression5.Please enter a valid expression");
                    return calculate();
                }
            }else


            if((int)(s[i]) == (int)')'){/*  )   */
                if( (int)(s[i+1]) != (int)'('){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression6.Please enter a valid expression");
                    return calculate();
                }
            }else
            
            if((int)(s[i]) == (int)'('){/*  (   */
                if( (int)(s[i+1]) == (int)' ' || isdigit((int)s[i+1]) != 0){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression7.Please enter a valid expression");
                    return calculate();
                }
            }else 
            if((int)(s[i]) == (int)'.'){/*  .   */
                if(isdigit((int)s[i+1]) != 0){
                    sPtr++;
                    continue;
                }else{
                    puts("Invalid expression8.Please enter a valid expression");
                    return calculate();
                }
            }

            }else{
                puts("Invalid expression9.Please enter a valid expression");
                 return calculate();
            }
        

    }
    /********************************************************************/
    sPtr = &s[0];
    char s1[]="()";
    if( strpbrk(sPtr,s1) != NULL ){/***********For expressions with paranthesis involved.*********** */
        sPtr = &s[0];
    for(int i=0; (int)*sPtr != '\0'; i++){
        if(i==0 && (int)*sPtr == '('){
            sPtr++;
            continue;
        }
        if( (int)*sPtr == ' ' || (int)*sPtr == ')'){
            sPtr++;
            continue;
        }

        if( isdigit((int)*sPtr) != 0 && p == 1000000){
            p=0;
            p=strtod(sPtr,&sPtr);
            continue;
        }
        if( (int)*sPtr == (int)'+' ){
            while(isdigit((int)*sPtr) == 0){
                sPtr++;
            }
            p = p + strtod(sPtr,&sPtr);
            continue;
        }
        if( (int)*sPtr == (int)'-' ){
            sPtr++;/*because strtod is even taking the minus sign so evaluation is proceeding in a wrong way.*/
            while(isdigit((int)*sPtr) == 0){
                sPtr++;
            }
            p = p - strtod(sPtr,&sPtr);
            continue;
        }
    }


        printf("%.10lf\n",p);

    } else {/***********For expressions without paranthesis involved.*********** */
        sPtr = &s[0];
    while(*sPtr != '\0'){
        if( (int)*sPtr == ' ' ){
            sPtr++;
            continue;
        }

        if( isdigit((int)*sPtr) != 0 && p == 1000000){
            p=0;
            p=strtod(sPtr,&sPtr);
            
            continue;
        }
        if( (int)*sPtr == (int)'+' ){
                p = p + strtod(sPtr,&sPtr);
                continue;
        }
        if( (int)*sPtr == (int)'-' ){
            sPtr++;/*because strtod is even taking the minus sign so evaluation is proceeding in a wrong way.*/
                p= p - strtod(sPtr,&sPtr);
                continue; 
        }
    }


        printf("%.10lf\n",p);
    }

}


int main(void) {
    calculate();
    return 0;
}