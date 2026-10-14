class Solution {
public:
    struct cmp {
        bool operator()(pair<int,char> &a, pair<int,char> &b) {
            if(a.first!=b.first) {
                return a.first<b.first;
            } else {
                return a.second<b.second;
            }
        }
    };
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> heap;
        unordered_map<char, int> f;
        string res = "";

        for(int i=0; i<n; i++) {
            f[s[i]]++;
        }

        for(auto i:f) {
            heap.push({i.second, i.first});
        }

        while(!heap.empty()) {
            pair<int,char> p1 = heap.top();
            heap.pop();
            if(res.empty() || res.back() != p1.second) {
                res.push_back(p1.second);
                p1.first--;
                if(p1.first>0) heap.push(p1);
            } else {
                if(heap.empty()) {
                    return "";
                }

                pair<int,char> p2 = heap.top();
                heap.pop();
                res.push_back(p2.second);
                p2.first--;
                if(p2.first>0) heap.push(p2);

                heap.push(p1);
            }
        }

        return res;
    }
};