bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int i, r, m, low , high;
    low = 0;
    high = matrixSize-1;

    while(low<=high) {
        m = low + (high-low)/2;

        if(matrix[m][0]<=target && matrix[m][*matrixColSize-1]>=target) {
            low = 0;
            high = *matrixColSize-1;
            i = m;
            while(low<=high) {
                m = low + (high-low)/2;
                if(matrix[i][m]==target) return true;

                if(matrix[i][m]<target) low = m+1;
                else high = m-1;
            }
            return false;
        }

        if(matrix[m][0]>target) high = m-1;
        else low = m+1;
    }
    return false;
}