#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage error!\n");
    }

    FILE *source1 = fopen(argv[1], "r"), *source2 = fopen(argv[2], "r"), *merge = fopen("merge.txt", "w");
    char ch1, ch2, temp_buff[3];
    if(source1 == NULL || source2 == NULL || merge == NULL){
        printf("Error opening file!\n");
        return 0;
    }
    
    temp_buff[2] = '\0';
    while(((ch1 = fgetc(source1)) != EOF) && ((ch2 = fgetc(source2)) != EOF)){
        fputc(ch1, merge);
        fputc(ch2, merge);
    }

}
