int binary_search(){
    ll lo,hi;
    while(lo < hi){
        //FFFFFFFFFFTTTTTTTTTTTTT
        ll mid = lo + (hi - lo)/2;
        if(p(mid)) hi = mid;
        else lo = mid + 1;

        //TTTTTTFFFFFFFFF ==> maxim
        ll mid = lo + (hi - lo + 1)/2;
        if(p(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
