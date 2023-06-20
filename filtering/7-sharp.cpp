}*/
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
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2, img_dst3, img_dst4;

    //入力画像オブジェクトの宣言と読み込み
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ここに核となる処理を記述する (例）flip(img_src, img_dst, 0); //垂直回転
    Mat img_tmp1;
    float k1 = 1.0;
    Mat op1 = Mat::ones(3, 3, CV_32F) * -k1;
    op1.at<float>(1, 1) = 1 + 8 * k1;
    filter2D(img_src, img_tmp1, CV_32F, op1);
    convertScaleAbs(img_tmp1, img_dst1, 1, 0);


    Mat img_tmp2;
    float k2 = 1.0;
    Mat op2 = Mat::ones(5, 5, CV_32F) * -k2;
    op2.at<float>(1, 1) = 1 + 8 * k2;
    filter2D(img_src, img_tmp2, CV_32F, op2);
    convertScaleAbs(img_tmp2, img_dst2, 1, 0);


    Mat img_tmp3;
    float k3 = 1.0;
    Mat op3 = Mat::ones(7, 7, CV_32F) * -k3;
    op3.at<float>(1, 1) = 1 + 8 * k3;
    filter2D(img_src, img_tmp3, CV_32F, op3);
    convertScaleAbs(img_tmp3, img_dst3, 1, 0);


    Mat img_tmp4;
    float k4 = 1.0;
    Mat op4 = Mat::ones(9, 9, CV_32F) * -k4;
    op4.at<float>(1, 1) = 1 + 8 * k4;
    filter2D(img_src, img_tmp4, CV_32F, op4);
    convertScaleAbs(img_tmp4, img_dst4, 1, 0);

    // ウィンドウの生成
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

    //画像の保存
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-1.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-2.jpg", img_dst1);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-3.jpg", img_dst2);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-4.jpg", img_dst3);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\7-5.jpg", img_dst4);

    waitKey(0);
    return 0;
}
