#define ll long long   //use the whole function for this line
const int mod;


/*
Call precal to remove logN factor during querie
*/


//use from here
const ll p1 = 31,p2 = 37; //primes just greater than the maximmum number of alphabets
const ll mod1 = 1e9 + 7,mod2 = 1e9 + 9;
const ll tot = 1e6 + 1;
ll prep1[tot],prep2[tot],inv_prep1[tot],inv_prep2[tot];


ll bin_exp(ll a, ll b,ll m = mod){
    a = a % m;
    ll ans = 1;
    while(b > 0){
        if((b & 1) == 1) ans = (a * ans) % m;
        a = (a * a) % m;
        b = b >> 1; 
    }
    return ans;
}

ll mod_inv(ll n,ll m = mod){
    ll a = bin_exp(n,m - 2,m);
    return a;
}


void precal(){
    ll ip1 = mod_inv(p1,mod1);
    ll ip2 = mod_inv(p2,mod2);
    prep1[0] = 1;
    prep2[0] = 1;
    inv_prep1[0] = 1;
    inv_prep2[0] = 1;
    for(int i = 1; i < tot; i++){
        prep1[i] = (p1*prep1[i - 1])%mod1;
        prep2[i] = (p2*prep2[i - 1])%mod2;
        inv_prep1[i] = (ip1*inv_prep1[i - 1])%mod1;
        inv_prep2[i] = (ip2*inv_prep2[i - 1])%mod2;
    }
    return;
}

vector<pair<ll,ll>> form_hash(string &s){
    ll n = s.size();
    vector<pll> h(n);
    rep(i,0,n){
        ll num = s[i] - 'a' + 1;
        ll l1=0,l2=0;
        if(i){
            l1 = h[i - 1].first;
            l2 = h[i - 1].second;       
        }
        h[i].first = (l1 + num*prep1[i]) % mod1;
        h[i].second = (l2 + num*prep2[i]) % mod2;
    }
    return h;
}

pair<ll,ll> range(ll l,ll r,vector<pair<ll,ll>> &h1){  //calculates hash for a given range l to r
    pll ans;
    if(l){ 
        ans.first = (h1[r].first - h1[l - 1].first + mod1) % mod1; 
        ans.second = (h1[r].second - h1[l - 1].second + mod2) % mod2;
    }
    else{
        ans.first = h1[r].first;
        ans.second = h1[r].second;
    }
    (ans.first *= inv_prep1[l]) %= mod1;
    (ans.second *= inv_prep2[l]) %= mod2;
    return ans;
}
//till here