#ifndef ONGLETDETAILTRAJET_H
#define ONGLETDETAILTRAJET_H
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QFont>

class ongletdetailtrajet : public QWidget
{

    public:

        ongletdetailtrajet();
        ongletdetailtrajet(QString NomStaDeb, QString NomStaFin, QString DurTron, QString Ligne, QString TpAttOuCor,int RgTron);


    private:

        QString m_NomStaDeb;
        QString m_NomStaFin;
        QString m_DurTron;
        QString m_LigneTron;
        QString m_TpAttOuCor;
        int m_RgTron;

        QHBoxLayout * m_DispoExt;
        QVBoxLayout * m_DispoInt;
        //QVBoxLayout * m_DispoIm;

        QLabel * m_TextPrec;
        QLabel * m_TextLigne;
        QLabel * m_TextStaDeb;
        QLabel * m_TextStaFin;
        QLabel * m_TextDur;
        QLabel * m_TextSuiv;
        //QLabel * m_Logo;


};

#endif // ONGLETDETAILTRAJET_H

