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
         
        const int N = 2000;
         
        const int mod = 1e9+7 ;
         
         
         
        int n , m ;
        string h,v ; 
        int mat[N][N] ; 
        vector<int> graph[N] ;
        vector<int> reversedGraph[N] ; 
        stack<int> nodes ; 
        bool visited1[N],visited2[N] ; 
        int cnt ; 
        void dfs1(int node){
            visited1[node] = true ; 
            for (int child : graph[node]){
                if (!visited1[child]){
                    dfs1(child) ; 
                }
            }
            nodes.push(node) ; 
        }
     
        void reverse(){
            for (int i = 0 ; i<cnt ; i++){
                for (int j : graph[i]){
                    reversedGraph[j].pb(i) ; 
                }
            }
        }
     
        void dfs2(int node){
            visited2[node] = 1 ; 
            for (int child : reversedGraph[node]){
                if (!visited2[child]){
                    dfs2(child) ; 
                }
            }
        }
        bool SCC(){
            for (int i = 0 ; i<cnt ; i++){
                if (!visited1[i])
                    dfs1(i) ; 
            }
            reverse() ; 
            int nb = 0 ; 
            while(!nodes.empty()){
                int i = nodes.top() ; 
                nodes.pop() ; 
                if (!visited2[i]){
                    ++nb ; 
                    dfs2(i) ; 
                }
            }
            return nb == 1 ; 
        }
        void solve(){
            cin >> n >> m;
            cin >> h >> v ;  
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<m ; j++){
                    mat[i][j] = cnt++ ; 
                }
            }
            for (int i = 0 ; i<n ; i++){
                int left = (h[i] == '<' ? 1 : 0) ; 
                int right = (left^1) ;  
                for (int j = 0 ; j<m ; j++){
                    if (left && j-1>=0){
                        graph[mat[i][j]].pb(mat[i][j-1]) ; 
                    }else if (right && j+1<m){
                        graph[mat[i][j]].pb(mat[i][j+1]); 
                    }
                    if (v[j] == 'v' && i+1<n){
                        graph[mat[i][j]].pb(mat[i+1][j]) ; 
                    }else if (v[j] == '^' && i-1>=0){
                        graph[mat[i][j]].pb(mat[i-1][j]) ; 
                    }
                }
            }
            if (SCC()){
                yes ; 
            }else 
                no ; 
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