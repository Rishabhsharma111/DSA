class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>result(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();

            int i=p.first;
            int j=p.second;

            for(auto d:dir){
                int new_r=i+d[0];
                int new_c=j+d[1];

                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&result[new_r][new_c]==-1){
                    result[new_r][new_c]=result[i][j]+1;
                    q.push({new_r,new_c});

                }
                
            }
        }

        return result;

         
        
    }
};