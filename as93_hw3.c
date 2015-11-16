

/*Arshdeep Singh
    C Programming
    Homework 3

    Comment explaining my logic:
        This program takes in three arguments at the command line.
        I take the first and third argument (which are strings) and then concatenate them together on one larger array (which is sized to be the combined size of the first and third argument).
        I then check for the second argument which will be +, -, /, or x.
        Depending on the second argument, I call the appropriate method which will do the calculation and then print the result.
 
 
 
    EXTRA CREDIT:
        Takes the first char to the power of the second char.
 
*/






#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>






int calcStringLength( /*in*/ char *value);
int calSumIn( /*in*/ char *first, /*in*/ char *second);
void stringAddition(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2);
void stringSubtraction(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2);
void stringDivision(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2);
void stringMultiplication(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2);
int power( /*in*/ int x, /*in*/ int y);
void stringPower(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2);







// Calculates the the size of the array that is passed in.
// pre: array allocated
// post: count of array values returned.
//
int calcStringLength( /*in*/ char *value) //Function to calculate length of given string
{
    int i;
    for(i=0; value[i]!='\0'; i++) {
        //do nothing
    }
    
    return i;
}









//Calculates the combined size of the two parameters.
// pre: first (array) allocated, second (array) allocated
// post: count (strsize) of all characters in both arrays.
//
int calSumIn( /*in*/ char *first, /*in*/ char *second) {
    int strsize = 0;
    strsize += calcStringLength(first);
    strsize += calcStringLength(second);
    
    return strsize;
}









// Adds the two command line values and then prints out the sum.
// pre: an allocted array, size of array == (size1 + size2).
// post: array values (either first part or second) change and part of the array is printed out.
//
void stringAddition(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2) {
    
    int j;
    for (j = 0; j < size1; j++) { //print the first part
        printf("%c", array[j]);
    }
    
    printf(" + "); //print the middle
    
    for (j = size1; j < size1 + size2; j++) { //print the second part
        printf("%c", array[j]);
    }
    
    printf(" => "); //print the arrow

    
    //----------The following part prints out the end result----------
    
    
    if (size1 >= size2) { //add the second part to the first part
        
        int i;
        for (i = size1; i < size1 + size2; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;

            array[i - size1] = vali + valo + 96;
            
            if (vali + valo + 96 > 122) {
                array[i - size1] = valo + 64;
            }
        }
       
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n");

        
        
    } else { //add the first part to the second part
        
        int i;
        for (i = 0; i < size1; i++) {
            int vali = array[i] - 96;
            int valo = array[i + size1] - 96;
            
            array[i + size1] = vali + valo + 96;
            
            if (vali + valo + 96 > 122) {
                array[i + size1] = vali + 64;
            }
            
        }
        
        
        for (j = size1; j < size1 + size2; j++) {
            printf("%c", array[j]);
        }
        printf("\n");
        
        
    }
    printf("\n");
}










// Subtracts the two command line string and then prints the difference.
// pre: an allocted array, size of array == (size1 + size2).
// post: array values (either first part or second) change and part of the array is printed out.
//
void stringSubtraction(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2) {
   
    
    int j;
    for (j = 0; j < size1; j++) { //print the first part
        printf("%c", array[j]);
    }
    
    printf(" - "); //print the middle
    
    for (j = size1; j < size1 + size2; j++) { //print the second part
        printf("%c", array[j]);
    }
    
    printf(" => "); //print the arrow
    
    

    //----------The following part prints out the end result----------

    
    if (size1 >= size2) { //subtract the second part from the first part

        int i;
        for (i = size1; i < size1 + size2; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = valo - vali + 96;
            
            if (valo - vali <= 0) {
                //If the result is outside the range 1-26 then the output character should be the uppercase version of the input caracter from the first string.
                array[i - size1] = valo + 64;
            }
        }

     
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n\n");
        
        
    } else {
        //dont subtract the first part from the second part, because the input was first minus second and NOT second - first.
        
        int i;
        for (i = size1; i < size1 + size1; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = valo - vali + 96;
            
            if (valo - vali <= 0) {
                //If the result is outside the range 1-26 then the output character should be the uppercase version of the input caracter from the first string.
                array[i - size1] = valo + 64;
            }
        }
        
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        
        for (j = size1*2; j < size1 + size2; j++ ) { //print out rest from second input
            printf("%c", array[j]);
        }
        
        printf("\n\n");
        
    }
    
}










// Divides the first command-line argument by the second and then prints.
// pre: an allocted array, size of array == (size1 + size2).
// post: array values (either first part or second) change and part of the array is printed out.
//
void stringDivision(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2) {
    
    int j;
    for (j = 0; j < size1; j++) { //print the first part
        printf("%c", array[j]);
    }
    
    printf(" / "); //print the middle
    
    for (j = size1; j < size1 + size2; j++) { //print the second part
        printf("%c", array[j]);
    }
    
    printf(" => "); //print the arrow
    
    
    
    
    //----------The following part prints out the end result----------
    
    
    if (size1 >= size2) { //divide the first part by the second part

        int i;
        for (i = size1; i < size1 + size2; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = valo / vali + 96;
            
            if ( vali > valo ) {
                array[i - size1] = valo + 64;
            }
        }
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n\n");
        
        
    } else { //still dividing the first part by the second half, with leftovers
       
        
        int i;
        for (i = size1; i < size1 + size1; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = valo / vali + 96;
            
            if ( vali > valo ) {
                array[i - size1] = valo + 64;
            }
        }
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }

        
        for (j = size1*2; j < size1 + size2; j++ ) { //print out rest from second input
            printf("%c", array[j]);
        }
        
        printf("\n\n");
    }
    
    
}










