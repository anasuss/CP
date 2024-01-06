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
     

    vector<int> tree[N] ; 


    pair<int,int> dfs(int node , int parent){
        vector<int> subtree_with_edges , subtree_without_edges ; 
        int sum = 0 ; 
        for (int child : tree[node]){
            if (child == parent) continue; 
            pair<int,int> p = dfs(child,node) ; 
            sum+=max(p.first,p.second) ; 
            subtree_with_edges.pb(p.second) ; 
            subtree_without_edges.pb(p.first) ; 
        }
        int ans = sum ; 
        for (int i = 0 ; i<subtree_with_edges.size() ; i++){
            ans = max(ans,1+sum-subtree_with_edges[i]+subtree_without_edges[i]) ; 
        }
        return {sum,ans} ; 
    }

    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n-1 ; i++){
            int x,y ; cin >> x >> y ; --x ; --y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        }
        //yes ; 
        cout << dfs(0,-1).second << endl ; 
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