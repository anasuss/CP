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
     
    ll a[N] ;

    ll subtree[N] ; 

    vector<int> tree[N] ; 


    ll tot , cost , ans  ; 

    void dfs1(int node ,  int parent , int depth = 0){
        cost+=a[node]*depth ; 
        subtree[node] = a[node] ; 
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs1(child,node,depth+1) ; 
            subtree[node]+=subtree[child] ; 
        }
    }
    void dfs2(int node , int parent){
        ans = max(ans,cost) ; 
        for (int child : tree[node]){
            if (child == parent) continue; 
            ll s = (tot-subtree[child]) ; 
            cost += s-subtree[child] ; 
            dfs2(child,node) ; 
            cost -= (s-subtree[child]) ; 
        }
    }
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            tot+=a[i] ; 
        }
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; --x , --y ;  
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        } 
        dfs1(0,-1) ; 
        ans = cost ; 
        dfs2(0,-1) ; 
        cout << ans << endl  ; 
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