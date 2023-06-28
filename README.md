# my-opencv

このリポジトリは、画像処理に関連するコードと処理後の画像をまとめています。各処理ごとにフォルダが分かれており、それぞれのフォルダには処理のコードと出力画像が含まれています。使用した画像はpixabayというフリー画像の提供をしているサイトからダウンロードしています。

## ディレクトリ構造

- `binary-image/`: 二値化処理に関連するコードと処理後の画像が格納されています。
- `filtering/`: フィルタ処理に関連するコードと処理後の画像が格納されています。
- `Geometric transformation/`: 幾何学変換に関連するコードと処理後の画像が格納されています。
- `pgm/`: PGMファイル形式の処理に関連するコードと画像が格納されています。
- `tone-curve/`: トーンカーブ処理に関連するコードと処理後の画像が格納されています。


## フォルダの詳細

### 1. 二値化処理 (`binary-image/`)

このフォルダには、二値化処理に関連するコードと処理後の画像が含まれています。

- `binary-image-Mat/`: 出力結果の画像が格納されています。
- `1-binaryzation.cpp`: 二値化処理のコード
- `2-masking.cpp`: マスク合成のコード
- `3-dilate,erode.cpp`: 収縮と膨張のコード
- `4-open,close.cpp`: オープニングとクロージングのコード
- `5-labeling.cpp`: ラベリングのコード
- `6-aspect.cpp`: 縦横比の描画と計算のコード

## 2. フィルタ処理 (`filtering/`)

このフォルダには、フィルタ処理に関連するコードと処理後の画像が含まれています。

- `filtering-Mat/`: 出力結果の画像が格納されています。
- `1-averageop.cpp`: 平均化オペレータフィルタ処理のコード
- `2-Gaussianop.cpp`: ガウシアンオペレータフィルタ処理のコード
- `3-bilateralop.cpp`: バイラテラルオペレータフィルタ処理のコード
- `4-medianop.cpp`: 中央値フィルタ処理のコード
- `5-sobelop.cpp`: Sobelオペレータによるエッジ検出のコード
- `6-laplasian.cpp`: 二次微分オペレータによるエッジ検出のコード
- `7-sharp.cpp`: 鮮鋭化フィルタ処理のコード

## 3. 幾何学変換 (`Geometric transformation/`)

このフォルダには、幾何学変換に関連するコードと処理後の画像が含まれています。

- `Geometric transformation-Mat/`: 出力結果の画像が格納されています。
- `1-Scaling.cpp`: 拡大縮小処理のコード
- `2-Rotation.cpp`: 角度調整のコード
- `3-Shaering.cpp`: せん断調整のコード
- `4-reflection.cpp`: 線対称化のコード
- `5-perspective.cpp`: 射影変換のコード

## 4. PGMファイル形式の処理 (`pgm/`)

このフォルダには、PGMファイル形式の処理に関連するコードと画像が含まれています。

- `1.cpp`: pgm1.pgmのための数列を生成するコード
- `2.cpp`: pgm2.pgmのための数列を生成するコード
- `3.cpp`: pgm3.pgmのための数列を生成するコード
- `4.cpp`: pgm4.pgmのための数列を生成するコード
- `pgm1.pgm`: 上下方向のグラデーション（黒→白）のPGMファイル
- `pgm1.png`: pgm1.pgmをIrfanViewなどで開いたスクリーンショット
- `pgm1.txt`: pgm1.pgmをテキスト形式で保存したファイル
- `pgm2.pgm`: 上下方向のグラデーション（白→黒）のPGMファイル
- `pgm2.png`: pgm2.pgmをIrfanViewなどで開いたスクリーンショット
- `pgm2.txt`: pgm2.pgmをテキスト形式で保存したファイル
- `pgm3.pgm`: 左右方向のグラデーション（黒→白）のPGMファイル
- `pgm3.png`: pgm3.pgmをIrfanViewなどで開いたスクリーンショット
- `pgm3.txt`: pgm3.pgmをテキスト形式で保存したファイル
- `pgm4.pgm`: 左右方向のグラデーション（白→黒）のPGMファイル
- `pgm4.png`: pgm4.pgmをIrfanViewなどで開いたスクリーンショット
- `pgm4.txt`: pgm4.pgmをテキスト形式で保存したファイル

## 5. トーンカーブ処理 (`tone-curve/`)

このフォルダには、トーンカーブ処理に関連するコードと処理後の画像が含まれています。

- `tonesurve-Mat/`: 出力結果の画像が格納されています。
- `1-rgb.cpp`: RGB値の入れ替えのコード
- `2-histgram.cpp`: 画素値の度数のヒストグラムの生成のコード
- `3-equalize.cpp`: 度数の均一化のコード
- `4-negative.cpp`: ネガポジ変換のコード
- `5-luminance.cpp`: 明度調整のコード
- `6-contrast.cpp`: コントラスト調整のコード
- `7-gamma.cpp`: ガンマ変換のコード
