vector<int> par, sz;

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true;
}