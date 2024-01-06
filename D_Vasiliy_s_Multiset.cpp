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
        int cnt ;
        node(){
           // endNumber = 0 ; 
            cnt = 0 ; 
            for (int i = 0 ; i<2 ; i++)
                c[i] = 0 ; 
        }
    };
    vector<node> nxt ; 
    void insertt(int x){
        int root = 0 ; 
        for (int i = 31 ; i>=0 ; i--){
            int k = ((x&(1<<i)) != 0) ; 
            if (nxt[root].c[k] == 0){
                nxt[root].c[k] = ++nodes ; 
                nxt.pb(node()) ; 
            }
            root = nxt[root].c[k]; 
            nxt[root].cnt++ ; 
        }
    }
    void erasee(int x){
        int root = 0 ; 
        for (int i = 31 ; i>=0 ; i--){
            int k = ((x&(1<<i)) != 0) ; 
            root = nxt[root].c[k] ; 
            nxt[root].cnt-- ; 
        }
    }
    int getMax(int x){
        int cur = 0 ; 
        int root = 0 ; 
        for (int i = 31 ; i>=0 ; i--){
            if (x&(1<<i)){
                if (nxt[root].c[0] != 0 && nxt[nxt[root].c[0]].cnt>0){
                    root = nxt[root].c[0] ;
                }
                else if (nxt[root].c[1] != 0 && nxt[nxt[root].c[1]].cnt>0){
                    root = nxt[root].c[1] ;
                    cur+=(1<<i) ; 
                }else 
                    break ;
            }else{
                if (nxt[root].c[1] != 0 && nxt[nxt[root].c[1]].cnt>0){
                    root = nxt[root].c[1] ;
                    cur+=(1<<i) ; 
                } 
                else if (nxt[root].c[0] != 0 && nxt[nxt[root].c[0]].cnt>0){
                    root = nxt[root].c[0] ;
                }else 
                    break ; 
            }
        }
        return max(cur^x,x) ;  
    }
    void solve(){
        nxt.pb(node()) ; 
        cin >> n ; 
        while(n--){
            char c ; int x ; 
            cin >> c >> x ; 
            if (c == '+') insertt(x) ; 
            else if (c == '-') erasee(x) ; 
            else cout << getMax(x) << endl ; 
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