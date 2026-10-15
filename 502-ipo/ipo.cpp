class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector <pair<int,int>> choices;
        for(int i=0; i<n; i++) {
            choices.push_back({capital[i], profits[i]});
        }
        sort(choices.begin(), choices.end());

        priority_queue<int> heap;
        int idx=0;
        while(k--) {
            while(idx<n) {
                if(choices[idx].first > w)    break;

                heap.push(choices[idx].second);
                idx++;
            }

            if(heap.empty()) return w;

            w = w + heap.top();
            heap.pop();
        }

        return w;       
    }
};