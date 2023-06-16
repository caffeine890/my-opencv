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
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg";//入力画像のファイルpath

    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 1);

    //出力画像オブジェクトの宣言
    Mat img_dst1, img_dst2, img_dst3, img_dst4;

    //入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    // ここに核となる処理を記述する 
    blur(img_src, img_dst1, Size(3, 3));
    blur(img_src, img_dst2, Size(5, 5));
    blur(img_src, img_dst3, Size(7, 7));
    blur(img_src, img_dst4, Size(9, 9));

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
    
    
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\1-1.jpg", img_src);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\1-2.jpg", img_dst1);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\1-3.jpg", img_dst2);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\1-4.jpg", img_dst3);
    imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\filtering\\1-5.jpg", img_dst4);

    waitKey(0);
    return 0;
}

/*

後ほど
*/