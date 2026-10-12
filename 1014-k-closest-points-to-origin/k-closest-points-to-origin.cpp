class Solution {
public:
    struct cmp {
        bool operator()(pair<float, int>&a, pair<float, int>&b) {
            if(a.first!=b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> res;
        priority_queue<pair<float, int>, vector<pair<float,int>>, cmp> heap;

        for(int i=0; i<n; i++) {
            float dis = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            heap.push({dis, i});
        }

        for(int i=0; i<(n-k); i++) {
            heap.pop();
        }

        for(int i=0; i<k; i++) {
            pair<float, int> curr = heap.top();
            res.push_back({points[curr.second][0], points[curr.second][1]});
            heap.pop();
        }
        return res;
    }
};