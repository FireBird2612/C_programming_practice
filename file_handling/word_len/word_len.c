#include<stdio.h>
#include<string.h>


int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage error!\n");    
    }
    FILE *source = fopen(argv[1], "r");
    char ch;
    int count = 0;

    if(source == NULL){
        printf("Error opening file!\n");
    }
    
    while((ch = fgetc(source)) != EOF){
        if(ch != '\n' && ch != 32){
            count++;
        }
        else{
            if(count != 0){
                printf("count = %d\n", count);
            }
            count = 0;
        }
    }
    
    fclose(source);
    return 0;

}
