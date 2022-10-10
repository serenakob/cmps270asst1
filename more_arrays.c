#include <stdio.h>
#include <stdlib.h>

void concat(char * arr[][100], int row, int column);

int main(){
    char * arr[][100] ={{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    int row= 2;
    int column=3;
    concat(arr, row, column);
    printf("\n");
    char * arr2[][100] = {{"I", "HATE", "TEST", "CASES"}, {"LOL"}};
    int row2= 2;
    int col2= 4;
    concat(arr2, row2, col2);
}
/* 
requires:one 2d array of strings, the number of rows and the number of columns

effects:function that concatenates the elements in each element of 
        the 2d array with space between them and puts it in a 1d array

test cases: YOU HAVE TO CHANGE THE NUMBER OF ROWS AND COLUMNS ACCORDINGLY
            {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
            {{"I", "HATE", "TEST", "CASES"}, {"LOL"}};
            {{""}};
            {{},{}};
            {{"HI"}, {}};
*/
void concat(char * arr[][100], int row, int column){
    char * arr2[row*column];
    int m=0;
    for(int i=0; i<row;i++){
        for(int j=0; j<column; j++){
            arr2[m]= arr[i][j];
            m++;
        }
    }
    for(int i =0; i <row*column; i++){
        printf("%s",arr2[i]);
        printf(" ");
    }
}