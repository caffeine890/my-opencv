#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_hst = "hst";

    //入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";
    //string file_dst = "C:\\Users\\caffeine111\\Desktop\\Mats\\Falcon-gray.jpg";
    //string file_hist = "C:\\Users\\caffeine111\\Desktop\\Mats\\histgram.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    ////入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    //ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_hst, WINDOW_AUTOSIZE);

    // ヒストグラム表示用の画像の宣言
    Mat img_hst = Mat::zeros(100, 256, CV_8UC1);//変数の宣言と初期化

    //ヒストグラムの範囲、区分数の指定
    const int hdims[] = { 256 };
    const float hranges[] = { 0, 256 };
    const float* ranges[] = { hranges };

    //calcHistを使ってhistに度数分布を格納
    Mat hist;
    calcHist(&img_src, 1, 0, Mat(), hist, 1, hdims, ranges);

    // ヒストグラムの正規化,度数分布を0-img_hst.rowsの間で正規化してhistに格納する
    normalize(hist, hist, 0, img_hst.rows, NORM_MINMAX, -1, Mat());

    
    //変数ｖに正規化された度数分布i番目の度数をfloatからintへ変換して格納する。line関数で変数img_hstに線を描画する。
    //その時、任意の始点座標から終点座標まで指定した色で線を描画するが、それにPoint(),Scalar()を使う、y座標の向きと終点座標の式に注意
    for (int i = 0; i <= 255; i++) {
       int v = saturate_cast<int>(hist.at<float>(i));
       line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - v), Scalar(255, 255, 255));
    }



    //画像の表示
    imshow(win_src, img_src);
    imshow(win_hst, img_hst);

    //imwrite(file_dst, img_src);
    //imwrite(file_hist, img_hst);

    waitKey(0);
    return 0;
}
