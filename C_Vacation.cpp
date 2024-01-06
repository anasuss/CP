    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
    #define sz(x) (int)(x).size()
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
    #define nope cout << "-1\n" ;
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
     
    using namespace std;
     
    const int INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    ll a[N][3] ;
    ll dp[N][4] ;  
    ll work(int i  , int prv){
        if (i == n){
            return 0 ;  
        }
        if (dp[i][prv] != -1){
            return dp[i][prv] ; 
        }
        ll ans = -INF ; 
        for (int j = 0 ; j<3 ; j++){
            if (j == prv) continue;
            ans = max(ans,a[i][j]+work(i+1,j)) ; 
        }
        return dp[i][prv] = ans ; 
    }
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0 ; j<=3 ; j++){
                dp[i][j] = 0 ; 
            }
        }
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<3 ; j++){
                cin >> a[i][j] ; 
            } 
        } 
        for (int i = n-1 ; i>=0 ; i--){
            for (int prv = 3 ; prv>=0 ; prv--){
                for (int j = 0 ; j<3 ; j++){
                    if (j == prv) continue; 
                    dp[i][prv] = max(dp[i][prv],a[i][j]+dp[i+1][j]) ; 
                }
            }
        }
        cout << dp[0][3] << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }