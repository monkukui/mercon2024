## B:購入

### 問題
メルカリには、ユーザー $1$ からユーザー ${@constraints.MAX_U}$ までの ${@constraints.MAX_U}$ 人のユーザーがいます。また、メルカリには、商品 $1$ から商品 ${@constraints.MAX_V}$ までの ${@constraints.MAX_V}$ 個の商品が 1 つずつ出品されています。

はじめ、すべてのユーザーの**幸福度**は $0$ です。

次のような形式の情報が $N$ 個与えられます。

- ユーザー $u_i$ が商品 $v_i$ を購入すると、そのユーザーの幸福度が $h_i$ 上昇する。

すべてのユーザーの幸福度の合計が最大となるような**購入方法**を求めてください。
購入方法とは、商品 $v_i$ がユーザー $u_i$ によって購入されることを表す情報 $(v_i, u_i)$ の集合です。ただし、 $1$ つの商品は一度のみ購入することができます。

なお、与えられる入力では、幸福度の合計が最大となる購入方法が一意に定まることが保証されています。

### 入力形式
入力は以下の形式で与えられる。

```
$N$
$u_1$ $v_1$ $h_1$
$u_2$ $v_2$ $h_2$
$\dots$
$u_N$ $v_N$ $h_N$
```

### 制約

- ${@constraints.MIN_N} \leq N \leq {@constraints.MAX_N}$
- ${@constraints.MIN_U} \leq u_i \leq {@constraints.MAX_U}$
- ${@constraints.MIN_V} \leq v_i \leq {@constraints.MAX_V}$
- ${@constraints.MIN_H} \leq h_i \leq {@constraints.MAX_H}$
- $i \neq j$ のとき、$(u_i, v_i) \neq (u_j, v_j)$
- $i \neq j$ のとき、$h_i \neq h_j$
- 入力はすべて整数


### 出力形式
一行目に、幸福度の合計が最大となるような購入数 $M$ を出力してください。

続く二行目から $M+1$ 行目には、商品 $v_i$ がユーザ $u_i$ に購入されることを表す $v_i$ と $u_i$ を空白区切りで出力してください。
このとき、出力は $v_i$ が**昇順になるように**してください。
```
$M$
$v_1$ $u_1$
$v_1$ $u_2$
$\dots$
$v_M$ $u_M$
```

{@samples.all}

