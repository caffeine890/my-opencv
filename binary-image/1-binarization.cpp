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

    //変数ｖに正規化された度数分布i番目の度数をfloatからintへ変換して格納する。line関数で変数img_hstに線を描画する
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

    // 入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2, img_dst3, img_dst4;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    //二値化の処理
    int thresh1 = 50, thresh2 = 100, thresh3 = 150, thresh4 = 200;
    threshold(img_src, img_dst1, thresh1, 255, THRESH_BINARY);
    threshold(img_src, img_dst2, thresh2, 255, THRESH_BINARY);
    threshold(img_src, img_dst3, thresh3, 255, THRESH_BINARY);
    threshold(img_src, img_dst4, thresh4, 255, THRESH_BINARY);

    //ウィンドウの処理
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
    drawHistogram(img_src, "Hist-src", "C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-1.jpg");
    drawHistogram(img_dst1, "Hist-dst1", "C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-2.jpg");
    drawHistogram(img_dst2, "Hist-dst2", "C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-3.jpg");
    drawHistogram(img_dst3, "Hist-dst3", "C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-4.jpg");
    drawHistogram(img_dst4, "Hist-dst4", "C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-5.jpg");

    //画像の保存
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-6.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-7.jpg", img_dst1);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-8.jpg", img_dst2);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-9.jpg", img_dst2);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\1-10.jpg", img_dst2);

    waitKey(0);
    return 0;
}
