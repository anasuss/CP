    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
    #define sz(x) (int)(x).size()
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
     
    const int N = 26 ;
     
    const int mod = 1e9+7 ;
     
    vector<int> graph[N] ; 

    bool vis[N] ; 
    bool ancestor[N] ; 
    vector<char> order ; 
    set<int> s ; 
    int n ; 
    bool dfs(int node){
        vis[node] = 1 ; 
        ancestor[node] = true ; 
        for (int child : graph[node]){
            if (!vis[child] && !dfs(child)){
                return false ;   
            }else if (ancestor[child])
                return false ; 
        }
        ancestor[node] = false ; 
       // order.pb(char(node+'a')) ; 
        return true ; 
    }
    void solve(){
        cin >> n ; 
        vector<string> v(n) ; 
        for (int i = 0 ; i<n ; i++){
            cin >> v[i] ; 
        }
        for (int i = 1 ; i<n ; i++){
            string s1 = v[i-1] ;
            string s2 = v[i] ; 
            bool check = false ; 
            for (int j = 0 ; j<min(sz(s1),sz(s2)) ; j++){
                if (s1[j] == s2[j]) continue; 
                int node = s1[j]-'a' ; 
                int child = s2[j]-'a' ;
                if (!s.count(node))
                    order.pb(char(node+'a')) ;  
                graph[node].pb(child) ;
                s.insert(node) ; 
                check = true;  
                break ; 
            }
            if (!check && sz(s1)>sz(s2)){
                cout << "Impossible" ; return ; 
            }

        }
        for (int i = 0 ; i<26 ; i++){
            if (!s.count(i)){
                order.pb(char(i+'a')) ; 
            }
            if (!vis[i]){
                if (!dfs(i)){
                    cout << "Impossible" ; 
                    return ;
                }
            }
        }
      //  reverse(all(order));
        for (char c : order) cout << c ; 
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