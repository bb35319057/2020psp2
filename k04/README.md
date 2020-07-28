# 課題4 レポート

bb35319057 吉田 龍生

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l.6 int型のgender,ID double型のheightからなる構造体Dataを定義

l.15 14個の配列を宣言

l.33　ファイル名を尋ね、もしファイルが開けたなら数が読み込めなくなるまで以下を繰り返す

l.38 sscanfで読み取った一つ目の値をgenderへ、
二つ目の値をheightへ格納

l.57 もう一つファイル名を尋ね、ファイルが開けたなら数が読み込めなくなるまで以下を繰り返す

l.58 sscanfで読み取った値をIDへ格納

l.66 IDを尋ね、int型のflagを0とし、以下を繰り返す

l.71 入力されたIDと格納しているIDを一つずつ比較し、等しかったらflagを1として、そのIDを出力。
同じ番号のgenderの値が1ならば"male"と出力、そうでなければ"female"と出力。
同じ番号のheightの値を出力する。

l.83 もしflagが0なら、"NO data"と出力



## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

↓ここから

```
input the filename of sample:../sample/heights.csv
the filename of sample: ../sample/heights.csv
input the filename of sample:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
Which ID's data do you want? :45313001
---
ID : 45313001
gender : male
height : 166.90
```
例えば，ID 45313210のデータを調べたいとき，
```
input the filename of sample:../sample/heights.csv
the filename of sample: ../sample/heights.csv
input the filename of sample:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
Which ID's data do you want? :45313210
---
No data
```
↑ここまで
## 修正履歴
[comment #20200721]
- 74行目の条件分岐を修正してください。==iだと変数のなので==1or2が良いです。

[comment #20200728]
- 修正の指示、アドバイス等は特にありません。引き続き先生に提出をお願いします。

[comment #20200728 sonoda]
- 課題4の完了を確認しました
