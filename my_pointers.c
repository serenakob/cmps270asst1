#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char* arr1[], char * arr2[], int size1, int size2);

int main(){
    char * arr1[2] = {"ab", "za"};
    char * arr2[3] = {"az", "ac", "zzzzc"};
    int size1= sizeof(arr1)/ sizeof(arr1[0]);
    int size2 = sizeof(arr2)/ sizeof(arr2[0]);
    merge(arr1, arr2, size1, size2);
}

/*
requires: two pointers to sorted arrays of strings and their size
effects: merges the strings into one array sorted by alpha numeric order
test cases: any array with any size
            empty array
            array of other type
*/
void merge(char* arr1[], char * arr2[], int size1, int size2){
    
    //creating a new array and adding the two arrays to it
    char * arrmerge[size1+size2];
    int m=0;
    for(int i=0; i<size1; i++){
        arrmerge[m]= arr1[i];
        m++;
    }
    for(int j=0; j<size2; j++){
        arrmerge[m] = arr2[j];
        m++;
    }

    //sorting the array using bubble sort
    for(int i=0; i<size1+size2; i++){
        for(int j=i+1; j<size1+size2; j++){
            int result= strcmp(arrmerge[i], arrmerge[j]);
            if(result>0){
                char* temp[1]= {arrmerge[i]};
                arrmerge[i]= arrmerge[j];
                arrmerge[j]= temp[0];
            }
        }
    }

    //printing the array
    for(int i=0; i<size1+size2; i++){
        printf("%s", arrmerge[i]);
        printf("\n");
    }
    
}