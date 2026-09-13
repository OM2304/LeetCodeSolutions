class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int h = arr.size()-1;
        int res = 0;

        while(l<=h) {
            int mid  = l + (h-l) /2;
            if(arr[mid]<arr[mid-1]) {
                res = mid-1;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return res;
    }
};