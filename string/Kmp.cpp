
  //s = carcard 
  // carcarcar   
   struct KMP{
                  int n;
                  string s;
                  vector<int>fail;
                  vector<vector<int>>aut;
      
                  KMP(string str=""){
                     s = str;
                     n = s.size();
                    fail = vector<int>(n);
                    aut=vector<vector<int>>(n,vector<int>(26));
                    failure();
                  }
      
                       void failure(){
      
                     for(int i=1;i<sz(s);++i){
                         fail[i] = getNext2(fail[i-1],s[i]);
                     }
                  }
      
      
                  void ComputeAll(){
      
                    for (int i = 0; i <s.size(); i++) {
      
                        for (int c = 0; c < 26; c++) {
                          if (i > 0 && 'a' + c != s[i])
                             aut[i][c] = aut[fail[i-1]][c];
                        else
                         aut[i][c] = i + ('a' + c == s[i]);
                        }
                     }
      
                  }
      
                  int getNext(int j,char c){ // if i currntlty matches j chars and get now char c what is the longest match i can get
                      return aut[j][c-'a'];
                  }
      
                  int getNext2(int j,char c){
      
                    while(j>0 && s[j]!=c)
                      j = fail[j-1];
      
                    if(s[j]==c) ++j;
      
                    return j;
                  }
      
                  int get_period_of_first_K(int k){
                     int lst = fail[k-1];
                     int period = k - lst;
                     return (k%period==0? period : -1);
      //                return (k%period==0? k/period : -1);
                  }
      
                  vector<int>CountPrefixs(){
      
                    vector<int>occ(n+1);
                    for(int i=0;i<n;++i)
                      occ[fail[i]]++;
      
                     for(int i=n-1;i>0;--i){
                      occ[fail[i-1]]+=occ[i];
                     }
      
                     for(int i=0;i<=n;++i)
                      occ[i]++;
      
                     return occ; //  from 1 to n represent the length of the prefix
                  }
                  // think of    S ,  SS , Rev(S) , S@S
      
                };
  
