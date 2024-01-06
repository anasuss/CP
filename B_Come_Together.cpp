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
     
     
     
     
    long long x1 ; ll  y11  ; ll x2, y2 , x3,y3 ; 

    void solve(){
        cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 ; 
        ll ans = 0 ; 
        if (x1>x2 && x1>x3){
            ans = min(x1-x2,x1-x3) ; 
        }else if (x1<x2 && x1 <x3){
            ans = min(x2-x1,x3-x1) ; 
        }
        if (y11>y2 && y11>y3){
            ans += min((ll)y11-y3,y11-y2) ; 
        }else if (y11<y2 && y11<y3){
            ans += min((ll)y2-y11,(ll)y3-y11) ; 
        }
        cout << ans+1 << endl ; 
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