## 反射

### 問題
メルカリの猫キャラクターであるミケは、スクリーンセーバーとして動く点が気になってしょうがありません。

点は縦 $H$ 横 $W$ サイズのディスプレイ上を動き、ディスプレイの端に触れると、反射角が入射角と同じになるように同じ速度のまま反射します。
左上の座標を $(0, 0)$ とした時、点は座標 $(s_x, s_y)$ から毎秒 $(v_x, v_y)$ のスピードで進みます。ミケの代わりに、点が $T$ 秒後にどの座標にあるかを教えてください。

### 入力形式
入力は以下の形式で与えられる。

```
$W$ $H$ $T$
$s_x$ $s_y$ $v_x$ $v_y$
```

### 制約

- 入力は全て整数
- ${@constraints.MIN_WHT} \leq W, H, T \leq {@constraints.MAX_WHT}$
- ${@constraints.MIN_WHT} \leq s_y \leq H$
- ${@constraints.MIN_WHT} \leq s_x \leq W$
- ${@constraints.MIN_V} \leq v_x, v_y \leq {@constraints.MAX_V}$


### 出力形式

答えの座標を $ans_x, ans_y$ として出力してください。
なお、答えが $32$ bit 整数に収まらないことがある事に注意してください。

{@samples.all}
