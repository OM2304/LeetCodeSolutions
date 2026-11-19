class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, great;
        for(int i=0; i<nums.size(); i++) {
            if(pivot == nums[i]) equal.push_back(nums[i]);
            else if(pivot < nums[i]) great.push_back(nums[i]);
            else less.push_back(nums[i]);
        }

        for(int i=0; i<equal.size(); i++) {
            less.push_back(equal[i]);
        }

        for(int i=0; i<great.size(); i++) {
            less.push_back(great[i]);
        }
        return less;
    }
};

