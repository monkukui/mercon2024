## 反射

### 問題
メルカリの猫キャラクターであるミケは、スクリーンセーバーとして動く点が気になってしょうがありません。
点は、縦 $H$ 横 $W$ サイズのディスプレイを、左上の座標を $(0, 0)$ とした時、から見て座標 $(s_x, s_y)$ から毎秒 $(v_x, v_y)$ のスピードで進みます。ミケの代わりに点が $T$ 秒後に、左上のにあるか予測してください。

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

答えの座標を $ans_x, ans_y$ として出力せよ。
なお、答えが $32$ bit 整数に収まらないことがある事に注意してください。

{@samples.all}