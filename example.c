#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MATRIXSIZE 3

int findDeterminant(int * matrix, int size){
    if(size == 1){
        // If size is 1x1 return the one remaining element
        return *(matrix);
    }

    // Create submatrices 
    int subMatrices [size] [size-1] [size-1];
    int subMtrIndexes [size];
    // Set all index counters to 0
    memset(subMtrIndexes, 0, sizeof(subMatrices));
    
    // Go through first matrix, create submatrices
    // Omit first row
    for(int row = 1; row < size; row++){
        for(int col = 0; col < size; col++){
            for(int subMtr = 0; subMtr < size; subMtr++){
                if(col != subMtr){
                    *((int *)subMatrices + (int)pow(size-1,2)*subMtr + subMtrIndexes[subMtr]) = *((int *)matrix + row*size + col);
                    subMtrIndexes[subMtr]++;
                }
            }
        }
    }
    // Calculate determinant
    int determinant = 0;
    for(int i = 0; i < size; i++){
        determinant += *(matrix + i) * (int)pow(-1,i) * findDeterminant((int * )subMatrices[i],size-1);   
    }
    return determinant;
}

int main(){
    int testMatrix [MATRIXSIZE] [MATRIXSIZE] = {
        {1,2,0},
        {-1,2,0},
        {0,1,3}
    };

    printf("%i",findDeterminant((int *) testMatrix, MATRIXSIZE));
    return 0;
}