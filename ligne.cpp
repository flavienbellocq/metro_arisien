#include "ligne.h"

ligne::ligne()
{
    m_CodeLigne = 0.0;
}

ligne::ligne(double CodeLigne)
{
    m_CodeLigne = CodeLigne;
}

ligne::ligne(ligne const& LigneACopier)
{
    m_CodeLigne = LigneACopier.m_CodeLigne;
    m_TabStationSurLigne = LigneACopier.m_TabStationSurLigne;
}

ligne::~ligne(void)
{

}

double ligne::GetCodeLigne(void) const
{
    return m_CodeLigne;
}

std::vector <int> ligne::GetTabStationSurLigne(void) const
{
    return m_TabStationSurLigne ;
}



void ligne::RTabSSL(station const& T)
{
    std::vector <double> A = T.GetTabLigneDansStation();
    int b = T.NbLigneDansStation();
    int i = 0;
    for(i=0;i<b;i++)
    {
        if(A[i] == m_CodeLigne)
        {
            m_TabStationSurLigne.push_back(T.GetCodeStation());
        }
    }

}

