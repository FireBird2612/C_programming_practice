#include<stdio.h>

void print_pattern(void);

int main(){
    print_pattern();
}

void print_pattern(void){
    static int odd_count = 1, i, j;

    if(i < 4){
        if(j >= 0){
            printf("%d ", odd_count);
            odd_count = odd_count + 2;
            j--;
            print_pattern();
        }else{
            odd_count = 1;
            printf("\n");
            i++;
            j = i;
            print_pattern();
        }
    }
}
