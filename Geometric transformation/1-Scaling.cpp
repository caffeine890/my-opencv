
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
    //string win_dst3 = "dst3";
    //string win_dst4 = "dst4";

    // 入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falconikichi.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2,img_dst3;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ここに核となる処理を記述する (例）flip(img_src, img_dst, 0); //垂直回転
    const Mat affine_matrix1 = (Mat_<double>(2, 3) << 0.5, 0, 0, 0, 0.5, 0);
    const Mat affine_matrix2 = (Mat_<double>(2, 3) << 2, 0, 0, 0, 2, 0);
    warpAffine(img_src, img_dst1, affine_matrix1, img_src.size(), INTER_CUBIC);
    warpAffine(img_src, img_dst2, affine_matrix2, img_src.size(), INTER_CUBIC);



    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);

    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);

     //画像の保存
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\Geometric transformation\\1-1.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\Geometric transformation\\1-2.jpg", img_dst1);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\Geometric transformation\\1-3.jpg", img_dst2);


    waitKey(0);
    return 0;
}