class Solution {
public:
    unordered_map<char, string> f;
    void fun(string &s, int n, int idx, string &diary, vector<string> &res) {
        if(idx==n) {
            res.push_back(diary);
            return;
        }

        string choices = f[s[idx]];
        for(int j=0; j<choices.size(); j++) {
            diary.push_back(choices[j]);
            fun(s, n, idx+1, diary, res);
            diary.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int n = digits.size();
        string diary = "";
        vector<string> res;
        fun(digits, n, 0, diary, res);
        return res;
    }
};