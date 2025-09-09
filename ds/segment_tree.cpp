template<class T> class SegmentTree
       {
     
       public :
     
           SegmentTree(int n,function<T(T,T)>op,T trash)
           {
               sz = 1;
               Left = 0, Right = n-1;
               this->op = op;
               this->trash = trash;
               while(sz<n) sz<<=1;
               seg=vector<T>(2*sz);
               lazy=vector<T>(2*sz);
           }
     
           template<class GG>
           void build(vector<GG>&v)
           {
               build(1,Left,Right,v);
           }
     
           template<class GG>
           void display(vector<GG>&v)
           {
               display(1,Left,Right,v);
           }
     
           void updatePos(int pos,T val)
           {
               updatePos(1,Left,Right,pos,val);
           }
     
           void updateRange(int st,int ed,T val)
           {
               updateRange(1,Left,Right,st,ed,val);
           }
     
     
           T get(int st,int ed)
           {
               if(st>ed)
                   return trash;
               return get(1,Left,Right,st,ed);
           }
     
     
       private :
           ll sz,Left,Right;
           function<T(T,T)>op;
     
           vector<T>seg;
           vector<T>lazy;
     
           T combine(T l,T r)
           {
               T node;
               node = op(l,r);
               return node;
           }
     
           T trash;
     
     
           void check(ll node,int l,ll r)
           {
     
               if(lazy[node])
               {
     
                   seg[node] += lazy[node];
     
                   if(l!=r)
                   {
     
                       lazy[node*2]+=lazy[node];
                       lazy[node*2 + 1]+= lazy[node];
                   }
                   lazy[node] = 0;
               }
           }
           template<class GG>
           void build(ll node,int l,int r,vector<GG>&v)
           {
     
               if(l==r)
               {
                   seg[node] = v[l]   ;
                   return;
               }
               int mid = l+r>>1;
               build(node*2,l,mid,v);
               build(node*2 + 1,mid+1,r,v);
               seg[node]  = combine(seg[node*2],seg[node*2 + 1]);
           }
     
           void updatePos(ll node,int l,int r,int pos,T val)
           {
     
               if(l==r)
               {
                   seg[node]=val;
                   return;
               }
               int mid = l+r>>1;
               if(mid>=pos)
                   updatePos(node*2,l,mid,pos,val);
               else updatePos(node*2 +1,mid+1,r,pos,val);
     
               seg[node]  = combine(seg[node*2],seg[node*2 + 1]);
           }
     
           void updateRange(ll node,int l,int r,int st,int ed,T val)
           {
     
               check(node,l,r);
     
               if(l>=st && r<=ed)  /// update
               {
                   lazy[node] = val;
                   check(node,l,r);
                   return;
               }
     
               if(st>r || l >ed) return ;
     
               int mid = l+r>>1;
               updateRange(node*2,l,mid,st,ed,val);
               updateRange(node*2 + 1,mid+1,r,st,ed,val);
               seg[node]  = combine(seg[node*2],seg[node*2 + 1]);
           }
     
           T get(ll node,int l,int r,int st,int ed)
           {
     
               check(node,l,r);
     
               if(l>=st && r<=ed)
               {
                   return seg[node];
               }
     
               if(st>r || l >ed) return trash;
     
               int mid = l+r>>1;
     
               return combine(get(node*2,l,mid,st,ed),get(node*2 + 1,mid+1,r,st,ed));
           }
           template<class GG>
           void display(ll node,int l,int r,vector<GG>&v)
           {
               check(node,l,r);
     
               if(l==r)
               {
                   if(l<v.size())
                   {
                       cout<<seg[node]<<" ";
                   }
                   return;
               }
               int mid = l+r>>1;
               display(node*2,l,mid,v);
               display(node*2 +1,mid+1,r,v);
           }
       };
