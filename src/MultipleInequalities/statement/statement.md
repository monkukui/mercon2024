## H:Multiple Inequalities

### 問題
長さ $N$ の順列 $A = (A_1, A_2 \ldots, A_N)$ が与えられます。
メルくんは、与えられた順列 $A$ から $N - M$ 個の要素を削除し、残った要素を元の順序で並べて得られる長さ $M$ の数列 $B$ を作ることにしました。
また、数列 $B = (B_1, B_2 \ldots, B_M)$ に対して、以下の形式の不等式が $M-1$ 個与えられます。

 - $B_{x_i} < B_{y_i}$
 
不等式をすべて満たすような数列 $B$ を作ることができますか？


### 入力形式
入力は以下の形式で与えられる。

```
$N M$
$A_1 A_2 \dots A_N$
$x_1$ $y_1$
$x_2$ $y_2$
$\vdots$
$x_{M - 1}$ $y_{M - 1}$
```

### 制約

- ${@constraints.MIN_N} \leq N \leq {@constraints.MAX_N}$
- $1 \leq M \leq N$
- $A_1, A_2 \ldots, A_N$ は、$(1, 2 \ldots, N)$ を並び替えて作られる順列
- $1 \leq x_i \leq M$
- $1 \leq y_i \leq M$
- $x_i \neq y_i$
- <span style="color: red;">$i \neq j$ ならば $y_i \neq y_j$</span>
- <span style="color: red;">$x_i = y_j$ $(i < j)$ を満たす $i$, $j$ の組は高々 2 つ</span>

### 出力形式
不等式をすべて満たすような数列 B を作ることができるなら `Yes` を、できないなら `No` を一行に出力してください。

{@samples.all}
