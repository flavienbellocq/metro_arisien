#include "estimdurees.h"

estimdurees::estimdurees()
{
    m_TpsCorres = 0.0;
    m_TempsArretMoyenStation = 0.0;
    m_CoefLinRegressionLineaire = 1.0;
    m_CoefInterceptRegressionLineaire = 1.0;
}

estimdurees::estimdurees(std::vector<std::vector<double> > const& MatriceDistance)
{
    m_TpsCorres = 0.0;
    m_MatriceDistance = MatriceDistance;
    m_TempsArretMoyenStation = 0.0;
    m_CoefLinRegressionLineaire = 1.0;
    m_CoefInterceptRegressionLineaire = 1.0;
}

estimdurees::~estimdurees()
{

}

void estimdurees::SetTempsArretMoyenStation(double alpha)
{
    m_TempsArretMoyenStation = alpha;
}

void estimdurees::SetCoefLinRegressionLineaire(double beta1)
{
    m_CoefLinRegressionLineaire = beta1;
}

void estimdurees::SetCoefInterceptRegressionLineaire(double beta0)
{
    m_CoefInterceptRegressionLineaire= beta0;
}

void estimdurees::SetTempsCorrespondanceMoyen(double TpsCorres)
{
    m_TpsCorres = TpsCorres;
}

double estimdurees::GetTpsCorres() const
{
    return m_TpsCorres;
}

std::vector <std::vector <double> > estimdurees::GetMatriceDurees() const
{
    return m_MatriceDurees;
}

double estimdurees::ModelisationDurees(double Distance)
{
    // estimation par régression linéaire sur un échantillon de trajet

    double duree = m_CoefInterceptRegressionLineaire + m_TempsArretMoyenStation + (Distance * m_CoefLinRegressionLineaire);
    return duree;
}

void estimdurees::CalculDureesTrajet()
{
    m_MatriceDurees = m_MatriceDistance;
    int i=0;
    int nb = m_MatriceDurees.size();
    for(i=0;i<nb;i++)
    {
        int j=0;
        for(j=0;j<nb;j++)
        {
            // on va "transformer" les distances en durée que pour les trajets existant réelement
            if(m_MatriceDurees[i][j] > 0.0 && m_MatriceDurees[i][j] < 1000000.0)
            {
                m_MatriceDurees[i][j] = ModelisationDurees(m_MatriceDistance[i][j]);
            }
        }
    }
}

double estimdurees::CalculTempsCorrespondanceMoyen()
{
    // Cette fonction permet si on le souhaite de
    // coder de nouvelles méthodes (calculatoire ou statistique)
    // Pour obtenir un temps de correspondance moyen plus fidèle
    m_TpsCorres = 120.0;
    return m_TpsCorres;
}
