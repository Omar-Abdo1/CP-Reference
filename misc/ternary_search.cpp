double l=0,r=1e8,mid1,mid2,ans,eps=1e-6;
while(r-l>eps){
 
  mid1 = l + (r-l)/3;
  mid2 = r - (r-l)/3;
 
  double val1 = Calc(mid1);
  double val2 = Calc(mid2);
 
   if(val1<val2)
     r=mid2;
   else if(val1>val2)
    l=mid1;
   else l=mid1,r=mid2;
}
// get the minmum value here because we cut the maximum 
