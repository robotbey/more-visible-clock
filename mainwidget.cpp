#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QTime>
#include <QDateTime>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include "settingsdialog.h"
#include "settings.h"

CMainWidget::CMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CMainWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(0,0);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &CMainWidget::OnTimerTimeout);
    timer->start();
}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::OnTimerTimeout()
{
    auto dt = QDateTime::currentDateTime();
    auto currentHour = dt.time().hour();
    auto nextHour = (currentHour+1)%24;

    auto currentMin = dt.time().minute();
    auto nextMin = (currentMin+1)%60;

    auto currentSec = dt.time().second();
    auto nextSec = (currentSec+1)%60;
    auto dateText = dt.toString(QString("dd MMMM yyyy\nddd"));

    auto formatInt = [](auto num){
        return QString("%1").arg(num,2,10,QChar('0'));
    };

    ui->labelCurrentHour->setText(formatInt(currentHour));
    ui->labelNextHour->setText(formatInt(nextHour));
    ui->progressBarHour->setValue(currentHour);

    ui->labelCurrentMinute->setText(formatInt(currentMin));
    ui->labelNextMinute->setText(formatInt(nextMin));
    ui->progressBarMinute->setValue(currentMin);

    ui->labelCurrentSecond->setText(formatInt(currentSec));
    ui->labelNextSecond->setText(formatInt(nextSec));
    ui->progressBarSecond->setValue(currentSec);

    ui->labelDate->setText(dateText);
}

void CMainWidget::setAlwaysOnTop(bool yea)
{
    this->setWindowFlag(Qt::WindowStaysOnTopHint, yea);
    this->show();
}


void CMainWidget::on_pushButtonSettings_clicked()
{
    CSettings settings;
    settings.Opacity = windowOpacity();
    CSettingsDialog dlg(this, settings);
    auto curOpacity{this->windowOpacity()};
    connect(&dlg, &CSettingsDialog::OpacityChanged,[this](int value){
        setWindowOpacity(qreal(value) * 0.01f);
    });
    auto result = dlg.exec();
    if(result == QDialog::Rejected){
        setWindowOpacity(curOpacity);
    }
}

void CMainWidget::mousePressEvent(QMouseEvent *e)
{
    clickPos =  e->position();
    isDragging = true;
}

void CMainWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(isDragging){
        auto p = e->globalPosition() - clickPos;
        move(p.x(), p.y());
    }
}

void CMainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    isDragging = false;
}


void CMainWidget::on_pushButtonAbout_clicked()
{
    QMessageBox::about(this,"About",
    R"(More Visible Clock v1.0

        RobotBey
    [github.com/robotbey](https://github.com/robotbey)");
}

