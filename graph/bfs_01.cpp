  int n;
  vector<vector<pair<int,int>>>v;
 void bfs_01(int src,int dis){

  deque<int>qu;
  qu.push_front(src);
  vector<bool>vis(n);
  vis[src] = 1;
  vector<int>dist(n+1,1e9);
  dist[src] = 0;
  while(!qu.empty()){

   int node = qu.front();
   qu.pop_front();

   for(auto &[j,w] : v[node]){

    if(dist[j] > w+dist[node]){

     dist[j] = w+ dist[node];

      if(w==1)
        qu.push_back(j);
      else qu.push_front(j);
    }

   }
  }

 }
