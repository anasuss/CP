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
    int a[N] ; 
    struct node{
        int c[2] ; 
        node(){
           // endNumber = 0 ; 
            for (int i = 0 ; i<2 ; i++)
                c[i] = -1 ; 
        }
    };
    vector<node> nxt ; 
    void insertt(int x){
        int root = 0 ; 
        for (int i = 29 ; i>=0 ; i--){
            int k = ((x&(1<<i)) != 0) ; 
            if (nxt[root].c[k] == -1){
                nxt[root].c[k] = ++nodes ; 
                nxt.pb(node()) ; 
            }
            root = nxt[root].c[k]; 
        }
    }
    int getMin(int u  , int p){
          if (p < 0) return 0 ; 
          if (nxt[u].c[0] != -1 && nxt[u].c[1] != -1)
            return min(getMin(nxt[u].c[0],p-1),getMin(nxt[u].c[1],p-1))+(1<<p) ; 
          else if (nxt[u].c[0] != -1) 
            return getMin(nxt[u].c[0],p-1);
          else if (nxt[u].c[1] != -1)
            return getMin(nxt[u].c[1],p-1) ; 
    }
    void solve(){ 
        nxt.pb(node()) ; 
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; insertt(x) ; 
        }
        cout << getMin(0,29) << endl ; 
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