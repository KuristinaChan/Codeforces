#include<bits/stdc++.h>
using namespace std;


vector<vector<bool>>dp(501,vector<bool> (501,false));

void solve(){
    int n,k;
    cin>>n>>k;
    dp[0][0]=true;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int i=k;i>=x;i--){
            for(int sum = k-x;sum>=0;sum--){
                if(dp[i-x][sum]){
                    dp[i][sum+x]=true;
                    dp[i][sum]=true;
                   
                }
                
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<=k;i++){
        if(dp[k][i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}