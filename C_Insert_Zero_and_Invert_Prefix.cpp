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
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        } 
        if (a[n-1] == 1){
            no ; 
            return ; 
        }
        yes ; 
        for (int i = n-1 ; i>=0 ; i--){
            if (a[i] == 0){
                cout << 0 << " " ; continue; 
            } 
            int j = i , nb = 0 ; 
            while(j>=0 && a[j] == 1){
                ++nb ; --j ; 
            }

            i = j+1 ; 
            for (int k = 1 ; k<nb ; k++) cout << 0 << " " ; 
            cout << nb << " " ; 
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