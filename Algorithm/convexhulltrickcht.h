//Credit ==> unknown as of now
//For minima ==> y = mx + c   ===> replace m with -m and x with -x
//Tested on 
 
using LT = long long;
 
struct line {
 
	LT m, c;
 
	LT eval(LT x) {
 
		return m * x + c;
	}
 
	long double isect(line l) {
 
		return (long double)(c - l.c) / (l.m - m);
	}
};
 
struct CHT {
 
	deque<line> lines;
	vector<int> indices;
 
	void init(int N) {
 
		indices.resize(N + 5);
		iota(indices.begin(), indices.end(), 0);
	}
 
	void add(LT m, LT c) {
 
		line l;
		l.m = m; l.c = c;
 
		// ADDING LINES IN INCREASING ORDER OF SLOPE,
		// AND QUERYING FOR MAXIMUM LINE 
		// TOGGLE BLOCK
		// ---------------------------------------------------------------------------------
		// while((int)lines.size() >= 2 && l.isect(lines[(int)lines.size() - 1]) <= lines[(int)lines.size() - 1].isect(lines[(int)lines.size() - 2])) {
 
		// 	lines.pop_back();
		// }
 
		// lines.push_back(l);
		// ---------------------------------------------------------------------------------
 
		// ADDING LINES IN INCREASING ORDER OF SLOPE,
		// AND QUERYING FOR MINIMUM LINE 
		// TOGGLE BLOCK
		// ---------------------------------------------------------------------------------
		while((int)lines.size() >= 2 && l.isect(lines[0]) >= lines[0].isect(lines[1])) {
 
			lines.pop_front();
		}
 
		lines.push_front(l);
		// ---------------------------------------------------------------------------------
	}
 
	LT query(LT x) {
 
		int idx = *lower_bound(indices.begin(), indices.begin() + (int)lines.size() - 1, x, [&](int i, LT X) {
 
			return lines[i].isect(lines[i + 1]) < X;
		});
 
		return lines[idx].eval(x);
	}
};
