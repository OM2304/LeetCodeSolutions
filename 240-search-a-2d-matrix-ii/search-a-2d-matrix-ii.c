bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int r = matrixSize-1;
    int c = 0;

    while(r>=0 && c<*matrixColSize) {
        if(matrix[r][c] == target) return true;

        if(matrix[r][c] > target) r--;
        else c++;
    }
    return false;
}