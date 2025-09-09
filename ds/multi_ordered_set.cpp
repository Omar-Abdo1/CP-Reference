
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
#define ordered_set tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
// multi order set 
// usual set -> less only

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero). 0-based



template<class T>
  class MultiOrderedSet{
 public :

   ordered_set<T>s; // less_equal

  void Insert(ll x){

     s.insert(x);
 }

bool Exist(ll x){

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}


void Erase(ll x){

     if(Exist(x)){
        s.erase(s.upper_bound(x));
     }

}


int Idx(ll x){

    if(!Exist(x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int LastIdx(ll x){

    if(!Exist(x)){
        return -1;
    }
    if(s((int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return Idx(s,*s.lower_bound(x))-1;

}


ll Value(ll index){

   return (*s.find_by_order(index));

}


int Count(ll x){

     if(!Exist(x)){
        return 0;
     }
     return LastIdx(x)-Idx(x)+1;

}


void Clear(){

     s.clear();

}

int Size(){

     return (int)(s.size());

}

  };
