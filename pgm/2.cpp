#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("出力ファイルpath"); 

    if (outputFile.is_open()) { 
        for (int i = 0; i >= 255; i--) {
            for (int j = 1; j <= 256; j++) {
                outputFile << i << " "; 
            }
        }
        outputFile.close(); 
        std::cout << "ファイルに書き込み完了\n";
    } else {
        std::cout << "ファイルに書き込み失敗\n";
    }
    return 0;
}
