//
// Created by 余玮 on 2023/4/1.
//

#pragma execution_character_set("utf-8")
#include "chess.h"
#include<qDebug>
chess::chess()
{
    //初始化棋盘
    for (int i = 0; i < M;i++) {
        for (int j = 0; j < M; j++) {
            chessBoard[i][j] = 0;
        }
    }
    score = 0;
}

int chess::getchess(int i, int j)
{
    return chessBoard[i][j];
}

int chess::getscore() const
{
    return score;
}

//3/16/16:修改了随机数生成的代码
void chess::randfirst()//随机生成两个2数字方块
{
    uniform_int_distribution<int> u(0,1);
    chessBoard[u(e) % 4][u(e) % 4] = 2;
    int i = u(e) % 4;
    int j = u(e) % 4;
    while (chessBoard[i][j] != 0) {
        i = u(e) % 4;
        j = u(e) % 4;
    }
    chessBoard[i][j] = 2;
}

void chess::randpro()
{
    uniform_int_distribution<int> u(0,1);
    int i = u(e) % 4;
    int j = u(e) % 4;
    while (chessBoard[i][j] != 0) {
        i = u(e) % 4;
        j = u(e) % 4;
    }
    chessBoard[i][j] = (u(e) % 2+1) * 2;
    //qDebug() << "随机生成成功！";
}

bool chess::leftSlide()
{
    //设置监视哨
    bool change = false;
    int copy[4][4];//拷贝棋盘，用于判断
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            copy[i][j] = chessBoard[i][j];
        }
    }
    //对每一行进行操作
    qDebug() << "leftSlide";
    for (int i = 0; i < M; i++) {
        //先将所有方块移至最左边，再判断是否能合并
        //失败的方法：
        /*for (int j = 1; j < M; j++) {
            int k = j-1;
            int l = j;
            while (k>=0&&chessBoard[i][k] == 0) {
                chessBoard[i][k] = chessBoard[i][l];
                chessBoard[i][1] = 0;
                l = k;
                k--;
                show();
                qDebug() << "";
            }
        }*/
        int temp[4] = {0};
        int t = 0;
        for (int j = 0; j < M; j++) {
            if (chessBoard[i][j] != 0) {
                temp[t++] = chessBoard[i][j];
            }
        }
        for (int j = 0; j < M; j++) {
            chessBoard[i][j]=temp[j];
        }
        if (chessBoard[i][0] == 0||chessBoard[i][1]==0) {
            continue;
        }
        else if (chessBoard[i][0] == chessBoard[i][1]) {
            chessBoard[i][0] += chessBoard[i][1];
            score += chessBoard[i][0];
            if (chessBoard[i][0] == chessBoard[i][2]) {
                chessBoard[i][0] += chessBoard[i][2];
                score += chessBoard[i][0];
                if (chessBoard[i][0] == chessBoard[i][3]) {
                    chessBoard[i][0] += chessBoard[i][3];
                    score += chessBoard[i][0];
                    chessBoard[i][1] = 0;
                    chessBoard[i][2] = 0;
                    chessBoard[i][3] = 0;
                }
                else {
                    chessBoard[i][1] = chessBoard[i][3];
                    chessBoard[i][2] = 0;
                    chessBoard[i][3] = 0;
                }
            }
            else if (chessBoard[i][2]!=0&& chessBoard[i][2]==chessBoard[i][3]) {
                chessBoard[i][1] = chessBoard[i][2]+chessBoard[i][3];
                score += chessBoard[i][1];
                chessBoard[i][2] = 0;
                chessBoard[i][3] = 0;
                if (chessBoard[i][0] == chessBoard[i][1]) {
                    chessBoard[i][0] += chessBoard[i][1];
                    score += chessBoard[i][0];
                    chessBoard[i][1] = 0;
                }
            }
            else {
                chessBoard[i][1] = chessBoard[i][2];
                chessBoard[i][2] = chessBoard[i][3];
                chessBoard[i][3] = 0;
            }
        }
        else if (chessBoard[i][2] == 0) {
            continue;
        }
        else if(chessBoard[i][1]==chessBoard[i][2]){//2、3均非0且相等
            chessBoard[i][1] += chessBoard[i][2];//2、3合并,3为0
            score += chessBoard[i][1];
            chessBoard[i][2] = 0;
            if (chessBoard[i][0] == chessBoard[i][1]) {//2、3合并后与1相等
                chessBoard[i][0] += chessBoard[i][1];//1、2、3合并，判断4
                score += chessBoard[i][0];
                chessBoard[i][1] = 0;
                if (chessBoard[i][0] == chessBoard[i][3]) {
                    chessBoard[i][0] += chessBoard[i][3];
                    score += chessBoard[i][0];
                    chessBoard[i][3] = 0;
                }
                else {
                    chessBoard[i][1] += chessBoard[i][3];
                    score += chessBoard[i][1];
                    chessBoard[i][3] = 0;
                }
            }
            else if(chessBoard[i][1]==chessBoard[i][3]){//2和4相等
                chessBoard[i][1] += chessBoard[i][3];
                score += chessBoard[i][1];
                chessBoard[i][3] = 0;
                if (chessBoard[i][0] == chessBoard[i][1]) {
                    chessBoard[i][0] += chessBoard[i][1];
                    score += chessBoard[i][0];
                    chessBoard[i][1] = 0;
                }
            }
            else {
                chessBoard[i][2] = chessBoard[i][3];
                chessBoard[i][3] = 0;
            }
        }
            //前三个数字均非0，且左右不等时
        else if (chessBoard[i][3] == 0) {
            continue;
        }
        else if (chessBoard[i][2] == chessBoard[i][3]) {
            chessBoard[i][2] += chessBoard[i][3];
            score += chessBoard[i][2];
            chessBoard[i][3] = 0;
            if (chessBoard[i][1] == chessBoard[i][2]) {
                chessBoard[i][1] += chessBoard[i][2];
                score += chessBoard[i][1];
                chessBoard[i][2] = 0;
                if (chessBoard[i][0] == chessBoard[i][1]) {
                    chessBoard[i][0] += chessBoard[i][1];
                    score += chessBoard[i][0];
                    chessBoard[i][1] = 0;
                }
            }
        }
    }
    //判断是否改变
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (copy[i][j] != chessBoard[i][j]) {
                change=true;
            }
        }
    }
    return change;
}

