#include<string>
class Solution {
public:
    int digitFrequencyScore(int n) {
        int res=0;
        unordered_map<int, int> f;
        string s = to_string(n);
        for(char c:s) {
            f[c-'0']++;
        }
        for(auto x:f) {
            int d = x.first;
            int frq = x.second;
            res += (d*frq);
        }
        return res;

    }
};