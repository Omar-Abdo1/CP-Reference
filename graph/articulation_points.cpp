class Tarjan{
            
           public  :
          vector<vector<int>>comp;
         vector<pair<int,int>>Bridges;
         vector<bool>Art,InStack;
         int timer,child;
         vector<int>low,idx,id;
         stack<int>st;

            Tarjan(int n){
              Art = InStack = vector<bool>(n+2);
              id =  low = idx = vector<int>(n+2);
              timer = 0;
            }

            void dfs1(int i,int par,vector<vector<int>>&adj){
                low[i] = idx[i] = ++timer;
                   
                   for(auto &j : adj[i]){
                       if(low[j]==0){
                          if(par==-1)++child;
                          dfs1(j,i,adj);
                          low[i] = min(low[i],low[j]);
                          if(low[j]>idx[i])
                              Bridges.push_back({i,j});
                          if(low[j]>=idx[i])
                              Art[i] = 1;
                       }
                       else if(j!=par)
                          low[i] = min(low[i],idx[j]);
                   }
            }

             void dfs2(int i,vector<vector<int>>&adj){
                 idx[i] = low[i] = ++timer;
               InStack[i] = 1;
               st.push(i);
               for(auto &j : adj[i]){
                 
                 if(idx[j]==0)
                    dfs2(j,adj);

                 if(InStack[j])
                 low[i]=min(low[i],low[j]);
               }
               if(low[i]==idx[i]){
                    






               } 
            }

           void Get_BR_AP(int n,vector<vector<int>>&adj){
                  
                 for(int i=1;i<=n;++i){
                     if(idx[i]==0)
                        {
                          child = 0;
                          dfs1(i,-1,adj);
                          Art[i] = child>1;
                        }
                 }
           }

           void Get_SCC(int n,vector<vector<int>>&adj){
                    for(int i=1;i<=n;++i)
                     if(idx[i]==0)
                         dfs2(i,adj);
           }  
        };
