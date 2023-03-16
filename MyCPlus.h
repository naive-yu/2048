#ifndef MYCPLUS_H
#define MYCPLUS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyCPlus; }
QT_END_NAMESPACE

class MyCPlus : public QWidget
{
    Q_OBJECT

public:
    MyCPlus(QWidget *parent = nullptr);
    ~MyCPlus();

private:
    Ui::MyCPlus *ui;
};
#endif // MYCPLUS_H
