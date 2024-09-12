## 作業分担

## rime

非公式ドキュメントが色々書いてある
https://rime-doc.readthedocs.io/ja/latest/index.html

### 導入

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

### テストの実行方法

自分の作ったデレクトリで `rime test` するとテストを実行できる

### 問題文生成方法

```
ss-manager run <your-problem-folder>
```

### WA, TLEのコードの追加方法

https://matsu7874.hatenablog.com/entry/2019/08/21/010308

WAの設定
```
cxx_solution(src='main.cpp', flags=['-std=c++14'], challenge_cases=[])
```

TLEの設定
```
cxx_solution(src='main.cpp', flags=['-std=c++14'], challenge_cases=[])
expected_verdicts([TLE, AC])
```
