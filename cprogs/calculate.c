#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int charToIntConverter2(int x){/*this function takes the ascii code of character digit and returns it as an integer. if ascii code is not 
    of integer then it returns -1.*/
    for(int i=0;i<10;i++){
       if(x == (i+48)){
            return i;
       }else if( x != (i+48) && i==9){
        return -1;
       }
    }
}

void calculate(void) {
    char s[1000];
    double p=1000000;
    puts("Please enter a valid expression.");
    scanf("%s",s);
    char*sPtr=&s[0];
    char* fPtr;

    //here spaces are allowed, that is one thing.

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
    if( strstr(sPtr,"(") != NULL ){/***********For expressions with paranthesis involved.*********** */
        //DO ANALYZE THIS CHUNK COMPLETELY....

//      char *cPtr=NULL;
//         while(strstr(sPtr,")") != NULL){
//         sPtr = strstr(sPtr,")");
//     }
//         cPtr = sPtr;

//          sPtr = &s[0];
//     while(strstr(sPtr,"(") != NULL){
//         sPtr = strstr(sPtr,"(");
//     }
  
//     /*After this loop sPtr is at innermost paranthesis.*/

// while(sPtr != cPtr){//Evaluating the parantheses.

//         fPtr = sPtr;
//         sPtr++;
// /*******************************************************************************/
//          while( (int)*sPtr != ')' ){

//         if( (int)*sPtr != ' ' ){
//             sPtr++;
//             continue;
//         }
//         if( isdigit((int)*sPtr) != 0 ){
//             p=strtod(sPtr,&sPtr);
//             sPtr++;
//             continue;
//         }
//         if( (int)*sPtr == (int)'+' ){
//                 p = p + strtod(sPtr,&sPtr);
//                 continue;
//         }
//         if( (int)*sPtr == (int)'-' ){
//                 p = p - strtod(sPtr,&sPtr);
//                 continue; 
//         }
//         if( (int)*sPtr == (int)'(' ){
//             while(*sPtr == ')'){
//                 sPtr++;
//             }
//             sPtr++;//placing next to ")".
//         }

//     }
// /********************************************************************************/
//        while(sPtr == fPtr){
//             sPtr--;
//         }
//         /*now sPtr would be at the "(" that we just evaluated.*/
//         while(*sPtr == '('){
//             sPtr--;
//         }


// }
// /*Once all the paranthesis is evaluated(which is achieved by the above while loop) do the following*/

// sPtr = &s[0];
//     for(int i=0; s[i] != '\0'; i++){
//         if( (int)*sPtr != ' ' ){
//             sPtr++;
//             continue;
//         }

//         if( (int)*sPtr == (int)'(' ){
//             while(*sPtr == ')'){
//                 sPtr++;
//             }

//         }
//         if( charToIntConverter2((int)*sPtr) != 1){
//             p=charToIntConverter2((int)*sPtr);
//             sPtr++;
//             continue;
//         }
//         if( (int)*sPtr == (int)'+' ){
//                 p = p + (int)strtol(sPtr,&sPtr,10);
//                 continue;
//         }
//         if( (int)*sPtr == (int)'-' ){
//                 p = p - (int)strtol(sPtr,&sPtr,10);
//                 continue; 
//         }
//     }
// printf("%lf\n",p);

    }  else  {/***********For expressions without paranthesis involved.*********** */
        sPtr = &s[0];
    for(int i=0; s[i] != '\0'; i++){
        if( (int)s[i] == ' ' ){
            sPtr++;
            continue;
        }

        if( isdigit((int)s[i]) != 0 && p == 1000000){
            p=0;
            p=strtod(sPtr,&sPtr);
             
            sPtr++;
            continue;
        }
        if( (int)s[i] == (int)'+' ){
                p = p + strtod(sPtr,&sPtr);
                continue;
        }
        if( (int)s[i] == (int)'-' ){
            sPtr++;/*because strtod is even taking the minus sign so evaluation is proceeding in a wrong way.*/
                p = p - strtod(sPtr,&sPtr);
                continue; 
        }
    }
        printf("%lf\n",p);
    }

}


int main(void) {

    calculate();
    return 0;
}