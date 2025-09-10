

struct HLD{
    // answer quereis in trees max/min/sum between two nodes with updates
    /*
      if values is on edges 
      then make the value of the edge on the node down it with dfs order 
       1
       2
      3 4
      then edge 1-2 will be on 2
      then edge 2-3 will be on 3
      then edge 2-4 will be on 4 and so on
    */
   vector<int> parent, depth, heavy, head, pos;
   int cur_pos=0,n;
    int trash;
   function<int(int,int)>op;    
   SegmentTree<int>seg;
    vector<int>arr;
     HLD(int n,vector<vector<int>>&adj ,function<int(int,int)>op ,int trash){
       parent=depth=head=pos=vector<int>(n+1);
       heavy=vector<int>(n+1,-1);
       arr=vector<int>(n+1);
       dfs(1,adj);
       decompose(1,1,adj);
       this->trash = trash;
       this->op  = op;
       this->n = n;
     }

     int dfs(int node,vector<vector<int>>&adj){
          int size = 1;
    int max_c_size = 0;

    for (int c : adj[node])if (c != parent[node]) {
            parent[c] = node, depth[c] = depth[node] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[node] = c;
          }
              return size;
     }

     void decompose(int v, int h, vector<vector<int>>& adj) { // 1-based
    head[v] = h, pos[v] = ++cur_pos;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

    void build(vector<int>&vals){ // vector of vals of nodes 
        
        seg=SegmentTree<int>(n+1,op,trash);

        for(int i=1;i<=n;++i)
            arr[pos[i]] = vals[i];

        seg.build(arr);
    }

    int qurey(int a,int b){
     
      int ans = trash;
      while(head[a]!=head[b]){ // not in same componnent 
          
          if(depth[ head[a] ] < depth[ head [b] ])
          swap(a,b);
          // move up from deepest node (a)
          int cur = seg.get(pos[head[a]] , pos[a]); // from head to me .. head always above me
          ans=op(ans,cur); 
          a = parent[head[a]]; // move to the next chain 
      }   

      if(depth[a]<depth[b])swap(a,b); // now in same chain
                                         //if values on edges will be from (pos[b]+1,pos[a])  
      int cur = seg.get(pos[b],pos[a]); // and need to check if(a!=b) then go get from  (pos[b]+1,pos[a])

      ans=op(ans,cur);
      return ans;
    }

    void update(int node,int new_val){
       arr[ pos[node] ] = new_val;
       seg.updatePos(pos[node],new_val);
    }

   };
