class Solution {
public:
    struct cmp {
        bool operator()(int a, int b) {
            return a<b;
        }
    };

    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int, vector<int>, cmp> heap;

        for(int i=0; i<n; i++) {
            heap.push(stones[i]);
        }

        int x;
        int y;
        while(!heap.empty()) {
            y = heap.top();
            heap.pop();
            if(heap.empty()) {
                return y;
            }

            x = heap.top();
            heap.pop();
               
            if(x<y) {
                y = y-x;
                heap.push(y);
            }
        }
        
        if(heap.empty()) return 0;
        return heap.top();
    }
};