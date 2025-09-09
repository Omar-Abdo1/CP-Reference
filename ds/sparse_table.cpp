 #include <vector>
#include <cmath>
#include <functional>
#include <limits>



template <typename T, typename Func = function<T(T, T)>>
class SparseTable {
  public:
    int n, log2dist;
    vector<vector<T>> st;
    Func func;
    T identity_value;

    SparseTable(const vector<T> &v, Func func, T identity)
        : func(func), identity_value(identity) {
        n = (int)v.size();
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v;

        for (int i = 1; i < log2dist; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T qry(int l, int r) {
        int i = (int)log2(r - l + 1);
        return func(st[i][l], st[i][r - (1 << i) + 1]);
    }

    T qry_log(int l, int r) {
        T result = identity_value;
        int length = r - l + 1;

        for (int i = log2dist - 1; i >= 0; i--) {
            if (length >= (1 << i)) {
                result = func(result, st[i][l]);
                l += (1 << i);
                length -= (1 << i);
            }
        }
        return result;
    }
};

/*
 How to Use it : 
 
  vector<int>v={1,2,3,10,20,-1};
  SparseTable<int>sp(v,[&](int x,int y){return min(x,y);},INT_MAX); // defintion 
  cout<<sp.qry(0,3)<<"\n";
  cout<<sp.qry_log(0,v.size()-1)<<"\n"; 
*/



