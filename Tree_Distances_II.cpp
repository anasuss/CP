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
     
     
     
    ll n ;
    
    vector<int> tree[N] ; 

    ll sum = 0 ; 
    
    ll sz[N] ; 

    ll ans[N] ; 

    void dfs(int node , int parent , ll depth = 0){
        sum+=depth ; 
        sz[node] = 1 ; 
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs(child,node,depth+1) ; 
            sz[node]+=sz[child] ; 
        }
    }
    void dfs2(int node , int parent){

        for (int child : tree[node]){
            if (child == parent) continue;
            sum+= n-2*sz[child] ;  
            ans[child] = sum; 
            dfs2(child,node) ; 
            sum-=n-2*sz[child] ;
        }
    }
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        } 
        dfs(1,-1) ; 
        ans[1] = sum ; 
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