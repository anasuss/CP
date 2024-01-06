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
     
    const int N = 400+10 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
     
    ll a[N] ;
    ll dp[N][N] ;   
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0 ; j<=n ; j++){
                dp[i][j] = inf ; 
            }
        }
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        for (int k = 0 ; k<n ; k++){
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                if (i != 0)
                    dp[i][j] = min(dp[i-1][j],a[k]+dp[i][j]) ;
                dp[i][j] = min(dp[i][j+1],a[k]+dp[i][j]) ;  
            }
        }
        }
        cout << dp[0][n-1] << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
     //   cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }