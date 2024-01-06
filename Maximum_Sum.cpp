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

    struct node{
        ll x , y ; 
        node(){
            x = 0 ; y = 0  ;  
        }
        node(int _x , int _y){
            x = _x ; 
            y = _y ; 
        }
    }; 
    ll a[N] ;
    
    vector<ll> v ; 

    node tree[4*N] ; 

    node merge(node node1 , node node2){
        v.clear() ; 
        v = {node1.x , node1.y , node2.x , node2.y} ; 
        sort(v.rbegin(),v.rend()) ; 
        return node(v[0],v[1]) ;
    }
    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(a[ns],0LL); 
            return ; 
        }
        int l = 2*id+1 ;  
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ;
        build(l,ns,mid) ;
        build(r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]) ;  
    }
    node query(int qs , int qe , int id = 0 , int ns = 0 , int ne = n-1){
        if (ns>qe || qs>ne){
            return node(-1e9,-1e9) ; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }
    
    void updt(int idx , int x , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            tree[id] = node(x,0) ; 
            return ; 
        }
        int l = 2*id+1 ; 
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        updt(idx,x,l,ns,mid) ; 
        updt(idx,x,r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]); 
    }
    void solve(){
        int q ; 
        cin >> n ; 
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        build() ; 
        cin >> q ; 
        while(q--){
            char c ; int l , r ; 
            cin >> c >> l >> r ; 
            if (c == 'Q'){
                node ans = query(--l,--r) ; 
                cout << ans.x + ans.y << endl ;
            }else{
                updt(--l,r) ; 
            }
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