#ifndef WRITETOFILES_H
#define WRITETOFILES_H

#include <QThread>
#include <QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"

class  WriteToFiles;
class UDP_Recv;

class WriteToFiles : public QThread
{
public:
    WriteToFiles(UDP_Recv* udp_Recv);

    UDP_Recv* udp_recv;
    bool isTimeUpdate;
    QDateTime dateTime; //当前系统时间
    string saveFolder;//存储目录（文件夹）
    QString saveFilename1; //CH1存储文件名
    QString saveFilename2;
    QString saveFilename3;
    QString saveFilename4;
    QString saveFilenameAll;
    QString saveFileDemo;
    QString file1;
    QString file2;
    QString file3;
    QString file4;
    QString fileAll;
    ofstream outfile1;//CH1
    ofstream outfile2;
    ofstream outfile3;
    ofstream outfile4;
    ofstream outfileAll;
    ofstream outfileDemo;
    bool saveFlag = false;
    bool demoFlag = false;
    int PeakNum=31;
    qint64 LenoDemo = 4096*1000;
    shared_ptr<CirQueue<unsigned char>> CHdata;
    shared_ptr<CirQueue<float>> Phdata;

protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();

signals:

public slots:
    void recvPhSlot(float Ph[]);

};

#endif // WRITETOFILES_H