bool chess::rightSlide()
{
    //设置监视哨
    bool change = false;
    int copy[4][4];//拷贝棋盘，用于判断
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            copy[i][j] = chessBoard[i][j];
        }
    }
    //对每一行进行操作
    qDebug() << "rightSlide";
    for (int i = 0; i < M; i++) {
        //先将所有方块移至最右边，再判断是否能合并
        int temp[4] = { 0 };
        int t = M-1;
        for (int j = M-1; j >=0; j--) {
            if (chessBoard[i][j] != 0) {
                temp[t--] = chessBoard[i][j];
            }
        }
        for (int j = 0; j < M; j++) {
            chessBoard[i][j] = temp[j];
        }
        if (chessBoard[i][3] == 0 || chessBoard[i][2] == 0) {
            continue;
        }
        else if (chessBoard[i][3] == chessBoard[i][2]) {
            chessBoard[i][3] += chessBoard[i][2];
            score += chessBoard[i][3];
            if (chessBoard[i][3] == chessBoard[i][1]) {
                chessBoard[i][3] += chessBoard[i][1];
                score += chessBoard[i][3];
                if (chessBoard[i][3] == chessBoard[i][0]) {
                    chessBoard[i][3] += chessBoard[i][0];
                    score += chessBoard[i][3];
                    chessBoard[i][2] = 0;
                    chessBoard[i][1] = 0;
                    chessBoard[i][0] = 0;
                }
                else {
                    chessBoard[i][2] = chessBoard[i][0];
                    chessBoard[i][1] = 0;
                    chessBoard[i][0] = 0;
                }
            }
            else if (chessBoard[i][1] != 0 && chessBoard[i][1] == chessBoard[i][0]) {
                chessBoard[i][2] = chessBoard[i][1] + chessBoard[i][0];
                score += chessBoard[i][2];
                chessBoard[i][1] = 0;
                chessBoard[i][0] = 0;
                if (chessBoard[i][2] == chessBoard[i][3]) {
                    chessBoard[i][3] += chessBoard[i][2];
                    score += chessBoard[i][3];
                    chessBoard[i][2] = 0;
                }
            }
            else {
                chessBoard[i][2] = chessBoard[i][1];
                chessBoard[i][1] = chessBoard[i][0];
                chessBoard[i][0] = 0;
            }
        }
        else if (chessBoard[i][1] == 0) {
            continue;
        }
        else if (chessBoard[i][2] == chessBoard[i][1]) {//2、3均非0且相等
            chessBoard[i][2] += chessBoard[i][1];//2、3合并,2为0
            score += chessBoard[i][2];
            chessBoard[i][1] = 0;
            if (chessBoard[i][3] == chessBoard[i][2]) {//2、3合并后与4相等
                chessBoard[i][3] += chessBoard[i][2];//1、2、3合并，判断4
                score += chessBoard[i][3];
                chessBoard[i][2] = 0;
                if (chessBoard[i][3] == chessBoard[i][0]) {
                    chessBoard[i][3] += chessBoard[i][0];
                    score += chessBoard[i][3];
                    chessBoard[i][0] = 0;
                }
                else {
                    chessBoard[i][2] += chessBoard[i][0];
                    score += chessBoard[i][2];
                    chessBoard[i][0] = 0;
                }
            }
            else if (chessBoard[i][2] == chessBoard[i][0]) {//3和0相等
                chessBoard[i][2] += chessBoard[i][0];
                score += chessBoard[i][2];
                chessBoard[i][0] = 0;
                if (chessBoard[i][3] == chessBoard[i][2]) {
                    chessBoard[i][3] += chessBoard[i][2];
                    score += chessBoard[i][3];
                    chessBoard[i][2] = 0;
                }
            }
            else {
                chessBoard[i][1] = chessBoard[i][0];
                chessBoard[i][0] = 0;
            }
        }
            //后三个数字均非0，且左右不等时
        else if (chessBoard[i][0] == 0) {
            continue;
        }
        else if (chessBoard[i][1] == chessBoard[i][0]) {
            chessBoard[i][1] += chessBoard[i][0];
            score += chessBoard[i][1];
            chessBoard[i][0] = 0;
            if (chessBoard[i][2] == chessBoard[i][1]) {
                chessBoard[i][2] += chessBoard[i][1];
                score += chessBoard[i][2];
                chessBoard[i][1] = 0;
                if (chessBoard[i][3] == chessBoard[i][2]) {
                    chessBoard[i][3] += chessBoard[i][2];
                    score += chessBoard[i][3];
                    chessBoard[i][2] = 0;
                }
            }
        }
    }
    //判断是否改变
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (copy[i][j] != chessBoard[i][j]) {
                change = true;
            }
        }
    }
    return change;
}

