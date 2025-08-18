class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size() ;
        int k = 0 ;
        for (int i = 0 ; i < n ; i++){
            if(endWord == wordList[i]) break ;
            k ++ ;
        }
        if (k == n) return 0 ;

        queue<pair<string , int>>q ;
        unordered_set<string>st(wordList.begin() , wordList.end()) ;
        st.erase(beginWord) ;
        q.push({beginWord , 1}) ;


        int shortestSeq = 1 ;

        while (!q.empty()){
            string word = q.front().first ;
            int steps = q.front().second ;  
            q.pop() ;
            for (int i = 0 ; i < word.length() ; i++){
                char real = word[i] ;
                for (char c  = 'a' ; c <= 'z' ; c ++){
                    word[i] = c ;
                if(st.find(word) != st.end()){
                        if(word == endWord) return steps + 1 ;
                        st.erase(word) ;
                        q.push({word , steps + 1});
                    }
                }
                word[i] = real ;
            }
        }

        return shortestSeq ;

    }
};