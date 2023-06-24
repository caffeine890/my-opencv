#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("出力ファイルpath"); 

    if (outputFile.is_open()) { 
        for (int i = 1; i <= 256; i++) {
            for (int j = 0;  j <= 255; j++) {
                outputFile << j << " ";
            }
        }
        outputFile.close(); 
        std::cout << "ファイルに書き込み完了\n";
    } else {
        std::cout << "ファイルに書き込み失敗\n";
    }
    return 0;
}
