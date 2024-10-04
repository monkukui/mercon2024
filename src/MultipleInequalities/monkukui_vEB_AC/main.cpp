// O(nm log log n) time, O(nm) space, van Emde Boas Tree
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>
#include <cstddef>
#include <type_traits>
#include <vector>

using namespace std;
const long long int INF = numeric_limits<long long int>::max() / 4;
const int inf = numeric_limits<int>::max() / 4;
const long long int MOD1000000007 = 1000000007;
const long long int MOD998244353 = 998244353;
const double MATH_PI = 3.1415926535897932;

template<typename T1, typename T2>
inline void chmin(T1 &a, const T2 &b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, const T2 &b) { if (a < b) a = b; }

#define lint long long int
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define VI vector<int>
#define VLL vector<long long>
#define VC vector<char>
#define VB vector<bool>
#define PI pair<int, int>
#define PLL pair<long long, long long>
#define VPI vector<pair<int, int>>
#define VPLL vector<pair<long long, long long>>
#define VVI vector<vector<int>>
#define VVPI vecor<vector<pair<int, int>>>
#define VVPILL vector<vector<pair<int, long long>>>

#define SUM(v) accumulate(ALL(v), 0LL)
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))

class vanEmdeBoasTree
{
private:
    const uint32_t LENGTH;
    uint32_t _size;
    struct layer {
        static const uint32_t THRESHOULD = 64;
        uint32_t length, num_blocks, quo, rem;
        int32_t _max, _min;
        uint64_t data;
        layer *summary, **sublayers;
        layer(const uint32_t length)
                : length(length), num_blocks((int)sqrt(length)),
                  quo(length / num_blocks), rem(length % num_blocks),
                  _max(-1), _min(length), data(0ULL){
            if(length <= THRESHOULD) return;
            summary = new layer(num_blocks);
            sublayers = new layer*[num_blocks];
            for(uint32_t i = 0; i < num_blocks; ++i){
                sublayers[i] = new layer(quo + (i < rem));
            }
        }
        layer(const layer& another)
                : length(another.length), num_blocks(another.num_blocks), quo(another.quo), rem(another.rem),
                  _max(another._max), _min(another._min), data(another.data){
            if(length <= THRESHOULD) return;
            summary = new layer(*another.summary);
            sublayers = new layer*[num_blocks];
            for(uint32_t i = 0; i < num_blocks; ++i){
                sublayers[i] = new layer(*another.sublayers[i]);
            }
        }
        layer(layer&& another)
                : length(move(another.length)), num_blocks(move(another.num_blocks)),
                  quo(move(another.quo)), rem(move(another.rem)),
                  _max(move(another._max)), _min(move(another._min)), data(move(another.data)){
            if(length <= THRESHOULD) return;
            summary = another.summary, sublayers = another.sublayers;
            another.summary = nullptr, another.sublayers = nullptr;
        }
        layer& operator=(const layer& another){
            length = another.length, num_blocks = another.num_blocks, quo = another.quo, rem = another.rem;
            _max = another._max, _min = another._min, data = another.data;
            this->~layer();
            if(length <= THRESHOULD) return *this;
            summary = new layer(*another.summary);
            sublayers = new layer*[num_blocks];
            for(uint32_t i = 0; i < num_blocks; ++i){
                sublayers[i] = new layer(*another.sublayers[i]);
            }
            return *this;
        }
        layer& operator=(layer&& another){
            this->~layer();
            length = move(another.length), num_blocks = move(another.num_blocks);
            quo = move(another.quo), rem = move(another.rem);
            _max = move(another._max), _min = move(another._min), data = move(another.data);
            if(length <= THRESHOULD) return *this;
            summary = another.summary, sublayers = another.sublayers;
            another.summary = nullptr, another.sublayers = nullptr;
            return *this;
        }
        ~layer(){
            if(length <= THRESHOULD) return;
            delete summary;
            for(uint32_t i = 0; i < num_blocks; ++i){
                delete sublayers[i];
            }
            delete[] sublayers;
        }
        inline static int32_t msb(uint64_t u){
            return 63 - __builtin_clzll(u);
        }
        inline static int32_t lsb(uint64_t u){
            return __builtin_ctzll(u);
        }
        inline bool empty() const noexcept { return (_max == -1); }
        inline bool isOne() const noexcept { return (_max == _min); }
        inline int32_t max() const noexcept { return _max; }
        inline int32_t min() const noexcept { return _min; }
        inline int32_t index(const uint32_t value) const noexcept {
            return (value >= rem * (quo + 1))
                   ? (rem + (value - rem * (quo + 1)) / quo) : (value / (quo + 1));
        }
        inline int32_t sum(uint32_t index) const noexcept {
            return (index > rem)
                   ? (rem * (quo + 1) + (index - rem) * quo) : (index * (quo + 1));
        }
        bool small_find(const int32_t value) const noexcept {
            return (data >> value) & 1ULL;
        }
        bool find(const int32_t value) const noexcept {
            if(value == _min) return true;
            if(length <= THRESHOULD) return small_find(value);
            const int32_t id = index(value);
            return sublayers[id]->find(value - sum(id));
        }
        bool small_insert(const int32_t value) noexcept {
            if(small_find(value)) return false;
            data ^= (1ULL << value);
            return true;
        }
        bool insert(int32_t value) noexcept {
            if(empty()){
                _max = _min = value;
                return true;
            }else if(value == _min){
                return false;
            }else if(value < _min){
                swap(value, _min);
            }else if(value > _max){
                _max = value;
            }
            if(length <= THRESHOULD) return small_insert(value);
            const int32_t id = index(value);
            if(sublayers[id]->insert(value - sum(id))){
                if(sublayers[id]->isOne()) summary->insert(id);
                return true;
            }else{
                return false;
            }
        }
        void small_erase(const int32_t value){
            if(value == _min){
                _min = lsb(data);
                data ^= (1ULL << _min);
            }else{
                data ^= (1ULL << value);
                if(data == 0) _max = _min;
                else if(value == _max){
                    _max = msb(data);
                }
            }
        }
        void erase(int32_t value){
            if(isOne()){
                _max = -1, _min = length;
                return;
            }
            if(length <= THRESHOULD) return small_erase(value);
            if(value == _min){
                const int32_t id = summary->min();
                _min = value = sum(id) + sublayers[id]->min();
            }
            const int32_t id = index(value);
            sublayers[id]->erase(value - sum(id));
            if(sublayers[id]->empty()){
                summary->erase(id);
            }
            if(value == _max){
                if(summary->empty()){
                    _max = _min;
                }else{
                    const int32_t id = summary->max();
                    _max = sum(id) + sublayers[id]->max();
                }
            }
        }
        int32_t small_predecessor(const int32_t value) const noexcept {
            const uint64_t tmp = (data & ((1ULL << value) - 1ULL));
            return tmp ? msb(tmp) : _min;
        }
        int32_t predecessor(const int32_t value) const noexcept {
            if(_min >= value){
                return -1;
            }else if(value > _max){
                return _max;
            }
            if(length <= THRESHOULD) return small_predecessor(value);
            const int32_t id = index(value), sm = sum(id);
            if(value > sm + sublayers[id]->min()){
                return sm + sublayers[id]->predecessor(value - sm);
            }else{
                const int32_t id2 = summary->predecessor(id);
                return (id2 >= 0) ? (sum(id2) + sublayers[id2]->max()) : _min;
            }
        }
        int32_t small_successor(const int32_t value) const noexcept {
            return lsb(data & ~((1ULL << (value + 1)) - 1ULL));
        }
        int32_t successor(const int32_t value) const noexcept {
            if(value < _min){
                return _min;
            }else if(value >= _max){
                return length;
            }
            if(length <= THRESHOULD) return small_successor(value);
            const int32_t id = index(value), sm = sum(id);
            if(value < sm + sublayers[id]->max()){
                return sm + sublayers[id]->successor(value - sm);
            }else{
                const int32_t id2 = summary->successor(id);
                return sum(id2) + sublayers[id2]->min();
            }
        }
    };
    layer base_layer;
public:
    vanEmdeBoasTree(const uint32_t length) : LENGTH(length), _size(0), base_layer(length){}
    vanEmdeBoasTree(const vanEmdeBoasTree&) = default;
    vanEmdeBoasTree(vanEmdeBoasTree&&) = default;
    vanEmdeBoasTree& operator=(const vanEmdeBoasTree&) = default;
    vanEmdeBoasTree& operator=(vanEmdeBoasTree&&) = default;
    friend ostream& operator<< (ostream& os, vanEmdeBoasTree& veb) noexcept {
        for(uint32_t st = veb.successor(-1); st != veb.LENGTH; st = veb.successor(st))
            os << st << " ";
        return os;
    }
    bool empty() const noexcept { return (_size == 0); }
    uint32_t size() const noexcept { return _size; }
    uint32_t max_size() const noexcept { return LENGTH; }
    bool find(const uint32_t value) const noexcept {
        if(value >= LENGTH) return false;
        return base_layer.find(value);
    }
    uint32_t count(const uint32_t value) const noexcept {
        return find(value);
    }
    int32_t max() const noexcept { return base_layer.max(); }
    int32_t min() const noexcept { return base_layer.min(); }
    void insert(const uint32_t value){
        assert(value < LENGTH);
        _size += base_layer.insert(value);
    }
    void erase(const uint32_t value){
        assert(value < LENGTH);
        base_layer.erase(value), --_size;
    }
    int32_t predecessor(const int32_t value) const noexcept {
        return base_layer.predecessor(value);
    }
    int32_t successor(const int32_t value) const noexcept {
        return base_layer.successor(value);
    }
};

