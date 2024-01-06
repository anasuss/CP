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
    ll b[N] ;  
    void solve(){
        cin >> n ; 
        int pos1 , pos2,posn ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            if (a[i] == 1) pos1 = i+1 ;
            if (a[i] == 2) pos2 = i+1 ; 
            if (a[i] == n) posn = i+1 ; 
        }
        if ((pos1<posn && posn<pos2) ||(pos1>posn && posn>pos2)){
            cout << pos1 << " " << pos1 << endl ; 
        }else if ((pos1<pos2 && pos2<posn) || (pos1>pos2 && pos2>posn)){
            cout << pos2 << " " << posn << endl ; 
        }else if ((pos1<pos2 && pos1>posn) || (pos1>pos2 && pos1<posn)){
            cout << pos1 << " " << posn << endl; 
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