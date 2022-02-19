
vector<int> tin,tout,depth;   //for euler tour of the tree
vector<vector<int>> up,g;
int timer,lg;   //timer = 0, lg = 20 in most caes

void dfs(int v,int p,int lvl = 0){
	up[v][0] = p;
    depth[v] = lvl;
    timer++;
	tin[v] = timer;
	for(int i = 1; i < lg; i++) up[v][i] = up[up[v][i - 1]][i - 1];

	for(auto x:grid[v]){
		if(x != p) dfs(x,v,lvl + 1);
	}
	tout[v] = timer;
}

bool ances(ll a,ll b){
	if(tin[a] <= tin[b] && tout[a] >= tout[b]) return true;
	return false;
}

ll lca(ll a,ll b){
	if(ances(a,b)) return a;
	if(ances(b,a)) return b;
	pre(i,l,0){
		if(!ances(up[a][i],b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}