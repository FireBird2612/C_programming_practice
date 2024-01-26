/**
 *
 *  Problem:    Find the majority element in the array. 
 *              A majority element in an array A[] of size n is an element that appears more than n/2 times. 
 *
 *  Examples :  Input : A[]={3, 3, 4, 2, 4, 4, 2, 4, 4}
 *              Output : 4
 *  
 *  Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 
 *  Input : A[] = {3, 3, 4, 2, 4, 4, 2, 4}
 *  Output : No Majority Element
 *  Explanation: There is no element whose frequency is greater than the half of the size of the array size.
 *
 **/

#include<stdio.h>


int main(){
    int ele, counter = 1;
    
    printf("Enter an array element: \n");
    scanf("%d", &ele);

    int A[ele];
    printf("Enter integers in array: \n");
    for(int count = 0; count < ele; count++){
        scanf("%d", &A[count]);
    }

    /* Sort the array first */
    for(int count = 0; count < ele; count++){
        for(int inner_count = count + 1; inner_count < ele; inner_count++){
            if(A[count] > A[inner_count]){
                // swap
                int temp = A[count];
                A[count] = A[inner_count];
                A[inner_count] = temp;
            }
        }
    }
    int inner_count; 
    for(int count = 0; count < ele; count++){
        for(inner_count = count + 1; inner_count < ele; inner_count++){
            if(A[count] == A[inner_count]){
                counter++;
            }
            else{
                break;    
            }
        }
        if(counter > (ele/2)){
            printf("%d\n", A[count]);
       
        }
        count = inner_count;
        count = 0;
    }
}


