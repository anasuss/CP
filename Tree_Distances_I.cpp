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
     
    const int N = 2e5+10 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    
    vector<int> tree[N] ; 
 
    int depth[N] ; 

    int ans[N]; 
 
    void dfs(int node , int parent){
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs(child,node) ; 
            depth[node] = max(depth[node],1+depth[child]) ; 
        }
    }
    void dfs2(int node , int parent){
        ans[node] = depth[node] ; 
        for (int child : tree[parent]){
            if (child == node) continue;
            ans[node] = max(ans[node],depth[child]+2);
        }
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs2(child,node) ; 
        }
    }
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; 
            tree[x].pb(y) ; 
           // tree[y].pb(x) ; 
        } 
        dfs(1,0) ;
        ans[1] = depth[1] ; 
        dfs2(1,-1) ;  
        for (int i = 1 ; i<=n ; i++) cout << ans[i] << " " ; 
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