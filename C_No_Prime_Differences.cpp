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
     
    const int M = 1e3+20 ; 
     
    int n,m;
     
    ll a[N] ;
    ll b[N] ; 

    int grid[M][M] ; 

    void solve(){
        cin >> n >> m ;
        int cnt = m;
        int x = n/2 ; 
        int y = n/2+n%2;   
        for (int i = 0 ; i<x ; i++){
            for (int j = 0 ; j<m ; j++){
                cout << j+1+cnt << " "  ; 
            }
            cout << endl ; 
            cnt+=(2*m) ; // 5  
        } 
        cnt = 0 ; 
        for (int i = 0 ; i<y ; i++){
            for (int j = 0 ; j<m ; j++){
                cout << j+1+cnt << " " ; 
            }
            cnt+=(2*m) ; 
            cout << endl ; 
        }
        cout << endl ; 
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