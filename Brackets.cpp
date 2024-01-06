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
     
     
     

    struct node{
        /* data */
        int open , close ; 
        node(){
            open = 0 ,  close = 0 ; 
        }
        node(int _open , int _close){
            open = _open ; 
            close = _close ; 
        }
    };
    

    int n ;

    string s ; 

    node tree[4*N] ; 

    node merge(node left , node right){
        node x = node(left.close,right.open) ; 
        int dif = left.open-right.close ; 
        if (dif>0)
            x.open +=dif ; 
        else 
            x.close -=dif ; 
        return x ; 
    }

    void build(int id = 0 , int ns = 0 , int ne = n-1){
        if (ns == ne){
            tree[id] = node(s[ns] == '(',s[ns] == ')') ; 
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
            return node(0,0) ; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }
    
    void updt(int idx , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            if (s[ns] == ')'){
                s[ns] = '(' ; 
                tree[id] = node(1,0) ; 
            }else{
                s[ns] = ')' ; 
                tree[id] = node(0,1) ; 
            }
            return ; 
        }
        int l = 2*id+1 ; 
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        updt(idx,l,ns,mid) ; 
        updt(idx,r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]); 
    }

    int q ;

    void solve(){
        cin >> n >> s >> q ;     
        build() ; 
         while(q--){
            int x ; cin >> x ; 
            if (x == 0){
                if (tree[0].open == 0 && tree[0].close == 0) yes ; 
                else no ; 
            }else{
                updt(--x) ; 
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
            cout << "Test " << i << ":" << endl ; 
            solve() ;
        }
    }