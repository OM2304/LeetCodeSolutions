class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int el : nums) {
            if(el%3 != 0) count++;
        }
        return count;
    }
};