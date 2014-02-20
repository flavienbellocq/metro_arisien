#include "station.h"

station::station()
{
    m_CodeStation = -1;
    m_Longitude = 0.0;
    m_Latitude = 0.0;
}

station::station(int CodeStation, double Latitude, double Longitude)
{
    m_CodeStation = CodeStation;
    m_Longitude = Longitude;
    m_Latitude = Latitude;
}


station::station(station const& StationACopier)
{
    m_CodeStation = StationACopier.m_CodeStation;
    m_Longitude = StationACopier.m_Longitude;
    m_Latitude = StationACopier.m_Latitude;
    m_TabStationVoisine = StationACopier.m_TabStationVoisine;
    m_TabLigneDansStation = StationACopier.m_TabLigneDansStation;
}

station::~station(void)
{

}

int station::GetCodeStation() const
{
    return m_CodeStation;
}

std::vector <int> station::GetTabStationVoisine() const
{
    return m_TabStationVoisine;
}

std::vector <double> station::GetTabLigneDansStation() const
{
    return m_TabLigneDansStation;
}

// fonctions completant les infos sur une station (lignes passant par celle ci et stations voisines)

void station::RTabSV (int CodeStationVoisine)
{
    m_TabStationVoisine.push_back(CodeStationVoisine);
}

void station::RTabLDS (double CodeLigne)
{
    m_TabLigneDansStation.push_back(CodeLigne);
}


// fonctions renvoyant les nombres de ligne passant par la station et le nombre de stations voisines

int station::NbStationVoisine (void) const
{
    return m_TabStationVoisine.size();
}

int station::NbLigneDansStation(void) const
{
    return m_TabLigneDansStation.size();
}


std::vector <double> station::GPS (void)
{
    std::vector <double> coord(2,0.0);
    coord[0] = m_Latitude;
    coord[1] = m_Longitude;
    return coord;
}
