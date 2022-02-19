vector<int>  pi;

//Prefix function
void lsa(string t){
    int n = t.size();
    pi.clear();
    pi.resize(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        ll l = pi[i - 1];
        while(l > 0 && t[i] != t[l]) l = pi[l - 1];
        if(t[i] == t[l]) l++;
        pi[i] = l;
    }
} 

//KMPfunction
bool kmp(string s,string patt){
    int k = patt.size();
    patt = patt + '#' + s;
    lsa(patt);
    for(int i = k; i < patt.size(); i++){
        if(pi[i] == k) return true;
    }
    return false;
}