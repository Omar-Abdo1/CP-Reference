  struct Trie {
  
  const int B = 31;
  
  struct Node {
    
    Node* ch[2]; // 0 and 1 bit children
    int cnt;     // counts all the masks
    int unq;     // counts only unique masks
    
    Node() {
      ch[0] = ch[1] = nullptr;
      cnt = unq = 0;
    }
    
  };
  
  Node* root;
  
  Trie() {
    init();
  }
  
  void init() {
    root = new Node();
  }
  
  // insert a mask in the trie
  void insert(long long mask) {
    Node* p = root;
    for(int i = B; i >= 0 ; i--){
      bool c = (mask & (1ll << i)) ? 1 : 0;
      if(!p->ch[c]){
        p->ch[c] = new Node();
      }
      p = p->ch[c];
      p->cnt++;
    }
    if(p->cnt == 1){
      p = root;
      for(int i = B ; i >= 0 ; i--){
        bool c = (mask & (1ll << i)) ? 1 : 0;
        p = p->ch[c];
        p->unq++;
      }
    }
  }
  
  // erase a mask from the trie
  void erase(long long mask) {
    Node* p = root;
    for(int i = B  ; i >= 0 ; i--){
      bool c = (mask & (1ll << i)) ? 1 : 0;
      p = p->ch[c];
      p->cnt--;
    }
    if(p->cnt == 0){
      p = root;
      for(int i = B ; i >= 0 ; i--){
        bool c = (mask & (1ll << i)) ? 1 : 0;
        p = p->ch[c];
        p->unq--;
      }
    }
  }
  
  // mex of all the masks inserted in the trie
  long long mex() {
    Node* p = root;
    long long res = 0;
    for(int i = B ; i >= 0 ; i--){
      Node* c0 = p->ch[0];
      Node* c1 = p->ch[1];
      if(!c0 || c0->unq == 0) return res;
      if(c0->unq < (1ll << i)){
        p = c0; continue;
      }
      res ^= (1ll << i);
      if(!c1 || c1->unq == 0) return res;
      p = c1;
    }
    return res;
  }
  
  // maximum xor with the query mask
  long long max_xor(long long mask = 0) {
    Node* p = root;
    long long res = 0;
    for(int i = B ; i >= 0 ; i--){
      bool c = (mask & (1ll << i)) ? 0 : 1;
      if(p->ch[c] && p->ch[c]->cnt){
        res ^= (1ll << i);
      }
      else c = !c;
      p = p->ch[c];
    }
    return res;
  }
  
  // count of the masks x for which (x xor mask) <= k 
  int count(long long mask = 0, long long k = 9e18) {
    Node* p = root;
    int res = 0;
    for(int i = B ; i >= 0 ; i--){
      long long x = (mask & (1ll << i));
      long long y = (x ^ (1ll << i));
      long long z = (k & (1ll << i));
      if(x == z){
        bool c = 0;
        if(y < z && p->ch[!c]){
          res += p->ch[!c]->cnt;
        }
        if(!p->ch[c]) return res;
        p = p->ch[c];
      }
      else {
        bool c = 1;
        if(x < z && p->ch[!c]){
          res += p->ch[!c]->cnt;
        }
        if(!p->ch[c]) return res;
        p = p->ch[c];
      }
    }
    return res + p->cnt;
  }
    // count of the masks x for which (x xor mask) <= k 
  int Count(long long mask, long long k) {
    Node* p = root;
    int res = 0;
    for(int i = B ; i >= 0 ; i--){
          bool bit = (mask & (1ll << i)) ? 1 : 0;
         if(getBit(k,i)){
                
                if(p->ch[bit])
                res+=p->ch[bit]->cnt;
              if(!p->ch[1-bit])return res;
              p = p->ch[1-bit];
 
         }
         else
         {
             if(!p->ch[bit])
                return res;
             p = p->ch[bit];
         }
    }
    return res + p->cnt;
  }
 
  
  ~Trie() {
    delete_trie(root);
  }
  
  void delete_trie(Node* p) {
    if(!p) return;
    delete_trie(p->ch[0]);
    delete_trie(p->ch[1]);
    delete p;
  }
  void gg(){
    delete_trie(root);
  }
 
  bool isHere(long long mask = 0){
    Node *p = root;
    for(int i=B;i>=0;--i){
        bool c = getBit(mask,i);
        if(!p->ch[c] || !p->ch[c]->cnt)return 0;
        p = p->ch[c];
    }
    return 1;
}
  
};

