 int pw1[N+1],pw2[N+1],inv1[N+1],inv2[N+1];
 
         int exp(int x, int n, int m) {
                     x %= m;
               int res = 1;
              while (n > 0) {
                 if (n % 2 == 1) { res =mul(res,x,m);}
                  x = mul(x,x,m);
                  n>>=1;
               }
                     return res%m;
            }
 
            void Hash(int Base1=31 , int Base2=37){
                  pw1[0]=inv1[0]=1;
                  int minv1 = exp(Base1,MOD-2,MOD);
                for(int i=1;i<=N;++i){
                     pw1[i]=mul(pw1[i-1],Base1,MOD);
                     inv1[i] = mul(inv1[i-1],minv1,MOD);
                }
                  pw2[0]=inv2[0]=1;
                  int minv2 = exp(Base2,MOD-2,MOD);
                for(int i=1;i<=N;++i){
                     pw2[i]=mul(pw2[i-1],Base2,MOD);
                     inv2[i] = mul(inv2[i-1],minv2,MOD);
                }
            }
 
            struct Hashing{
 
              vector<int>pre1,pre2;
              string s;
 
               Hashing(string s){
                   this->s = s;
                 pre1=pre2=vector<int>(s.size());
                 calc_pre_Hash();
               }
 
             int get_Hash_value(bool bs){
                 return !bs ? pre1.back() : pre2.back();
             }
 
             void calc_pre_Hash(){
                   int  sum1 = 0 ;
                   int sum2 = 0;
                   for(int i=0;i<s.size();++i){
                    int c = s[i]<='Z' ? s[i]-'A' + 27 : s[i]-'a' + 1;
                    sum1 = add(sum1,mul(c,pw1[i],MOD),MOD);
                    pre1[i]=sum1;
                    sum2 = add(sum2,mul(c,pw2[i],MOD),MOD);
                    pre2[i]=sum2;
                   }
             }
 
            pair<int,int> get_Hash_range(int L,int R){
                 if(L==0)
                    return {pre1[R],pre2[R]};
                return {mul(inv1[L] ,add(pre1[R],-pre1[L-1],MOD),MOD),mul(inv2[L] ,add(pre2[R],-pre2[L-1],MOD),MOD) };
            }
 
            int get_Hash_range(int L,int R,bool bs){
                 if(L==0)
                    return !bs ? pre1[R] : pre2[R];
                return !bs ? mul(inv1[L] ,add(pre1[R],-pre1[L-1],MOD),MOD):mul(inv2[L] ,add(pre2[R],-pre2[L-1],MOD),MOD) ;
            }
 
     };
// do not forget to call Hash() 
