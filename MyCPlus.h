//
// Created by 余玮 on 2023/3/16.
//

#pragma once
#include "chess.h"
#include <QtWidgets/QWidget>
#include "ui_MyCPlus.h"
#include<QPainter>
#define M 4
class MyCPlus : public QWidget
{
Q_OBJECT

public:
    explicit MyCPlus(QWidget *parent = Q_NULLPTR);
    void save();
    static int getMaxScore();
private slots:
    void exit();
    void playGame();
    void newGame();
    void reGame();
protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
private:
    Ui::MyCPlusClass ui{};
    QPoint p,start;
    chess *MyChess;
    //const int M=4;
};
