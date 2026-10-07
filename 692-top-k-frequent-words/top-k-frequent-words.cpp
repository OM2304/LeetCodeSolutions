class Solution {
public:
    struct cmp {
        bool operator() (pair<int, string> &a, pair<int, string> &b) {
            if(a.first!=b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        int n = words.size();

        for(int i=0; i<n; i++) {
            f[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> heap;
        for(auto i : f) {
            string ele = i.first;
            int frq = i.second;
            pair<int, string> curr = {frq, ele};

            if(heap.size() < k) {
                heap.push(curr);
            }

            else if(frq > heap.top().first || (frq==heap.top().first && ele < heap.top().second)) {
                heap.pop();
                heap.push(curr);
            }
        }

        vector<string> res;
        for(int i=0; i<k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};