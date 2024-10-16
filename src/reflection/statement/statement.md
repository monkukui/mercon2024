## 反射

### 問題
高さ $H$ cm、幅 $W$ cmのディスプレイがあります。このディスプレイ内を点が動くスクリーンセーバーを開発しました。ディスプレイの左下の座標を $(0, 0)$ とし、ディスプレイの左下から右に $x$ cm、上に $y$ cm移動した点の座標を $(x, y)$ と表します。

時刻 $0$ 秒に点は $(s_x, s_y)$ にあります。はじめ、点は $(s_x, s_y)$ から $(s_x + 1, s_y + 1)$ 方向に秒速 $\sqrt[]{2}$ cmで真っすぐ進み出します。そして、この点は普通の光と同じように真っすぐ進み、画面端に到達すると同じ速度で反射します。
例えば、$W=4, H=3, T=7, s_x=2, s_y=0$ の時は、以下のような軌跡を描き、 $T$ 秒後には $(1, 1)$ に存在しています。

<center>
    <img src='https://github.com/user-attachments/assets/2d297379-3400-4e33-b11b-d2de3e2c8662' width='40%'>
</center>

初期座標 $(s_x, s_y)$ が与えられるので時刻 $T$ 秒での点の座標を求めてください。


### 入力形式
入力は以下の形式で与えられる。

``` math
$W$ $H$ $T$
$s_x$ $s_y$
```

### 制約

- 入力は全て整数
- ${@constraints.MIN_WHT} \leq W, H, T \leq {@constraints.MAX_WHT}$
- ${@constraints.MIN_XY} \leq s_x \leq W$
- ${@constraints.MIN_XY} \leq s_y \leq H$



### 出力形式

答えの座標が $(ans_x, ans_y)$ のとき次の形式で出力せよ。
なお、答えが $32$ bit 整数に収まらないことがある事に注意せよ。

``` math
$ans_x$ $ans_y$
```

{@samples.all}
