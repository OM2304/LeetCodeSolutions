bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int r = matrixSize;
    int c = *matrixColSize;

    int l = 0;
    int h = (r*c)-1;
    
    while(l<=h) {
        int guess = l + (h-l) / 2;
        int row = guess/c;
        int col = guess%c;

        if(matrix[row][col]==target) return true;

        if(matrix[row][col]<target) l = guess+1;
        else h = guess-1;
    }
    return false;
}