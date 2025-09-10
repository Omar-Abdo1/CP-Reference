void Comp(vector<long long>&v)
{
      sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
}

int GetComp(long long x,vector<long long>&v)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
