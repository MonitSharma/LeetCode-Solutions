class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        pq = []
        for val in nums:
            heapq.heappush(pq, val)
            if len(pq) > k:
                heapq.heappop(pq)

        return heapq.heappop(pq)