## 作業分担

## 作問手順

### 事前準備

仮想環境の作成
```
python3 -m venv myenv
```

仮想環境のアクティベート
```
source myenv/bin/activate
```

rime install
```
pip3 install git+https://github.com/icpc-jag/rime
```

statements-manager install(問題文生成用)
```
pip3 install statements-manager
```

### 問題文作成

1. src/templateをsrc/[your problem]にコピペする
2. src/[your problem]/statement/statement.mdに問題文を書いて、レビューしてもらう
3. 制約をsrc/[your problem]/problem.tomlで定義して、問題文で引用する
4. ss-managerで問題文のHTMLを生成する
```
ss-manager run src/[your problem]
```

### テストケース生成

テストケースはsrc/[your problem]/testsに置く

op1: genertor を C++ or Python で書く
https://github.com/monkukui/mercon2024/blob/main/src/sample-A/tests/generator.cpp
op2: 直接 .in .out file を tests 以下に置く
https://github.com/monkukui/mercon2024/tree/main/src/sample-A/tests

### Writer 解を書く
参考: https://github.com/monkukui/mercon2024/tree/main/src/sample-A/TAB_AC

1. src/[your problem]/codename_ACというフォルダの名前をsrc/[your problem]/[your solution name]に変えてください
2. src/[your problem]/[your solution name]/main.cppに答えとなるプログラムを置いてください
3. 想定WA,TLE解やpythonを使った解放を書く場合はsrc/[your problem]/SOLUTION内のコメントに従ってをsrc/[your problem]/SOLUTION編集してください

## rime

非公式ドキュメントが色々書いてある
https://rime-doc.readthedocs.io/ja/latest/index.html

### テストの実行方法

src/[your problem]/で `rime test` するとテストを実行できる
