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
     
    int a[N] ;

    int b[N] ;  

    void solve(){
        cin >> n ; 
        int mxNeg = 50 ; 
        int mxPos = -50  ; 
        bool ok = true ; 
        vector<pii> ans1 , ans2  ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
            b[i] = a[i] ; 
            if (i>0 && a[i]<a[i-1]) ok = false ; 
            if (a[i]<0){
                mxNeg = min(a[i],mxNeg) ; 
            }else if (a[i]>0){
                mxPos = max(a[i],mxPos) ; 
            }
        }
        if (ok || n == 1){
            cout << 0 << endl ; 
            return ; 
        }
        if (mxPos == -50){
            vector<pii> ans ; 
            for (int i = n-2 ; i>=0 ; i--){
                ans.pb({i,i+1}) ; 
                a[i]+=a[i+1] ; 
            }
            cout << ans.size() << endl ; 
            for (auto p : ans){
                cout << p.first+1 << " " << p.second+1 << endl ;
            }
            return ; 
        }   
        if (mxNeg == 50){
            vector<pii> ans ; 
            for (int i = 1 ; i<n ; i++){
                ans.pb({i,i-1}) ; 
                a[i]+=a[i-1] ; 
            }
            cout << ans.size() << endl ; 
            for (auto p : ans){
                cout << p.first+1 << " " << p.second+1 << endl ;
            }
            return ; 
        }
        // Make All Positive 
        int idxMaxPos = -1 ;
        int temp1 = mxPos ; 
        for (int i = 0 ; i<n ; i++){
            idxMaxPos = i ;
            if (a[i] == mxPos){
                for (int j = 0 ; mxPos+ mxNeg < 0 ; j++){
                    a[i]+=a[i] ;
                    mxPos = a[i] ;   
                    ans1.pb({i,i}) ; 
                }
                break ; 
            }
        }
        for (int i = 0 ; i<n ; i++){
            if (a[i]<0){
                a[i]+=mxPos ; 
                ans1.pb({i,idxMaxPos}) ; 
            }
        }
        for (int i = 1 ; i<n ; i++){
            if (a[i]>=a[i-1]) continue;
            a[i]+=a[i-1] ; 
            ans1.pb({i,i-1}) ; 
        }
        // Make All Negative
        mxPos = temp1 ; 
        int idxMaxNeg = -1 ; 
        for (int i = 0 ; i<n ; i++){
            if (b[i] == mxNeg){
                idxMaxNeg = i ;
                for (int j = 0 ; mxPos+mxNeg>0 ; j++){
                    b[i]+=b[i] ;
                    mxNeg = b[i] ;   
                    ans2.pb({i,i}) ; 
                }
                break ; 
            }
        }
        for (int i = 0 ; i<n ; i++){
            if (b[i]>0){
                b[i]+=mxNeg ; 
                ans2.pb({i,idxMaxNeg}) ; 
            }
        }
        for (int i = n-2 ; i>=0 ; i--){
            if (b[i]<=b[i+1]) continue;
            b[i]+=b[i+1] ; 
            ans2.pb({i,i+1}) ; 
        }
        vector<pii> ans ; 
        if (ans1.size()<ans2.size()){
            ans = ans1 ; 
        }else 
            ans = ans2 ; 
        cout << ans.size() << endl ; 
        for (auto p : ans){
            cout << p.first+1 << " " << p.second+1 << endl ; 
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