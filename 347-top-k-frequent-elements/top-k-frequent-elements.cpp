class Solution {
    struct cmp {
        bool operator() (pair<int, int> &a, pair<int, int> &b) {
            if(a.first!=b.first)
                return a.first>b.first;
            else
                return a.second>b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;

        for(int i=0; i<n; i++) {
            f[nums[i]]++;
        }

        for(auto i: f) {
            int ele = i.first;
            int frq = i.second;
            pair<int, int> curr = {frq, ele};
            
            if(heap.size()<k)   heap.push(curr);
            else if(frq > heap.top().first) {
                heap.pop();
                heap.push(curr);
            }
        }

        vector<int> res;
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

// unordered_map<int,int> f;
//         int i;
//         for(i=0; i<nums.size(); i++) {
//             f[nums[i]]++;
//         }

//         vector<pair<int,int>> v;
//         for(auto i:f) {
//             v.push_back(i);
//         }

//         sort(v.begin(), v.end(), [](pair<int,int>a, pair<int,int>b) {
//             return a.second>b.second;
//         });

//         vector<int> ans;
//         for(i=0; i<k; i++) {
//             ans.push_back(v[i].first);
//         }
//         return ans;