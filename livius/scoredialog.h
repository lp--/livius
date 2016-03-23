#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include <QDialog>

namespace Ui {
class ScoreDialog;
}

class ScoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreDialog(QWidget *parent = 0);
    ~ScoreDialog();
    void setText( const QString &txt);

private slots:
    void on_Update_clicked();

private:
    Ui::ScoreDialog *ui;
};

#endif // SCOREDIALOG_H
