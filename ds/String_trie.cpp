 trie
  struct Node
     {
         Node* child[26];
         bool isend;
         int cnt ; 
         string word;
         Node(){
             for(int i=0;i<26;++i)child[i]=NULL;
             isend  = false;
             cnt = 0;
             word = "";
         }
         ~Node(){
             for(auto & ch : child){
                 delete ch;
                 ch = NULL;
             }
             isend = false;
             cnt=0;
             word = "";
         }
     };


      struct Trie{
           Node* root;
           Trie(){
             root = new Node();
           }
            void insert(string s){
                 Node* temp = root;
                 for(int i=0;i<s.size();++i){
                     int c = s[i]-'a';
                      if(temp->child[c]==NULL)
                         temp->child[c] = new Node();
                     temp->child[c]->cnt++;
                     temp = temp->child[c];
                 }
                 temp->isend = true;
                 temp->word = s;
            }

             bool isPrefix(string s){
                  Node* temp = root;
                  for(int i=0;i<s.size();++i){
                     int c = s[i]-'a';
                      if(temp->child[c]->cnt==0 || temp->child[c]==NULL)return false;
                      temp = temp->child[c];
                  }
                  return true ;
             }

             void del(string s){
                 Node* temp = root;
                  if(isHere(s)){
                     
                     for(int i=0;i<s.size();++i){
                         int c = s[i]-'a';
                         temp->child[c]->cnt--;
                         temp  = temp->child[c];
                     }
                     temp->isend = false;
                     temp->word = s;
                  }
             }

              bool isHere(string s){
                 Node* temp = root;
                  for(int i=0;i<s.size();++i){
                     int c = s[i]-'a';
                      if(temp->child[c]->cnt==0 || temp->child[c]==NULL)return false;
                      temp = temp->child[c];
                  }
                  return temp->isend;
              }

             ~Trie(){
                delete root;
             }
      };
