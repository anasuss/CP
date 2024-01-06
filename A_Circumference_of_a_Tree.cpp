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
     
    const int N = 3e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    
    vector<int> tree[N] ; 

    int dist[N] ; 
    
    int mx , mxnode ; 

    void dfs(int node , int parent){
        if (parent != -1) dist[node] = dist[parent]+1 ; 
        if (dist[node]>mx){
            mx = dist[node] ; 
            mxn = node ; 
        }
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs(child,node) ; 
        }
    }

    int diamater(){
        for (int i = 0 ; i<=n ; i++){
            dist[i] = 0 ; 
        }  
        dfs(1,-1) ; 
        for (int i = 0 ; i<=n ; i++){
            dist[i] = 0 ; 
        }  
        dfs(mxn,-1) ; 
        return mx ; 
    }
    
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        } 
        int diam = diamater() ; 
        for (int i = 1 ; i<=n ; i++){
            if (dist[i] == mx) cout << mx+1 << endl ; 
            else cout << mx << endl ; 
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
        //freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }