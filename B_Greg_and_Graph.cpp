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
     
    const int N = 550;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;

    ll graph[N][N] ; 

    ll dist[N][N] ; 

    set<int> s ; 

/*     void floydWarshall(){
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                dist[i][j] = graph[i][j] ; 
            }
        }
        for (int k = 0 ; k<n ; k++){
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<n ; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]) ; 
                }
            }
        }
        return  ; 
    }  */
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                cin >> graph[i][j] ; 
            }
        }
        vector<int> vec ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; --x ; 
            vec.pb(x) ; 
        }
        reverse(all(vec)) ; 
        vector<ll> answers ; 
        for (int ii = 0 ; ii<n ; ii++){
            int k = vec[ii] ; 
            for (int i = 0 ; i<n ; i++){
                for (int j = 0 ; j<n ; j++){
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]) ; 
                }
            }
            ll ans = 0 ; 
            for (int i = 0 ; i<=ii ; i++){
                for (int j = 0 ; j<=ii ; j++){
                 
                    ans+=graph[vec[i]][vec[j]] ; 
                }
            }
            answers.pb(ans) ; 
        }
        reverse(all(answers)) ; 
        for (ll x : answers) cout << x << " " ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }