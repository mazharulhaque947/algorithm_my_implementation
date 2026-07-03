
#include<bits/stdc++.h>
#define int long long
#include<math.h>
using namespace std;
double dd(int a,int b, int c, int d){ if(d==b){return (double)0;} double g;  g= (double)(((d-b)*1.0)/(c-a)); return g; }
int32_t main()
{   ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a[2000000],b[2000000],t,i,j,l,k,m,n,xx[2000000][3],ll,aa[4000002],bb[4000002],pp,ud[2000],du[2000],fdu,fud,ndu,nud;
    double o,p,h,hh;
    map<int,int>x,y;
    cin>>n;

    for(i=0;i<n;i++){cin>>a[i]>>b[i];
                     if(x.find(a[i])==x.end()){ x[a[i]]=b[i]; y[a[i]]=b[i];}
                     else{
                            if(x[a[i]]>b[i]){ x[a[i]]=b[i]; }
                            if(y[a[i]]<b[i]){ y[a[i]]=b[i]; }
                         }
    }
  l=0;
   for(auto v :x){  xx[l][0]=v.first; xx[l][1]=v.second; if(l==0){nud=v.first;} l++;}

   l=0;
   for(auto v :y){ ndu=v.first; xx[l][2]=v.second; l++; }
    fud=fdu=0;
    for(i=0;i<n;i++){ if(a[i]==nud){ud[fud]=b[i];fud++;}  if(a[i]==ndu){du[fdu]=b[i];fdu++;} }
sort(ud,ud+fud); sort(du,du+fdu);
 //  for(i=0;i<l;i++){ cout<<xx[i][0]<<" "<<xx[i][1]<<" "<<xx[i][2]<<"\n"; }
   ll=0;
   aa[ll]=xx[0][0];
    bb[ll]=xx[0][1];
    ll++;

   m=0;
   pp=1;

   for(i=m;i<l;){ pp=i+1;
     for(j=i+1;j<l;j++){ if( pp<l&& dd( xx[i][0], xx[i][1],   xx[j][0],   xx[j][1]  )< dd( xx[i][0], xx[i][1],   xx[pp][0],   xx[pp][1])  ){pp=j;} }
     i=pp;
      if(pp<l){aa[ll]=xx[pp][0]; bb[ll]=xx[pp][1]; ll++;}
    }


    for(i=1;i<fdu-1;i++){ aa[ll]=ndu; bb[ll]=du[i]; ll++;  }
    if(xx[l-1][1]==xx[l-1][2]){  }else{ aa[ll]=xx[l-1][0]; bb[ll]=xx[l-1][2]; ll++; }




 for(i=l-1;i>=0;){ pp=i-1;
     for(j=i-1;j>=0;j--){ if( pp>=0&& dd( xx[i][0], xx[i][2],   xx[j][0],   xx[j][2]  )< dd( xx[i][0], xx[i][2],   xx[pp][0],   xx[pp][2])  ){pp=j;} }
     i=pp;
      if(pp>=0){aa[ll]=xx[pp][0]; bb[ll]=xx[pp][2]; ll++;}
    }
     if(xx[0][1]==xx[0][2]){ ll--; }
    // else{ aa[ll]=xx[0][0]; bb[ll]=xx[0][2]; ll++; }
 for(i=fud-2;i>=1;i--){ aa[ll]=nud; bb[ll]=ud[i]; ll++;  }


    cout<<ll<<"\n";
      for(i=0;i<ll;i++){ cout<<aa[i]<< " "<<bb[i]<<"\n"; }
    return 0;
}
