class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st ;
        int n = asteroids.size() ;
        
        for (int i = 0 ; i < n ; i++){
            bool flag = true ;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if (abs(asteroids[i]) > abs(st.top())){
                    st.pop() ;
                    continue ;                 
                }
                else if (abs(asteroids[i]) == abs(st.top())){
                    st.pop() ;
                    flag = false ;
                    break ;
                }
                
                else {

                    flag = false ;   
                    break ;

                }          
               
            }

            if (flag) st.push(asteroids[i]) ;
        }

        vector<int> result ;
        while (!st.empty()){
            int top = st.top() ;
            st.pop() ;
            result .push_back (top) ;
        }

        reverse(result.begin() , result.end()) ;
        return result ;
    }
};