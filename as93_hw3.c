

/*Arshdeep Singh
    C Programming
    Homework 3

    Comment explaining my logic:
 
 
 
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int calcStringLength(char *value) //Function to calculate length of given string
{
    int i;
    for(i=0; value[i]!='\0'; i++) {
        //do nothing
    }
    
    return i;
}


//Calculates the combined size of the two parameters.
int calSumIn(char *first, char *second) {
    int strsize = 0;
    strsize += calcStringLength(first);
    strsize += calcStringLength(second);
    
    return strsize;
}



void stringAddition(char* array, int size1, int size2) {
    
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
                array[i - size1] -= 58;
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
                array[i + size1] -= 58;
            }
            
        }
        
        
        for (j = size1; j < size1 + size2; j++) {
            printf("%c", array[j]);
        }
        printf("\n");
        
        
    }
    printf("\n");
}



void stringSubtraction(char* array, int size1, int size2) {
   
    
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
        //dont subtract the first part from the second part, because the input was first - second and NOT second - first.
        
        

        
    }

    
}


void stringDivision(char* array, int size1, int size2) {
    
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

        
        for (j = size1*2; j < size1 + size2; j++ ) { //print out rest from second input
            printf("%c", array[j]);
        }
        
        printf("\n\n");
    }
    
    
}

void stringMultiplication(char* array, int size1, int size2) {
    
    
    
    
    
}




//argc is 1 plus the number of arguments passed in
//argv contains pointers ( at argv[1] to argv[n] ) that point to the arguments
int main( int argc, char *argv[] ) {
    
    //expecting three arguments plus the name of the program.
    if ( argc != 4) {
        printf("Wrong number of arguments\n");
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
   
        
        
        
        //TODO check if either part has a capitol letter
        //if so then print bad input and end program.
        //else continue.
        
        
        
        if (middle[0] == '+') {
            stringAddition(summ, size1, size2);
            
        } else if (middle[0] == '-') {
            stringSubtraction(summ, size1, size2);
            
        } else if (middle[0] == '/') {
            stringDivision(summ, size1, size2);
            
        } else if (middle[0] == 'x') { //it must be x
            stringMultiplication(summ, size1, size2);
            
        } else {
            printf("bad input\n");
        }
    }
}










/**
 
 //take the first argument and store it in one array
 int length = calcStringLength(argv[1]);
 char firstArray[length];
 int j;
 for (j = 0; j < length; j++) {
 //firstArray[j] =
 }
 //take the third argument and store it in a second array.
 
 **/








