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
    int depth[N] ; 

    struct node{
        int c[26] ; 
        node(){
           // endNumber = 0 ; 
            for (int i = 0 ; i<26 ; i++)
                c[i] = -1 ; 
        }
    };
    vector<node> nxt ; 
    void insertt(const string &s){
        int root = 0 ; 
        for (int i = 0 ; i<s.size() ; i++){
            int k = (s[i]-'a') ; 
            if (nxt[root].c[k] == -1){
                nxt[root].c[k] = ++nodes ; 
                nxt.pb(node()) ; 
            }
            root = nxt[root].c[k]; 
        }
    }
/*     void dfs(int node = 0){
        depth[node] = 1 ; 
        for (int i = 0 ; i<26 ; i++){
            int child = nxt[node].c[i] ; 
            if (child != -1){
                dfs(child) ; 
                depth[node]+=depth[child] ; 
            }
        }
    } */
    int dp[30*N][2] ; 
    int work(int node , int p){
        if (node == -1) return p ; 
        for (int i = 0 ; i<26 ; i++){
            return work(nxt[node].c[i],p^1) ; 
        }

    }
    int k ; 
    void solve(){
        memset(dp,-1,sizeof(dp)) ; 
        nxt.pb(node()) ; 
        cin >> n >> k ; 
        while(n--){
            string s ; cin >> s ; 
            insertt(s) ; 
        }
        cout << work(0,0) << endl ; 
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