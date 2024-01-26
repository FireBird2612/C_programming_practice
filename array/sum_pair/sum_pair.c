/**
 *  Problem: Given an array A[] of n numbers and another number x, the
 *  task is to check wether or not htere exist two elements in A[]
 *  whose sum is exactly x.
 *
 *  EXAMPLE:
 *  INPUT: arr[] = {0, -1, 2, -3, 1}, x = -2;
 *  Output: Yes
 *          1 + (-3) = -2
 **/

#include<stdio.h>


int main(){
    int ele, x;

    printf("Enter x: \n");
    scanf("%d", &x);
    
    printf("Enter total no. of elements: \n");
    scanf("%d", &ele);

    int num_arr[ele];
    printf("Enter integer values in array: \n");
    for(int count = 0; count < ele; count++){
        scanf("%d", &num_arr[count]);
    }
    
    /** Logic **/
    for(int count = 0; count < ele; count++){
        for(int inner_count = count + 1; count < ele; inner_count++){
            if(num_arr[count] + (num_arr[inner_count]) == x){
                printf("Yes\n");
                return 0;
            }
        }
    }
    
    printf("No!\n");
}


