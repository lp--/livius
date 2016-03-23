#include "graphdialog.h"
#include "ui_graphdialog.h"
#include "mainwindow.h"

extern MainWindow* ww;

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::updateAll(const QVector<double>&  sc, const QVector<double>& tm, const QVector<double>&  dp, const QVector<double>& np , int mnum0)
{

    QVector<double>  scb( sc.size()/2 ) , scw( sc.size() - scb.size()), xw(scw.size()), xb(scb.size()),
                     tmb( tm.size()/2),   tmw( tm.size() - tmb.size()),
                     dpb( dp.size()/2),   dpw( dp.size() - dpb.size()),
                     npb( np.size()/2),   npw( np.size() - npb.size());

    double minX = 100, maxX=1, maxSC=1, minSC = -1, maxTM=1, maxNP=1, maxDP = 1;


    for(int i=0; i<sc.size(); i=i+2)
    {
      xw[i/2]=i/2+mnum0+0.9, scw[i/2]=sc[i],tmw[i/2]=tm[i], dpw[i/2]=dp[i], npw[i/2]=round(np[i]/1e4)/1e2;
      maxX=fmax(maxX, xw[i/2]);
      minX = fmin(minX, xw[i/2]);
      maxSC=fmax(maxSC, scw[i/2]);
      minSC=fmin(minSC, scw[i/2]);
      maxTM = fmax(maxTM, tmw[i/2]);
      maxDP = fmax(maxDP, dpw[i/2]);
      maxNP = fmax(maxNP, npw[i/2]);

      if(i+1<sc.size())
      {
        xb[i/2]=i/2+mnum0+1.1,scb[i/2]=-sc[i+1], tmb[i/2]=tm[i+1], dpb[i/2]=dp[i+1], npb[i/2]=round(np[i+1]/1e4)/1e2;
        maxX=fmax(maxX, xb[i/2]);
        minX = fmin(minX, xb[i/2]);
        maxSC=fmax(maxSC, scb[i/2]);
        minSC=fmin(minSC, scb[i/2]);
        maxTM = fmax(maxTM, tmb[i/2]);
        maxDP = fmax(maxDP, dpb[i/2]);
        maxNP = fmax(maxNP, npb[i/2]);
      }
    }

    maxSC = round( maxSC*10/9);
    minSC = round( minSC*10/9);
    maxTM = round( maxTM*10/9);
    maxDP = round( maxDP*10/9);
    maxNP = round( maxNP*10/9);

    maxX = round(maxX+2);
    minX = round(fmax(0,minX-5));

    QCustomPlot* sPlot = ui->scorePlot;
    QCPGraph* graph0 = sPlot->addGraph();

    graph0->setData( xw,  scw);
    graph0->setScatterStyle(QCPScatterStyle::ssCircle);
    graph0->setPen(QPen(Qt::white));


    QCPGraph* graph1 = sPlot->addGraph();

    graph1->setData( xb,  scb);
    graph1->setScatterStyle(QCPScatterStyle::ssCircle);
    graph1->setPen(QPen(Qt::black));

    sPlot->setBackground(Qt::lightGray);
    sPlot->xAxis->setRange(minX,maxX);
    sPlot->yAxis->setRange(minSC,maxSC);
    sPlot->xAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    sPlot->yAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    sPlot->yAxis->setLabel("score (cp)");
    sPlot->xAxis->setSubTickLength(0);
    sPlot->yAxis->setSubTickLength(0);
    sPlot->xAxis->setTickLength(0);
    sPlot->yAxis->setTickLength(0);;
    sPlot->replot();

    QCustomPlot* tPlot = ui->timePlot;
    QCPGraph* graph2 = tPlot->addGraph();

    graph2->setData( xw,  tmw);
    graph2->setScatterStyle(QCPScatterStyle::ssCircle);
    graph2->setPen(QPen(Qt::white));


    QCPGraph* graph3 = tPlot->addGraph();

    graph3->setData( xb,  tmb);
    graph3->setScatterStyle(QCPScatterStyle::ssCircle);
    graph3->setPen(QPen(Qt::black));

    tPlot->setBackground(Qt::lightGray);
    tPlot->xAxis->setRange(minX,maxX);
    tPlot->yAxis->setRange(0,maxTM);
    tPlot->xAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    tPlot->yAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    tPlot->yAxis->setLabel("time used per move (secs)");
    tPlot->xAxis->setSubTickLength(0);
    tPlot->yAxis->setSubTickLength(0);
    tPlot->xAxis->setTickLength(0);
    tPlot->yAxis->setTickLength(0);
    tPlot->replot();


    QCustomPlot* dPlot = ui->depthPlot;
    QCPGraph* graph4 = dPlot->addGraph();

    graph4->setData( xw,  dpw);
    graph4->setScatterStyle(QCPScatterStyle::ssCircle);
    graph4->setPen(QPen(Qt::white));


    QCPGraph* graph5 = dPlot->addGraph();

    graph5->setData( xb,  dpb);
    graph5->setScatterStyle(QCPScatterStyle::ssCircle);
    graph5->setPen(QPen(Qt::black));

    dPlot->setBackground(Qt::lightGray);
    dPlot->xAxis->setRange(minX,maxX);
    dPlot->yAxis->setRange(0,maxDP);
    dPlot->xAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    dPlot->yAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    dPlot->yAxis->setLabel("depth");
    dPlot->xAxis->setSubTickLength(0);
    dPlot->yAxis->setSubTickLength(0);
    dPlot->xAxis->setTickLength(0);
    dPlot->yAxis->setTickLength(0);
    dPlot->replot();

    QCustomPlot* nPlot = ui->npsPlot;
    QCPGraph* graph6 = nPlot->addGraph();

    graph6->setData( xw,  npw);
    graph6->setScatterStyle(QCPScatterStyle::ssCircle);
    graph6->setPen(QPen(Qt::white));


    QCPGraph* graph7 = nPlot->addGraph();

    graph7->setData( xb,  npb);
    graph7->setScatterStyle(QCPScatterStyle::ssCircle);
    graph7->setPen(QPen(Qt::black));

    nPlot->setBackground(Qt::lightGray);
    nPlot->xAxis->setRange(minX,maxX);
    nPlot->yAxis->setRange(0,maxNP);
    nPlot->xAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    nPlot->yAxis->grid()->setPen(QPen(Qt::black, 1, Qt::DotLine));
    nPlot->yAxis->setLabel("nodes per second in millions");
    nPlot->xAxis->setSubTickLength(0);
    nPlot->yAxis->setSubTickLength(0);
    nPlot->xAxis->setTickLength(0);
    nPlot->yAxis->setTickLength(0);
    nPlot->replot();


}

void GraphDialog::on_pushButton_clicked()
{
    LiveFrame *lf = ww->getLiveFrame();
    Q_ASSERT( lf );
    if ( !lf )
        return;		// better safe than sorry
    ui->scorePlot->clearGraphs(), ui->timePlot->clearGraphs(), ui->depthPlot->clearGraphs(), ui->npsPlot->clearGraphs();
    this->updateAll(lf->getVScore(), lf->getVTime(), lf->getVDepth(), lf->getVNPS(), lf->getNum0());
}
