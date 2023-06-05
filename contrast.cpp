#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void drawHistogram(const Mat& image, const string& windowName) {
    // ヒストグラム表示用の画像の宣言
    Mat img_hst = Mat::zeros(100, 256, CV_8UC1);//変数の宣言と初期化

    // ヒストグラムの計算
    const int hdims[] = { 256 };
    const float hranges[] = { 0, 256 };
    const float* ranges[] = { hranges };

    Mat hist;//calcHistを使ってhistに度数分布を格納
    calcHist(&image, 1, 0, Mat(), hist, 1, hdims, ranges);

    // ヒストグラムの正規化
    normalize(hist, hist, 0, img_hst.rows, NORM_MINMAX, -1, Mat());//度数分布を0-img_hst.rowsの間で正規化してhistに格納する

    for (int i = 0; i <= 255; i++) {
        int v = saturate_cast<int>(hist.at<float>(i));//まず、変数ｖに正規化された度数分布i番目の度数をfloatからintへ変換して格納する
        line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - v), Scalar(255, 255, 255));//line関数で変数img_hstに線を描画する
    }//その時、任意の始点座標から終点座標まで指定した色で線を描画するが、それにPoint(),Scalar()を使う、y座標の向きと終点座標の式に注意

    //画像の表示と保存
    imshow(windowName, img_hst);
}

int main() {
    string win_src = "src";
    string win_dst1 = "dst1";
    string win_dst2 = "dst2";
    string win_dst3 = "dst3";
    string win_dst4 = "dst4";

    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";
    string file_dst = "C:\\Users\\caffeine111\\Documents\\Falconikichi2.jpg";

    Mat img_src = imread(file_src, 0);
    Mat img_dst1, img_dst2 ,img_dst3, img_dst4;

    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }
    
    //区間を100,200の2つにする。それを暗いと明るいで明度調整する
    int min1 = 50, max1 = 250, min2 = 100, max2 = 200;
    
    img_src.convertTo(img_dst1, img_src.type(), (max1 - min1) / 255.0, min1);
    img_src.convertTo(img_dst2, img_src.type(), (max2 - min2) / 255.0, min2);
    

    int min3 = 50, max3 = 250, min4 = 100, max4 = 200;
    img_src.convertTo(img_dst3, img_src.type(), 255.0 / (max3 - min3), -255.0 * min3 / (max3 - min3));
    img_src.convertTo(img_dst4, img_src.type(), 255.0 / (max4 - min4), -255.0 * min4 / (max4 - min4));
    
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    namedWindow(win_dst3, WINDOW_AUTOSIZE);
    namedWindow(win_dst4, WINDOW_AUTOSIZE);

    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);
    imshow(win_dst4, img_dst4);

    // ヒストグラムの表示
    drawHistogram(img_src, "Hist src");
    drawHistogram(img_dst1, "Hist dst1");
    drawHistogram(img_dst2, "Hist dst2");
    drawHistogram(img_dst3, "Hist dst3");
    drawHistogram(img_dst4, "Hist dst4");

    //imwrite(file_dst, img_dst);

    waitKey(0);
    return 0;
}
