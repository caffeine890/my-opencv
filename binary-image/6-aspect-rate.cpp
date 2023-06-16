#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_dst1 = "dst1";

    // 入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falconikichi.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1 = img_src.clone();

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    //縦横比の処理
    Rect rect = boundingRect(img_src);
    double aspectRatio = (double)(rect.height) / rect.width;
    cout << "Aspect Ratio: " << aspectRatio << endl;
    rectangle(img_dst1, rect, Scalar(128));

    //ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);

    ///画像の保存
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\6-1.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\binary-image\\6-2.jpg", img_dst1);

    waitKey(0);
    return 0;
}

