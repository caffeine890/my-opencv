#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//ヒストグラム表示の関数
void drawHistogram(const Mat& image, const string& windowName, const string& histogramName) {
    // ヒストグラム表示用の画像オブジェクトの宣言、初期化
    Mat img_hst = Mat::zeros(100, 256, CV_8UC1);

    // ヒストグラムの範囲、区分数の指定
    const int hdims[] = { 256 };
    const float hranges[] = { 0, 256 };
    const float* ranges[] = { hranges };

    //calcHistを使ってhistに度数分布を格納
    Mat hist;
    calcHist(&image, 1, 0, Mat(), hist, 1, hdims, ranges);

    // ヒストグラムの正規化,度数分布を0-img_hst.rowsの間で正規化してhistに格納する
    normalize(hist, hist, 0, img_hst.rows, NORM_MINMAX, -1, Mat());

    //変数ｖに正規化された度数分布i番目の度数をfloatからintへ変換して格納する。line関数で変数img_hstに線を描画する。
    for (int i = 0; i <= 255; i++) {
        int v = saturate_cast<int>(hist.at<float>(i));
        line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - v), Scalar(255, 255, 255));
    }

    //画像の表示
    imshow(windowName, img_hst);

    // ヒストグラムの保存
    imwrite(histogramName, img_hst);
}

int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_dst1 = "dst1";
    string win_dst2 = "dst2";
    string win_dst3 = "dst3";
    string win_dst4 = "dst4";

    //入力画像のpathの格納
    string file_src = "入力画像path";


    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2, img_dst3, img_dst4;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    //コントラスト調整の処理
    int min1 = 50, max1 = 250, min2 = 100, max2 = 200;

    img_src.convertTo(img_dst1, img_src.type(), (max1 - min1) / 255.0, min1);
    img_src.convertTo(img_dst2, img_src.type(), (max2 - min2) / 255.0, min2);


    int min3 = 50, max3 = 250, min4 = 100, max4 = 200;
    img_src.convertTo(img_dst3, img_src.type(), 255.0 / (max3 - min3), -255.0 * min3 / (max3 - min3));
    img_src.convertTo(img_dst4, img_src.type(), 255.0 / (max4 - min4), -255.0 * min4 / (max4 - min4));

    //ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    namedWindow(win_dst3, WINDOW_AUTOSIZE);
    namedWindow(win_dst4, WINDOW_AUTOSIZE);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);
    imshow(win_dst4, img_dst4);

    // ヒストグラムの表示
    drawHistogram(img_src, "Hst-src", "出力画像path1");
    drawHistogram(img_dst1, "Hst-dst1", "出力画像path2");
    drawHistogram(img_dst2, "Hst-dst2", "出力画像path3");
    drawHistogram(img_dst3, "Hst-dst3", "出力画像path4");
    drawHistogram(img_dst4, "Hst-dst4", "出力画像path5");

    imwrite("出力画像path6", img_src);
    imwrite("出力画像path7", img_dst1);
    imwrite("出力画像path8", img_dst2);
    imwrite("出力画像path9", img_dst3);
    imwrite("出力画像path10", img_dst4);

    waitKey(0);
    return 0;
}

