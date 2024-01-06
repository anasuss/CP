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
     
    const int N = 3e2 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n , m ; 

    vector<int> graph[N] ; 
    
    int depth[N] ; 

    bool vis[N]; 

    void dfs(int node){

        for (int child : graph[node]){
            if (!vis[child]){
                vis[child] = true; 
                depth[child] = depth[node]+1 ;
                dfs(child) ; 
            }
        }
        return ; 
    }
    void solve(){
        memset(depth,0,sizeof(depth)) ;
        memset(vis,0,sizeof(vis)) ;
        for (int i = 0 ; i<N ; i++){
            graph[i].clear() ; 
        }
        cin >> n >> m; 
        for (int i = 0 ; i<m ; i++){
            int u,v ; 
            cin >> u >> v ; 
            --u , --v ; 
            graph[u].pb(v) ; 
            graph[v].pb(u) ; 
        }
        for (int i = 0 ; i<n ; i++){
            memset(depth,0,sizeof(depth)) ;
            memset(vis,0,sizeof(vis)) ;
            vis[i] = true ; 
            dfs(i) ;
            int cnt1 = 0 , cnt2 = 0 ; 
            for (int j = 0 ; j<n ; j++){
                cnt1+=depth[j] == 1 ; 
                cnt2 += depth[j] == 2 ; 
            }
            if (cnt1+cnt2+1 == n && cnt2%cnt1 == 0){
                cout << cnt1 << " " << cnt2/cnt1 << endl ; 
                return ; 
            }
        }
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