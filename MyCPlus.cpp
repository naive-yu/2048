//
// Created by 余玮 on 2023/3/16.
//

#pragma execution_character_set("utf-8")
#include "MyCPlus.h"
#include<QPixmap>
#include<qDebug>
#include<QMouseEvent>
#include<QEventLoop>
#include<QMessageBox>
#include<QTimer>
#include<QFile>
#include<cmath>
#include<QDataStream>
MyCPlus::MyCPlus(QWidget *parent)
        : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowIcon(QIcon(":/images/icon1.ico"));
    //去除窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //设置窗口背景色透明
    setAttribute(Qt::WA_TranslucentBackground);
    ui.stackedWidget->setCurrentWidget(ui.pageSet);
    MyChess = nullptr;
}

void MyCPlus::save()
{
    if (MyChess->getscore()==0) {//游戏总分为0，不记录
        return;
    }
    QFile file("score.txt");
    if (file.open(QIODevice::Append)) {
        QTextStream stream(&file);
        stream.setAutoDetectUnicode("utf-8");
        //!!!stream.setCodec("utf-8");
        stream <<" "+QString::number(MyChess->getscore());
        file.close();
    }
    else {
        qDebug() << "WRITE ERROR！";
    }
}

int MyCPlus::getMaxScore()
{
    QFile file("score.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        int max=0;
        int score;
        stream >> max;
        stream >> score;
        while (score) {
            if (max < score) {
                max = score;
            }
            stream >> score;
        }
        file.close();
        return max;
    }
    else {
        qDebug() << "READ ERROR!";
        return 0;
    }
}

void MyCPlus::playGame()
{
    ui.stackedWidget->setCurrentWidget(ui.pageGame);
    /*QFile file("score.txt");
    QDataStream stream;*/

    MyChess = new chess;
    MyChess->randfirst();
    ui.label_20->setText(QString::number(MyChess->getscore()));
    ui.label_21->setText(QString::number(getMaxScore()));
    MyChess->show();
    update();
}

void MyCPlus::newGame()
{
    int res = QMessageBox::question(this, "提示信息", QString("当前得分%1分，确定要结束本次游戏吗？").arg(QString::number(MyChess->getscore())), QMessageBox::Yes, QMessageBox::Cancel);//枚举类型
    if (res == QMessageBox::Yes) {
        save();
        free(MyChess);
        MyChess = new chess;
        MyChess->randfirst();
        ui.label_20->setText(QString::number(MyChess->getscore()));
        ui.label_21->setText(QString::number(getMaxScore()));
        MyChess->show();
    }
}

void MyCPlus::reGame()
{
    int res = QMessageBox::question(this, "提示信息", "确定要结束本次游戏吗？", QMessageBox::Yes, QMessageBox::Cancel);//枚举类型
    if (res == QMessageBox::Yes) {
        save();
        free (MyChess);
        ui.stackedWidget->setCurrentWidget(ui.pageSet);
    }
}

void MyCPlus::paintEvent(QPaintEvent*)
{
    if (ui.stackedWidget->currentWidget() == ui.pageSet) {
        QPainter q(ui.pageSet);
        q.drawPixmap(0, 0, 600,400, QPixmap(":/images/background1.png"));
        q.end();
        qDebug() << "pageSet";
    }
    else if (ui.stackedWidget->currentWidget()==ui.pageGame) {
        //为方便操作，采用数组存储所有Label标签
        QLabel* labels[M][M] = { {ui.label_2,ui.label_3,ui.label_4,ui.label_5 },
                                 {ui.label_7,ui.label_8,ui.label_9,ui.label_6},
                                 {ui.label_10,ui.label_12,ui.label_11,ui.label_13},
                                 {ui.label_16,ui.label_14,ui.label_18,ui.label_15} };
        //ui.label_2->setText(QString::number(MyChess->getchess(0,0)));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                //除0外均要进行的操作
                labels[i][j]->setText(QString::number(MyChess->getchess(i, j)));
                if (MyChess->getchess(i, j) == 0) {
                    labels[i][j]->setText("");
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#ccc0b2"
                                                "}");
                }
                else if (MyChess->getchess(i,j)==2) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#ebb388;color:#776e65;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 4) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#ece0c8;color:#776e65;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 8) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#f2b179;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 16) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#f59563;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 32) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#f57c5f;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 64) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#f65d3b;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 128) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#eecf6b;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 256) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#eccd62;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 512) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#edc64e;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 1024) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#e2ba13;color:#fffffe;"
                                                "}");
                }
                else if (MyChess->getchess(i, j) == 2048) {
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#ecc400;color:#fffffe;"
                                                "}");
                    static int flag = 0;//初次达成弹出提示信息
                    if (flag == 0) {
                        QMessageBox::question(this, "提示信息", "恭喜已达成2048！");
                        flag++;
                    }
                }
                else{
                    labels[i][j]->setStyleSheet("QLabel{"
                                                "background-color:#ecc400;color:#fffffe;"
                                                "}");
                }
            }
        }
    }
    QPainter pa(this);
    pa.drawPixmap(0, 0, width(), height(), QPixmap(":/images/background1.png"));
    pa.end();

}
//QWidget{
//    background:url("../images/back2.jpg")100 % 100 % no - repeat;
//}

