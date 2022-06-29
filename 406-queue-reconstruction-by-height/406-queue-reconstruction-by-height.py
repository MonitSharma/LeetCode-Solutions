class Solution(object):
    def reconstructQueue(self, people): 
        group = {}
        for h,k in people:
            if h not in group:
                group[h] = []
            group[h].append([h,k])
        
        heights = sorted(group.keys(), reverse = True)
        answer = []
        while heights:
            tallest = heights.pop(0)
            if not answer:
                # list of [h,k]
                answer = sorted(group[tallest])
            else:
                # list of [h,k]
                nxt_ppl = sorted(group[tallest])
                tmp,i = [],0
                while nxt_ppl:
                    h,k = nxt_ppl.pop(0)
                    while i < k:
                        tmp.append(answer.pop(0))
                        i += 1
                    tmp.append([h,k])
                    i += 1
                
                answer = tmp + answer
                        
        return answer