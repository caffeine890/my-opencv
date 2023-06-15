#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_dst1 = "dst1";
    string win_dst2 = "dst2";
    string win_dst3 = "dst3";
    string win_dst4 = "dst4";
    string win_dst5 = "dst5";
    //入力画像のpathの格納
    string file_src = "入力画像path";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 1);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2, img_dst3, img_dst4, img_dst5;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    namedWindow(win_dst3, WINDOW_AUTOSIZE);
    namedWindow(win_dst4, WINDOW_AUTOSIZE);
    namedWindow(win_dst5, WINDOW_AUTOSIZE);

    //RGB値の処理※
    vector<Mat> img_bgr(3);
    split(img_src, img_bgr);
    merge(vector<Mat>{img_bgr[0], img_bgr[2], img_bgr[1]}, img_dst1);
    merge(vector<Mat>{img_bgr[1], img_bgr[0], img_bgr[2]}, img_dst2);
    merge(vector<Mat>{img_bgr[1], img_bgr[2], img_bgr[0]}, img_dst3);
    merge(vector<Mat>{img_bgr[2], img_bgr[0], img_bgr[1]}, img_dst4);
    merge(vector<Mat>{img_bgr[2], img_bgr[1], img_bgr[0]}, img_dst5);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);
    imshow(win_dst4, img_dst4);
    imshow(win_dst5, img_dst5);

    //画像の保存
    imwrite("出力画像path1", img_dst1);
    imwrite("出力画像path2", img_dst2);
    imwrite("出力画像path3", img_dst3);
    imwrite("出力画像path4", img_dst4);
    imwrite("出力画像path5", img_dst5);

    waitKey(0);
    return 0;
}
/*

RGB値の総入れ替えの方法※

1.vector<Mat>型を用いて、3要素を持つ画像オブジェクトimg_bgrを宣言する
2.split関数を用いて、マルチチャンネルの入力画像をシングルチャンネルに分割して、それぞれをimg_bgrに格納する
3.merge関数を用いて、img_bgrの要素を任意の並びを作り、出力画像を指定する

*/