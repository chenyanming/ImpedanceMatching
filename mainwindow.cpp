#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QImage>
#include <QLabel>


#include <QValidator>
#include <QString>
#include <math.h>

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create Gridlayout for each tab
    //QGridLayout *layout_0 = new QGridLayout;
    //ui->tab_0->setLayout(layout_0);
    //QGridLayout *layout_1 = new QGridLayout;
    //ui->tab_1->setLayout(layout_1);
    //QGridLayout *layout_2 = new QGridLayout;
    //ui->tab_2->setLayout(layout_2);
    //QGridLayout *layout_3 = new QGridLayout;
    //ui->tab_3->setLayout(layout_3);
    //QGridLayout *layout_4 = new QGridLayout;
    //ui->tab_4->setLayout(layout_4);

    //Create the seriesl image widget
    QImage *seriesl = new QImage;
    QImage *seriesl_scaled = new QImage;
    seriesl->load(":/MyFiles/seriesl.png");
    *seriesl_scaled=seriesl->scaled(400,400,Qt::KeepAspectRatio);
    QLabel *label_0 = new QLabel;
    label_0->setPixmap(QPixmap::fromImage(*seriesl_scaled));

    //Create the shuntl image widget
    QImage *shuntl = new QImage;
    QImage *shuntl_scaled = new QImage;
    shuntl->load(":/MyFiles/shuntl.png");
    *shuntl_scaled=shuntl->scaled(400,400,Qt::KeepAspectRatio);
    QLabel *label_1 = new QLabel;
    label_1->setPixmap(QPixmap::fromImage(*shuntl_scaled));

    //Create the picircuit image widget
    QImage *picircuit = new QImage;
    QImage *picircuit_scaled = new QImage;
    picircuit->load(":/MyFiles/picircuit.png");
    *picircuit_scaled=picircuit->scaled(400,400,Qt::KeepAspectRatio);
    QLabel *label_2 = new QLabel;
    label_2->setPixmap(QPixmap::fromImage(*picircuit_scaled));

    //Create the tcircuit image widget
    QImage *tcircuit = new QImage;
    QImage *tcircuit_scaled = new QImage;
    tcircuit->load(":/MyFiles/tcircuit.png");
    *tcircuit_scaled=tcircuit->scaled(400,400,Qt::KeepAspectRatio);
    QLabel *label_3 = new QLabel;
    label_3->setPixmap(QPixmap::fromImage(*tcircuit_scaled));

    //Create the tap image widget
    QImage *tappedcapacitor = new QImage;
    QImage *tappedcapacitor_scaled = new QImage;
    tappedcapacitor->load(":/MyFiles/tappedcapacitor.png");
    *tappedcapacitor_scaled=tappedcapacitor->scaled(400,400,Qt::KeepAspectRatio);
    QLabel *label_4 = new QLabel;
    label_4->setPixmap(QPixmap::fromImage(*tappedcapacitor_scaled));

    ui->verticalLayout_3->addWidget(label_0);

    ui->verticalLayout_4->addWidget(label_1);

    ui->verticalLayout_5->addWidget(label_2);

    ui->verticalLayout_6->addWidget(label_3);

    ui->verticalLayout_9->addWidget(label_4);

    /*
     * Series L circuit
     */
    //Set The Value Range for Series L circuit.
    ui->lineEdit->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_2->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0, 100000,this));
    //Set some output lineedits are read only.
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_14->setReadOnly(true);
    ui->lineEdit_13->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);

    /*
     * Shunt L circuit
     */
    //Set The Value Range for Shunt L circuit.
    ui->lineEdit_34->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_31->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_38->setValidator(new QIntValidator(0, 100000,this));
    //Set some output lineedits are read only.
    ui->lineEdit_32->setReadOnly(true);
    ui->lineEdit_33->setReadOnly(true);
    ui->lineEdit_36->setReadOnly(true);
    ui->lineEdit_37->setReadOnly(true);
    ui->lineEdit_39->setReadOnly(true);

    /*
     * Pi circuit
     */
    //Set The Value Range for Pi circuit.
    ui->lineEdit_40->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_41->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_42->setValidator(new QIntValidator(0, 100000,this));
    ui->lineEdit_43->setValidator(new QIntValidator(0, 10000000,this));
    //Set some output lineedits are read only.
    ui->lineEdit_56->setReadOnly(true);
    ui->lineEdit_58->setReadOnly(true);
    ui->lineEdit_60->setReadOnly(true);
    ui->lineEdit_57->setReadOnly(true);
    ui->lineEdit_59->setReadOnly(true);
    ui->lineEdit_61->setReadOnly(true);

    /*
     * T circuit
     */
    //Set The Value Range for T circuit.
    ui->lineEdit_44->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_45->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_46->setValidator(new QIntValidator(0, 100000,this));
    ui->lineEdit_47->setValidator(new QIntValidator(0, 10000000,this));
    //Set some output lineedits are read only.
    ui->lineEdit_62->setReadOnly(true);
    ui->lineEdit_63->setReadOnly(true);
    ui->lineEdit_64->setReadOnly(true);
    ui->lineEdit_65->setReadOnly(true);
    ui->lineEdit_66->setReadOnly(true);
    ui->lineEdit_67->setReadOnly(true);

    /*
     * Tapped Capacitor circuit
     */
    //Set The Value Range for Tapped Capacitor circuit.
    ui->lineEdit_48->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_49->setValidator(new QIntValidator(0, 10000000,this));
    ui->lineEdit_50->setValidator(new QIntValidator(0, 100000,this));
    ui->lineEdit_51->setValidator(new QIntValidator(0, 100000,this));
    //Set some output lineedits are read only.
    ui->lineEdit_68->setReadOnly(true);
    ui->lineEdit_69->setReadOnly(true);
    ui->lineEdit_70->setReadOnly(true);
    ui->lineEdit_72->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}




