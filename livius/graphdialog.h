#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class GraphDialog;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = 0);
    ~GraphDialog();
    void updateAll(const QVector <double> &x1, const QVector <double> &x2, const QVector <double> &x3, const QVector <double> &x4, int mnum0);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphDialog *ui;
};

#endif // GRAPHDIALOG_H
