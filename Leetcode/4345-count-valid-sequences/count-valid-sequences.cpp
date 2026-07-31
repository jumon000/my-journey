class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;

    bool bl = false;

    vector<ll>fact,invFact;

    ll binpow(ll b,ll e){
        ll res = 1;

        while(e > 0){
            if(e&1) res = (res*b)%mod;
            b = (b*b)%mod;
            e /= 2;
        }

        return res;
    }

    void pre(int n){

        if(bl) return;
        bl = true;

        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0] = 1;

        for(int i = 1; i <= n; i++){
            fact[i] = (fact[i-1]*i)%mod;
        }

        invFact[n] = binpow(fact[n],mod-2);

        for(int i = n-1; i >= 0; i--){
            invFact[i] = (invFact[i+1]*(i+1))%mod;
        }
    }

    ll nCr(int n,int r){
        if(r < 0 || r > n) return 0;
        return (((fact[n]*invFact[r])%mod)*invFact[n-r])%mod;
    }
    
    int countValidSequences(int n, int k) {

       pre(n);
        
       ll tot = nCr(n-1,k-1);

       ll oddi = 0;

       if((n-k)%2 == 0){
           int x = (n-k)/2;
           oddi = nCr(x+k-1,k-1);
       }

       return (int)((tot-oddi+mod)%mod);
    }
};