#include "linked_list_q.h"

int count = 0;

int main()
{
    /* Create a headpointer */
    STI *headptr = NULL;

    int opt;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Add_begin\n2. Add_middle\n3. Add_end\n4. Count_node\n");
        printf("5. Print_node\n6. Save_file\n7. Read_file\n8. Reverse_print\n");
        printf("9. Print_record\n10. Reverse_record\n11. Delete_all\n12. delete_node\n");
        printf("13. Search_node\n14. Sort_data\n15. Reverse_links\n16. Exit\n");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            add_begin(&headptr);
            break;

        case 2:
            add_middle(&headptr);
            break;

        case 3:
            add_end(&headptr);
            break;

        case 4:
            count_node(headptr);
            printf("Count = %d\n", count);
            break;

        case 5:
            print_node(headptr);
            break;

        case 6:
            save_file(headptr);
            break;
    
        case 7:
            read_file(&headptr);
            break;

        case 16:
            exit(0);

        default:
            printf("Unknown Choice\n");
            break;
        }
    }
}

void add_begin(STI **headptr)
{

    STI *new_node = calloc(1, sizeof(STI));
    if (new_node == NULL)
    {
        printf("Memory not allocated!\n");
        exit(0);
    }
    /* Get data in the node from user */
    printf("Enter your name, rollno and marks:\n");
    scanf("%s%d%f", new_node->name, &new_node->rollno, &new_node->marks);

    new_node->next = *headptr; // create a link between new_node and first_node
    *headptr = new_node;       // make the new_node as first node
}

void print_node(STI *headptr)
{
    /* Check headptr for NULL */
    if (headptr == NULL)
    {
        printf("No record found\n");
        return;
    }

    while (headptr)
    {
        printf("Name: %s\nRollNo: %d\nMarks: %g\n", headptr->name, headptr->rollno, headptr->marks);
        headptr = headptr->next;
    }
}

void add_end(STI **headptr)
{
    STI *new_node, *temp_node;
    new_node = calloc(1, sizeof(STI));
    printf("Enter your name, rollno and marks:\n");
    scanf("%s%d%f", new_node->name, &new_node->rollno, &new_node->marks);

    if (*headptr == NULL)
    {
        *headptr = new_node;
        return;
    }

    temp_node = *headptr;
    while (temp_node->next)
    {
        temp_node = temp_node->next;
    }
    temp_node->next = new_node;
}

void add_middle(STI **headptr)
{
    STI *new_node, *temp_node;
    new_node = calloc(1, sizeof(STI));

    printf("Enter your name, rollno and marks:\n");
    scanf("%s%d%f", new_node->name, &new_node->rollno, &new_node->marks);

    if ((*headptr == NULL) || (new_node->rollno < (*headptr)->rollno))
    {
        new_node->next = *headptr;
        *headptr = new_node;
    }
    else
    {
        temp_node = *headptr;
        while ((temp_node->next != NULL) && (temp_node->next->rollno < new_node->rollno))
        {
            temp_node = temp_node->next;
        }

        new_node->next = temp_node->next;
        temp_node->next = new_node;
    }
}

void count_node(STI *headptr)
{

    if (headptr == NULL)
    {
        return;
    }
    while (headptr)
    {
        count++;
        headptr = headptr->next;
    }
}

void save_file(STI *headptr)
{
    if (headptr == NULL)
    {
        printf("No record to save\n");
        return;
    }
    else
    {
        FILE *fp = fopen("record.txt", "r+");
        if (fp == NULL)
        {
            printf("Error opening file!\n");
            return;
        }
        while (headptr)
        {
            fprintf(fp, "%s %d %g\n", headptr->name, headptr->rollno, headptr->marks);
            headptr = headptr->next;
        }
        fclose(fp);
    }
}

void read_file(STI **headptr){

    FILE *fp = fopen("record.txt", "r");
    if(fp == NULL){
        printf("Failed to open the file!\n");
        return;
    }
    
    STI *last_node, *new_node;
    
    while(1){
        new_node = calloc(1, sizeof(STI));
        if((fscanf(fp, "%s%d%g", new_node->name, &new_node->rollno, &new_node->marks)) == EOF){
            break;
        }

        if(*headptr == 0){
            *headptr = new_node;
        }
        else{
            last_node = *headptr;
            while(last_node->next){
                last_node = last_node->next;
            }
            last_node->next = new_node;
        }   
    } 
}
