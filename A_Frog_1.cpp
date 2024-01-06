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
    int a[N] ;  
    int dp[N] ; 
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<=n ; i++){
            dp[i] = INF ;  
        } 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        dp[0] = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (i+2<n){
                int x = abs(a[i]-a[i+1])  ; 
                int y = abs(a[i]-a[i+2]) ; 
                dp[i+1] = min(dp[i]+x,dp[i+1]) ; 
                dp[i+2] = min(dp[i]+y,dp[i+2]) ; 
            }else if (i+1<n){
                int x = abs(a[i]-a[i+1])  ; 
                dp[i+1] = min(dp[i+1],dp[i]+x) ; 
            }
        }
        cout << dp[n-1] << endl ; 
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