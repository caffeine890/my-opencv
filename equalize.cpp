#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

    int main() {
        string win_src = "src";
        string win_hst = "hst";
        string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg"; 
        string file_dst = "C:\\Users\\caffeine111\\Desktop\\Mats\\equalized1.jpg";

        Mat img_src = imread(file_src, 0);//入力画像の宣言と読み込み
        Mat img_dst2;
        if (img_src.empty()) {
            cout << "error" << endl;
            return -1;
        }//入力画像の読み込みの確認

        //ウィンドウの生成
        namedWindow(win_src, WINDOW_AUTOSIZE);
        namedWindow(win_hst, WINDOW_AUTOSIZE);

        // ヒストグラム表示用の画像の宣言
        Mat img_hst = Mat::zeros(100, 256, CV_8UC1);

        //必要な処理
        equalizeHist(img_src, img_src);


        //ヒストグラムの描画
        const int hdims[] = { 256 };
        const float hranges[] = { 0, 256 };
        const float* ranges[] = { hranges };
        
        Mat hist;
        calcHist(&img_src, 1, 0, Mat(), hist, 1, hdims, ranges);
        
        double hist_min, hist_max;
        minMaxLoc(hist, &hist_min, &hist_max);
    
        for (int i = 0; i <= 255; i++) {
            int v = saturate_cast<int>(hist.at<float>(i));
            line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - img_hst.rows * (v / hist_max)), Scalar(255, 255, 255));
        }
        
        //画像の表示と保存
        imshow(win_src, img_src);
        imshow(win_hst, img_hst);
        imwrite( file_dst , img_hst );
        imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\equalized.jpg", img_src);
        imwrite("C:\\Users\\caffeine111\\Desktop\\Mats\\equalized1.jpg", img_hst); 

        waitKey(0);
        return 0;
    }
    