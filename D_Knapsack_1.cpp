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
     
    const int N = 100+10 ;
    const int M = 1e5+10 ;
    const int mod = 1e9+7 ;
     
     
    int n ,m;
    ll dp[M] ; 
    void solve(){
        cin >> n >> m ; 
       
        for (int i = 0 ; i<n ; i++){
            int w , v ; 
            cin >> w >> v ; 
            for (int j = m-w ; j>=0 ; j--){
                dp[j+w] = max(dp[j+w],dp[j]+v) ; 
            }
        }
        ll ans = 0 ; 
        for (int i = 0 ; i<=m ; i++){
            ans = max(dp[i],ans) ; 
        }
        cout << ans << endl ;  
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