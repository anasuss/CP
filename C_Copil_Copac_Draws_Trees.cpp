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
     
     
     
    int n ;
     
    map<pair<int,int>,int> mp ; 

    vector<int> graph[N] ; 

    int depth[N] ; 

    bool visited[N] ; 

    int ans = 1 ; 

    void work(int node , int parent){
        visited[node] = true ; 
        for (int child : graph[node]){
            if (!visited[child]){
                if (node == 0){
                    depth[child] = 1 ; 
                }
                else if (mp[{parent,node}]<mp[{node,child}]){
                   // cout << parent << " " << node << " " << mp[{parent,node}] << endl ; 
                   // cout << node << " " << child << " " << mp[{node,child}] << endl ; 
                    depth[child] = depth[node] ; 
                }else{
                    depth[child] = depth[node]+1 ; 
                   // cout << parent << " " << node << " " << mp[{parent,node}] << endl ; 
                   // cout << node << " " << child << " " << mp[{node,child}] << endl ; 
                }
                ans = max(ans,depth[child]) ; 
                work(child,node) ; 
            }
        }
        return ; 
    }
    void solve(){
        memset(depth,0,sizeof(depth)) ; 
        memset(visited,0,sizeof(visited)) ; 
        mp.clear() ; 
        ans = 1 ; 
        cin >> n ; 
        for (int i = 0 ; i<=n ; i++) graph[i].clear() ; 
        for (int i = 0 ; i<n-1 ; i++){
            int u,v ; 
            cin >> u >> v ; 
            --u , --v ; 
            graph[u].pb(v) ; 
            graph[v].pb(u) ; 
            int x = min(u,v) ; 
            int y = max(u,v) ; 
            mp[{x,y}] = i+1 ; 
            mp[{y,x}] = i+1 ; 
        }
        work(0,-1) ; 
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