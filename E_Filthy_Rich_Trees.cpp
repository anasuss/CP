    #include<bits/stdc++.h>

    typedef double  ll;
     
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
     
         
    const int N = 3e5+100 ;
          
     
     
    int n ;

    ll tree[4*N] ;

    ll a[N] ;
    
    vector<int> graph[N] ; 

    int start[N] , finish[N] ; 

    ll merge(ll left , ll right){
        return left+right ; 
    }
    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = a[ns];  
            return ; 
        }
        int l = 2*id+1 ;  
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ;
        build(l,ns,mid) ;
        build(r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]) ;  
    }
    ll query(int qs , int qe , int id = 0 , int ns = 0 , int ne = n-1){
        if (ns>qe || qs>ne){
            return 0 ; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }
    
    void updt(int idx , double x , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            tree[id] = x ; 
            return ; 
        }
        int l = 2*id+1 ; 
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        updt(idx,x,l,ns,mid) ; 
        updt(idx,x,r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]); 
    }

    int cnt = 0 ; 
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
        cin >> n ; 
        for (int i = 0 ; i<n-1 ; i++){
            int u , v ; cin >> u >> v ; --u , --v ; 
            graph[u].pb(v) ; graph[v].pb(u) ; 
        }
        dfs(0,-1) ; 
        build() ; 
        cin >> q ; 
        while(q--){
            int t,x,y ; 
            cin >> t >> x >> y ; 
            if (t == 1){
                --x ; 
                updt(start[x],log(y)) ; 
            }else{
                --x , --y ; 
                ll p1 = query(start[x],finish[x]) ; 
                ll p2 = query(start[y],finish[y]) ; 
                ll ans = p1-p2 ;     
                ll e = max(log(1e-9),min(ans,log(1e9)));
                cout << fixed << setprecision(10) << exp(e) << endl ; 
            }
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ,
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }