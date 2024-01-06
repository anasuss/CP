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
     
    int a[N] , b[N] ; 

    map<int,int> mp ; 

    void solve(){
        mp.clear() ; 
        cin >> n ;
        int ans = 0 ;  
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        for (int i = 0 ; i<n ; i++){
            cin >> b[i] ; 
        }
        for (int i = 0 ; i<n ; i++){
            int j = i , nb = 1 ; 
            while(j<n-1 && a[j] == a[j+1]) ++j , nb++ ;
            mp[a[i]] = max(mp[a[i]],nb) ; 
            ans = max(ans,mp[a[i]]) ; 
            i = j ;  
        }
        for (int i = 0 ; i<n ; i++){
            int j = i , nb = 1 ; 
            while(j<n-1 && b[j] == b[j+1]) ++j , ++nb ; 
            i = j ; 
            ans = max(ans,mp[b[i]]+nb) ; 
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