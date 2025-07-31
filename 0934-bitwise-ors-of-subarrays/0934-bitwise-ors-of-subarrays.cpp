class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur ;
        unordered_set<int> res ;

        for (int &i : A){
            unordered_set<int> next ;
            next.insert(i) ;

            for (auto &val : cur){
                next.insert(val | i) ;

            }

            cur = next ;
            res.insert(cur.begin() , cur.end()) ;

        }

        return res.size() ;

    }
};
