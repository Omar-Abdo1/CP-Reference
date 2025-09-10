 vector<int> Z_Function(string s){
         vector<int>z(sz(s));
     for(int i=1,l=0,r=0;i<sz(s);++i){
        if(i<r)
            z[i]=min(r-i,z[i-l]);
        while(i+z[i]<sz(s) && s[z[i]]==s[i+z[i]])++z[i];
        if(r<i+z[i]) l = i , r = i+z[i];
     }
       return z;
    } /// return array that at each indx the lonegest substring starting
     // at indx i and matches suffix  
    // if at z[3] = 5  then from [3,7] matches prefix
