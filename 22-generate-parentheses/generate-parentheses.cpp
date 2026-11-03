class Solution {
public:
    void fun(int open, int close, int n, string& tmp, vector<string>& res) {
        if(open==n && close==n) {
            res.push_back(tmp);
            return;
        }

        //open '(' :
        if(open < n) {
            tmp.push_back('(');
            fun(open+1, close, n, tmp, res);
            tmp.pop_back(); // backtrack
        }

        //close ')' :
        if(close < open) {
            tmp.push_back(')');
            fun(open, close+1, n, tmp, res);
            tmp.pop_back(); // backtrack
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0;
        int close = 0;
        string tmp;

        fun(open, close, n, tmp, res);
        return res;
    }
};