/*
 * Series L circuit
 */
void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    QString TempString;
    unsigned int rs, r, f;
    double q, x1, x2, l1, l2, c1, c2;
    //Convert QString to Int.
    //Get the value of R', R and F
    r = ui->lineEdit->text().toInt();
    rs = ui->lineEdit_2->text().toInt();
    f = ui->lineEdit_3->text().toInt();
    //MHz to Hz
    f = f*1000000;

    //In series L circuit, R' > R."
    if (r > rs)
    {
        msgBox.setText("In series L circuit, R' > R.");
        msgBox.exec();
    }
    else if (r < rs)
    {
        //Caculate the Q factor, X1, X2, C1, C2, L1, L2 and display them.
        q = sqrt(rs/r-1);
        x2 = rs/q;
        x1 = q*r;

        c1=1/(2*3.14*f*x1);
        c2=1/(2*3.14*f*x2);

        l1= x1/(2*3.14*f);
        l2= x2/(2*3.14*f);

        ui->lineEdit_4->setText(TempString.setNum(q));
        ui->lineEdit_6->setText(TempString.setNum(c1));
        ui->lineEdit_14->setText(TempString.setNum(c2));
        ui->lineEdit_13->setText(TempString.setNum(l1));
        ui->lineEdit_5->setText(TempString.setNum(l2));
    }
    else
    {
        msgBox.setText("R'= R");
        msgBox.exec();
    }

}

/*
 * Shunt L circuit
 */
