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
     
    ll a[N] ;
    
    vector<ll> tree[N] ; 

    ll p[N] ; 

    ll centeroid[N] ; 

    ll sz[N] ; 

    ll worst[N] ; 

    void dfs(ll node , ll parent){
        p[node] = parent; 
        sz[node] = 1 ; 
        worst[node] = 0 ; 
        for (ll child : tree[node]){
            if (child == parent) continue ; 
            dfs(child,node) ; 
            sz[node]+=sz[child] ; 
            worst[node] = max(worst[node],sz[child]); 
        }
        ll r = sz[node]/2 ; 
        if (worst[node]<=r){
            centeroid[node] = node ; 
            return ; 
        }
        for (ll child : tree[node]){
            if (child == parent) continue;
            if (sz[child] == worst[node]){
                ll targ = centeroid[child] ; 
                while(true){
                    int above = sz[node]-sz[targ] ; 
                    int below = worst[targ] ; 
                    if (max(above,below)<=r){
                        break ; 
                    }
                    targ = p[targ] ; 
                }
                centeroid[node] = targ ;
                break ; 
            }
        } 
    } 
    int m ; 
    void solve(){
        cin >> n >> m;
        for (ll i = 1 ; i<n ; i++){
            //sz[i] = 1 ; 
            int x ; cin >> x ; --x ; 
            tree[i].pb(x) ; 
            tree[x].pb(i) ; 
        }
        dfs(0,-1) ;
        while(m--){
            int x ; cin >> x ; cout << centeroid[x-1]+1 << endl ; 
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