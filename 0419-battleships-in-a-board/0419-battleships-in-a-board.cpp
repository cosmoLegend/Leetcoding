class Solution {
public:
    void dfs (int i , int j , vector<vector<char>> & board , int n , int m){
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'X' ) return ;

        board[i][j] = '.' ;

        dfs (i + 1 ,  j , board , n , m) ;
        dfs (i , j + 1 , board , n , m) ;
        dfs (i , j - 1 , board , n , m) ;
        dfs (i - 1 , j , board , n , m) ;
    }

    int countBattleships(vector<vector<char>>& board) {
        int ans = 0 ;
        int n = board.size() ;
        int m = board[0].size() ;


        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j ++){
                if (board[i][j] == 'X'){
                    ans ++ , dfs (i , j , board , n , m) ;
                }
            }
        }


        return ans ;
    }
};