void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    QString TempString;
    unsigned int rs, r, f;
    double q, x1, x2, l1, l2, c1, c2;
    //Convert QString to Int.
    //Get the value of R', R and F
    r = ui->lineEdit_34->text().toInt();
    rs = ui->lineEdit_31->text().toInt();
    f = ui->lineEdit_38->text().toInt();
    //MHz to Hz
    f = f*1000000;

    //In shuntl L circuit, R' < R."
    if (r < rs)
    {
        msgBox.setText("In series L circuit, R' < R.");
        msgBox.exec();
    }
    else if(r > rs)
    {
        //Caculate the Q factor, X1, X2, C1, C2, L1, L2 and display them.
        q=sqrt(r/rs-1);
        x2 = rs*q;
        x1 = r/q;

        c1=1/(2*3.14*f*x1);
        c2=1/(2*3.14*f*x2);

        l1= x1/(2*3.14*f);
        l2= x2/(2*3.14*f);

        ui->lineEdit_39->setText(TempString.setNum(q));
        ui->lineEdit_32->setText(TempString.setNum(c1));
        ui->lineEdit_37->setText(TempString.setNum(c2));
        ui->lineEdit_33->setText(TempString.setNum(l1));
        ui->lineEdit_36->setText(TempString.setNum(l2));
    }
    else
    {
          msgBox.setText("R'= R");
          msgBox.exec();
    }

}


/*
 * Pi circuit
 */
void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox msgBox;
    QString TempString;
    unsigned int rs, r, f, q;
    double q1, q2, r1, b1, b3;
    double x2, pc1, pl2, pc3, bl1, bc2, bl3;

    //Convert QString to Int.
    //Get the value of R', R, F and q.
    r = ui->lineEdit_40->text().toInt();
    rs = ui->lineEdit_41->text().toInt();
    f = ui->lineEdit_42->text().toInt();
    q = ui->lineEdit_43->text().toInt();
    //MHz to Hz
    f = f*1000000;

    if (rs < r)
    {
        q1=q;
        r1=r/(1+q1*q1);
        q2=sqrt(rs/r1-1);
        b1=q1/r;
        x2=r1*(q1+q2);
        b3=q2/rs;

        pc1=b1/(2*3.14*f);
        pl2=x2/(2*3.14*f);
        pc3=b3/(2*3.14*f);
        bl1=1/(2*3.14*f*b1);
        bc2=1/(2*3.14*f*x2);
        bl3=1/(2*3.14*f*b3);

        if (rs*(1+q1*q1) < r)
          msgBox.setText("Please check your parameters and reinput it or read the HELP");

        ui->lineEdit_56->setText(TempString.setNum(pc1));
        ui->lineEdit_58->setText(TempString.setNum(pl2));
        ui->lineEdit_60->setText(TempString.setNum(pc3));
        ui->lineEdit_57->setText(TempString.setNum(bl1));
        ui->lineEdit_59->setText(TempString.setNum(bc2));
        ui->lineEdit_61->setText(TempString.setNum(bl3));
    }
    else if (rs > r)
    {
        q2=q;
        r1=rs/(1+q2*q2);
        q1=sqrt(r/r1-1);

        b1=q1/r;
        x2=r1*(q1+q2);
        b3=q2/rs;

        bl1=1/(2*3.14*f*b1);
        bc2=1/(2*3.14*f*x2);
        bl3=1/(2*3.14*f*b3);
        pc1=b1/(2*3.14*f);
        pl2=x2/(2*3.14*f);
        pc3=b3/(2*3.14*f);

        if (r*(1+q2*q2) < rs)
        {
          msgBox.setText("Please check your parameters and reinput it or read the HELP");
          msgBox.exec();

        }

        ui->lineEdit_56->setText(TempString.setNum(pc1));
        ui->lineEdit_58->setText(TempString.setNum(pl2));
        ui->lineEdit_60->setText(TempString.setNum(pc3));
        ui->lineEdit_57->setText(TempString.setNum(bl1));
        ui->lineEdit_59->setText(TempString.setNum(bc2));
        ui->lineEdit_61->setText(TempString.setNum(bl3));
    }
    else
    {
          msgBox.setText("R'= R");
          msgBox.exec();

    }


}



/*
 * T circuit
 */