// O(n)
template <class T, class Compare> std::vector<int> cartesian_tree(const std::vector<T>& a, Compare comp) {
    int n = a.size();
    std::vector<int> res(n), prv(n), nxt(n), stk;
    stk.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && comp(a[i], a[stk.back()])) stk.pop_back();
        prv[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n; i--;) {
        while (!stk.empty() && !comp(a[stk.back()], a[i])) stk.pop_back();
        nxt[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (nxt[i] == n)
            res[i] = prv[i];
        else if (prv[i] == -1)
            res[i] = nxt[i];
        else
            res[i] = comp(a[nxt[i]], a[prv[i]]) ? prv[i] : nxt[i];
    return res;
}
template <class T> std::vector<int> cartesian_tree(const std::vector<T>& a) { return cartesian_tree(a, std::less{}); }

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep (i, n) {
        cin >> a[i];
    }
    rep (i, m) {
        cin >> b[i];
    }

    vector<int> ids(n);
    iota(ALL(ids), 0);
    sort(ALL(ids), [&](int l, int r) {
        return a[l] > a[r];
    });

    // auto p = build_cartesian_tree(b);
    auto p = cartesian_tree(b);

    vector<pair<int, int>> g(m, {-1, -1});
    int r = min_element(b.begin(), b.end()) - b.begin();
    for (int i = 0; i < m; i++) {
        if (p[i] < 0) continue;
        if (i < p[i]) {
            g[p[i]].first = i;
        }
        if (i > p[i]) {
            g[p[i]].second = i;
        }
    }

    auto dfs = [&](auto &&self, int cur) -> pair<vector<int>, vector<int>> {
        // 左
        vector<int> dpl(n, -inf);

        if (g[cur].first != -1) {
            auto[cdpl, cdpr] = self(self, g[cur].first);

            vanEmdeBoasTree veb(n);
            vector<int> mp(n); // key: r, value: l
            for (auto i : ids) {
                {
                    // max(l) s.t. r < i
                    int val = veb.predecessor(i); // i より小さい中で最大
                    if (val != -1) dpl[i] = mp[val];
                }

                int l = cdpl[i];
                int r = cdpr[i];
                // 区間 [l, r] を挿入 ... する前に、

                if (l != -inf and r != inf) {
                    // パターン 1. [l, r] を含む区間については消去する
                    while (true) {
                        int val = veb.successor(r - 1);
                        if (val < n and mp[val] <= l) {
                            veb.erase(val);
                        } else {
                            break;
                        }
                    }

                    // パターン 2. [l, r] が含む区間が存在しないなら、挿入する
                    {
                        int val = veb.predecessor(r + 1);
                        if (val == -1 or (val != r and mp[val] < l)) {
                            veb.insert(r);
                            mp[r] = l;
                        }
                    }
                }
            }

        } else {
            iota(ALL(dpl), 0);
        }

        // 右
        vector<int> dpr(n, inf);
        if (g[cur].second != -1) {
            auto[cdpl, cdpr] = self(self, g[cur].second);


            vanEmdeBoasTree veb(n);
            vector<int> mp(n);

            for (auto i : ids) {
                {
                    // min(r) s.t. i < l
                    int val = veb.successor(i);
                    if (val < n) dpr[i] = mp[val];
                }

                int l = cdpl[i];
                int r = cdpr[i];
                // 区間 [l, r] を挿入 ... する前に、

                if (l != -inf and r != inf) {
                    // パターン 1. [l, r] を含む区間については消去する
                    while (true) {
                        int val = veb.predecessor(l + 1);
                        if (val != -1 and r <= mp[val]) {
                            veb.erase(val);
                        } else {
                            break;
                        }
                    }

                    // パターン 2. [l, r] が含む区間が存在しないなら、挿入する
                    {
                        int val = veb.successor(l - 1);
                        if (val >= n or (val != l and r < mp[val])) {
                            veb.insert(l);
                            mp[l] = r;
                        }
                    }
                }
            }


        } else {
            iota(ALL(dpr), 0);
        }

        return {dpl, dpr};
    };

    auto[dpl, dpr] = dfs(dfs, r);
    for (int i = 0; i < n; i++) {
        if (dpl[i] != -inf and dpr[i] != inf) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}