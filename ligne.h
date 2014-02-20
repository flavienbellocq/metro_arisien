#ifndef LIGNE_H
#define LIGNE_H
#include <vector>
#include "station.h"

class ligne
{

public:

    ligne(void);
    ligne(double CodeLigne);
    ligne(ligne const& LigneACopier);
    ~ligne(void);

    double GetCodeLigne(void) const;
    std::vector <int> GetTabStationSurLigne(void) const;

    void RTabSSL(station const& T);

private:

    double m_CodeLigne;
    std::vector <int>  m_TabStationSurLigne;
};

#endif // LIGNE_H

