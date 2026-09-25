#include <algorithm> // Required for std::max_element
class Solution {
public:
    long long check(vector<int>& a, int n, int speed) {
        long long hours = 0;
        for(int i=0; i<n; i++) {
            hours = hours + (a[i]/speed);
            if(a[i]%speed != 0) hours++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        int n = piles.size();

        while(low<=high) {
            int guess = low + (high-low) / 2;
            long long hours = check(piles, n, guess);

            if(hours>h) low = guess+1;

            else {
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};