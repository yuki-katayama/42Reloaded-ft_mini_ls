# ft_mini_ls
## 日本語
### 概要
簡単なlsコマンドを実装する。

### 実装コマンド
* -F ファイルのタイプ識別子を表示
* -G ファイルのタイプに色をつける
* -a 隠しファイルも表示
* -s ファイルのブロック数を表示
* -S ファイルサイズの大きい順に並べる
* -t ファイルの更新順に並べる
* -r 逆に並べる
* -i ファイルのノードナンバーを表示
* -m 改行ではなく、コンマ区切りにする
* -k -sした時にkバイト表示  1/2するだけ
* -S その方が -tより優先される

### 実行方法
1.  make allコマンドは ls -1tr出力になっている。
1.  様々なフラグ対応は、make bonusコマンドで実行する。
2.  ft_mini_lsの実行ファイルができる。
3.  ./ft_mini_ls -GFなどで実行できる。

## English

### Summary
Implement a simple ls command.

### Implemented commands.
* -F Display type identifiers for files
* -G Color the file type.
* -a Show hidden files too
* -s Show the number of blocks in a file
* -S Sort files in order of increasing file size
* -t Sort by file updates
* -r Sort in reverse order
* -i Display node numbers of files
* -m Use comma separator instead of line feed
* -k Display k bytes when you do -s Just do 1/2
* -S That takes precedence over -t.

### How to execute
1. make all command has ls -1tr output.
1. The various flag support is done by the make bonus command. 2.
2. ft_mini_ls executable is created. 3.
3. . /ft_mini_ls -GF etc. 3.

![pic-1](https://i.gyazo.com/9886447a023b9ecce2726feb38103cca.png)

