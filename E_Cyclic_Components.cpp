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
     
     
     
    int n,m ;
     
    vector<int> graph[N] ; 

    bool visited[N] ; 

    int cnt = 0 ; 

    int nd ; 

    bool ok ; 
    void dfs(int node , int par){
        if (graph[node].size() != 2){
            cnt = 10 ; 
        }
        visited[node] = true ; 
        for (int child : graph[node]){
            if (child == par) continue; 
            if (visited[child]){
                ++cnt ; 
                if (child == nd) ok = true ; 
                continue; ;
            }
            dfs(child,node) ; 
        }
    }
    void solve(){
        cin >> n >> m;
        for (int i = 0 ; i<m ; i++){
            int u,v ; cin >> u >> v ; 
            --u; --v ; graph[u].pb(v) ; 
            graph[v].pb(u) ; 
        } 
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (!visited[i]){
                nd = i ; 
                cnt = 0 , ok = 0 ; 
                dfs(i,-1) ; 
              //  cout << nd << " " << cnt << " " << ok << endl ; 
                if (cnt == 2 && ok) ++ans ; 
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