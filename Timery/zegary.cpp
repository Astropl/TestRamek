#include "zegary.h"
#include <iostream>
#include "time.h"
#include <ctime>
#include <stdio.h>
//#include <string>
//#include "pierwsza.h"
//#include "ui_pierwsza.h"
#include "QApplication"

using namespace std;
//time_t czas;
//tm timeinfo;
//Pierwsza *pier ;
Zegary::Zegary(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
}

int Zegary::myfunctiontimer()
{
//    cout<<"Jestem w myfunction"<<endl;
//    time( &czas );
//    timeinfo = *localtime( &czas );

//    int godzina = timeinfo.tm_hour;
//    int minuta = timeinfo.tm_min;
//    int sekunda = timeinfo.tm_sec;
//    int dzien = timeinfo.tm_mday;
//    int miesiac = timeinfo.tm_mon;
//    int rok = timeinfo.tm_year;

//    miesiac = miesiac +1;
//    rok=rok+1900;
//    this->Pierwsza::labelZegara =new QLabel("oryginal tesityr");
//    zegary = new Zegary;
//    connect(zegary, Signal(textChanged(QString)),this->labelZegara, Slot(setText(QString)));

//    cout<<godzina<<endl;
//    cout<<minuta<<endl;
//    cout<<sekunda<<endl;
//    cout<<dzien<<endl;
//    cout<<miesiac<<endl;
//    cout<<rok<<endl;

//    //pier->zmianaLabela(sekunda);
//    return ( sekunda);
return 0;
}


