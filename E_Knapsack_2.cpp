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
     
    const int mod = 1e9+7 ;
     
     
    int n ,m;
     
    int w[N] ;
    int v[N] ;  
    int sum ; 
    vector<ll> dp ; 

    void solve(){
        cin >> n >> m ; 
        for (int i = 0 ; i<n ; i++){
            cin >> w[i] >> v[i] ;
            sum+=v[i] ;  
        }
        dp.resize(sum+10,inf) ; 
        dp[0] = 0 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = sum-v[i] ; j>=0 ; j--){
                dp[j+v[i]] = min(dp[j+v[i]],dp[j]+w[i]) ; 
            }
        }
        int ans = 0 ; 
        for (int i = 0 ; i<=sum ; i++){
            if (dp[i]<=m){
                ans = i ; 
            }
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