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
     
    ll a[N] ;

    void solve(){
        cin >> n ; 
        int f = 0 , lst = 0 ; 
        bool ok = 1 ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; 
            if (i == 0){
                lst = x ; f = x ; 
                cout << 1 ; 
                continue; 
            }
            if (x>=lst && ok){
                cout << 1 ; 
                lst = x ; 
            }else if (x<=f){
                if (!ok){
                    if (x<lst){
                        cout << 0 ; 
                        continue; 
                    }
                }
                ok = 0 ; 
                lst = x ; 
                cout << 1 ;
            }else{
                cout << 0 ;
            }
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