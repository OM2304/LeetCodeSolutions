class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int> f;
        vector<int> res;

        for(int i=0; i<friends.size(); i++) {
            int idx = find(order.begin(), order.end(), friends[i])- order.begin();
            res.push_back(idx);
        }
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) {
            res[i] = order[res[i]];
        }
        return res;
    }
};