class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = *max_element(piles.begin(), piles.end());
        int ans=hi, l=1;

        while(l<=hi) {
            int m = (l+hi)/2;
            long long hrs=0;

            for(int i=0; i<piles.size(); i++) {
                hrs += ceil((double)piles[i] / m);
            }

            if(hrs<=h) {
                ans=m;
                hi=m-1;
            } else {
                l=m+1;
            }
        }
        return ans;
    }
};