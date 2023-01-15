#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWidget; }
QT_END_NAMESPACE

class QTimer;
class QMouseEvent;

class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    CMainWidget(QWidget *parent = nullptr);
    ~CMainWidget();

private slots:
    void OnTimerTimeout();
    void setAlwaysOnTop(bool);



    void on_pushButtonSettings_clicked();

    void mousePressEvent(QMouseEvent *e)override;
    void mouseMoveEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;

    void on_pushButtonAbout_clicked();

private:
    Ui::CMainWidget *ui;
    QTimer *timer;
    bool isDragging = false;
    QPointF clickPos;
};
#endif // CMAINWIDGET_H

