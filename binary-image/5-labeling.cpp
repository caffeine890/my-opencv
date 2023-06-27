#define _USE_MATH_DEFINES
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

    // 入力画像のpathの格納
    string file_src = "入力画像path";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1,img_dst2 , img_dst3, img_dst4;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ラベリング処理
    Mat img_lab1;
    int nlabel1 = connectedComponents(img_src, img_lab1);
    compare(img_lab1, 1, img_dst1, CMP_EQ);

    Mat img_lab2;
    int nlabel2 = connectedComponents(img_src, img_lab2);
    compare(img_lab2, 1, img_dst2, CMP_EQ);

    Mat img_lab3;
    int nlabel3 = connectedComponents(img_src, img_lab3);
    compare(img_lab3, 1, img_dst3, CMP_EQ);



    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    namedWindow(win_dst3, WINDOW_AUTOSIZE);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);
    imshow(win_dst3, img_dst3);

    //画像の保存
    imwrite("出力画像path1", img_src);
    imwrite("出力画像path2", img_dst1);
    imwrite("出力画像path3", img_dst2);
    imwrite("出力画像path4", img_dst3);

    waitKey(0);
    return 0;
}
