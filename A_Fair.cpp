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
     
     
     
    int n,m,k,s ;
     
    ll a[N] ;

    vector<ll> graph[N] ; 

    queue<ll> q ; 

    ll dist[N][110] ; 

    void solve(){
        cin >> n >> m >> k >> s;
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        for (int i = 0 ; i<m ; i++){
            ll u , v ; cin >> u >> v; --u , --v ; 
            graph[u].pb(v) ; 
            graph[v].pb(u) ; 
        } 
        for (int i = 0 ; i<=n ; i++){
            for (int j = 0 ; j<=k ; j++){
                dist[i][j] = inf ; 
            }
        }
        for (int f = 1 ; f<=k ; f++){
            while(!q.empty()) q.pop() ; 
            for (int i = 0 ; i<n ; i++){
                if (a[i] == f){
                    q.push(i) ; 
                    dist[i][f] = 0 ; 
                }
            }
            while(!q.empty()){
                int node = q.front() ; 
                q.pop() ; 
                for (int child : graph[node]){
                    if (dist[child][f] == inf){
                        q.push(child) ; 
                        dist[child][f] = dist[node][f]+1 ; 
                    }
                }
            }
        }
        for (int i = 0 ; i<n ; i++){
            sort(dist[i]+1,dist[i]+k+1) ;
            ll ans = 0 ;  
            for (int j = 1 ; j<=s ; j++){
                ans+=dist[i][j] ; 
            }
            cout << ans << " " ; 
        }
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