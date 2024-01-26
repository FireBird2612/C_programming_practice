/**
 *  Insert an elemenet at any desired position
 **/

#include<stdio.h>

int main(){
    int ins_at_ele, ins_num, ele;

    printf("Insert at element: \n");
    scanf("%d", &ins_at_ele);
    printf("number to be inserted: \n");
    scanf("%d", &ins_num);

    // Array scanning
    printf("Enter total array elements: \n");
    scanf("%d", &ele);
    
    int arr[ele + 1];
    printf("Enter array: \n");
    
    for(int count = 0; count < ele; count++){
        scanf("%d", &arr[count]);    
    }

    // Logic
    for(int count = ele; count >= ins_at_ele; count--){
        arr[count + 1] = arr[count];
    }
    arr[ins_at_ele] = ins_num;

    //print the array
    for(int count = 0; count < ele + 1; count++){
        printf("%d ", arr[count]);    
    }
    printf("\n");
}
