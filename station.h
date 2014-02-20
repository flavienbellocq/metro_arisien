#ifndef STATION_H
#define STATION_H
#include <vector>
#include <QString>

class station
{

public:

    station(void);
    station(int Codestation, double Latitude, double Longitude);
    station(station const& StationACopier);
    ~station(void);

    int GetCodeStation(void) const;
    std::vector <int> GetTabStationVoisine(void) const;
    std::vector <double> GetTabLigneDansStation(void) const;


    void RTabSV (int CodeStationVoisine);
    void RTabLDS (double CodeLigne);

    int NbStationVoisine (void) const;
    int NbLigneDansStation(void) const;

    std::vector <double> GPS (void);

private:

    int m_CodeStation;
    double m_Longitude;
    double m_Latitude;
    std::vector <int> m_TabStationVoisine;
    std::vector <double> m_TabLigneDansStation;

};

#endif // STATION_H
