class Solution {
public:
    string frequencySort(string s) {

        unordered_map <char , int> freq ;

        for (char &c : s) freq[c] ++ ;

        priority_queue<pair<int ,char>>pq ;

        for (auto &it : freq){
            int fqcy = it.second ;
            char ch = it.first ;
            pq.push({fqcy , ch}) ;
        }

        string result = "" ;

        while (!pq.empty()){
            int count = pq.top().first ;
            char ch = pq.top().second ;
            pq.pop() ;
            result += string(count , ch) ;
        }

        return result ;
        
    }
};