## H:Multiple Inequalities

### 問題
長さ $N$ の順列 $A = (a_1, \ldots, a_N)$ が与えられます。
また、長さ $M$ の数列 $B = (b_1, \ldots, b_M)$ に対して、以下の形式の不等式が $M-1$ 個与えられます。

 - $b_{x_i} < b_{y_i}$

メルくんは、与えられた順列 $A$ から $0$ 個以上の要素を削除し、残った要素を元の順序で並べて得られる数列を $B$ とすることにしました。
不等式をすべて満たすような数列 $B$ を作ることができますか？


### 入力形式
入力は以下の形式で与えられる。

```
$N M$
$a_1 \dots a_N$
$x_1$ $y_1$
$\vdots$
$x_{M - 1}$ $y_{M - 1}$
```

### 制約

- ${@constraints.MIN_N} \leq N \leq {@constraints.MAX_N}$
- ${@constraints.MIN_N} \leq M \leq {@constraints.MAX_N}$
- $a_1, \ldots, a_N$ は、$(1, \ldots, N)$ を並び替えて作られる順列
- $1 \leq x_i \leq M$
- $1 \leq y_i \leq M$
- $x_i \neq y_i$
- <span style="color: red;">$i \neq j$ ならば $y_i \neq y_j$</span>
- <span style="color: red;">$x_i = y_j$ $(i < j)$ を満たす $i$, $j$ の組は高々 2 つ</span>

### 出力形式
不等式をすべて満たすような数列 B をつくることができるなら `Yes` を、できないなら `No` を一行に出力してください。

{@samples.all}
