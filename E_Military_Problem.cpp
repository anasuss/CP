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
     
     
     
    int n,q ; 
    vector<int> ans ;  
    vector<int> tree[N] ;
    int start[N] ; 
    int endd[N] ; 
    int cnt = 0 ; 
    void dfs(int node , int parent){
        start[node] = cnt ; 
        for (int child : tree[node]){
            if (child == parent) continue;  
            ans.pb(child) ; 
            ++cnt ;
            dfs(child,node) ;
        }
        endd[node] = cnt ; 
        return ; 
    } 
    void solve(){
        cin >> n >> q ; 
        for (int i = 2 ; i<=n ; i++){
            int x ; cin >> x ; 
            tree[x].pb(i) ; 
            tree[i].pb(x) ;  
        }
        for (int i = 1 ; i<=n ; i++){
            sort(tree[i].begin(),tree[i].end()) ; 
        }
        ans.pb(1) ; 
        dfs(1,0) ;
        while(q--){
            int u , k ; cin >> u >> k ; 
            int len = endd[u]-start[u]+1 ; 
            if (len<k){
                cout << -1 << endl ; continue; ; 
            }
            cout << ans[start[u]+k-1] << endl ; 
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