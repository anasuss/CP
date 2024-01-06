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
         
        const int N = 1e3+100 ;
         
        const int mod = 1e9+7 ;
         
         
         
        int n,m ; 
        int dx[] = {0,1,-1,0} ; 
        int dy[] = {1,0,0,-1} ; 
        map<int,pair<int,int>> mprow ; 
        map<int,pair<int,int>> mpcol ; 
        set<int> s1 , s2 ; 
        bool grid[N][N] ;
        bool isvalid(int x , int y){
            return x>=0 && y>=0 && x<n && y<m && grid[x][y]; 
        }
        void dfs(int x , int y){
            s1.insert(x) ; s2.insert(y) ; 
            grid[x][y] = 0 ; 
            if (!mprow.count(x)){
                mprow[x].first = y ; 
                mprow[x].second = y ; 
            }else{
                mprow[x].first = min(mprow[x].first,y) ; 
                mprow[x].second = max(mprow[x].second,y) ; 
            }
            if (!mpcol.count(y)){
                mpcol[y].first = x ; 
                mpcol[y].second = x ; 
            }else{
                mpcol[y].first = min(mpcol[y].first,x) ; 
                mpcol[y].second = max(mpcol[y].second,x) ; 
            }
            for (int i = 0 ; i<4 ; i++){
                int nx = x+dx[i] ; 
                int ny = y+dy[i] ; 
                if (isvalid(nx,ny)){
                    dfs(nx,ny) ; 
                }
            }
        }
        void solve(){
            map<int,set<int>> mpr ; 
            map<int,set<int>> mpc ; 
            cin >> n >> m;
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<m ; j++){
                    char c ; cin >> c ;
                    grid[i][j] = (c == '#') ; 
                    if (!grid[i][j]){
                        mpr[i].insert(j) ; 
                        mpc[j].insert(i) ; 
                    }
                }
            }
            int ans = 0 ; 
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<m ; j++){
                    if (grid[i][j]){
                     /*    mprow.clear() ;
                        mpcol.clear() ;   */ 
                        ++ans ; 
                        dfs(i,j) ; 
                         for (auto &p : mprow){
                            int row = p.first ; 
                            int mn = p.second.first ; 
                            int mx = p.second.second ; 
                            if (mn == mx) continue;
                            auto it = mpr[row].lower_bound(mn) ; 
                            if (it != mpr[row].end() && (*(it))<mx){
                                cout << -1 << endl ; 
                                return ; 
                            }
                        }
                        for (auto &p : mpcol){
                            int col = p.first ; 
                            int mn = p.second.first ; 
                            int mx = p.second.second ; 
                            if (mn == mx) continue; 
                            auto it = mpc[col].lower_bound(mn) ; 
                            if (it != mpc[col].end() && (*(it))<mx){
                                cout << -1 << endl ; 
                                return ; 
                            }
                        } 
                    }
                } 
            }
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<m ; j++){
                    if (!mprow.count(i) && !mpcol.count(j)){
                        s1.insert(i) ; s2.insert(j) ; 
                    }
                }
            }
            //cout << ans << endl ;
            if (s1.size() == n && s2.size() == m){
                cout << ans << endl ; 
                return ; 
            } 
            cout << -1 << endl ; 
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