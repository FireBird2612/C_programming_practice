#include<stdio.h>

void print_pattern(void);

int main(){
    print_pattern();

}
void print_pattern(void){
    static int odd_c = 1, i, j, adder = 1, space, space_a = 1;

    if(i < 5){
        if(j < 5){
            if(space == 0){
                printf("%d", odd_c);
                odd_c += 2;
                j++;
            }
            else{
                printf(" ");
                space--;
                j++;
            }
            print_pattern();
        }
        else{
            j = 0;
            i++;
            space = space_a;
            space_a++;
            printf("\n");
            adder += 2;
            odd_c = adder;
            print_pattern();
        }
    }
}
