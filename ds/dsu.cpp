
class DSU
{
       public : 

    vector<int>par;
    vector<long long>sz;

    DSU(int n)
    {
        par=vector<int>(n+1);
        sz=vector<long long>(n+1,1);
        iota(par.begin(), par.end(),0);
    }

    int find(int i)
    {
        if(i==par[i])
            return i;
        return par[i]=find(par[i]);
    }

    void mergeSet(int i,int j)
    {

        int a = find(i);
        int b =find(j);
        if(a!=b)
        {
            if(sz[a]<sz[b])
                swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }

    bool sameSet(int i,int j)
    {
        return find(i)==find(j);
    }


};
