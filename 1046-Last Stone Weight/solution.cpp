class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
      //Sort the array using heap/Priority Queue
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
      //If only one element return that element
        if (pq.size()==1) return pq.top();
      //Repeat the process till we left wtho zero or one element.
        while(pq.size()>1){
          //Pick two greater elements
         int   x=pq.top();
            pq.pop();
         int   y=pq.top();
            pq.pop();
            if(x==y) continue;  
            else pq.push(x-y);
            
        }
        int ans;
        if (!pq.empty()) ans=pq.top();
        else ans=0;
        return ans;
    }
};