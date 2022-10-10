#include <stdio.h>
#include <stdlib.h>

void binary(int n1, int n2);

/*
this program keeps on taking 2 integers, calculating their binary representations and
finding their hamming difference until the user inserts a negative non zero number
*/
int main() {
    int n1,n2;
    printf("Please enter two positive integers (enter a negative non zero to stop): ");
    scanf("%d",&n1);   
    if(n1<0){
        exit(0);
    }  
    scanf("%d",&n2);     
    while(n1>=0){ 
        binary(n1,n2); 
        printf("\n");
       
        printf("Please enter two positive integers: ");
        scanf("%d",&n1);   
        if(n1<0){
            exit(0);
        }
        scanf("%d",&n2);   
    } 
}

/*
requires: 2 positive integers n1 and n2 

effects: calculates their binary representation and their hamming differences 
        (i.e how many bits they have differently).

test cases: any 2 positive number makes the program keep looping and negative non zero 
            number makes the loop stop
*/ 
void binary(int n1, int n2){
    int k=7,m=7;
    int arr1[8];
    int arr2[8];
    for(int j=0; j<8; j++){
        arr1[j]=0;
    }
    for(int j=0; j<8; j++){
        arr2[j]=0;
    }

    while (n1!=0){
        if(n1%2!=0){
            arr1[k]=1;
        }
        else{
            arr1[k]=0;  
        }
        k--;
        n1/=2;
        
    }
    
    while (n2!=0){
        if(n2%2!=0){
            arr2[m]= 1;
        }
        
        else{
            arr2[m]=0;
        }       
        m--;
        n2/=2;
        
 
    }

    printf("\n");;
    
    int diff=0;
    for(int i=0; i<8; i++){
        if(arr1[i]!= arr2[i]){
            diff++;
        }
    }
    printf("%d", diff);
    printf("\n");
}