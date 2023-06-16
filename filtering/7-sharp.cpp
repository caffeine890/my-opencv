#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    //ウィンドウ名の宣言
    string win_src = "src";
    string win_dst1 = "dst1";
    //string win_dst2 = "dst2";
    //string win_dst3 = "dst3";
    //string win_dst4 = "dst4";

    // 入力画像のpathの格納
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";
    
    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1; //img_dst2, img_dst3, img_dst4;

    //入力画像オブジェクトの宣言と読み込み
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }
        
    // ここに核となる処理を記述する (例）flip(img_src, img_dst, 0); //垂直回転
    Mat img_tmp;

    float k = 1.0;
    Mat op = Mat::ones(3, 3, CV_32F) * -k;
    op.at<float>(1, 1) = 1 + 8 * k;

    filter2D(img_src, img_tmp, CV_32F, op);
    convertScaleAbs(img_tmp, img_dst1, 1, 0);

    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    //namedWindow(win_dst2, WINDOW_AUTOSIZE);
    //namedWindow(win_dst3, WINDOW_AUTOSIZE);
    //namedWindow(win_dst4, WINDOW_AUTOSIZE);
    
    //画像の表示
    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    //imshow(win_dst2, img_dst2);
    //imshow(win_dst3, img_dst3);
    //imshow(win_dst4, img_dst4);
    //画像の保存
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-1.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-2.jpg", img_dst1);

    waitKey(0);
    return 0;
}
