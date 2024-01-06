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
     
     
     
    int n,q;
     
    ll a[N] ;

    map<int,int> mp ;

    vector<pair<int,int>> v ;

    struct node{
        int val1 , val2 , freq1 , freq2 ; 
        int ans ; 
        node(){
            val1 = 0 , val2 = 0 , freq1 = 0 , freq2 = 0 , ans = 0 ; 
        }
        node(int v1 , int f1 , int v2 , int f2 , int _ans){
            val1 = v1 ; 
            val2 = v2 ; 
            freq1 = f1 ; 
            freq2 = f2 ; 
            ans = _ans ; 
        }
    };
    

    node tree[4*N] ; 

    node merge(node node1 , node node2){
        if (node1.val1==-1e6) return node2 ; 
        if (node2.val1 == -1e6) return node1 ; 
        node res = node() ; 
        res.ans = max(node1.ans,node2.ans) ; 
        
        res.val1 = node1.val1 ; 
        
        res.freq1 = node1.freq1 ; 
        
        res.val2 = node2.val2 ; 

        res.freq2 = node2.freq2 ; 

        if (node1.val2 == node2.val1){
            res.ans = max(res.ans,node1.freq2+node2.freq1) ; 
        }

        if (node1.val1 == node2.val1){
            res.freq1 = max(res.freq1,node1.freq1+node2.freq1) ; 
        }

        if (node1.val2 == node2.val2){
            res.freq2 = max(res.freq2,node1.freq2+node2.freq2) ;
        }
        return res ; 

    }
    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(a[ns],1,a[ns],1,1); 
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
            return node(-1e6,-1e6,-1e6,-1e6,-1e6) ; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }
    void solve(){
        cin >> q ;
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        build() ; 
        while(q--){
            int l,r ; cin >> l >> r ; 
            cout << query(--l,--r).ans << endl ; 
        }  
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        while(cin >> n){
            if (n == 0) break ; 
            solve() ; 
        }
    }