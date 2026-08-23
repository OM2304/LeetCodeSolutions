class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int no_deletion = arr[0];
        int deletion = 0;
        int res = arr[0];

        for(int i=1; i<arr.size(); i++) {
            int power_used = deletion;
            int power_not_used = no_deletion;

            int v1 = arr[i];
            int v2 = power_not_used + arr[i];

            int v3 = power_used + arr[i];
            int v4 = power_not_used;

            res = max(res, max(v1, max(v2, max(v3, v4))));
            no_deletion = max(v1, v2);
            deletion = max(v3, v4);
        }
        return res;
    }
};