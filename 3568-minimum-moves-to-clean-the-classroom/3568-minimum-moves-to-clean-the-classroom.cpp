class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size(),m=classroom[0].size();
        unordered_map<int,int>id;
        int sr=-1,sc=-1,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(classroom[i][j]=='L'){
                    id[i*m+j]=cnt;
                    cnt++;
                }
            }
        }
        int totm=(1<<cnt)-1;
        vector<vector<vector<int>>>best(n,vector<vector<int>>(m,vector<int>(totm+1,-1)));
        queue<vector<int>>q;
        q.push({sr,sc,0,energy,0});
        best[sr][sc][0]=energy;
        vector<int>dir={0,1,0,-1,0};
        while(!q.empty()){
            auto& it=q.front();
            int r=it[0],c=it[1],lit=it[2],en=it[3],dis=it[4];
            q.pop();
            if(lit==totm)return dis;
            if(en==0)continue;
            for(int i=0;i<4;i++){
                int nr=r+dir[i],nc=c+dir[i+1];
                if(nr<0||nr>=n||nc<0||nc>=m)continue;
                if(classroom[nr][nc]=='X')continue;
                int nlit=lit,nen=en-1;
                if(classroom[nr][nc]=='L'){
                    nlit=nlit|(1<<(id[m*nr+nc]));
                }
                if(classroom[nr][nc]=='R'){
                    nen=energy;
                }
                if(nen>best[nr][nc][nlit]){
                    best[nr][nc][nlit]=nen;
                    q.push({nr,nc,nlit,nen,dis+1});
                }
            }
        }
        return -1;
    }
};