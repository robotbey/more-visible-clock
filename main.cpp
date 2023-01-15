#include "mainwidget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("MoreVisibleClock");
    a.setApplicationName("MoreVisibleClock");
    a.setApplicationVersion("0.1.0");
    a.setOrganizationName("Tachyon Software");
    CMainWidget w;
    w.show();
    auto appIcon = QIcon(":/icons/main");
    a.setWindowIcon(appIcon);
    return a.exec();
}
