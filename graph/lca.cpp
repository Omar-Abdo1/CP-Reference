  class LCA{
  
    public :
        using T = int;
      vector<vector<int>>up;
      vector<int>depth,tin,tout;
      int LG,timer=0;
  
        LCA(int sz){
            LG = log2(sz) + 3;
           tin = tout = depth = vector<int>(sz+2);
           up = vector<vector<int>>(sz+1,vector<int>(LG+4));
        }
  
        void Build(int node , int par , vector<vector<T>>&graph){
             dfs(node,par,graph);
        }
  
        void dfs(int v, int p,vector<vector<T>>&graph)
        {
  
      tin[v] = ++timer;
  
      for (auto &u : graph[v])if(u!=p){
          depth[u] = depth[v] + 1;
          up[u][0] = v;
          for(int j=0;j<=LG;++j)
              up[u][j+1] = up[up[u][j]][j];
        dfs(u,v,graph);
      }
  
      tout[v] = ++timer;
  }
  
  bool is_ancestor(int u, int v)
  {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
  }
  
     int getKTH(int a,int k){
  
              if(depth[a]<k)
                   return -1;
  
            for(int j=0;j<=LG;++j){
               if(k&(1<<j)){
                  a = up[a][j];
               }
            }
            return a;
         }
  
  
    ll lca(int a,int b){
  
       if(depth[a]<depth[b])
          swap(a,b);
  
        int k = depth[a] -depth[b];
  
        for(int j=LG;j>=0;--j){
  
          if(k&(1<<j))
              a=up[a][j];
        }
  
      if(a==b) return a;
  
       for(int j=LG;j>=0;--j){
  
          if(up[a][j]!=up[b][j])
              {
                  a=up[a][j];
                  b=up[b][j];
              }
        }
  
        return up[a][0];
      }
  
      ll dis(int a,int b){
       return depth[a] + depth[b] - 2*depth[lca(a,b)];
     }
  
  };
