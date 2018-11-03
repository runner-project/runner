#ifndef TABBARCHECKWIDGET_H
#define TABBARCHECKWIDGET_H

#include <QWidget>

namespace Ui {
class TabBarCheckWidget;
}

class TabBarCheckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabBarCheckWidget(QWidget *parent = 0);
    ~TabBarCheckWidget();

    void setCurrentIndex(int index);
    void setChecked(int index = 0);
    
    Ui::TabBarCheckWidget *ui;
public slots:
    void onClickedMsg();
signals:
    void signalCheckedIndex(int index);
private:
};

#endif // TABBARCHECKWIDGET_H
