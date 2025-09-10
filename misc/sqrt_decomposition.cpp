/*
examples for sqrt decompostitoon 

1- divide queries into sqrt(q)

each sqrt(q) make something like bfs,sort
it will be  time * q/sqrt(q)

2- if we have to update in o(n) each query 
think to divide it into sqrt(n) blocks
so each update will be sqrt(n) not o(n)


3 - solve the problem with simple soluition then try to optimize
*/

  2024 : 

           struct SqrtD
    {
        int block,NoBLocks;
        vector<vector<ll>>D;
        vector<ll>a;
        SqrtD(vector<ll>v){
          a = v;
          int n = sz(a);  
         block = sqrtl(n)+1;
         NoBLocks = (n+block-1)/block;
         D = vector<vector<ll>>(NoBLocks);
 
         for(int i=0;i<n;++i)
            D[i].push_back(a[i]);
 
        for(int i=0;i<NoBLocks;++i)
        sort(D[i].begin(),D[i].end());
        }
 
      ll get(int l,int r,int x){ // number of elementes <=x
        ll sum = 0;
 
        while(l<=r && l%block)
            sum+=a[l++]<=x;
 
        while(l+block<=r){
           sum+=upper_bound(D[l/block].begin(),D[l/block].end(),x)-D[l/block].begin();
            l+=block;
        }
        while(l<=r)
            sum += a[l++]<=x;
 
        return sum;
      }
 
 
      void update(int pos,int val){
        int it = lower_bound(D[pos/block].begin(),D[pos/block].end(),a[pos])-D[pos/block].begin();
        D[pos/block][it] = val;
        a[pos] = val;
        sort(D[pos/block].begin(),D[pos/block].end());
      }
            
    };   
