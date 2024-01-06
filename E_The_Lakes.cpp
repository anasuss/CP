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
     
    const int N = 2e3 ;
     
    const int mod = 1e9+7 ;
     
    ll a[N][N] ; 

    bool vis[N][N]; 

    int n , m;
    
    int dx[4] = {0,1,0,-1} ;
    int dy[4] = {1,0,-1,0} ; 
    bool valide(int x , int y){
        return x>=0 && y>=0 && x<n && y<m && a[x][y] > 0 && !vis[x][y]; 
    }
    ll work(int x , int y){
        ll ans = a[x][y] ; 
        vis[x][y] = true ; 
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ;
            if (valide(nx,ny)){
                ans+=work(nx,ny) ; 
            } 
        }
        return ans ; 
    }
    void solve(){
        memset(vis,0,sizeof(vis)) ; 
        cin >> n >> m;
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                cin >> a[i][j] ; 
            }
        }
        ll ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (!vis[i][j] && a[i][j]>0){
                    ans = max(ans,work(i,j)) ; 
                }
            } 
        }
        cout << ans << endl ; 
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