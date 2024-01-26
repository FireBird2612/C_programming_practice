/***
 *  Problem: Program to find the largest element in an array
 *  
 *  input: arr[] = {10, 20, 30};
 *  output: 20
 *
 ***/

#include<stdio.h>

int main(){
    int ele, count, largest = 0; 
    printf("Enter the total number of array elements: \n");
    scanf("%d", &ele);

    int arr[ele];
    printf("Enter value: \n");
    for(count = 0; count < ele; count++){
        scanf("%d", &arr[count]);
        if(arr[count] > largest){
            largest = arr[count];
        }
    }

    printf("%d\n", largest);
}
