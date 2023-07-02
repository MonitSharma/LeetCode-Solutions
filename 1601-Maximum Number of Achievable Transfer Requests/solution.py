class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
            def cyclic(path): return requests[path[0]][0]==requests[path[-1]][1]
            def joins(path, e): return requests[e][0] == requests[path[-1]][1]
            def overlapping(c1, c2): return any([True for e in c1 if e in c2])
            def include(cycle, cycles): return [c for c in cycles if not overlapping(c, cycle)] + [cycle]
            def value(c): return len(sum(c,[]))

            cycles = [[e] for e in range(len(requests)) if requests[e][0]==requests[e][1]]
            paths = [[e] for e in range(len(requests))]
            new_paths = []
            for i in range(2, n+1):                
                for path in paths:                    
                    for e in [ e for e in range(len(requests)) if e not in path and joins(path,e) ]:                        
                        if cyclic(path+[e]):                            
                            new_res = include(path+[e], cycles)                            
                            if value(new_res) > value(cycles):
                                cycles = new_res
                        else:
                            new_paths.append(path+[e])                    
                paths = new_paths
                new_paths = []        
            return value(cycles)