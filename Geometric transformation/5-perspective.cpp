
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
    

    // 入力画像のpathの格納
    string file_src = "入力画像path";
    
    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }
    
    Point2f pts1[] = { Point2f(0,0), Point2f(0,960), Point2f(668, 960), Point2f(668, 0) };
    Point2f pts2[] = { Point2f(240,240), Point2f(0,668), Point2f(668, 960), Point2f(720, 240) };
    Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);
    warpPerspective(img_src, img_dst1, perspective_matrix, img_src.size(), INTER_LINEAR);


    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    
    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    
    //画像の保存
    imwrite("出力画像path1", img_src);
    imwrite("出力画像path2", img_dst1);

    waitKey(0);
    return 0;
}

