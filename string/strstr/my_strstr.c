#include<stdio.h>
#include<string.h>

char *my_strstr(char *haystack, char *needle);

int main(){
    char haystack[20], needle[20];
    char *needle_found = NULL;
    
    printf("Enter a string for haystack: \n");
    scanf(" %[^\n]s", haystack);
    printf("Enter a string for needle: \n");
    scanf(" %[^\n]s", needle);
   
    needle_found = my_strstr(haystack, needle);
    if(needle_found == NULL){
        printf("No match found\n");
        return 0;
    }
    printf("%s\n", needle_found);
}
char *my_strstr(char *haystack, char *needle){
    int i, j = 0, k;
    char *ch_ptr = NULL;

    
    for(i = 0; haystack[i]; i++){
        if(haystack[i] == needle[j]){
            ch_ptr = haystack + i;
            for(k = i; haystack[k] == needle[j]; k++, j++);
            
            if(j == (strlen(needle))){
                return ch_ptr;   
            }
            j = 0;
        }
    }

    return NULL;
}
