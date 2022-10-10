#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * binary(int input);
int msb(int input);
int lsb(int input);
int distance(int input);

int main(){
    int input;
    scanf("%d", &input);
    int dist= distance(input);
    printf("%d", dist);
}
/* 
requires: one positive nonzero integer 
effects:returns binary number
test cases: zero / any negative number 
            any positive number
            decimal
            characters
*/
int * binary(int input){
    if(input ==0|| input<0 || input%1 !=0){
        printf("only insert positive non zero integer!");
        exit(0);
    }
    int n=31;
    static int arr[32];
    for(int j=0; j<32; j++){
        arr[j]=0;
    }
    while (input!=0){
        if(input%2!=0){
            arr[n]=1;
        }
        else{
            arr[n]=0;  
        }
        n--;
        input= input/2;
        
    }
    return arr;
}

/*
requires: a positive non zero integer
effects: finding the index of the most significant bit
*/
int msb(int input){
    int index;
    int *n =binary(input);
    for(int i=0; i<32; i++){ 
        if(n[i]== 1){
            index = 31-i;
            break;
        }
    }
    return index;
}
/*
requires: a positive non zero integer
effects: finding the index of the least significant bit
*/
int lsb(int input){
    int index;
    int *n =binary(input);
    for(int i=31; i>0; i--){ 
        if(n[i]== 1){
            index = 31-i;
            break;
        }
    }
    return index;
}

/*
requires: a positive non zero integer
effects: finding the difference between msb and lsb
*/ 
int distance(int input){
    int msb1= msb(input);
    int lsb1= lsb(input);
    int dist = msb1 -lsb1;

    return dist;
}