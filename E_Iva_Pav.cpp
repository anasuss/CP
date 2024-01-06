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
    int tree[4*N] ; 
    int merge(int int1 , int int2){
        return int1&int2;
    }
    int query(int qs , int qe , int id = 0 , int ns = 0 , int ne = n-1){
        if (ns>qe || qs>ne){
            int x = (1 << 31);
            x-=1; 
            return x; 
        }
        if (ns>=qs && qe>=ne){
            return tree[id] ; 
        }
        int l = 2*id+1 ;
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        return merge(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne)) ; 
    }
    void updt(int idx , int x , int id = 0 , int ns = 0 , int ne = n-1){
        if (idx<ns || idx>ne){
            return ; 
        }
        if (ns == ne){
            tree[id] = x ; 
            return ; 
        }
        int l = 2*id+1 ; 
        int r = 2*id+2 ; 
        int mid = ns+(ne-ns)/2 ; 
        updt(idx,x,l,ns,mid) ; 
        updt(idx,x,r,mid+1,ne) ; 
        tree[id] = merge(tree[l],tree[r]); 
    }
    bool can(int l , int mid , int k){
        return query(l,mid)>=k ; 
    }
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; updt(i,x) ; 
        }
        int q; cin >> q ; 
        while (q--){
            int l , k , r = n-1 ;
            cin >> l >> k ; --l ;
            int ll = l ;  
            int ans = -1 ; 
            while(l<=r){
                int mid = l+(r-l)/2 ; 
                if (can(ll,mid,k)){
                    l = mid+1 ; 
                    ans = mid ;  
                }
                else 
                    r = mid-1 ; 
            }
            cout << (ans == -1 ? ans : ans+1)  << " " ;  
        }
        cout << endl ; 
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