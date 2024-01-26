#include<stdio.h>
#include<string.h>


int main(int argc, char **argv){
    if(argc != 3){
        printf("usage warning!\n");
        return 0;
    }

    FILE *source = NULL;
    char rev[10] = {0};

    source = fopen(argv[1], "r+");
    if(source == NULL){
        printf("Error opening file\n");
    }
    
    while(fscanf(source, "%s", rev) != EOF){
        if(strcmp(argv[2], rev) == 0){
            
            printf("%ld\n", ftell(source));
            
            int len = strlen(rev);
            
            for(int count = 0, rev_count = len - 1; count < len; count ++, rev_count--){
                rev[count] = argv[2][rev_count];
            }
            
            printf("%s\n",rev);
            fseek(source, -len, SEEK_CUR);
            fprintf(source, "%s", rev); 
        }
    }
    
    fclose(source);
    return 0;
}   