// Multiplies the two command-line strings and then prints the product.
// pre: an allocted array, size of array == (size1 + size2).
// post: array values (either first part or second) change and part of the array is printed out.
//
void stringMultiplication(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2) {
    
    int j;
    for (j = 0; j < size1; j++) { //print the first part
        printf("%c", array[j]);
    }
    
    printf(" x "); //print the middle
    
    for (j = size1; j < size1 + size2; j++) { //print the second part
        printf("%c", array[j]);
    }
    
    printf(" => "); //print the arrow
    
    
    //----------The following part prints out the end result----------
    
    
    if (size1 >= size2) { //multiply the first part by the second part
        
        int i;
        for (i = size1; i < size1 + size2; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = vali * valo + 96;
            
            if (vali * valo > 26) {
                array[i - size1] = valo + 64;
            }
        }
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n\n");
        
        
    } else { //multiply the second part by the first part.
        
        int i;
        for (i = 0; i < size1; i ++) {
            
            int vali = array[i] - 96;
            int valo = array[i + size1] - 96;
            
            array[i + size1] = vali * valo + 96;
            
            if (vali * valo > 26) {
                array[i + size1] = vali + 64;
            }
        }
        
        for (j = size1; j < size1 + size2; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n\n");
        
    }
    
}









//This function takes a number to a power.
// pre: two integers
// post: the first integer multiplied by itself a [second integer] number of times.
//
int power( /*in*/ int x, /*in*/ int y) {
    int returner = 1;
    while (y--) {
        returner = returner * x;
    }
    return returner;
}









// Takes the first char to the power of the second char.
// pre: an allocted array, size of array == (size1 + size2).
// post: array values (either first part or second) change and part of the array is printed out.
//
void stringPower(/*inout*/ char* array, /*in*/ int size1, /*in*/ int size2) {
    
    int j;
    for (j = 0; j < size1; j++) { //print the first part
        printf("%c", array[j]);
    }
    
    printf(" ^ "); //print the middle
    
    for (j = size1; j < size1 + size2; j++) { //print the second part
        printf("%c", array[j]);
    }
    
    printf(" => "); //print the arrow

    
    if (size1 >= size2) {
        
        int i;
        for (i = size1; i < size1 + size2; i++) {
            
            int vali = array[i] - 96;
            int valo = array[i - size1] - 96;
            
            array[i - size1] = power(valo, vali) + 96;
            
       
            
            if ( power(valo, vali) > 26 ) {
                array[i - size1] = valo + 64;
            }
        }
        
        for (j = 0; j < size1; j++) { //print out the final set of characters
            printf("%c", array[j]);
        }
        printf("\n\n");
        
        
        
    } else {
        
        int i;
        for (i = 0; i < size1; i ++) {
            
            int valo = array[i] - 96;
            int vali = array[i + size1] - 96;
            
            array[i] = power(valo, vali) + 96;
            
            if ( power (valo, vali) > 26) {
                array[i] = valo + 64;
            }
        }
        
        for (j = 0; j < size1; j++) { //print out the first set of characters
            printf("%c", array[j]);
        }
        
        for (j= size1*2 ; j < size1 + size2; j++) {
              printf("%c", array[j]);
        }
        
        printf("\n\n");
        
    }
    
}









//The main method which starts everything.
//Pre:
//argc is 1 plus the number of arguments passed in
//argv contains pointers ( at argv[1] to argv[n] ) that point to the arguments
//
//Post: none
//
int main( /*in*/ int argc, /*in*/char *argv[] ) {
    
    //expecting three arguments plus the name of the program.
    if ( argc != 4) {
        printf("bad input\n");
    } else {
        
        //find the combined size of the two arguments.
        int inSize = calSumIn(argv[1], argv[3]);
        
        //dynamically allocate memory and then concatenate the command line parameters.
        char *summ;
        summ = malloc(inSize);
        strcat(summ, argv[1]);
        strcat(summ, argv[3]);
        
        int size1 = calcStringLength(argv[1]); //get the size of the two strings
        int size2 = calcStringLength(argv[3]);
        
        char *middle = argv[2]; //retreive the mathamatic symbol in the middle
   
        
        //check if either part has a capitol letter
        //if so then print bad input and end program.
        //else continue.
        
        bool correct = true;
        
        int i;
        for (i = 0; i < size1 + size2; i++) {
            int theChar = summ[i] - 96;
            
            if (theChar < 1 || theChar > 26) {
                correct = false;
                break;
            }
        }
        
        if (correct) {
        
            if (middle[0] == '+') {
                stringAddition(summ, size1, size2);
            
            } else if (middle[0] == '-') {
                stringSubtraction(summ, size1, size2);
            
            } else if (middle[0] == '/') {
                stringDivision(summ, size1, size2);
            
            } else if (middle[0] == 'x') { //it must be x
                stringMultiplication(summ, size1, size2);
            
            } else if (middle[0] == '^') {
                stringPower(summ, size1, size2);
                
            } else {
                printf("bad input\n");
                
            }
            
        } else {
            printf("bad input\n");
            
        }
    }
}








