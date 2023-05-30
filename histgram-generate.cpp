#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

    using namespace std;
    using namespace cv;

    int main() {
        string win_src = "src";
        string win_hst = "hst";
        string file_src = "C:\\Users\\caffeine111\\Documents\\Falcon.jpg"; 

        Mat img_src = imread(file_src, 0);

        if (img_src.empty()) {
            cout << "Error: Failed to read the image" << endl;
            return -1;
        }

        namedWindow(win_src, WINDOW_AUTOSIZE);
        namedWindow(win_hst, WINDOW_AUTOSIZE);

        
        // ヒストグラム表示用、256 * 100 ピクセル、　0(黒) で
        Mat img_hst = Mat::zeros(100, 256, CV_8UC1);
       
        const int hdims[] = { 256 };
        const float hranges[] = { 0, 256 };
        const float* ranges[] = { hranges };
        // 1チャンネル画像の度数分布表を計算
        Mat hist;
        calcHist(&img_src, 1, 0, Mat(), hist, 1, hdims, ranges);
        // 度数の最大値を取得
        double hist_min, hist_max;
        minMaxLoc(hist, &hist_min, &hist_max);
        
        // ヒスとグラムを白線で描画
        for (int i = 0; i <= 255; i++) {
            int v = saturate_cast<int>(hist.at<float>(i));
            line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - img_hst.rows * (v / hist_max)), Scalar(255, 255, 255));
        }
        

        imshow(win_src, img_src);
        imshow(win_hst, img_hst);
        //imwrite(file_dst, img_src);

        waitKey(0);
        return 0;
    }