#include "ongletdetailtrajet.h"

ongletdetailtrajet::ongletdetailtrajet() : QWidget()
{

}

ongletdetailtrajet::ongletdetailtrajet(QString NomStaDeb, QString NomStaFin, QString DurTron, QString LigneTron, QString TpAttOuCor,int RgTron) : QWidget()
{
    m_NomStaDeb = NomStaDeb;
    m_NomStaFin = NomStaFin;
    m_DurTron = DurTron;
    m_LigneTron = LigneTron;
    m_TpAttOuCor = TpAttOuCor;
    m_RgTron = RgTron;
    QFont e("lucida grande",13);

    m_DispoExt = new QHBoxLayout;
    m_DispoInt = new QVBoxLayout;
    //m_DispoIm = new QVBoxLayout;

    //Partie Explication
    m_TextPrec = new QLabel;
    m_TextLigne = new QLabel;
    m_TextStaDeb = new QLabel;
    m_TextStaFin = new QLabel;
    m_TextDur = new QLabel;
    m_TextSuiv = new QLabel;
    //m_Logo = new QLabel;

    // nous n'avons pas réussir à faire s'afficher le logo du métro parisien dans les onglets
    //m_Logo->setPixmap(QPixmap("parislogometro.png"));
    //m_DispoIm->addWidget(m_Logo);

    m_TextPrec->setFont(e);
    m_TextPrec->setTextFormat(Qt::RichText);
    m_TextPrec->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextPrec->setMargin(1);

    m_TextLigne->setFont(e);
    m_TextLigne->setTextFormat(Qt::RichText);
    m_TextLigne->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextLigne->setMargin(1);

    m_TextStaDeb->setFont(e);
    m_TextStaDeb->setTextFormat(Qt::RichText);
    m_TextStaDeb->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextStaDeb->setMargin(1);

    m_TextStaFin->setFont(e);
    m_TextStaFin->setTextFormat(Qt::RichText);
    m_TextStaFin->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextStaFin->setMargin(1);

    m_TextDur->setFont(e);
    m_TextDur->setTextFormat(Qt::RichText);
    m_TextDur->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextDur->setMargin(1);

    m_TextSuiv->setFont(e);
    m_TextSuiv->setTextFormat(Qt::RichText);
    m_TextSuiv->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_TextSuiv->setMargin(1);

    // 4 cas : 0 si premier tronçon, 1 si tronçon unique, 2 si dernier tronçon, 3 si tronçon intermédiaire
    if(m_RgTron == 0)
    {
        m_TextPrec->setText("Temps d'attente au départ : " + m_TpAttOuCor + " minutes");
        m_TextSuiv->setText("Correspondance");
    }
    else if(m_RgTron == 1)
    {
        m_TextPrec->setText("Durée de l'attente au départ : " + m_TpAttOuCor + " minutes");
        m_TextSuiv->setText("Vous êtes arrivés !");
    }
    else if(m_RgTron == 2)
    {
        m_TextPrec->setText("Durée de la correspondance : " + m_TpAttOuCor + " minutes");
        m_TextSuiv->setText("Vous êtes arrivés !");
    }
    else if(m_RgTron == 3)
    {
        m_TextPrec->setText("Durée de la correspondance : " + m_TpAttOuCor + " minutes");
        m_TextSuiv->setText("Nouvelle correspondance");
    }

    m_TextLigne->setText("Prendre la " + m_LigneTron);
    m_TextStaDeb->setText("De la station : " + m_NomStaDeb);
    m_TextStaFin->setText("Jusqu'à la station : " + m_NomStaFin);
    m_TextDur->setText("Durée estimée : " + m_DurTron + " minutes");

    m_DispoInt->addWidget(m_TextPrec);
    m_DispoInt->addWidget(m_TextLigne);
    m_DispoInt->addWidget(m_TextStaDeb);
    m_DispoInt->addWidget(m_TextStaFin);
    m_DispoInt->addWidget(m_TextDur);
    m_DispoInt->addWidget(m_TextSuiv);

    //m_DispoExt->addLayout(m_DispoIm);
    m_DispoExt->addLayout(m_DispoInt);
    setLayout(m_DispoExt);
}

