class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        d = dict()
        heap = []
        for ele in nums:
            if ele in d:
                d[ele] += 1
            else:
                d[ele] = 1

        for ele, freq in d.items():
            heapq.heappush(heap, (-freq, ele))
        
        ans = []
        for i in range(k):
            freq, ele = heapq.heappop(heap)
            ans.append(ele)
        return ans
        