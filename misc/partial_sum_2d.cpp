
            int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			int mx=min(x1,x2)  , my=min(y1,y2) , mxX=max(x1,x2) , mxY=max(y1,y2);
			a[mx][my]--;
			a[mxX+1][mxY+1] --;
			a[mxX +1][my]++;
 			a[mx][mxY+1]++;
   
    preifx 2D :

 for(int i=1;i<=n;++i)
   for(int j=1;j<=m;++j)
    pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+arr[i][j];
    
   
   int x1,y2,x2,y2;

int Get(int x1,int y1,int x2,int y2){
    return pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
}
