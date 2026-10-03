1class Solution {
2public:
3int check(vector<vector<int>>& a, int n, int m, int guess) {
4    int row = n-1;
5    int col = 0;
6    int count = 0;
7    while(row>=0 && col<m) {
8        if(a[row][col] <= guess) {
9            count = count + (row+1);
10            col++;
11        } else{
12            row--;
13        }
14    }
15    return count;
16}
17    int kthSmallest(vector<vector<int>>& matrix, int k) {
18        int n = matrix.size();
19        int m = matrix[0].size();
20
21        int l = matrix[0][0];
22        int h = matrix[n-1][m-1];
23        int res = -1;
24
25        while(l<=h) {
26            int guess = l + (h-l) / 2;
27            int ans = check(matrix, n, m, guess);
28
29            if(ans<k) {
30                l = guess+1;
31            } else {
32                res = guess;
33                h = guess-1;
34            }
35        }
36        return res;
37    }
38};