void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox;
    QString TempString;
    unsigned int rs, r, f, q;
    double q1, q2, r1, b2;
    double x1, x3, pl1, pc2, pl3, bc1, bl2, bc3;

    //Convert QString to Int.
    //Get the value of R', R, F and q.
    r = ui->lineEdit_44->text().toInt();
    rs = ui->lineEdit_45->text().toInt();
    f = ui->lineEdit_46->text().toInt();
    q = ui->lineEdit_47->text().toInt();
    //MHz to Hz
    f = f*1000000;

    if (rs>r)
    {

       q1=q;
       r1=r*(1+q1*q1);
       q2=sqrt(r1/rs-1);
       x1=q1*r;
       b2=(q1+q2)/r1;
       x3=q2*rs;

       if (r*(1+q1*q1)<rs)
         msgBox.setText("Please check your parameters and reinput it or read the HELP.");

       bc1=1/(2*3.14*f*x1);
       bl2=1/(2*3.14*f*b2);
       bc3=1/(2*3.14*f*x3);
       pl1=x1/(2*3.14*f);
       pc2=b2/(2*3.14*f);
       pl3=x3/(2*3.14*f);

       ui->lineEdit_62->setText(TempString.setNum(bc1));
       ui->lineEdit_64->setText(TempString.setNum(bl2));
       ui->lineEdit_66->setText(TempString.setNum(bc3));
       ui->lineEdit_63->setText(TempString.setNum(pl1));
       ui->lineEdit_65->setText(TempString.setNum(pc2));
       ui->lineEdit_67->setText(TempString.setNum(pl3));
    }

    else if(rs<r)
    {
       q2=q;
       r1=rs*(1+q2*q2);
       q1=sqrt(r1/r-1);

       x1=q1*r;
       b2=(q1+q2)/r1;
       x3=q2*rs;

      if (rs*(1+q1*q1)<r)
         msgBox.setText("Please check your parameters and reinput it or read the HELP.");

       bc1=1/(2*3.14*f*x1);
       bl2=1/(2*3.14*f*b2);
       bc3=1/(2*3.14*f*x3);
       pl1=x1/(2*3.14*f);
       pc2=b2/(2*3.14*f);
       pl3=x3/(2*3.14*f);

       ui->lineEdit_62->setText(TempString.setNum(bc1));
       ui->lineEdit_64->setText(TempString.setNum(bl2));
       ui->lineEdit_66->setText(TempString.setNum(bc3));
       ui->lineEdit_63->setText(TempString.setNum(pl1));
       ui->lineEdit_65->setText(TempString.setNum(pc2));
       ui->lineEdit_67->setText(TempString.setNum(pl3));
    }
    else
    {
          msgBox.setText("R'= R");
          msgBox.exec();
    }

}

/*
 * Tapped Capacitor circuit
 */
void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox msgBox;
    QString TempString;
    unsigned int rs, r, f, q;
    double q1, bw, w0, dw, l, ceq, c, c1, c2, qp;

    //Convert QString to Int.
    //Get the value of R', R, F and q.
    r = ui->lineEdit_48->text().toInt();
    rs = ui->lineEdit_49->text().toInt();
    f = ui->lineEdit_50->text().toInt();
    bw = ui->lineEdit_51->text().toInt();
    //MHz to Hz
    f = f*1000000;
    bw = bw*1000000;

    w0 = 2*3.14*f;
    dw = 2*3.14*bw;

    q1=w0/dw;
    c=q1/(w0*rs);
    l=1/(w0*w0*c);
    if ((r/rs)*(1+q1*q1)-1<0)
        msgBox.setText("Please check your parameters and reinput it or read the HELP.");

    qp=sqrt((r/rs)*(1+q1*q1)-1);
    c2=qp/(w0*r);
    ceq=c2*(1+qp*qp)/(qp*qp);
    c1=(ceq*c2)/(ceq-c2);
    q=qp;

    ui->lineEdit_69->setText(TempString.setNum(q));
    ui->lineEdit_68->setText(TempString.setNum(c1));
    ui->lineEdit_70->setText(TempString.setNum(c2));
    ui->lineEdit_72->setText(TempString.setNum(l));

}
