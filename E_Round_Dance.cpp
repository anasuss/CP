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
     
     
     
    int n ;

    set<int> graph[N] ; 

    bool visited[N] ; 

    int cycle ; 
    
    void dfs(int node , int parent){
        visited[node] = true ; 
        for (int child : graph[node]){
            if (!visited[child])
                dfs(child,node) ;
            else if (child != parent)
                cycle = 1 ; 
        }
    }
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<=n ; i++){
            visited[i] = false ; 
            graph[i].clear() ; 
        }
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; --x ; 
            graph[i].insert(x) ; 
            graph[x].insert(i) ; 
        } 
        int x = 0 , y = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (!visited[i]){
                cycle = 0 ; 
                dfs(i,-1) ; 
                if (cycle) 
                    ++x ; 
                else 
                    ++y ; 
            }
        }
        cout << x+min(1,y) << " " << y+x << endl;  
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }