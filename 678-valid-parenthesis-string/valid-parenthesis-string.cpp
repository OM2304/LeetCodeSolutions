class Solution {
public:
    vector<vector<int>> memo;

    bool check(string s, int index, int balance) {
        if(balance<0) return false;

        if(index == s.size()) return balance == 0;

        if(memo[index][balance] != -1) return memo[index][balance];

        bool ans = false;
        if(s[index] == '(') {
            ans = check(s, index+1, balance+1);
        }

        else if(s[index] == ')') {
            ans = check(s, index+1, balance-1);
        }
        else {
            bool asClosing = check(s, index + 1, balance - 1); 
            bool asOpening = check(s, index + 1, balance + 1); 
            bool asNothing = check(s, index + 1, balance); 
            
            ans = asClosing || asOpening || asNothing; 
        } 
        
        return memo[index][balance] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        memo.assign(n+1, vector<int>(n+1, -1));
        
        return check(s, 0, 0);
    }
};