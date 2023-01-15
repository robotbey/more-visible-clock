#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class CSettingsDialog;
}

struct CSettings;

class CSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSettingsDialog(QWidget *parent, CSettings & initialSettings);
    ~CSettingsDialog();

signals:
    void OpacityChanged(int value);

private:
    Ui::CSettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
