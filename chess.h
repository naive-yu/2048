//
// Created by 余玮 on 2023/4/1.
//

#pragma once
#include<iostream>
#include<random>
using namespace std;
class chess{
public:
    chess();
    int getchess(int i,int j);
    int getscore() const;
    void randfirst();//随机产生两个方块
    void randpro();//随机产生一个方块

    //手势滑动时，均随机产生一个新的方块
    bool leftSlide();
    bool rightSlide();
    bool topSlide();
    bool downSlide();
    bool gameOver();
    void show();//测试棋盘数据变化
private:
    int chessBoard[4][4]{};
    int score;
    const int M=4;
    default_random_engine e;
};

