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

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
#define int long long
// To show that the max distance can also be found in one iteration
// stack<pair<ll, ll>> mono_stack;
// 	for (int i = 0; i < n; i++) {
// 		int start = i;
// 		while (!mono_stack.empty() && heights[i] < mono_stack.top().second) {
// 			pair<ll, ll> cur = mono_stack.top();
// 			mono_stack.pop();
// 			start = cur.first;
// 			ans = max(ans, (i - cur.first) * cur.second);
// 		}
// 		mono_stack.push({start, heights[i]});
// 	}

// 	// finish up the remaining rectangles
// 	while (!mono_stack.empty()) {
// 		pair<ll, ll> cur = mono_stack.top();
// 		mono_stack.pop();
// 		ans = max(ans, (n - cur.first) * cur.second);
// 	}
void solve(){
    int n;
    cin>>n;
    vll a(n);
    rep(i,0,n)cin>>a[i];
    stack<pii> l;
    stack<pii> r;
    l.push({0,0});
    vi left(n),right(n);
    rep(i,0,n){
        while(!l.empty()&&l.top().ff>=a[i])l.pop();
        left[i]=l.top().ss;
        l.push({a[i],i+1});
    }
    r.push({0,n+1});
    
    for(int i=n-1;i>=0;i--){
        while(!r.empty()&&r.top().ff>=a[i])r.pop();
        right[i]=r.top().ss;
        r.push({a[i],i+1});
    }
    vi dp(n+1,-1);
    rep(i,0,n){
        dp[right[i]-left[i]-1]=max(dp[right[i]-left[i]-1],a[i]);
    }
    ll cur=dp[n];
    for(int i=n;i>=1;i--){
        
        if(dp[i]>=cur){
            cur=dp[i];
            continue;
        }
        dp[i]=cur;
    }
    rep(i,1,n+1){
        cout<<dp[i]<<" ";
    }
    cout<<ln;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
