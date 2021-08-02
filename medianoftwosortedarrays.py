class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # merge the array
        # and then find the median
        i = 0
        j = 0
        n = len(nums1)
        m = len(nums2)
        m1 , m2 = -1, -1
        
        # checking even and odd
        if((m+n)%2 == 1):
            for count in range(((n+m)//2) + 1):
                if( i != n and j != m):
                    if nums1[i] > nums2[j]:
                        m1 = nums2[j]
                        j += 1
                    else:
                        m1 = nums1[i]
                        i += 1
                elif(i < n):
                    m1 = nums1[i]
                    i += 1
                    
                else:
                    m1 = nums2[j]
                    j += 1
            return m1
        
        else:
            for count in range(((n+m)//2)+ 1):
                m2 = m1
                if(i != 1 and j != m):
                    
                    if(nums1[i] > nums2[j]):
                        m1 = nums2[j]
                        j += 1
                    else:
                        m1 = nums1[i]
                        i+= 1
                elif(i < n) :
                    m1 = nums1[i]
                    i += 1
                    
                    
                else:
                    m1 = nums2[j]
                    j+=1 
            return (m1+m2)//2
        
        
        
        
        # median
        
        
        
        