class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        triangle.push_back({1});
        triangle.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int>v(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) v[j]=1;
                else v[j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
            triangle.push_back(v);

        }
        return triangle;
    }
};