bool chess::topSlide()
{
    //设置监视哨
    bool change = false;
    int copy[4][4];//拷贝棋盘，用于判断
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            copy[i][j] = chessBoard[i][j];
        }
    }
    //对每一列进行操作
    qDebug() << "topSlide";
    for (int i = 0; i < M; i++) {
        //先将所有方块移至最上方，再判断是否能合并
        int temp[4] = { 0 };
        int t = 0;
        for (int j = 0; j < M; j++) {
            if (chessBoard[j][i] != 0) {
                temp[t++] = chessBoard[j][i];
            }
        }
        for (int j = 0; j < M; j++) {
            chessBoard[j][i] = temp[j];
        }
        if (chessBoard[0][i] == 0 || chessBoard[1][i] == 0) {
            continue;
        }
        else if (chessBoard[0][i] == chessBoard[1][i]) {
            chessBoard[0][i] += chessBoard[1][i];
            score += chessBoard[0][i];
            if (chessBoard[0][i] == chessBoard[2][i]) {
                chessBoard[0][i] += chessBoard[2][i];
                score += chessBoard[0][i];
                if (chessBoard[0][i] == chessBoard[3][i]) {
                    chessBoard[0][i] += chessBoard[3][i];
                    score += chessBoard[0][i];
                    chessBoard[1][i] = 0;
                    chessBoard[2][i] = 0;
                    chessBoard[3][i] = 0;
                }
                else {
                    chessBoard[1][i] = chessBoard[3][i];
                    chessBoard[2][i] = 0;
                    chessBoard[3][i] = 0;
                }
            }
            else if (chessBoard[2][i] != 0 && chessBoard[2][i] == chessBoard[3][i]) {
                chessBoard[1][i] = chessBoard[2][i] + chessBoard[3][i];
                score += chessBoard[1][i];
                chessBoard[2][i] = 0;
                chessBoard[3][i] = 0;
                if (chessBoard[0][i] == chessBoard[1][i]) {
                    chessBoard[0][i] += chessBoard[1][i];
                    score += chessBoard[0][i];
                    chessBoard[1][i] = 0;
                }
            }
            else {
                chessBoard[1][i] = chessBoard[2][i];
                chessBoard[2][i] = chessBoard[3][i];
                chessBoard[3][i] = 0;
            }
        }
        else if (chessBoard[2][i] == 0) {
            continue;
        }
        else if (chessBoard[1][i] == chessBoard[2][i]) {//2、3均非0且相等
            chessBoard[1][i] += chessBoard[2][i];//2、3合并,3为0
            score += chessBoard[1][i];
            chessBoard[2][i] = 0;
            if (chessBoard[0][i] == chessBoard[1][i]) {//2、3合并后与1相等
                chessBoard[0][i] += chessBoard[1][i];//1、2、3合并，判断4
                score += chessBoard[0][i];
                chessBoard[1][i] = 0;
                if (chessBoard[0][i] == chessBoard[3][i]) {
                    chessBoard[0][i] += chessBoard[3][i];
                    score += chessBoard[0][i];
                    chessBoard[3][i] = 0;
                }
                else {
                    chessBoard[1][i] += chessBoard[3][i];
                    score += chessBoard[1][i];
                    chessBoard[3][i] = 0;
                }
            }
            else if (chessBoard[1][i] == chessBoard[3][i]) {//2和4相等
                chessBoard[1][i] += chessBoard[3][i];
                score += chessBoard[1][i];
                chessBoard[3][i] = 0;
                if (chessBoard[0][i] == chessBoard[1][i]) {
                    chessBoard[0][i] += chessBoard[1][i];
                    score += chessBoard[0][i];
                    chessBoard[1][i] = 0;
                }
            }
            else {
                chessBoard[2][i] = chessBoard[3][i];
                chessBoard[3][i] = 0;
            }
        }
            //前三个数字均非0，且左右不等时
        else if (chessBoard[3][i] == 0) {
            continue;
        }
        else if (chessBoard[2][i] == chessBoard[3][i]) {
            chessBoard[2][i] += chessBoard[3][i];
            score += chessBoard[2][i];
            chessBoard[3][i] = 0;
            if (chessBoard[1][i] == chessBoard[2][i]) {
                chessBoard[1][i] += chessBoard[2][i];
                score += chessBoard[1][i];
                chessBoard[2][i] = 0;
                if (chessBoard[0][i] == chessBoard[1][i]) {
                    chessBoard[0][i] += chessBoard[1][i];
                    score += chessBoard[0][i];
                    chessBoard[1][i] = 0;
                }
            }
        }
    }
    //判断是否改变
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (copy[i][j] != chessBoard[i][j]) {
                change = true;
            }
        }
    }
    return change;
}

