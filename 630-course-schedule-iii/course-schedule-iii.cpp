class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<vector<int>> v;
        priority_queue<int> pq;
        int n = courses.size();
        for(int i=0; i<n; i++) {
            v.push_back({courses[i][1], courses[i][0]});
        }
        sort(v.begin(), v.end());

        int duration = 0;
        for(int i=0; i<n; i++) {
            duration += v[i][1];
            pq.push(v[i][1]);
            if(v[i][0] < duration) {
                duration-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};