void MyCPlus::mousePressEvent(QMouseEvent* e)
{
    //游戏页面手势确定的初始点
    if (e->button() == Qt::LeftButton && ui.stackedWidget->currentWidget() == ui.pageGame) {
        start = e->pos();
    }
        //非游戏页面窗口拖动处理
    else if (e->button() == Qt::LeftButton) {
        //globalPos()为屏幕坐标
        //frameGeometry()为含边框的窗口矩形对象，geometry()为不含边框
        p = e->pos() - frameGeometry().topLeft();//toLeft()为矩形对象距屏幕左上角的距离
    }

}

void MyCPlus::mouseMoveEvent(QMouseEvent* e)
{
    if (e->buttons() != 0 && ui.stackedWidget->currentWidget() != ui.pageGame) {
        //if (e->buttons() && Qt::LeftButton&&ui.stackedWidget->currentWidget() != ui.pageGame) {
        move(e->pos() - p);
    }
}
void MyCPlus::mouseReleaseEvent(QMouseEvent* e)
{
    if (ui.stackedWidget->currentWidget() == ui.pageGame) {
        //通过x,y增量确定手势方向
        if (MyChess->gameOver()) {
            QMessageBox::question(this, "提示信息", "GameOver!");
            return;
        }
        int movex = e->pos().x() - start.x();
        int movey = e->pos().y()-start.y();
        if (abs(movex) >= abs(movey)) {//相等时默认为x方向
            if (movex > 0) {
                if (MyChess->rightSlide()) {
                    MyChess->randpro();
                    ui.label_20->setText(QString::number(MyChess->getscore()));
                    if (MyChess->getscore() > getMaxScore()) {
                        ui.label_21->setText(QString::number(MyChess->getscore()));
                    }
                    update();
                }
            }
            else if (movex<0) {
                if (MyChess->leftSlide()) {
                    MyChess->randpro();
                    ui.label_20->setText(QString::number(MyChess->getscore()));
                    if (MyChess->getscore() > getMaxScore()) {
                        ui.label_21->setText(QString::number(MyChess->getscore()));
                    }
                    update();
                }
            }
            else {//movex=0说明两者均为0，无操作
                return;
            }
        }
        else {
            if (movey > 0) {
                if (MyChess->downSlide()) {
                    MyChess->randpro();
                    ui.label_20->setText(QString::number(MyChess->getscore()));
                    if (MyChess->getscore() > getMaxScore()) {
                        ui.label_21->setText(QString::number(MyChess->getscore()));
                    }
                    update();
                }
            }
            else if (movey < 0) {
                if (MyChess->topSlide()) {
                    MyChess->randpro();
                    ui.label_20->setText(QString::number(MyChess->getscore()));
                    if (MyChess->getscore() > getMaxScore()) {
                        ui.label_21->setText(QString::number(MyChess->getscore()));
                    }
                    update();
                }
            }
        }
    }
}
void MyCPlus::exit() {
    int ret = QMessageBox::question(this, "提示信息", "确定要退出吗？", QMessageBox::Yes, QMessageBox::Cancel);//枚举类型
    if (ret==QMessageBox::Yes) {
        close();
    }
    qDebug() << "exit";
}


