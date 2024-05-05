#include<bits/stdc++.h>
using namespace std;
#define l first
#define r second
int n,d[64][64],m[64][64][2];
int ch(int y,int x){return d[y][x]&&d[y][x-1]&&d[y][x+1];}
int cv(int y,int x){return d[y][x]&&d[y-1][x]&&d[y+1][x];}
int c3(int y,int x) {return ch(y,x)&&ch(y-1,x)&&ch(y+1,x);}
int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin >> n;
for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){char c;cin>>c;d[i][j]=c-'1';}
pair<int,int>bp,ep;bool bv,ev;for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
if (d[i][j]==17){if(d[i][j-1]==17&&d[i][j+1]==17)bp={i,j},bv=0;if(d[i-1][j]==17&&d[i+1][j]==17)bp={i,j},bv=1;}
else if(d[i][j]==20){if(d[i][j-1]==20&&d[i][j+1]==20)ep={i,j},ev=0;if(d[i-1][j]==20&&d[i+1][j]==20)ep={i,j},ev=1;}
tuple<int,int,int>ans={ep.l,ep.r,ev};queue<tuple<int,int,int>>q;q.push({bp.l,bp.r,bv});m[bp.l][bp.r][bv]=1;int d=0;
while(!q.empty()){int sz=q.size();for(int ss=0;ss<sz;++ss){auto[y,x,v]=q.front();q.pop();
if(make_tuple(y,x,v)==ans){cout<<d;exit(0);}if(!m[y][x][!v]&&c3(y,x))m[y][x][!v]=1,q.push({y,x,!v});
#define A(dy, dx, hv){if (!m[y+(dy)][x+(dx)][v]&&c##hv(y+(dy), x+(dx)))m[y+(dy)][x+(dx)][v]=1,q.push({y+(dy), x+(dx), v});}
if(v){A(-1,0,v)A(1,0,v)A(0,-1,v)A(0,1,v)}else{A(-1,0,h)A(1,0,h)A(0,-1,h)A(0,1,h)}}++d;}cout<<0;}