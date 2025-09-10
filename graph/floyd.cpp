

 void floyd(){
   
   for(int k=1;k<=n;++k){
     
     for(int i=1;i<=n;++i){
        
        for(int j=1;j<=n;++j){
           
           dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);  
             
           }
        
        }
     }
     
   }
   
    void TransitiveClosure()
{
	// assume matrix is 0 for disconnect, 1 is connect
	// we only care if a path exist or not, not a shortest path value

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] |= (adj[i][k] & adj[k][j]);
}

void minimax()
{
	// find path such that max value on road is minimum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void maximin()
{
	// find path such that min value on road is maximum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]) );
}


void longestPathDAG()
{
	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void countPaths()
{
	// 1- assume graph is DAG

	lp(k, n) lp(i, n) lp(j, n) 	// Floyd warshal for counting #of paths
		adj[i][j] += adj[i][k] * adj[k][j];

}
