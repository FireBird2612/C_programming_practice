#include"linked_list_q.h"

int main(){
    /* Create a headpointer */
    STI *headptr = NULL;
    
    int opt;

    while(1){
        printf("Enter your choice:\n");
        printf("1. Add_begin\n2. Add_middle\n3. Add_end\n4. Count_node\n");
        printf("5. Print_node\n6. Save_file\n7. Read_file\n8. Reverse_print\n");
        printf("9. Print_record\n10. Reverse_record\n11. Delete_all\n12. delete_node\n");
        printf("13. Search_node\n14. Sort_data\n15. Reverse_links\n16. Exit\n");
        
        scanf("%d", &opt);
        
        switch(opt){
            case 1: add_begin(&headptr);
                    break;
            
            case 3: add_end(&headptr);
                    break;

            case 5: print_node(headptr);
                    break;

            case 16: exit(0);

            default: printf("Unknown Choice\n");
        }
        
    }
}

void add_begin(STI **headptr){
    
    STI *new_node = calloc(1, sizeof(STI));
    if(new_node == NULL){
        printf("Memory not allocated!\n");
        exit(0);
    }
    /* Get data in the node from user */
    printf("Enter your name, rollno and marks:\n");
    scanf("%s%d%f", new_node->name, &new_node->rollno, &new_node->marks);
    
    new_node->next = *headptr;      // create a link between new_node and first_node 
    *headptr = new_node;           // make the new_node as first node
    
}

void print_node(STI *headptr){
    /* Check headptr for NULL */
    if(headptr == NULL){
        printf("No record found\n");
        return;
    }
    
    while(headptr){
        printf("Name: %s\nRollNo: %d\nMarks: %g\n", headptr->name, headptr->rollno, headptr->marks);
        headptr = headptr->next;
    }
}

void add_end(STI **headptr){
    STI *new_node, *temp_node;
    new_node = calloc(1, sizeof(STI));
    printf("Enter your name, rollno and marks:\n");
    scanf("%s%d%f", new_node->name, &new_node->rollno, &new_node->marks);
    
    if(*headptr == NULL){
        *headptr = new_node;    
        return;
    }
    
    temp_node = *headptr;
    while(temp_node->next){
        temp_node = temp_node->next;
    }
    temp_node->next = new_node;

}


