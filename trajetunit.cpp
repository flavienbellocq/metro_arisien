#include "trajetunit.h"

trajetunit::trajetunit()
{
    station deb;
    station fin;
    m_Debut = deb ;
    m_Fin = fin ;
    m_Distance = 0.0;

}

trajetunit::trajetunit(station const& Debut, station const& Fin)
{
    m_Debut = Debut;
    m_Fin = Fin;
    m_Distance = 0.0;
    m_TabLigneSurTrajet = std::vector <double> (1,0.0);
}

trajetunit::~trajetunit()
{

}

std::vector <double> trajetunit::GetTabLigneSurTrajet()
{
    return m_TabLigneSurTrajet;
}

double trajetunit::CalculDistance()
{

    std::vector <int> TDS = m_Debut.GetTabStationVoisine();
    std::vector <int> TFS = m_Fin.GetTabStationVoisine();
    int NTDS = m_Debut.NbStationVoisine();
    int NTFS = m_Fin.NbStationVoisine();

    int result1 = 0;
    int result2 = 0;
    int result;

    //si station debut = station fin : trajet nul
    if(m_Debut.GetCodeStation()==m_Fin.GetCodeStation())
    {
        m_Distance = 0.0;
        m_TabLigneSurTrajet[0]=0.3;
        return m_Distance;
    }

    else
    {
        int i=0;
        for(i=0;i<NTFS;i++)
        {
            // si la station départ est parmi les stations voisines de la station d'arrivée
            if(TFS[i]==m_Debut.GetCodeStation())
            {
                result1 = 1;
            }
        }

        int j=0;
        for(j=0;j<NTDS;j++)
        {
            // si la station arrivée est parmi les stations voisines de la station de départ
            if(TDS[j]==m_Fin.GetCodeStation())
            {
                result2 = 1;
            }
        }

        result = result1 + result2 ;

        // si les deux précédante condition ne sont pas remplies : pas de lien direct -> distance arbitrairement grande (infini)
        if(result < 2)
        {
            m_Distance = 1000000.0;
            return m_Distance;
        }
        else
        {
            double PI = 3.14159265358979 ;
            std::vector <double> GPSD = m_Debut.GPS();
            std::vector <double> GPSF = m_Fin.GPS();
            double LAD = GPSD[0] * ( PI / 180.0);
            double LAF = GPSF[0] * (PI / 180.0);
            double LOD = GPSD[1] * ( PI / 180.0);
            double LOF = GPSF[1] * (PI / 180.0);
            double s1 = sin (((LAD - LAF) / 2));
            double s2 = sin (((LOD - LOF) / 2));
            double R = 6371000 ; // Rayon terretre en mètre
            //calcul de distance en mètre
            m_Distance = 2 * R * asin (sqrt ((s1 * s1) + (cos (LAD) * cos (LAF) * s2 * s2)));
            m_TabLigneSurTrajet[0]=0.5;
            return m_Distance;
        }
    }
}


void trajetunit::LigneSurTajet(ligne const& L)
{

    /* Cas où un trajet direct existe :
     * On liste les lignes utilisant ce trajet
     */

    if(m_TabLigneSurTrajet[0] >= 0.5)
    {
        std::vector <double> TDL = m_Debut.GetTabLigneDansStation();
        std::vector <double> TFL = m_Fin.GetTabLigneDansStation();
        int NTDL = m_Debut.NbLigneDansStation();
        int NTFL = m_Fin.NbLigneDansStation();

        int result1 = 0;
        int result2 = 0;
        int result;

        int i=0;
        for(i=0;i<NTFL;i++)
        {
            // Si ligne L passe dans station d'arrivée
            if(TFL[i]==L.GetCodeLigne())
            {
                result1 = 1;
            }
        }

        int j=0;
        for(j=0;j<NTDL;j++)
        {
            // Si ligne L passe dans station de départ
            if(TDL[j]==L.GetCodeLigne())
            {
                result2 = 1;
            }
        }

        result = result1 + result2 ;

        // Si les 2 conditions précédentes sont remplies
        if(result == 2)
        {
            if(m_TabLigneSurTrajet[0] <1.0) // cas où on est en train d'ajouter la première ligne passant sur ce trajet
            {
                m_TabLigneSurTrajet[0] = L.GetCodeLigne();
            }
            else
            {
                m_TabLigneSurTrajet.push_back(L.GetCodeLigne()); // cas où il y a déjà des lignes passant sur ce trajet
            }
        }
    }

    /* Cas où le trajet "n'existe pas" : distance = 0.0 ou distance infini = 1 000 000
     * Pour le vecteur des ligne sur le "trajet" on met la première valeur à -1
     */

    else
    {
        m_TabLigneSurTrajet[0] = -1.0;
    }
 }
