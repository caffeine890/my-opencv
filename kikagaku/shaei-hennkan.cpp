
#define _USE_MATH_DEFINES
#include<iostream>//ひな形コード第一完成+版
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
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falconikichi.jpg";//入力画像のファイルpath
    //string file_dst = "C:\\Users\\caffeine111\\Documents\\Falconikichi2.jpg";//出力画像のファイルpath
    
    //入力画像オブジェクトの宣言と読み込み
    Mat img_src = imread(file_src, 0);

    //出力画像オブジェクトの宣言
    Mat img_dst1;//img_dst2;// , img_dst3, img_dst4;

    /入力画像の読み込みの確認
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }// 
        
    // ここに核となる処理を記述する (例）flip(img_src, img_dst, 0); //垂直回転
    //const Mat affine_matrix1 = (Mat_<double>(2,3)<< cos(2 * M_PI / 4.0), sin( 2 * M_PI / 4.0), 0,
                                //sin(2 * M_PI / 4.0), -cos(2 * M_PI / 4.0), 0);
    //const Mat affine_matrix2 = (Mat_<double>(2, 3) << cos(2 * M_PI / 6.0), sin(2 * M_PI / 6.0), 0,
                                 //sin(2 * M_PI / 6.0), -cos(2 * M_PI / 6.0), 0);
    //warpAffine(img_src, img_dst1, affine_matrix1, img_src.size(), INTER_CUBIC);
    //warpAffine(img_src, img_dst2, affine_matrix2, img_src.size(), INTER_CUBIC);
    //πをプラスにすれば画像は時計周りに回転する
    Point2f pts1[] = { Point2f(0,0), Point2f(0,960), Point2f(668, 960), Point2f(668, 0) };
    Point2f pts2[] = { Point2f(240,240), Point2f(0,668), Point2f(668, 960), Point2f(720, 240) };
    Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);
    warpPerspective(img_src, img_dst1, perspective_matrix, img_src.size(), INTER_LINEAR);
    //float angle = 45.0, scale = 1.0;
    //Point2f center(0,0);
    //Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
    //warpAffine(img_src, img_dst1, affine_matrix, img_src.size(), INTER_CUBIC);


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
    
    //imwrite(file_dst, img_dst);// 処理結果の保存

    waitKey(0);
    return 0;
}

