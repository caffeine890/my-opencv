#include<iostream>
#include<cmath>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    string win_src = "src";
    string win_dst1 = "dst1";
    string file_src = "C:\\Users\\caffeine111\\Documents\\Falconikichi.jpg";
    string file_dst = "C:\\Users\\caffeine111\\Documents\\Falconikichi2.jpg";

    Mat img_src = imread(file_src, 0);
    Mat img_dst1 = img_src.clone();
    if (!img_src.data) {
        cout << "error" << endl;
        return -1;
    }

    Rect rect = boundingRect(img_src);
    double aspectRatio = (double)(rect.height) / rect.width;
    cout << "Aspect Ratio: " << aspectRatio << endl;
    rectangle(img_dst1, rect, Scalar(128));

    namedWindow(win_src, WINDOW_AUTOSIZE);
    namedWindow(win_dst1, WINDOW_AUTOSIZE);
    

    imshow(win_src, img_src);
    imshow(win_dst1, img_dst1);
    

    waitKey(0);
    return 0;
}

