/***
 *
 *  Problem:    Given two matrices, the task is to multiply them. 
 *              Matrices can either be square or rectangular
 *
 *  Input:  mat1[m][n] = { {1, 1}, {2, 2} }
 *          mat2[n][p] = { {1, 1}, {2, 2} }
 *  Output: result[m][p] = { {3, 3}, {6, 6} }            
 *
 ***/

#include<stdio.h>


int main(){
    int rws, clm;
    printf("Enter no. of rows and columns: \n");
    scanf("%d%d", &rws, &clm);

    int mat1[rws][clm], mat2[rws][clm], res[rws][clm];
    printf("Enter integers in matrix 1: \n");
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            scanf("%d", &mat1[count][in_count]);
        }
    }
    
    printf("Enter integers in matrix 2: \n");
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            scanf("%d", &mat2[count][in_count]);
        }
    }

    /** Making all the elements in the arr 0 **/
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            res[count][in_count] = 0;
        }
    }

    
    /** Logic for square matrix multiplication **/
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            for(int k = 0; k < clm; k++){
                res[count][in_count] += mat1[count][k] * mat2[k][in_count];
            }
        }
    }


    // print the matrix
    printf("\nMatrix 1:\n");
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            printf("%d\t", mat1[count][in_count]);
        }
        printf("\n");
    }

    printf("\nMatix 2:\n");
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            printf("%d\t", mat2[count][in_count]);
        }
        printf("\n");
    }
    
    printf("\nMat1 and Mat2 multiplication 2:\n");
    for(int count = 0; count < rws; count++){
        for(int in_count = 0; in_count < clm; in_count++){
            printf("%d\t", res[count][in_count]);
        }
        printf("\n");
    }
    
}
