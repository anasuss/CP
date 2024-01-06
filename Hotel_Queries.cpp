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
     
     
     
    int n,m;
         
    struct node{
        int mx ; 
        node(){
            mx = 0 ; 
        }
        node(int _mx){
            mx = _mx ; 
        }
    };
    node tree[4*N] ;

    int a[N] ; 

    node merge(node node1 , node node2){
        return max(node1.mx,node2.mx); 
    }
    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(a[ns]); 
            return ; 
        }
        int l = 2*id+1 ;  
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ;
        build(l,ns,mid) ;
        build(r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]) ;  
    }
    int query(int x , int id = 0 , int ns = 0 , int ne = n-1){
        if (tree[id].mx<x) return n ; 
        if (ns>ne) return n ; 
        if (ns == ne){
            if (tree[id].mx>=x)
                return ns ; 
            else 
                return n ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ;
        int ans = query(x,l,ns,mid) ; 
        if (ans != n)
            return ans ; 
        else
            return query(x,r,mid+1,ne) ; 
    }
    
    void updt(int idx , int x , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            tree[id] = node(x) ; 
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
        cin >> n >> m;
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        build() ; 
        for (int i = 0 ; i<m ; i++){
            int x ; 
            cin >> x ; 
            int ans = query(x) ; 
            if (ans == n) cout << 0 << " "  ;
            else{
                cout << ans+1 << " " ; 
                updt(ans,a[ans]-x) ; 
                a[ans]-=x ;
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