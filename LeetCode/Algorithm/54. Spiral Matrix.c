/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int i = 0, j = 0;
    int rowTemp = matrixRowSize - 1;
    int rowTemp1 = 0;//第0行
    
    int colTemp = matrixColSize - 1;
    int colTemp1 = 0;//第0列
    
    for(i = colTemp1; i < matrixRowSize; i++)
    {
        printf("%d",matrix[rowTemp1][i]);//打印最上面
    }
    rowTemp1++;
    for(j = rowTemp1; j < matrixColSize; j++)
    {
        printf("%d",matrix[j][colTemp]);//打印最右边
    }
    for(i--; )
    
}