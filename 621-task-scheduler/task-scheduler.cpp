class Solution {
public:

    struct cmp {
        bool operator() (pair<int, char>&a, pair<int, char>&b) {
            if(a.first!=b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> nextSeat;
        unordered_map<char,int> f;

        for(int i=0; i<tasks.size(); i++) {
            f[tasks[i]]++;
            nextSeat[tasks[i]] = 1;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for(auto i : f) {
            pq.push({i.second, i.first});
        }

        int index = 1;
        while(!pq.empty()) {
            vector<pair<int, char>> v;

            while(!pq.empty()) {
                pair<int,char> p1 = pq.top();
                pq.pop();
                int frq = p1.first;
                int child = p1.second;
                int seat = nextSeat[child];

                if(seat<=index) {
                    frq--;
                    int next = index+n+1;
                    if(frq>0) pq.push({frq, child});

                    nextSeat[child] = next;
                    break;
                } else {
                    v.push_back(p1);
                }
            }
            for(int i=0; i<v.size(); i++) {
                pq.push(v[i]);
            }
            index++;
        }
        return index-1;
    }
};