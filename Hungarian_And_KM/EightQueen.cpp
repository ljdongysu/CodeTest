//// eightQueen
//// Created by donglijian on 10/27/22.
//// http://t.zoukankan.com/evenleee-p-11946724.html
//
//#include <iostream>
//
//int queenPlace[8] = { 8 };  //全局变量，下标表示行，值表示queen存储在那一列
//int count = 0;  //计数器
//
//void printQueen() {  //打印一个二维数组
//    for (int i = 0; i < 8; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            if (queenPlace[i] == j) {
//                printf("Q ");
//            } else {
//                printf("* ");
//            }
//        }
//        std::cout << std::endl;
//    }
//    std::cout << "----count:" << ++count << "-----" << std::endl;
////    printf("----count:%d-----
////           ", ++count);
//}
//
//bool isOk(int row, int col) {  //判断row行col列放置是否合适
//    int leftUp = col - 1;  //左上对角线
//    int rightUp = col + 1; //右上对角线
//    for (int i = row - 1; i >= 0; --i) {
//        if (queenPlace[i] == col) return false;  //同列上的格子有皇后
//        if (leftUp >= 0) {
//            if (queenPlace[i] == leftUp) return false;   //左上对角线有皇后
//        }
//        if (rightUp < 8) {
//            if (queenPlace[i] == rightUp) return false;  //右上对角线有皇后
//        }
//        --leftUp; ++rightUp;
//    }
//    return true;
//}
//
//void eightQueen(int row) {
//    if (row == 8) {  //8个皇后都放置好，打印，无法递归返回
//        printQueen();
//        return;
//    }
//    for (int col = 0; col < 8; ++col) {  //每一行都有8种方法
//        if (isOk(row, col)) {    //满足要求
//            queenPlace[row] = col; //第row行的皇后放在col列
//            eightQueen(row+1);     //考察下一行
//        }
//    }
//}
//
//
//int main() {
//    eightQueen(0);return 0;
//}
//


//
// Created by indemind on 10/27/22.
//

#include <iostream>
#include <vector>

std::vector<int> queenPlace[8] = { 8 };  //全局变量，下标表示行，值表示queen存储在那一列
int count = 0;  //计数器
std::vector<std::vector<float>> iouMap;
std::vector<std::vector<int>> indexMap;
void printQueen() {  //打印一个二维数组
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (queenPlace[i] == j) {
                printf("Q ");
            } else {
                printf("* ");
            }
        }
        std::cout << std::endl;
    }
    std::cout << "----count:" << ++count << "-----" << std::endl;

    for (int i = 0; i < 8; ++i)
    {
        std::cout << queenPlace[i] <<", ";
    }
    std::cout<< std::endl;
}

bool isOk(int row, int col, std::vector<std::vector<int>> &indexMap, std::vector<int> &queenPlace)
{  //判断row行col列放置是否合适
    if (indexMap[row][col] == -1) return true;
    for (int i = row - 1; i >= 0; --i)
    {
        if (queenPlace[i] == indexMap[row][col]) return false;  //同列上的格子有皇后
    }
    return true;
}

void EightQueen(int row, std::vector<std::vector<int>> &indexMap, std::vector<int> &queenPlace) {
    if (row == indexMap.size())
    {  //8个皇后都放置好，打印，无法递归返回
        printQueen();
        return;
    }
    for (int col = 0; col < indexMap[row].size(); ++col)
    {  //每一行都有8种方法
        if (isOk(row, col)) {    //满足要求
            queenPlace[row] = indexMap[row][col]; //第row行的皇后放在col列
            EightQueen(row+1);     //考察下一行
        }
    }
}


int main() {

    iouMap.push_back({0.1,0.2,0});
    iouMap.push_back({0.1,0.2,0.3,0.4,-1});
    iouMap.push_back({0.1,0.2,-1});
    iouMap.push_back({0.3,0.1,-1});
//    iouMap.push_back({1,2,-1});
//    iouMap.push_back({4,1,-1});
//    iouMap.push_back({2,1,-1});
//    iouMap.push_back({0,1,0});
    for (auot map : iouMap)
    {
        std::vector<int> index;
        for (int i = 0; i < map.size(); ++i)
        {
            if (map[i] > 0)
            {
                index.push_back(i);
            }
        }
        index.push_back(-1);
        indexMap.push_back(index);
    }






    EightQueen(0);return 0;
}
