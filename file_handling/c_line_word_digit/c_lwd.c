#include<stdio.h>
#include<string.h>


int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage error!\n");
        return 0;
    }
    
    int digit_c = 0, line_c = 0, word_c = 0;
    char ch;
    FILE *source = fopen(argv[1], "r");
    
    if(source == NULL){
        printf("Error opening file!\n");
        return 0;
    }
    while((ch = fgetc(source)) != EOF){
        if(ch > 48 && ch < 58){
            digit_c++;
        }
        else if(ch == 32 || ch == '\n'){
            word_c++;
            if(ch == '\n'){
                line_c++;
            }
        }
        else if(ch == '\n'){
            line_c++;
            
        }
        
    }
    fclose(source);

    printf("digit = %d\t word = %d\t line = %d\n", digit_c, word_c, line_c);

    return 0;
}
