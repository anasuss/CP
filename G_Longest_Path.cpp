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
     
     
     
    vector<int> graph[N] ; 
    int dp[N] ; 
    int n , m ; 
    int work(int node){
        if (dp[node] != -1)
            return dp[node] ;  
        int ans = 0 ; 
        for (int child : graph[node]){
            ans = max(ans,1+work(child)) ; 
        }
        return dp[node] = ans ; 
    }
    void solve(){
        cin >> n >> m ; 
        for (int i = 0 ; i<=n ; i++){
            dp[i] = -1 ; 
        }
        for (int i = 0 ; i<m ; i++){
            int x , y ; cin >> x >> y ; --x ; --y ; 
            graph[x].push_back(y) ; 
        }
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (dp[i] == -1){
                ans = max(ans,work(i)) ; 
            }
        }
        cout << ans << endl ; 
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