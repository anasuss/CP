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

    ll ans[N] ;
    
    ll pos[N] ; 

    void work(int pos){
        vector<int> v1 , v2 , v3 ; 
        for (int i = pos ; i<n ; i++){
            v1.pb(a[i]) ; 
        }
        for (int i = pos-1 ; i>=0 ; i--){
            if (i == pos-1){
                if (pos == n-1 && a[pos-1]<a[0]){
                    cout << a[pos] << " " ; 
                    for (int j = 0 ; j<pos ; j++){
                        cout << a[j] << " "; 
                    }
                    cout << endl ; 
                    return ; 
                }
                v2.pb(a[i]) ; 
                continue; 
            }
            if (a[i]>a[0]){
                v2.pb(a[i]) ; 
            }else{
                for (int j = 0 ; j<=i ; j++)
                    v3.pb(a[j]) ; 
                break ; 
            }
        }
        for (int i : v1) cout << i << " " ; 
        for (int i : v2) cout << i << " " ; 
        for (int i : v3) cout << i << " " ; 
        cout << endl ; 
        return ; 
    }
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
            pos[a[i]] = i ; 
        }
        if (pos[n] == 0)
            work(pos[n-1]) ; 
        else 
            work(pos[n]) ; 
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