
#define _CRT_SECURE_NO_WARNINGS// GBR値入れ替え全パターン
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";
string win_dst2 = "dst2";
string win_dst3 = "dst3";
string win_dst4 = "dst4";
string win_dst5 = "dst5";

int main() {
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";//入力画像のファイル名,これはimresdで必要
    //string file_dst = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";//出力画像のファイル名,これは保存の関数でだけ使っている
   
    Mat img_src = imread(file_src, 1);//入力画像の（カラー）の読み込み
    //Mat img_src = imread(file_src, 0;//入力画像（グレースケール）読み込み


    Mat img_dst, img_dst2, img_dst3, img_dst4, img_dst5;
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
    

    // ここに核となる処理を記述する flip(img_src, img_dst, 0);// 垂直回転
    vector<Mat> img_bgr(3);
    split(img_src, img_bgr);
    merge(vector<Mat>{img_bgr[0], img_bgr[2], img_bgr[1]}, img_dst);
    merge(vector<Mat>{img_bgr[1], img_bgr[0], img_bgr[2]}, img_dst2);
    merge(vector<Mat>{img_bgr[1], img_bgr[2], img_bgr[0]}, img_dst3);
    merge(vector<Mat>{img_bgr[2], img_bgr[0], img_bgr[1]}, img_dst4);
    merge(vector<Mat>{img_bgr[2], img_bgr[1], img_bgr[0]}, img_dst5);

    imshow(win_src, img_src);// 入力画像の表示
    imshow(win_dst, img_dst);// 出力画像の表示
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);
    imshow(win_dst4, img_dst4);
    imshow(win_dst5, img_dst5);
    
    
    imwrite("rgb-switch1.png", img_dst);// 処理結果の保存
    imwrite("rgb-switch2.png", img_dst2);
    imwrite("rgb-switch3.png", img_dst3);
    imwrite("rgb-switch4.png", img_dst4);
    imwrite("rgb-switch5.png", img_dst5);

    waitKey(0);// キー入力待ち
    return 0;
}