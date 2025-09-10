string calonicalForm(int i,int par)  /// to compare two tree using dfs
{

    vector<string>child;
    for(auto &j : v[i])if(j!=par)
            child.push_back(calonicalForm(j,i));

    string me = "(";
    sort(all(child));
    for(auto &ch : child)
        me+=ch;
    me+=')';
    return me;
}
