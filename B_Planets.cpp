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
     
    int nodes ; 
    int n ; 
    struct node{
        int c[2] ; 
        vector<int> cnt ; 
        node(){
           // endNumber = 0 ; 
            cnt.clear() ; 
            for (int i = 0 ; i<2 ; i++)
                c[i] = 0 ; 
        }
    };
    vector<node> nxt ; 
    vector<node> b ; 
    void insertt(int x){
        int root = 0 ; 
        for (int i = 31 ; i>=0 ; i--){
            int k = ((x&(1<<i)) != 0) ; 
            if (nxt[root].c[k] == 0){
                nxt[root].c[k] = ++nodes ; 
                nxt.pb(node()) ; 
            }
            root = nxt[root].c[k];  
        }
        nxt[root].cnt.pb(x) ;
    }
    void insertt2(int x){
        int root = 0 ; 
        for (int i = 31 ; i>=0 ; i--){
            int k = ((x&(1<<i)) != 0) ; 
            if (b[root].c[k] == 0){
                b[root].c[k] = b.size() ; 
                b.pb(node()) ; 
            }
            root = b[root].c[k]; 
        }
        b[root].cnt.pb(x) ; 
    }
    void dfs1(int node , int j , int val){
        int root = node ; 
        for (int i = j ; i>=0 ; i--){
            if (root == -1) return ; 
            for (int kk = 0 ; kk<nxt[root].cnt.size() ; kk++){
                if (nxt[root].cnt[kk] == val)
                    insertt2(val) ; 
            }
            root = nxt[root].c[0]; 
        }
        if (root == -1) return ; 
        for (int ii = 0 ; ii<nxt[root].cnt.size() ; ii++){
            if (nxt[root].cnt[kk] == val)
            insertt2(val) ; 
        }
    }
    int ans ; 
    void dfs2(int node , int i){
        if (i<0) return ; 
        ans+=b[node].cnt ; 
        if (b[node].c[0] != -1 && b[node].c[1] != 0){
            dfs2(b[node].c[0] , i-1) ;
            dfs2(b[node].c[1] , i-1) ; 
        }else if (b[node].c[0] != -1){
            dfs2(b[node].c[0] , i-1) ;
        }else if (b[node].c[1] != -1){
            dfs2(b[node].c[1] , i-1) ; 
        }
    }
    void solve(){
        nxt.pb(node()) ; 
        cin >> n ; 
        for(int i = 0 ; i<n ; i++){
            int x ; cin >> x ; insertt(x) ; 
        }
        int q ; cin >> q ; 
        while(q--){
            int x ; cin >> x ;
            int val  = 0 ; 
            int root = 0 ; 
            b.clear() ; b.pb(node()) ; 
            for (int i = 31 ; i>=0 ; i--){
                int k = ((x&(1<<i)) != 0) ;
                root = nxt[root].c[k]; 
                if (k){ 
                    val+=(1<<i) ; 
                    dfs1(root,i,val) ; 
                }
            }
            ans = 0 ; 
            dfs2(0,31) ; 
            cout << ans << endl ; 
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