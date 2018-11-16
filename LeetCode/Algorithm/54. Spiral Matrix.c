/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int i = 0, j = 0;
    int rowTemp = matrixRowSize - 1;
    int rowTemp1 = 0;//第0行

    int colTemp = matrixColSize - 1;
    int colTemp1 = 0;//第0列

    int* ans = (int*)malloc((matrixColSize * matrixRowSize +1) * sizeof(int));
    long count=0;

    for(;;)
    {
        //Print the first line
        for(j = colTemp1; j <= colTemp; j++)
        {
            ans[count] = matrix[rowTemp1][j];
            count++;
        }
        rowTemp1++;
        if(rowTemp < rowTemp1 || colTemp < colTemp1)
            break;

        //Print the right line
        for(i = rowTemp1; i <= rowTemp; i++)
        {
            ans[count] = matrix[i][colTemp];
            count++;
        }
        colTemp--;
        if(rowTemp < rowTemp1 || colTemp < colTemp1)
            break;

        //Print the bottom line
        for(j = colTemp;j >= colTemp1;j-- )
        {
            ans[count] = matrix[rowTemp][j];
            count++;
        }
        rowTemp--;
        if(rowTemp < rowTemp1 || colTemp < colTemp1)
            break;

        //Print the left line
        for(i = rowTemp;i >= rowTemp1;i--)
        {
            ans[count] = matrix[i][colTemp1];
            count++;
        }
        colTemp1++;

        if(rowTemp < rowTemp1 || colTemp < colTemp1)
            break;
    }
    return ans;
}
