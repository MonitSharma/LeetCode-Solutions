class Solution:
  
  def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
    ans = 0
    summ = 0
    
    A = sorted([(num2, num1)
               for num1, num2 in zip(nums1, nums2)], reverse=True)
    minHeap = []

    for num2, num1 in A:
      heapq.heappush(minHeap, num1)
      summ += num1
      if len(minHeap) > k:
        summ -= heapq.heappop(minHeap)
      if len(minHeap) == k:
        ans = max(ans, summ * num2)

    return ans