#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define f(i,o,n) for(int i=0;i<n;i++)
#define f(j,o,n) for(int j=0;j<n;j++)
#define mp make_pair
#define pqueue priority_queue

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
// const ll mod = 998244353;
const int m = 5e3+5;
void solve(){
    int n;
    cin>>n;
   
    int cnt[m]={0};
    f(i,o,n){
        ll x;
        cin>>x;
        if(x<n)cnt[x]++;
    }
    int p = 0;
    while(cnt[p])p++;
    vll dp(m,INF);
    dp[p]=0;
    for(int i = p;i>=1;i--){
        for(int j=0;j<i;j++){
            dp[j]=min(dp[j],dp[i]+1ll*i*(cnt[j]));
        }
    }

    cout<<dp[0]-p<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}