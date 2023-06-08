#include<iostream>//ひな形コード第一完成+版
#include<cmath>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    string win_src = "src";
    string win_dst1 = "dst1";
    string win_dst2 = "dst2";
    //string win_dst3 = "dst3";
    //string win_dst4 = "dst4";
   
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falconikichi.jpg";//入力画像のファイルpath
    string file_dst = "C:\\Users\\caffeine111\\Documents\\Falconikichi2.jpg";//出力画像のファイルpath
    //ウィンドウの名前は、nameWindow(),imshow()で入力を必要とするため、stringで変数宣言すると、手間がはかどる。
    //file_src, file_dst ファイルのpathを格納しているので短くするために変数宣言で手間が省ける。

    Mat img_src = imread(file_src, 0);//画像の読み込みと宣言
    Mat img_dst1, img_dst2;// , img_dst3, img_dst4;// 出力画像の宣言
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }// 読み込みの確認
        
    // ここに核となる処理を記述する (例）flip(img_src, img_dst, 0); //垂直回転
    //Mat element4 = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0); //4近傍
    Mat img_tmp;
    Mat element8 = (Mat_<uchar>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1); //8近傍
    morphologyEx(img_src, img_dst1, MORPH_OPEN, element8, Point(-1, -1), 1);
    morphologyEx(img_src, img_dst2, MORPH_CLOSE, element8, Point(-1, -1), 1);
    //dilate(img_src, img_dst1, element4, Point(-1, -1), 1);
    //dilate(img_src, img_dst2, element8, Point(-1, -1), 1);
    //erode(img_src, img_dst3, element4, Point(-1, -1), 1);
    //erode(img_src, img_dst4, element8, Point(-1, -1), 1);

    // ウィンドウの生成
    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    namedWindow(win_dst2, WINDOW_AUTOSIZE);
    //namedWindow(win_dst3, WINDOW_AUTOSIZE);
    //namedWindow(win_dst4, WINDOW_AUTOSIZE);

    imshow(win_src, img_src);//画像の表示
    imshow(win_dst1, img_dst1);
    imshow(win_dst2, img_dst2);
    //imshow(win_dst3, img_dst3);
    //imshow(win_dst4, img_dst4);
    
    //imwrite(file_dst, img_dst);// 処理結果の保存

    waitKey(0);
    return 0;
}
