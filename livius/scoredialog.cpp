#include "scoredialog.h"
#include "ui_scoredialog.h"
#include "mainwindow.h"


extern MainWindow* ww;

ScoreDialog::ScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreDialog)
{
    ui->setupUi(this);
}

ScoreDialog::~ScoreDialog()
{
    delete ui;
}

void ScoreDialog::setText( const QString &txt )
{
    ui->textBrowser->setText(txt);
}

void ScoreDialog::on_Update_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->moveCursor(QTextCursor::Start);


    LiveFrame *lf =  ww->getLiveFrame();
    Q_ASSERT( lf );
    if ( !lf )
        return;		// better safe than sorry
    ui->textBrowser->setText(lf->getScore() );

}
