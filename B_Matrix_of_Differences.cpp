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
    void solve(){
        cin >> n ;
        int ans[n][n] ; 
        int x = 1 , y = n*n ; 
        for (int i = 0 ; i<n ; i++){
            int cnt = 0 ; 
            if (i%2 == 0)
                for (int j = 0 ; j<n ; j++){
                    if (j%2 == 0)
                        ans[i][j] = x++ ;
                    else
                        ans[i][j] = y-- ; 
                }
            else
                for (int j = n-1 ; j>=0 ; j--){
                    if (cnt%2 == 0){
                        if (n%2)
                            ans[i][j] = y-- ; 
                        else 
                            ans[i][j] = x++ ; 
                    }
                    else{
                        if (n%2) ans[i][j] = x++ ; 
                        else ans[i][j] = y-- ; 
                    }
                    ++cnt ; 
                }
        }
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++)
                cout << ans[i][j] << " " ; 
            cout << endl ; 
        }
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