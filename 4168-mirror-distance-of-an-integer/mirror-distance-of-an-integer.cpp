class Solution {
public:
    int reverse(int n) {
        string s = to_string(n);
        std::reverse(s.begin(), s.end());
        return stoi(s);
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};