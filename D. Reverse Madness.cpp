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
     
     
     
    int n,k,q;
    string s ; 
    map<string,map<pair<int,int>,int>> mp ;
    vector<string> ans ; 
    int a[N] ; 
    int b[N] ; 
    void solve(){
        cin >> n >> k ; 
        cin >> s ; 
        vector<int> swaps(n+10,0);
        for (int i = 0 ; i<k ; i++){
            cin >> a[i] ; --a[i] ; 
        }
        for (int i = 0 ; i<k ; i++){
            cin >> b[i] ;  --b[i] ; 
        }
        cin >> q ; 
        while(q--){
            int x ; cin >> x ; --x ; 
            int l = 0 , r = k-1 ;
            while(l<=r){
                int mid = l+(r-l)/2 ; 
                if (b[mid]<x)
                    l = mid+1 ;
                else 
                    r = mid-1 ; 
            }
            int left = min(x,a[l]+b[l]-x) ;  
            int right = max(x,a[l]+b[l]-x) ;
            cout << left << " " << right << endl ; 
            swaps[left]^=1 ; 
            swaps[right+1]^=1 ; 
        }
        for (int i = 1 ; i<n ; i++){
            swaps[i]^=swaps[i-1] ; 
        }
        for (int i = 0 ; i<k ; i++){
            for (int j = a[i] ; j<=b[i];  j++){
                if (swaps[j] == 1){
                    swap(s[j],s[(a[i]+b[i]-j)]);
                    cout << j << " " << a[i]+b[i]-j << endl ; 
                    swaps[a[i]+b[i]-j] = 0 ; 
                }
            }
        }
        cout << s << endl ; 
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