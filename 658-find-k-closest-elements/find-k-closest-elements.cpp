class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if(a.first!=b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
        vector<int> res;

        for(int i=0; i<k; i++) {
            int dis = abs(arr[i]-x);
            heap.push({dis, arr[i]});
        }

        for(int i=k; i<n; i++) {
            int dis = abs(arr[i]-x);
            if(heap.top().first > dis) {
                heap.pop();
                heap.push({dis, arr[i]});
            }
        }

        for(int i=0; i<k; i++) {
            int ele = heap.top().second;
            res.push_back(ele);
            heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};