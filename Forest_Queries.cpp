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
     
    const int N = 2e3+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n,q ;
     
    ll a[N][N] ; 

    ll sum (int x , int y , int i , int j){
        return a[i][j]-a[i][y-1]-a[x-1][j]+a[x-1][y-1] ; 
    }
    
    void solve(){
        cin >> n >> q; 
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j<=n ; j++){
                char c ; cin >> c ; a[i][j] = (c == '*') ; 
            }
        }
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j<=n ; j++)
                a[i][j]+=a[i][j-1] ; 
        }
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j<=n ; j++){
                a[j][i]+=a[j-1][i] ; 
            }
        }
        while(q--){
            int x , y , i , j ; cin >> x >> y >> i >> j ; 
            cout << sum(x,y,i,j) << endl ; 
        }
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