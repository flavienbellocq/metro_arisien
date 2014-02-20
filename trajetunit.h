#ifndef TRAJETUNIT_H
#define TRAJETUNIT_H
#include <vector>
#include "ligne.h"
#include <math.h>

class trajetunit
{

public:

    trajetunit(void);
    trajetunit( station const& Debut, station const& Fin);
    ~trajetunit(void);

    std::vector <double> GetTabLigneSurTrajet(void);

    double CalculDistance(void);
    void LigneSurTajet(ligne const& L);

private:

    station m_Debut;
    station m_Fin;
    std::vector <double> m_TabLigneSurTrajet;
    double m_Distance;

};

#endif // TRAJETUNIT_H
