/***
 *  Problem: Given an array of integers, find the sum of its elements
 *
 *  Input : arr[] = {1, 2, 3}
 *  Output : 6
 *
 ***/

#include<stdio.h>

int main(){
    int arr[] = {1, 2, 3}, ele = sizeof(arr)/sizeof(arr[0]);
    int count, sum = 0;

    for(count = 0; count < ele; count++){
        sum += arr[count];
    }

    printf("%d\n", sum);

}

