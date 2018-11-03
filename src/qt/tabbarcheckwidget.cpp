#include "tabbarcheckwidget.h"
#include "ui_tabbarcheckwidget.h"

#include <QMessageBox>
#include <QDebug>

TabBarCheckWidget::TabBarCheckWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabBarCheckWidget)
{
    ui->setupUi(this);

    QString unfocusClass="";
    ui->pushButton_0->setIcon( QIcon( QString(":/icons/overview") ) );
    ui->pushButton_1->setIcon( QIcon( QString(":/icons/send%1").arg(unfocusClass) ) );
    ui->pushButton_2->setIcon( QIcon( QString(":/icons/receive%1").arg(unfocusClass) ) );
    ui->pushButton_3->setIcon( QIcon( QString(":/icons/history%1").arg(unfocusClass) ) );


    connect(ui->pushButton_0,SIGNAL(clicked())  ,SLOT( onClickedMsg() ));
    connect(ui->pushButton_1,SIGNAL(clicked())  ,SLOT( onClickedMsg() ));
    connect(ui->pushButton_2,SIGNAL(clicked())  ,SLOT( onClickedMsg() ));
    connect(ui->pushButton_3,SIGNAL(clicked())  ,SLOT( onClickedMsg() ));
}

TabBarCheckWidget::~TabBarCheckWidget()
{
    delete ui;
}


void TabBarCheckWidget::onClickedMsg()
{
//    qDebug()<<sender()->objectName()<< ((QPushButton*)sender())->isChecked();
    if( !((QPushButton*)sender())->isChecked() ){
        //其他的都不选择
        ((QPushButton*)sender())->setChecked(true);//设置选中
        return;
    }
    QString objName= sender()->objectName();
    if(objName.compare("pushButton_0" )==0 ){
        setChecked(0);
    }
    if(objName.compare("pushButton_1" )==0 ){
        setChecked(1);
    }
    if(objName.compare("pushButton_2" )==0 ){
        setChecked(2);
    }
    if(objName.compare("pushButton_3" )==0 ){
        setChecked(3);
    }
}

void TabBarCheckWidget::setCurrentIndex(int index){
    QString focusClass="_focus";
    QString unfocusClass="";
    switch (index) {
    case 0:
        ui->pushButton_0->setChecked(true);
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(false);

        ui->pushButton_0->setIcon( QIcon( QString(":/icons/overview") ) );
        ui->pushButton_1->setIcon( QIcon( QString(":/icons/send%1").arg(unfocusClass) ) );
        ui->pushButton_2->setIcon( QIcon( QString(":/icons/receive%1").arg(unfocusClass) ) );
        ui->pushButton_3->setIcon( QIcon( QString(":/icons/history%1").arg(unfocusClass) ) );
        break;
    case 1:
        ui->pushButton_0->setChecked(false);
        ui->pushButton_1->setChecked(true);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(false);

        ui->pushButton_0->setIcon( QIcon( QString(":/icons/overview") ) );
        ui->pushButton_1->setIcon( QIcon( QString(":/icons/send%1").arg(focusClass) ) );
        ui->pushButton_2->setIcon( QIcon( QString(":/icons/receive%1").arg(unfocusClass) ) );
        ui->pushButton_3->setIcon( QIcon( QString(":/icons/history%1").arg(unfocusClass) ) );
        break;
    case 2:
        ui->pushButton_0->setChecked(false);
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(true);
        ui->pushButton_3->setChecked(false);

        ui->pushButton_0->setIcon( QIcon( QString(":/icons/overview") ) );
        ui->pushButton_1->setIcon( QIcon( QString(":/icons/send%1").arg(unfocusClass) ) );
        ui->pushButton_2->setIcon( QIcon( QString(":/icons/receive%1").arg(focusClass) ) );
        ui->pushButton_3->setIcon( QIcon( QString(":/icons/history%1").arg(unfocusClass) ) );
        break;

    case 3:
        ui->pushButton_0->setChecked(false);
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(true);

        ui->pushButton_0->setIcon( QIcon( QString(":/icons/overview") ) );
        ui->pushButton_1->setIcon( QIcon( QString(":/icons/send%1").arg(unfocusClass) ) );
        ui->pushButton_2->setIcon( QIcon( QString(":/icons/receive%1").arg(unfocusClass) ) );
        ui->pushButton_3->setIcon( QIcon( QString(":/icons/history%1").arg(focusClass) ) );
        break;
    default:
        break;
    }

}

void TabBarCheckWidget::setChecked(int index){
    emit this->signalCheckedIndex(index);
    this->setCurrentIndex(index);
}


