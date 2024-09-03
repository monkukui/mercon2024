#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define pp pair<ll,ll>
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
#define difine define
constexpr int inf=2000001000;
constexpr ll INF=2e18;
constexpr ll mod=1000000007;
constexpr ll MOD=998244353;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

 
// #include <atcoder/all>
// typedef atcoder::modint1000000007 mint;
// typedef atcoder::modint998244353 mint;

int main() {
  int k;
  cin >> k;
  vector<int> n(k);
  rep(i,k) cin >> n[i];
  vector<vector<ll>> a(k,vector<ll>(0));
  rep(i,k){
    rep(j,n[i]){
      ll f;
      cin >> f;
      for (ll ii:a[i]){
        if (f>(f^ii)) f=(f^ii);
      }
      if (f!=0) a[i].push_back(f);
    }
  }
  vector<ll> p(62,1);
  rep(i,61) p[i+1]=p[i]*2;
  vector<vector<ll>> base(p[k],vector<ll>(0));
  __int128 ans=0;
  for (int i=1;i<p[k];i++){
    int f=i;
    int count=0;
    rep(i,k){
      if ((f&p[i])!=0) count++;
    }
    for (int j=k-1;j>=0;j--){
      if ((f&p[j])!=0){
        f=(f^p[j]);
        if (f==0){
          base[i]=a[j];
          ans+=p[base[i].size()];
          break;
        }
        rep(ii,a[j].size()){
          ll y=0;
          ll now=a[j][ii];
          rep(jj,base[f].size()){
            if (now>(now^base[f][jj])){
              now=(now^base[f][jj]);
              y=(y^base[f][jj]);
            }
          }
          rep(jj,a[j].size()){
            if (ii==jj) continue;
            if (now>(now^a[j][jj])) now=(now^a[j][jj]);
          }
          if (now==0){
            base[i].push_back(y);
          }
        }
        if (count%2==1) ans+=p[base[i].size()];
        else ans-=p[base[i].size()];
        break;
      }
    }
  }
  cout << (ll)ans << endl;
}
