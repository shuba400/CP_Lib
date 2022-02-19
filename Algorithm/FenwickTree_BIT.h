#define ll long long


//Use from here

//Fenwick Tree Range Sum Point Update;
//Remeber that indexing is 1 based
vector<ll> bit;
int n,lg = 20;

void add(int pos,ll val){
    int i = pos;
    while(i <= n){
        bit[i] += val;
        i += (i&(-1*i));
    }
}

ll sum(int pos){
    ll x = 0;
    int i = pos;
    while(i > 0){
        x += bit[i];
        i -= (i & -1*(i));
    }
    return x;
}

ll range(ll l,ll r){
    return sum(r) - sum(l - 1);
}

ll kth(ll k) {
    int ret = 0;
    for (int i=lg; i>=0; i--) {
        ret += 1 << i;
        if (ret <= n && bit[ret] < k)
            k -= bit[ret];
        else
            ret -= 1 << i;
    }
    return ret;
}