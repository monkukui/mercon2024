## 反射

### 問題
$H \times W$ のディスプレイ内を点が動くスクリーンセーバーを開発した。点は $x$ 軸とのなす角 $45 \tcdegree$ で進み、$1$ 秒あたり $x$ 座標と $y$ 座標がそれぞれ $1$ ずつ変化するように実装されている。そして、この点は普通の光と同じように真っすぐ進み、画面端に到達すると同じ速度で反射する。

初期座標 $(s_x, s_y)$ が与えられるので $T$ 秒後の点の座標を求めよ。

例えば、 

### 入力形式
入力は以下の形式で与えられる。

```
$W$ $H$ $T$
$s_x$ $s_y$
```

### 制約

- 入力は全て整数
- ${@constraints.MIN_WHT} \leq W, H, T \leq {@constraints.MAX_WHT}$
- ${@constraints.MIN_WHT} \leq s_y \leq H$
- ${@constraints.MIN_WHT} \leq s_x \leq W$


### 出力形式

答えの座標が $(ans_x, ans_y)$ のとき次の形式で出力せよ。
なお、答えが $32$ bit 整数に収まらないことがある事に注意せよ。

```
$ans_x$ $ans_y$
```

{@samples.all}
