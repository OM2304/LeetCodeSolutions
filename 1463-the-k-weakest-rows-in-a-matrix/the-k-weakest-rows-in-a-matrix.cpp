class Solution {
    struct cmp {
        bool operator()(pair<int,int>&a, pair<int,int>&b) {
            if(a.first!=b.first) {
                return a.first<b.first;
            } else{
                return a.second<b.second;
            }
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> heap;

        for(int i=0; i<k; i++) {
            int count = 0;
            for(int j=0; j<m; j++) {
                count += mat[i][j];
            }
            heap.push({count, i});
        }

        for(int i=k; i<n; i++) {
            int count = 0;
            for(int j=0; j<m; j++) {
                count += mat[i][j];
            }

            if(count < heap.top().first) {
                heap.pop();
                heap.push({count, i});
            }
        }

        for(int i=0; i<k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};