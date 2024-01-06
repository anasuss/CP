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
     
    const int N = 7e4+10 ;
     
    const int mod = 1e9+7 ;
     
    int nodes ; 
    int n ; 
    string S[N] ; 
    struct node{
        int c[10] ; 
        int cnt ;
        int nb ; 
        bool flag ; 
        node(){
            flag = true ; 
            nb = 0 ; 
            cnt = 0 ; 
            for (int i = 0 ; i<10 ; i++)
                c[i] = 0 ; 
        }
    };
    vector<node> nxt ; 
    void insertt(const string &s){
        int root = 0 ; 
        for (int i = 0 ; i<s.size() ; i++){
            int k = s[i]-'0' ; 
            if (nxt[root].c[k] == 0){
                nxt[root].c[k] = ++nodes ; 
                nxt.pb(node()) ; 
            }
            root = nxt[root].c[k]; 
            nxt[root].cnt++ ; 
        }
    }
    string work(const string &s){
        int root = 0 ; 
        string ans = "" ; 
        for (int i = 0 ; i<s.size() ; i++){
            int k = s[i]-'0' ; 
            ans+=s[i] ; 
            root = nxt[root].c[k] ; 
            if (nxt[root].cnt == 1){
                return ans ; 
            }
        }
        return ans ; 
    }
    void solve(){
        nxt.pb(node()) ; 
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            cin >> S[i] ;
            for (int ii = 0 ; ii<S[i].size() ; ii++){
                int root = 0 ; 
                for (int j = ii ; j<S[i].size() ; j++){
                    int k = S[i][j]-'0' ; 
                    if (nxt[root].c[k] == 0){
                        nxt[root].c[k] = ++nodes ; 
                        nxt.pb(node()) ; 
                    }
                    root = nxt[root].c[k]; 
                    nxt[root].cnt++ ; 
                    if (nxt[root].nb == 0){
                        nxt[root].nb = i+1 ; 
                    }else if (nxt[root].nb != i+1){
                        nxt[root].flag = false ; 
                    }
                }
            }
        }
        for (int i = 0 ; i<n ; i++){
            string ans = "99999999999999999999999999999999999999999999999999999999" ; 
            for (int ii = 0 ; ii<9 ; ii++){
                int root = 0 ; 
                string cur = "" ; 
                for (int j = ii ; j<9 ; j++){
                    if (root<0) break ; 
                    int k = S[i][j]-'0' ;  
                    cur+=S[i][j] ;
                    root = nxt[root].c[k]; 
                    if (nxt[root].cnt == 1 || (nxt[root].flag && root != 0)){
                        if (cur.size()<ans.size()){
                                ans = cur ; 
                        }
                        break ; 
                    }
                }
            }
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