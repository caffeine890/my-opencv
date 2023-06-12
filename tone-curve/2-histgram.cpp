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
    string file_src = "入力画像path";

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

    //ヒストグラム表示の処理　※
    Mat img_hst = Mat::zeros(100, 256, CV_8UC1);

    const int hdims[] = { 256 };
    const float hranges[] = { 0, 256 };
    const float* ranges[] = { hranges };

    Mat hist;
    calcHist(&img_src, 1, 0, Mat(), hist, 1, hdims, ranges);

    normalize(hist, hist, 0, img_hst.rows, NORM_MINMAX, -1, Mat());

    for (int i = 0; i <= 255; i++) {
        int v = saturate_cast<int>(hist.at<float>(i));
        line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - v), Scalar(255, 255, 255));
    }



    //画像の表示
    imshow(win_src, img_src);
    imshow(win_hst, img_hst);

    imwrite("出力画像path1", img_src);
    imwrite("出力画像path2", img_hst);

    waitKey(0);
    return 0;
}

/*

ヒストグラム表示の処理※

ヒストグラムの表示用の画像を100*256に指定する。
calcHist()を用いて、hstに度数を格納。その際に、度数分布のビン数と最大値・最小値を変数宣言しておく。
normalize()を用いて、度数分布histの値を0-img_hst.rows(100)の間で正規化する。 
度数分布histの値をfloat型からint型に変え、line()を用いて白色で度数を描画する。これをすべてのⅹ座標で繰り返すためにfor文を使用する。

*/