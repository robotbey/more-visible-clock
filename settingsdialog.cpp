#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "settings.h"


CSettingsDialog::CSettingsDialog(QWidget *parent, CSettings & initialSettings) :
    QDialog(parent),
    ui(new Ui::CSettingsDialog)
{
    ui->setupUi(this);
    ui->horizontalSliderOpacity->setValue(initialSettings.Opacity * 100);
    connect(ui->horizontalSliderOpacity, &QSlider::sliderMoved, this, &CSettingsDialog::OpacityChanged);
}

CSettingsDialog::~CSettingsDialog()
{
    delete ui;
}