bool chess::downSlide()
{
    //设置监视哨
    bool change = false;
    int copy[4][4];//拷贝棋盘，用于判断
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            copy[i][j] = chessBoard[i][j];
        }
    }
    //对每一行进行操作
    qDebug() << "downSlide";
    for (int i = 0; i < M; i++) {
        //先将所有方块移至最下边，再判断是否能合并
        int temp[4] = { 0 };
        int t = M - 1;
        for (int j = M - 1; j >= 0; j--) {
            if (chessBoard[j][i] != 0) {
                temp[t--] = chessBoard[j][i];
            }
        }
        for (int j = 0; j < M; j++) {
            chessBoard[j][i] = temp[j];
        }
        if (chessBoard[3][i] == 0 || chessBoard[2][i] == 0) {
            continue;
        }
        else if (chessBoard[3][i] == chessBoard[2][i]) {
            chessBoard[3][i] += chessBoard[2][i];
            score += chessBoard[3][i];
            if (chessBoard[3][i] == chessBoard[1][i]) {
                chessBoard[3][i] += chessBoard[1][i];
                score += chessBoard[3][i];
                if (chessBoard[3][i] == chessBoard[0][i]) {
                    chessBoard[3][i] += chessBoard[0][i];
                    score += chessBoard[3][i];
                    chessBoard[2][i] = 0;
                    chessBoard[1][i] = 0;
                    chessBoard[0][i] = 0;
                }
                else {
                    chessBoard[2][i] = chessBoard[i][0];
                    chessBoard[1][i] = 0;
                    chessBoard[0][i] = 0;
                }
            }
            else if (chessBoard[1][i] != 0 && chessBoard[1][i] == chessBoard[0][i]) {
                chessBoard[2][i] = chessBoard[1][i] + chessBoard[0][i];
                score += chessBoard[2][i];
                chessBoard[1][i] = 0;
                chessBoard[0][i] = 0;
                if (chessBoard[2][i] == chessBoard[3][i]) {
                    chessBoard[3][i] += chessBoard[2][i];
                    score += chessBoard[3][i];
                    chessBoard[2][i] = 0;
                }
            }
            else {
                chessBoard[2][i] = chessBoard[1][i];
                chessBoard[1][i] = chessBoard[0][i];
                chessBoard[0][i] = 0;
            }
        }
        else if (chessBoard[1][i] == 0) {
            continue;
        }
        else if (chessBoard[2][i] == chessBoard[1][i]) {//2、3均非0且相等
            chessBoard[2][i] += chessBoard[1][i];//2、3合并,2为0
            score += chessBoard[2][i];
            chessBoard[1][i] = 0;
            if (chessBoard[3][i] == chessBoard[2][i]) {//2、3合并后与4相等
                chessBoard[3][i] += chessBoard[2][i];//1、2、3合并，判断4
                score += chessBoard[3][i];
                chessBoard[2][i] = 0;
                if (chessBoard[3][i] == chessBoard[0][i]) {
                    chessBoard[3][i] += chessBoard[0][i];
                    score += chessBoard[3][i];
                    chessBoard[0][i] = 0;
                }
                else {
                    chessBoard[2][i] += chessBoard[0][i];
                    score += chessBoard[2][i];
                    chessBoard[0][i] = 0;
                }
            }
            else if (chessBoard[2][i] == chessBoard[0][i]) {//3和0相等
                chessBoard[2][i] += chessBoard[0][i];
                score += chessBoard[2][i];
                chessBoard[0][i] = 0;
                if (chessBoard[3][i] == chessBoard[2][i]) {
                    chessBoard[3][i] += chessBoard[2][i];
                    score += chessBoard[3][i];
                    chessBoard[2][i] = 0;
                }
            }
            else {
                chessBoard[1][i] = chessBoard[0][i];
                chessBoard[0][i] = 0;
            }
        }
            //后三个数字均非0，且左右不等时
        else if (chessBoard[0][i] == 0) {
            continue;
        }
        else if (chessBoard[1][i] == chessBoard[0][i]) {
            chessBoard[1][i] += chessBoard[0][i];
            score += chessBoard[1][i];
            chessBoard[0][i] = 0;
            if (chessBoard[2][i] == chessBoard[1][i]) {
                chessBoard[2][i] += chessBoard[1][i];
                score += chessBoard[2][i];
                chessBoard[1][i] = 0;
                if (chessBoard[3][i] == chessBoard[2][i]) {
                    chessBoard[3][i] += chessBoard[2][i];
                    score += chessBoard[3][i];
                    chessBoard[2][i] = 0;
                }
            }
        }
    }
    //判断是否改变
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (copy[i][j] != chessBoard[i][j]) {
                change = true;
            }
        }
    }
    return change;
}

bool chess::gameOver()
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (chessBoard[i][j] == 0) {
                return false;
            }
        }
    }
    int temp[M][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = chessBoard[i][j];
        }
    }
    if (!leftSlide()){
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                chessBoard[i][j] = temp[i][j];
            }
        }
        if (!rightSlide()) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    chessBoard[i][j] = temp[i][j];
                }
            }
            if (!topSlide()) {
                for (int i = 0; i < M; i++) {
                    for (int j = 0; j < M; j++) {
                        chessBoard[i][j] = temp[i][j];
                    }
                }
                if (!downSlide()) {
                    for (int i = 0; i < M; i++) {
                        for (int j = 0; j < M; j++) {
                            chessBoard[i][j] = temp[i][j];
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void chess::show()
{
    for (int i = 0; i < M; i++) {
        qDebug()<< chessBoard[i][0]<< chessBoard[i][1]<< chessBoard[i][2]<< chessBoard[i][3];
    }
}