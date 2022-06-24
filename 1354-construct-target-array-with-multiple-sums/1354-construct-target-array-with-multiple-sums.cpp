class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        unsigned int sum = 0;
        for (int num : target)
            sum += num, pq.push(num);
        while (pq.top() != 1) {
            int num = pq.top();
            pq.pop();
            sum -= num;
            if (num <= sum || sum < 1) return false;
            num %= sum, sum += num, pq.push(num ? num : sum);
        }
        return true;
    }
};