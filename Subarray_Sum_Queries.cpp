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
     
     
     
    int n,m;
     
    ll a[N] ;
 
    struct node{
        ll sum ,mxl,mxr ans ; 
        node(){
            mxl = 0 , mxr = 0 ; 
            sum = 0 ; ans = 0 ; 
        }
        node(ll _sum , ll _ans , ll _mxl , ll _mxr){
            sum = _sum ; 
            ans = _ans ;
            mxl =_mxl ; 
            mxr = _mxr ;  
        }
    };

    node tree[4*N] ; 

    node merge(node left , node right){
        node x = node() ;   
        x.ans = max({left.ans,right.ans,left.mxr+right.mxl}) ; 
        x.mxl = max(left.mxl,left.sum+right.left) ; 
        x.mxr = max({left.mxl,right.})
        x.sum = left.sum+right.sum ; 
        return x ; 
    }

    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(a[ns],a[ns]); 
            return ; 
        }
        int l = 2*id+1 ;  
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ;
        build(l,ns,mid) ;
        build(r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]) ;  
    }

    void updt(int idx , ll x , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            tree[id] = node(x,x) ; 
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
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        build() ; 
        //cout << tree[0].ans << endl ;
         while(m--){
            int x , y ; cin >> x >> y ; 
            updt(--x,(ll)y) ; 
            cout << max(0LL,tree[0].ans) << endl ; 
        } 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }