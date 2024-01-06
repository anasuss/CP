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
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
     
    char grid[5][5] ; 
    void solve(){
        int n = 3 ; 
        for (int i = 0 ; i<3 ; i++){
            for (int j = 0 ; j<3 ; j++)
                cin >> grid[i][j] ; 
        }
        for (int i = 0 ; i<n ; i++){
            int cnt = 1 ;
            for (int j = 1 ; j<n ; j++){
                if (grid[i][j] == '.') continue;
                cnt += (grid[i][j] == grid[i][0]) ; 
            }
            if (cnt == 3){
                cout << grid[i][0] << endl ; return ; 
            }
        }
        for (int j = 0 ; j<n ; j++){
            int cnt = 1 ; 
            for (int i = 1 ; i<n ; i++){
                if (grid[i][j] == '.') continue;
                cnt += (grid[i][j] == grid[0][j]) ; 
            }
            if (cnt == 3){
                cout << grid[0][j] << endl ; 
                return ; 
            }
        }
        int cnt = 1 ; 
        for (int i = 1 ; i<n ; i++){
            if (grid[i][i] == '.') continue;
            cnt += (grid[i][i] == grid[0][0]) ; 
        }
        if (cnt == 3){
            cout << grid[0][0] << endl ; return ; 
        }
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != '.'){
            cout << grid[0][2] << endl ; 
            return ; 
        }
        cout << "DRAW" << endl ; 
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