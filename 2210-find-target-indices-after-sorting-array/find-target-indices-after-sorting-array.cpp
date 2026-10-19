class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int h = n-1;

        vector<int> res;
        int ans = -1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid]>=target) {
                if(nums[mid]==target) ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        if(ans == -1) {
            return {};
        }

        for(int i=ans; i<n && nums[i]==target; i++) {
            res.push_back(i);
        }
        return res;
    }
};