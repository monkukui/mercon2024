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

#### rime
src/[your problem]/で `rime test` するとテストを実行できる

validator.cpp:4:10: fatal error: ../../common/testlib.h: No such file or directory
というエラーが出た場合はvalidator.cppとgenerator.cppの　#include "../../common/　を　#include "../../../common/　に変えてください

#### sampleの確認
src/で `python3 test_all_testcase.py`をすることで手動で作成したテストケースの答えとrimeで作成されたた答えが一致するか確認できます。

出力の見方

- `[ PASS ] {問題名}` 問題の解放全部で想定通りの動きをした時に出力されます。
- `[ ERROR ] {問題名}/{解法名}: {テストケース名}の解が存在しません、WAやTLEでrimeの実行が途中で止まっている可能性があります` sampleの答えが一致しない場合やsampleの答えが存在しない場合に起きます。AC解が途中でWAやTLEになっている時に発生します。
- `[ Unexpected Error ]` ファイルの構造がおかしい場合やファイル、フォルダが存在しない場合に起きます


## 問題

|     | 問題名 |
| --- | ----- |
| A | listing |
| B | BuyItem |
| C | reflection |
| D | RareShoes |
| E | TreeWalking |
| F | Mercard |
| G | hallo |
| H | MultipleInequalities |
