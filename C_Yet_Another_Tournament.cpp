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
     
     
     
    int n , m ;
    vector<pair<int,int>> v ; 
    bool comp(pair<int,int> x , pair<int,int> y){
        if (x.first != y.first)
            return x.first<y.first ; 
        return x.second>y.second ; 
    }
    bool can(int best){
        if (n-best<0)
            return true ; 
        int s = m ; 
        int lst = -1 ; 
        for (int i = 0 ; i<=n-best ; i++){
             if (s-v[i].first>=0){
                s-=v[i].first ; 
                lst = i ; 
             }else
                break ; 
        }
        if (lst == n-best)
            return true ; 
        s = m ; 
        int idx = -1 ; 
        for (int i = 0 ; i<n ; i++){
            if (v[i].second == n-best+1){
                if (v[i].first>s)
                    return false ; 
                idx = i ; 
                s-=v[i].first ; 
                break ; 
            }
        }
        int cnt = 1 ; 
        for (int i = 0 ; i<n ; i++){
            if (i == idx) continue;
            if (s-v[i].first>=0){
                ++cnt ; 
                s-=v[i].first ; 
            }else 
                break ; 
        }
        return cnt >= n-best ; 
    }
    void solve(int t){
        v.clear() ; 
        cin >> n >> m ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; v.pb({x,i+1}) ; 
        }
        sort(v.begin(),v.end(),comp) ; 
        if (m == 0){
            int cnt = 0 ; 
            for (int i = 0 ; i<n ; i++){
                if (v[i].first == 0){
                    ++cnt ; 
                    --v[i].second ; 
                }
            }
            vector<int> rang ; 
            for (int i = 0 ; i<n ; i++){
                rang.pb(v[i].second) ; 
            }
            sort(rang.rbegin(),rang.rend()) ; 
            int ans = 1 ; 
            for (int i = 0 ; i<rang.size() ; i++){
                if (cnt>=rang[i]){
                    cout << ans << endl ; 
                    return ;
                }
                ++ans ; 
            }
            cout << ans << endl ; 
            return ; 
        }
        int l = 1 , r = n+1 ; 
        int ans = r ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (can(mid)){
                ans = mid ; 
                r = mid-1 ; 
            }
            else 
                l = mid+1 ; 
        }
        cout << r+1 << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve(i) ;
        }
    }