    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
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
     
     
     
    int n , k ;
     
    int a[N] ;
    
    int dp[N][70] ; 

    int cnt = 0 ; 

    int solvee(int p, int c) {
        if (p >= n) {
            return c < 64 && (__builtin_popcount(c) == k);
        }
        int &rs = dp[p][c];
        if (rs != -1) {
            return rs;
        }
        rs = solvee(p + 1, c);
        rs = (rs + solvee(p + 1, c & a[p])) % mod;
        
        return rs;
    }
    void solve(){
        ++cnt;  
        cin >> n >> k; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            memset(dp[i],-1,sizeof(dp[i])) ; 
        }
        ll ans = solvee(0,63) ;
        if (k == 6) --ans ; 
        cout << ans << endl ;  
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }