    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
    #define nope cout << "-1\n" ;
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define sz(x) (int)(x).size()
    #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
     
    using namespace std;
     
    const int INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
    string s,s1,s2 ; 
    int ans ; 
    struct Node{
        Node *c[26] ; 
        Node(){
            for (int i = 0 ; i<26 ; i++)
                c[i] = NULL ; 
        }
    };
    Node *root ; 
    void dfs(Node *node , string &lst){
        if (sz(lst)>=sz(s2) && lst.substr(sz(lst)-sz(s2),sz(s2)) == s2){
            ++ans ; 
        }
        for (int i = 0 ; i<26 ; i++){
            if (node->c[i] != NULL){
                lst+=char(i+'a') ; 
                dfs(node->c[i],lst);
                lst.pop_back() ; 
            }
        }
    }
    void solve(){
        root = new Node() ; 
        cin >> s >> s1 >> s2 ; 
        for (int i = 0 ; i<s.size() ; i++){
            Node *node = root ; 
            for (int j = i ; j<s.size() ; j++){
                int k = s[j]-'a' ; 
                if (node->c[k] == NULL){
                    node->c[k] = new Node() ; 
                }
                node = node->c[k] ; 
            }
        }
        Node *node = root ; 
        for (int i = 0 ; i<s1.size() ; i++){
            int k = s1[i]-'a' ; 
            if (node->c[k] == NULL){
                cout << 0 << endl ; 
                return ; 
            }
            node = node->c[k] ; 
        }
        ans = 0; 
        string ss = s1 ; 
        dfs(node,ss) ; 
        cout << ans << endl ; 
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