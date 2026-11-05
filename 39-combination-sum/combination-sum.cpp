class Solution {
public:
    void fun(vector<int>& arr, int n, int idx,vector<int>& diary, int sum, vector<vector<int>>& res, int tar) {
        if(idx==n) {
            if(sum==tar) {
                res.push_back(diary);
            }
            return;
        }

        //Choice 1:
        fun(arr, n, idx+1, diary, sum, res, tar);

        //Choice 2:
        if(sum + arr[idx] <= tar) {
            diary.push_back(arr[idx]);
            sum += arr[idx];
            fun(arr, n, idx, diary, sum, res, tar);
            diary.pop_back();
            sum-= arr[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum=0;
        int idx=0;
        vector<vector<int>> res;
        vector<int> diary;

        fun(candidates, n, idx, diary, sum, res, target);
        return res;
    }
};