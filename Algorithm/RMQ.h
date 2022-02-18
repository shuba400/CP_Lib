
/**
 * Source: Competitive Programming 3,  https://github.com/mzhang2021/cp-library/blob/master/implementations/data-structures/RMQ.h
 * Time: O(n log n) build, O(1) query
 */

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = max(spt[j-1][i], spt[j-1][i+(1<<(j-1))]); //change here
        }
    }
    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return max(spt[k][i], spt[k][j-(1<<k)+1]); //change here
    }
};
