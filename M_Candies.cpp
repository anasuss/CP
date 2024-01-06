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
     
    const int N = 1e5+2 ;
     
    const int mod = 1e9+7 ;
     
     
    // 1 1 1 1 1
    // 1 2 3 4 5
    // 0 0 0 0 5
    int n ;
     
    int a[N] ;
    int dp[N] ; 
    template<class T> struct Seg { // comb(ID,b) = b
        const T ID = 1e9; T comb(T a, T b) { return a+b ; }
        int n; vector<T> seg;
        void init(int _n) { n = _n; seg.assign(2*n,ID); }
        void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
        void upd(int p, T val) { // set val at position p
            seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
        T query(int l, int r) {	// sum on interval [l, r]
            T ra = ID, rb = ID;
            for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
                if (l&1) ra = comb(ra,seg[l++]);
                if (r&1) rb = comb(seg[--r],rb);
            }
            return comb(ra,rb);
        }
    };
    void add_self(int &a , int b){
        a+=b ; 
        if (a>=mod)
            a-=mod ; 
    }
    void subtract_self(int &a , int b){
        a-=b ; 
        if (a<0)
            a+=mod ; 
    }
    void solve(){
        int k ; 
        cin >> n >> k ;
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        dp[0] = 1 ; 
        // used+L => used+R
        for (int i = 0 ; i<n ; i++){
            int up_to = a[i] ; 
            vector<int> pref(k+10,0) ; 
            for (int used = k ; used>=0 ; used--){
                int temp = dp[used] ; 
                int L = used+1 ; 
                int R = used+min(up_to,k-used) ;
                if (L<=R){
                    add_self(pref[L],temp); 
                    if (R+1<=k)
                        subtract_self(pref[R+1],temp) ;     
                } 
            }
            int pref_sum = 0 ; 
            for (int here = 0 ; here<=k ; here++){
                add_self(pref_sum,pref[here]) ; 
                add_self(dp[here],pref_sum) ; 
            }
        }  
        cout << dp[k] << endl ; 
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