#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int SIZE);
void arrayHistogram(int arr[], int SIZE);
void swapValues(int arr[], int i, int j, int SIZE);
void bubbleSort(int arr[], int SIZE);
void median(int arr[], int SIZE);
void mode(int arr[], int SIZE);
int isSorted(int arr[], int SIZE);

/*
requires: array and its size
effects: prints an array of integers with it's indexes
test cases: any array/ empty array/ array of characters negative size, size 0...
*/
void printArray(int arr[], int SIZE){
    printf("Index  Value");
    for(int i=0; i<SIZE; i++){
        printf("\n");
        printf(" %d        %d", i, arr[i]);
    }
}
/*
requires:the function takes an array and its size
effects: function to compute frequency of every value in array and print the histogram
test cases: any array/ empty array/ array of characters negative size, size 0...
*/
void arrayHistogram(int arr[], int SIZE){
    int freq1=0;
    int freq2=0;
    int freq3=0;
    for(int i=0; i<SIZE; i++){
        if(arr[i]==1){
            freq1++;
        }
        if(arr[i]==2){
            freq2++;
        }
        if(arr[i]==3){
            freq3++;
        }

    }
    char star1, star2, star3;
    printf("Value   Frequency   Histogram");
    printf("\n");
    printf("  %d        %d         ", 1, freq1); 
    for(int i=0; i<freq1; i++){
        printf("*");
    }   
    printf("\n");   
    printf("  %d        %d         ", 2, freq2); 
    for(int i=0; i<freq2; i++){
        printf("*");
    }  
    printf("\n");
    printf("  %d        %d         ", 3, freq3);
    for(int i=0; i<freq3; i++){
        printf("*");
    }  
}


/*
requires: the function takes an array, 2 indexes and the size of the array
effects: function to swap values
test cases: any array/ empty array/ array of characters negative size, size 0...
*/

void swapValues(int arr[], int i, int j, int SIZE){
    int arr2[1];
    arr2[0]= arr[i];
    arr[i]= arr[j];
    arr[j]= arr2[0];

}

/*
requires: the function takes an array and the size of the array
effects:function to sort an array using bubble sort
test cases: any array/ empty array/ array of characters negative size, size 0...
*/


void bubbleSort(int arr[], int SIZE){
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(arr[j]> arr[j+1]){
                swapValues(arr, j, j+1, SIZE);
            }
        }
    }
}

/*
requires: the function takes an array and the size of the array
effects:function to find median
test cases: any array/ empty array/ array of characters negative size, size 0...
*/

void median(int arr[], int SIZE){
    bubbleSort(arr, SIZE);
    if(SIZE%2 ==0){
        double d=(double) (arr[(SIZE-1)/2]+ arr[((SIZE-1)/2)+1])/2;
        printf("%f", d);
    }
    else{
        printf("%d", arr[(SIZE-1)/2]);
    }
}

/*
requires: the function takes an array and the size of the array
effects:function to find mode
test cases: any array/ empty array/ array of characters negative size, size 0...
*/

void mode(int arr[], int SIZE){
    int maxValue=0, maxCount=0;
    for(int i=0; i<SIZE; i++){
        int count=0;
        for(int j=0; j<SIZE; j++){
            if(arr[j]== arr[i]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            maxValue = arr[i];
        }

    }
    printf("%d", maxValue);
}

/*
requires: the function takes an array and the size of the array
effects:function to check if array is sorted
test cases: any array/ empty array/ array of characters, negative size, size 0...
*/

int isSorted(int arr[], int SIZE){
    for(int i =0; i <SIZE; i ++){
        if(arr[i]>arr[i+1])
        return 0;
        
    }
    return 1;
}

int main(){
    
    //created an array filled with 1, 2 or 3s
    int arr[10]= {1,1,1,1,1,2,2,2,3,3};
    int SIZE = 10;

    //printed the array in a table
    printArray(arr, SIZE);
    printf("\n");

    //printed the frequency and histogram of each element
    arrayHistogram(arr, SIZE);

    //created another array with random elements
    int arr2[10]= {3,1,6,4,5,2,7,8,10,9};

    //swapped the values at index 4 and 5
    swapValues(arr2, 4, 5, SIZE);
    printf("\n");

    //printing arr2
    for(int l=0; l<10; l++){
        printf("%d", arr2[l]);
    }
    printf("\n");
    
    //sorting the array
    bubbleSort(arr2, SIZE);

    //printing arr2 again
    for(int l=0; l<10; l++){
        printf("%d", arr2[l]);
    }
    printf("\n");

    //finding the median of arr
    median(arr, SIZE);
    printf("\n");
    
    //finding the mode of arr2
    mode(arr2, SIZE);
    printf("\n");
    
    //creating a random array
    int arr10[10] ={9,3,5,3,2,4,6,3,2,7};
    
    //checking if the array is sorted
    int sorted= isSorted(arr10, SIZE);
    printf("%d", sorted);

}