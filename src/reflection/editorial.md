## C. 反射
点の $x$ 座標と $y$ 座標は独立しているため、それぞれ分解して考えることが出来る。そして、点は $x$ 軸とのなす角 $45$° で進むため、壁が存在しない場合の座標は、時間 $T$ を用いて $(s_x + T, s_y + T)$ とおける。

また、分解された座標系において、同じ向きで同じ座標に戻るまでの距離は、 $x$ 軸において $2 * w$ 、 $y$ 軸において $2 * h$ である。そのため、 $T$ 秒後の $x, y$ 座標は次のように書ける。

$$\left\{
\begin{array}{ll}
(s_x + T) \% (2 * w) & ((s_x + T) \% (2 * w) \leq w)\\
(2 * w) - (s_x + T) \% (2 * w) & ((s_x + T) \% (2 * w) \gt w)
\end{array}
\right.$$

$$\left\{
    \begin{array}{ll}
    (s_y + T) \% (2 * h) & ((s_y + T) \% (2 * h) \leq h)\\
    (2 * h) - (s_y + T) \% (2 * h) & ((s_y + T) \% (2 * h) \gt h)
    \end{array}
\right.$$

したがって、最終的な解法例は次の通りである。ここで、値は32bit整数の範囲に収まらない可能性があることに留意したい。

```cpp
#include <iostream>
using namespace std;
#define min(a, b) (a < b ? a : b)

int main() {
    long long w, h, t;
    cin >> w >> h >> t;
    long long sx, sy;
    cin >> sx >> sy;

    long long x = (sx + t) % (2 * w);
    long long y = (sy + t) % (2 * h);

    long long ansx = min(x, 2 * w - x);
    long long ansy = min(y, 2 * h - y);
    cout << ansx << " " << ansy << endl;

    return 0;
}
```
