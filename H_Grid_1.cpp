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
     
    const int N = 1e3+5 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n,m ;
    bool grid[N][N] ;   
    int dp[N][N] ; 
    int dx[2] = {0,1} ; 
    int dy[2] = {1,0} ; 
    bool check(int x , int y){
        return x>=0 && y>=0 && x<n && y<m && grid[x][y]; 
    }
    int add(int &a , int b){
        a+=b ; 
        if (a>=mod) a-=mod ; 
        return a ; 
    }
    void solve(){
        cin >> n >> m;  
        dp[0][0] = 1 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                char c ; cin >> c ; 
                grid[i][j] = (c == '.') ; 
            }
        } 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                for (int k = 0 ; k<2 ; k++){
                    int x = i+dx[k] ; 
                    int y = j+dy[k] ; 
                    if (check(x,y)){
                        add(dp[x][y],dp[i][j]) ; 
                    }
                }
            }
        }
        cout << dp[n-1][m-1] << endl ;  
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