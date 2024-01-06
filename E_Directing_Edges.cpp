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
    

    bool vis[N] ; 

    int order[N] ; 

    bool Khan(){
        vector<int> indegree(n,0) ; 
        for (int i = 0 ; i<n ; i++){
            for (int j : graph[i]){
                indegree[j]++; 
            }
        }
        queue<int> q ; 
        for (int i = 0 ; i<n ; i++){
            if (indegree[i] == 0) q.push(i) ; 
        }
        int cnt = 0 ; 
        while(!q.empty()){
            int node = q.front() ; q.pop() ;
            if (order[node] != -1) continue;
            order[node] = cnt++ ;  
            for (int j : graph[node]){
                if (order[j] == -1 &&(--indegree[j]) == 0){
                    q.push(j) ; 
                }
            }
        }
        for (int i = 0 ; i<n ; i++){
            if (indegree[i] != 0) return false;  
        }
        return true ; 
    }
    void solve(){
        cin >> n >> m ;
        for (int i = 0 ; i<=n ; i++){
            graph[i].clear() ; 
            vis[i] = false ; 
            order[i] = -1 ; 
        }
        vector<pair<int,pii>> edges ; 
        for (int i = 0 ; i<m ; i++){
            int t , u , v ; 
            cin >> t >> u >> v ; --u ; --v ; 
            edges.pb({t,{u,v}}) ;
            if (t){
                graph[u].pb(v) ; 
            }
        } 
        if (!Khan()){
                cout << "NO" << endl ; 
                return ; 
        } 
        yes; 
        for (int i = 0 ; i<edges.size() ; i++){
            int t = edges[i].first ; 
            int u = edges[i].second.first ; 
            int v = edges[i].second.second ; 
            if (t == 0){
                if (order[u]>order[v]){
                    swap(u,v) ; 
                }
            }
            ++u ; ++v ; 
            cout << u << " " << v << endl ; 
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