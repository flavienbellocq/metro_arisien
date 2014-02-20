#ifndef INTERFACE_H
#define INTERFACE_H
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QLabel>
#include <QComboBox>
#include <QLCDNumber>
#include <QFrame>
#include <QFont>
#include <QString>
#include <QStringList>
#include <vector>
#include <QMessageBox>
#include <QVector>

#include "ongletdetailtrajet.h"
#include "reseauparis.h"
#include "dijkstra.h"


class interface : public QWidget
{
    Q_OBJECT

    public:

        interface(reseauparis const& RATP, dijkstra& DJK);
        void DefAlpha(void);

   public slots:

        void MajListeStaDep(int RgDepLetSta);
        void MajListeStaArr(int RgDepLetSta);
        void RecupCodeDepSelect(int CodeStaDepSelect);
        void RecupCodeArrSelect(int CodeStaArrSelect);
        void ExecutionAlgoDijkstra(void);

    private:

        reseauparis m_RATP;
        dijkstra m_DJK;
        int m_StationDepartSelect;
        int m_StationArriveeSelect;
        double m_TempsAttente ;
        double m_TpCor;

        // général
        QVBoxLayout * m_DispoVGen;

        //Partie recherche
        QFrame * m_FrameRecherche;
        QHBoxLayout * m_DispoHChoixBout;
        QVBoxLayout * m_Choix;
        QHBoxLayout * m_ChampsDep;
        QHBoxLayout * m_ChampsArr;

        QLabel * m_TextChoisirDep;
        QLabel * m_TextChoisirArr;
        QLabel * m_TextComDep;
        QLabel * m_TextComArr;
        QComboBox * m_ListeAlphaDep;
        QComboBox * m_ListeAlphaArr;
        QComboBox * m_ListeStaDep;
        QComboBox * m_ListeStaArr;
        QPushButton * m_RechercheBoutton;

        std::vector <QString> m_VecteurNomStation;
        QStringList m_QSListeStaDep;
        QStringList m_QSListeStaArr;
        std::vector <int> m_CodeStationDepIssueTriAlpha;
        std::vector <int> m_CodeStationArrIssueTriAlpha;
        QStringList m_Alpha;

        //Partie Resultat
        QFrame * m_FrameResult;
        QHBoxLayout * m_DispoResult;

        QLabel * m_TextDurTot;
        QLCDNumber * m_DurTot;
        QFrame * m_SepV;
        QLabel * m_TextCorres;
        QLCDNumber * m_NbCorres;

        //Texte "Detail..."
        QLabel * m_TextDetailTraj;

        //Onglets
        std::vector <std::vector <double> > m_CheminOpt;
        QTabWidget * m_Onglets;
        QVector<ongletdetailtrajet *> m_VectOnglets;

};

#endif // INTERFACE_H
