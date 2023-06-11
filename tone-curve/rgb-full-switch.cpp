#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_dst = "dst";
    string win_dst2 = "dst2";
    string win_dst3 = "dst3";
    string win_dst4 = "dst4";
    string win_dst5 = "dst5";
    //入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 1);

    //出力画像オブジェクトの宣言
    Mat img_dst, img_dst2, img_dst3, img_dst4, img_dst5;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    namedWindow(win_dst3, WINDOW_AUTOSIZE);
    namedWindow(win_dst4, WINDOW_AUTOSIZE);
    namedWindow(win_dst5, WINDOW_AUTOSIZE);

    //RGB値の編集
    vector<Mat> img_bgr(3);
    split(img_src, img_bgr);
    merge(vector<Mat>{img_bgr[0], img_bgr[2], img_bgr[1]}, img_dst);
    merge(vector<Mat>{img_bgr[1], img_bgr[0], img_bgr[2]}, img_dst2);
    merge(vector<Mat>{img_bgr[1], img_bgr[2], img_bgr[0]}, img_dst3);
    merge(vector<Mat>{img_bgr[2], img_bgr[0], img_bgr[1]}, img_dst4);
    merge(vector<Mat>{img_bgr[2], img_bgr[1], img_bgr[0]}, img_dst5);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst, img_dst);
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);
    imshow(win_dst4, img_dst4);
    imshow(win_dst5, img_dst5);

    //画像の保存
    //imwrite("C:\\Users\\caffeine111\\Desktop\\my-opencv\\rgb-switch1.jpg", img_dst);
    //imwrite("C:\\Users\\caffeine111\\Desktop\\my-opencv\\rgb-switch2.jpg", img_dst2);
    //imwrite("C:\\Users\\caffeine111\\Desktop\\my-opencv\\rgb-switch3.jpg", img_dst3);
    //imwrite("C:\\Users\\caffeine111\\Desktop\\my-opencv\\rgb-switch4.jpg", img_dst4);
    //imwrite("C:\\Users\\caffeine111\\Desktop\\my-opencv\\rgb-switch5.jpg", img_dst5);

    waitKey(0);//キー入力待ち
    return 0;
}
