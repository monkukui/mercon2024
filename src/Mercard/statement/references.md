メルカードとは、メルカリから生まれたおトクなクレジットカードのことです。
参考:
https://jp-news.mercari.com/contents/10969
あなたはメルカードを使ってN個の商品を購入しようと考えており、商品iの値段はA_i 円です。
参考:
https://atcoder.jp/contests/ABC203/tasks/ABC203_F
https://atcoder.jp/contests/ABC209/tasks/ABC209_E
メルカードを使って商品iを購入すると、**ポイント**が次の通り増加します。
今まで購入した商品の金額の合計がS円のとき、商品iを購入するとポイントが A_i * (0.01 + min(0.04,  \lfloor S / X \rfloor )) 増加する。ただし商品A_iを購入するとき、  **今まで購入した商品に商品A_iは含まれません** 。
参考:
ポイントの表記とか https://atcoder.jp/contests/ABC280/tasks/ABC280_F
合計をSと表すこと https://atcoder.jp/contests/ABC202/tasks/ABC202_D
購入する商品の順番を自由に
選べるとき、N個の商品を購入した状態で所持しているポイントの最大値を出力してください。
参考:
ポイントの言い回し https://atcoder.jp/contests/ABC280/tasks/ABC280_F
最大値の言い回し https://atcoder.jp/contests/ABC236/tasks/ABC236_D
# 注釈
\lfloor Y \rfloor は、 Y の小数点以下を切り捨てた値を指します。
この問題文は実際のメルカードの説明とは異なります。(この文章は人事の方に確認していただきたい)
参考
注釈にガウス記号の説明
https://atcoder.jp/contests/ABC233/tasks/ABC233_E
