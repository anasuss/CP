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
     
    const int N = 3000+1 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    ll a[N] ;
    ll dp[N][N][2] ; 
    ll work(int i = 0 , int j = n-1 , int p = 0){
        if (i>j){
            return 0 ; 
        }
        if (dp[i][j][p] != -1)  return dp[i][j][p] ; 
        ll ans = 0 ;
        if (p == 0){
            ans = max(a[i]+work(i+1,j,p^1),a[j]+work(i,j-1,p^1)) ; 
        }else if (p){
            ans = min(work(i+1,j,p^1),work(i,j-1,p^1)) ;
        }
        return dp[i][j][p] = ans ; 
    }
    void solve(){
        cin >> n ; 
        ll sum = 0 ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            sum += a[i] ; 
        }
        memset(dp,-1,sizeof(dp)) ; 
        cout << work()-(sum-work()) << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }