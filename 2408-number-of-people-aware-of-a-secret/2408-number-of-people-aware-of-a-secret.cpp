class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        queue<pair<int, long long>> q; 
        q.push({1, 1}); // {day_learned, count}
        
        int day = 1;
        while (!q.empty() && day <= n) {
            int size = q.size();
            long long cnt = 0;
            
            while (size--) {
                auto [learnDay, people] = q.front();
                q.pop();
                
                if (learnDay + forget > day) { // still remember
                    if (learnDay + delay <= day) {
                        cnt = (cnt + people) % MOD;
                    }
                    q.push({learnDay, people}); // keep them in queue
                }
            }
            
            if (cnt > 0) {
                q.push({day, cnt}); // new learners on this day
            }
            
            day++;
        }
        
        long long ans = 0;
        while (!q.empty()) {
            ans = (ans + q.front().second) % MOD;
            q.pop();
        }
        
        return (int)ans;
    }
};
