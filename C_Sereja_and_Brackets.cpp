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
     
    const int N = 2e6+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    
    string s ; 
    
    struct node{
        /* data */
        ll opened,closed ; 
        ll ans ; 
        node(){
            opened = 0 , closed = 0 , ans = 0 ; 
        }
        node(ll _opened , ll _closed , ll _ans){
            opened = _opened ; closed = _closed ; ans = _ans ; 
        }
    };
    
    node tree[4*N] ; 

    node merge(node left , node right){
        ll x = left.ans+right.ans ; 
        x+=min(left.opened,right.closed) ; 
        node y = node(right.opened,left.closed,x) ; 
        ll dif = left.opened-right.closed ; 
        if (dif>0)
            y.opened+=dif ; 
        else 
            y.closed-=dif ; 
        return y ; 
    }

    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(s[ns] == '(' , s[ns] == ')' , 0); 
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
            return node(0LL,0LL,0LL) ; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }

    int q ; 

    void solve(){
        cin >> s >> q ;
        n = s.size() ; 
        //cout << s << " " << q << endl ; 
        build() ; 
        while(q--){
            int x , y ; 
            cin >> x >> y ; 
            cout << 2LL*query(--x,--y).ans << endl ; 
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