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
     
         
    const int N = 1e5+10 ;
          
     
     
    int n ;

    ll tree[N] ;

    ll a[N] ;
    
    vector<int> graph[N] ; 

    int start[N] , finish[N] ; 

   void update(int x, ll val){
        for (int i = x; i <=n ; i += i & -i) tree[i] += val;
    }

    ll get_sum(int x){
        ll res=0;
        for ( ; x ; x-=(x)&(-x))
            res+=tree[x] ; 
        return res;
    }
    ll getrange(int l , int r){
        return get_sum(r)-get_sum(l-1) ; 
    }
    int cnt =  1 ; 

    void dfs(int node , int parent){
        start[node] = cnt ; 
        for (int child : graph[node]){
            if (child == parent) continue;
            ++cnt; 
            dfs(child,node) ; 
        }
        finish[node] = cnt ; 
    }
    int q ; 
    void solve(){
        cnt = 1 ; 
        cin >> n >> q ; 
        for (int i = 0 ; i<=n+10 ; i++){
            graph[i].clear() ; 
            a[i] = 0 ; 
            start[i] = 0 ; 
            finish[i] = 0 ; 
            tree[i] = 0 ; 
        }
        for (int i = 0 ; i<n-1 ; i++){
            int u , v ; cin >> u >> v ; 
            graph[u].pb(v) ; graph[v].pb(u) ; 
        }
        dfs(1,-1) ; 
        while(q--){
          int u , v ; ll x ; cin >> u >> v >> x ;
            if (x == 0){
                    ll ans = getrange(start[u],finish[u]); 
                    ll ans1 = getrange(start[v],finish[v]);
                    if (start[u]>=start[v] && finish[u]<=finish[v]) cout << abs(ans) << endl ; 
                    else cout << abs(ans1) << endl ; 
            }else{
               // cout << start[u] << " " << a[start[u]] << endl ; 
                //cout << start[v] << " " << a[start[v]] << endl ; 
                a[start[u]]+=x ; 
                a[start[v]]-=x ; 
                update(start[u],a[start[u]]) ; 
                update(start[v],a[start[v]]) ; 
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