#include "dijkstra.h"

dijkstra::dijkstra()
{
    m_CodeStationDepart = 0;
    m_CodeStationArrivee = 0;
    m_MatricePoidsArete = std::vector <std::vector <double> > (1,std::vector <double> (1,0.0));
    m_MatriceLigneSurTrajet = std::vector <std::vector <std::vector <double> > > (1,std::vector <std::vector <double> > (1,std::vector <double> (1,0.0)));
    m_TpsCorres = 0.0;
    m_TpsAttente = 0.0;
    m_NbCorres = 0;
    m_DureeTotale = 0.0;

}

dijkstra::dijkstra(std::vector<std::vector<double> > const& MatriceDureeTrajet, std::vector<std::vector<std::vector<double> > > const& MatriceLigneSurTrajet, double const& TpsCorres, double const& Ta)
{
    m_CodeStationDepart = 0;
    m_CodeStationArrivee = 0;
    m_MatricePoidsArete = MatriceDureeTrajet;
    m_MatriceLigneSurTrajet = MatriceLigneSurTrajet;
    m_TpsCorres = TpsCorres;
    m_TpsAttente = Ta;
    m_NbCorres = 0;
    int lgh = MatriceDureeTrajet.size();
    m_DureeTotale = 0.0;
    m_VecteurDistanceSommet = std::vector <double> (lgh,0.0);
    m_VecteurPredecesseur = std::vector <int> (lgh,-1);

    int k=0;
    for (k=0;k<lgh;k++)
    {
        m_VecteurNoeudATester.push_back(k);
        std::vector <double> A(lgh,0.0);
        m_VecteurBidimTopCorres.push_back(A);
        std::vector <double> C(1,0.0);
        std::vector <std::vector <double> > B(lgh,C);
        m_VecteurTridimLigneAct.push_back((B));
    }
}

dijkstra::~dijkstra()
{

}

void dijkstra::SetCodeStationDepart(int CSD)
{
    m_CodeStationDepart = CSD;
}

void dijkstra::SetCodeStationArrivee(int CSA)
{
    m_CodeStationArrivee = CSA ;
}


void dijkstra::SetMatricePoidsArete(std::vector <std::vector <double> > MPA)
{
    m_MatricePoidsArete = MPA;
}

void dijkstra::SetMatriceLigneSurTrajet(std::vector <std::vector <std::vector <double> > > MLST)
{
    m_MatriceLigneSurTrajet = MLST;
}

void dijkstra::SetTpsCorres(double Tps)
{
    m_TpsCorres = Tps;
}

void dijkstra::SetTpsAttente(double Ta)
{
    m_TpsAttente = Ta;
}

double dijkstra::GetDureeTotale() const
{
    return m_DureeTotale;
}

int dijkstra::GetNbCorres() const
{
    return m_NbCorres;
}

std::vector <std::vector <double> > dijkstra::GetMatriceSortie() const
{
    return m_MatriceSortie;
}

double dijkstra::GetTpsCorres()
{
   return m_TpsCorres;
}

double dijkstra::GetTpsAttente()
{
    return m_TpsAttente;
}

void dijkstra::RebootAlgo()
{
    m_NbCorres = 0;
    int lgh = m_MatricePoidsArete.size();
    m_DureeTotale = 0.0;
    m_VecteurDistanceSommet = std::vector <double> (lgh,0.0);
    m_VecteurPredecesseur = std::vector <int> (lgh,-1);
    m_ListeCodeStationPlusCourtChemin.clear();
    m_VecteurBidimNoeudVoisin.clear();
    m_MatriceSortie.clear();
    //int lgl = m_VecteurBidimNoeudVoisin.size();
    m_VecteurNoeudATester.clear();
    m_VecteurBidimTopCorres.clear();
    m_VecteurTridimLigneAct.clear();
    int k=0;
    for (k=0;k<lgh;k++)
    {
        m_VecteurNoeudATester.push_back(k);
        std::vector <double> A(lgh,0.0);
        m_VecteurBidimTopCorres.push_back(A);
        std::vector <double> C(1,0.0);
        std::vector <std::vector <double> > B(lgh,C);
        m_VecteurTridimLigneAct.push_back((B));
    }
}


void dijkstra::InitDijk()
{
    std::vector <double> AretesDeb = m_MatricePoidsArete[m_CodeStationDepart];
    int LVDS = AretesDeb.size();

    int i;
    for (i=0;i<LVDS;i++)
    {
        if (i==m_CodeStationDepart)
        {
            m_VecteurDistanceSommet[i] = 0.0;
        }
        else
        {
            m_VecteurDistanceSommet[i] = 1000000.0;
        }
    }
    m_VecteurNoeudATester.erase(m_VecteurNoeudATester.begin() + m_CodeStationDepart);
}

int dijkstra::AppartAVecteurNoeudATester(int CodeStationATester)
{
    int k=0;
    int nbk = m_VecteurNoeudATester.size();
    int test = 0;
    while(test == 0 && k < nbk)
    {
        if(m_VecteurNoeudATester[k] == CodeStationATester)
        {
            test = 1;
        }
        k = k+1;
    }
    return test;
}

std::vector <int> dijkstra::RechercheVoisin(int CodeStationAct)
{
    std::vector <int> voisin(1,CodeStationAct);
    int j=0;
    int nbj = m_MatricePoidsArete.size();
    for(j=0;j<nbj;j++)
    {
        int Q = AppartAVecteurNoeudATester(j);
        if(m_MatricePoidsArete[CodeStationAct][j] > 0.0 && m_MatricePoidsArete[CodeStationAct][j] < 1000000.0 && Q == 1)
        {
             voisin.push_back(j);
        }
    }
    m_VecteurBidimNoeudVoisin.push_back(voisin);
    return voisin;
    // le vecteur contient donc en premiere position la station dont on cherche les voisins
    // puis les codes des différentes stations voisines qui n'ont pas encore étaient tester
    // (interdiction de repasser plusieurs fois dans une même station)
}


void dijkstra::InitDistanceLignePredecesseurSommet(std::vector <int> const& voisin)
{
    int nbv = voisin.size();
    int v=1;
    for(v=1;v<nbv;v++)
    {
        m_VecteurDistanceSommet[voisin[v]] = m_MatricePoidsArete[m_CodeStationDepart][voisin[v]]; //maj distance
        m_VecteurTridimLigneAct[m_CodeStationDepart][voisin[v]] = m_MatriceLigneSurTrajet[m_CodeStationDepart][voisin[v]]; //maj ligne sur trajet
        m_VecteurPredecesseur[voisin[v]] = m_CodeStationDepart; //maj prédécesseur
        m_VecteurBidimTopCorres[m_CodeStationDepart][voisin[v]] = 0.5;
    }
}

void dijkstra::MajDistanceLignePredecesseurSommet(std::vector <int> const& voisin)
{
    // Dans le réseau parisien les trajet partagés par plusieurs lignes ne le sont que pas 2 lignes au maximum
    std::vector <double> t = m_VecteurTridimLigneAct[m_VecteurPredecesseur[voisin[0]]][voisin[0]];
    int lt = t.size();
    // t trié par ordre croissant (cela est déjà fait lors de la construction)
    int nbv = voisin.size();
    int v=1;
    for (v=1;v<nbv;v++)
    {
        std::vector <double> vv = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
        // vv trié par ordre croissant (cela est déjà fait lors de la construction)
        int lvv = vv.size();
        if(lt == 2 && lvv == 2)
        {
            if((vv[0] == t[0] && vv[1] != t[1]) || (vv[0] == t[1] && vv[1] != t[0])) // pas de corres une seule ligne en commun
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    std::vector <double> svv(1,vv[0]);
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = svv;  // seule la ligne commune à t et vv reste
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
            else if((vv[1] == t[0] && vv[0] != t[1]) || (vv[1] == t[1] && vv[0] != t[0])) // pas de corres une seule ligne en commun
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    std::vector <double> svv(1,vv[1]);
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = svv;  // seule la ligne commune à t et vv reste
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
            else if((vv[0] == t[0] && vv[1] == t[1])) // pas de corres, trajet identique en terme de ligne
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
            else if((vv[0] != t[0] && vv[0] != t[1]) && (vv[1] != t[0] && vv[1] != t[1])) // corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres)
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres;
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                    m_VecteurBidimTopCorres[voisin[0]][voisin[v]] = 1.0;
                }
            }
        }
        else if(lt == 1 && lvv == 2)
        {
            if (vv[0] == t[0] || vv[1] == t[0]) // pas de corres mais on corrige la ligne emprunté pour le trajet voisin[0]->voisin[v]
            {

                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    std::vector <double> st(1,t[0]);
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = st; // ligne commune entre trajet prec et trajet entre voisin[0] et voisin [v]
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
            else if (vv[0] != t[0] && vv[1] != t[0]) // corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres)
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres;
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                    m_VecteurBidimTopCorres[voisin[0]][voisin[v]] = 1.0;
                }
            }
        }
        else if(lt == 2 && lvv == 1)
        {
            if (vv[0] == t[0] || vv[0] == t[1]) // pas de corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
            else if (vv[0] != t[0] && vv[0] != t[1]) // corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres)
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres;
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                    m_VecteurBidimTopCorres[voisin[0]][voisin[v]] = 1.0;
                }
            }
        }
        else if(lt ==1 && lvv == 1) // (cas le plus fréquent)
        {
            if(vv[0] != t[0]) // corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres)
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]] + m_TpsCorres;
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                    m_VecteurBidimTopCorres[voisin[0]][voisin[v]] = 1.0;
                }
            }
            else // Pas de corres
            {
                if(m_VecteurDistanceSommet[voisin[v]] > m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]])
                {
                    m_VecteurDistanceSommet[voisin[v]] = m_VecteurDistanceSommet[voisin[0]] + m_MatricePoidsArete[voisin[0]][voisin[v]];
                    m_VecteurTridimLigneAct[voisin[0]][voisin[v]] = m_MatriceLigneSurTrajet[voisin[0]][voisin[v]];
                    m_VecteurPredecesseur[voisin[v]] = voisin[0];
                }
            }
        }
    }
}



int dijkstra::RechercheMin()
{
    int nbs = m_VecteurNoeudATester.size();
    int s=0;
    double mini=1000000.0;
    int rgmin;
    for(s=0;s<nbs;s++)
    {
        if (m_VecteurDistanceSommet[m_VecteurNoeudATester[s]] <= mini )
        {
            mini = m_VecteurDistanceSommet[m_VecteurNoeudATester[s]];
            rgmin = m_VecteurNoeudATester[s];
        }
    }
    // suppresiion du min dans le vectuer des noeuds à tester
    int t = 0;
    int SommetASupprimer ;
    while(rgmin != m_VecteurNoeudATester[t] && t<nbs )
    {
    SommetASupprimer = t;
    t = t+1;
    }
    m_VecteurNoeudATester.erase(m_VecteurNoeudATester.begin()+t);
    return rgmin;
}

void dijkstra::AlgoDuree()
{
    //Initialisation
    InitDijk();
    int cpt = 0;
    int stop = m_MatricePoidsArete.size() - 1;
    int stmin = m_CodeStationDepart;
    std::vector <int> voisin;

    // Algorithme
    while (stmin != m_CodeStationArrivee && cpt < stop)
    {
        voisin = RechercheVoisin(stmin);
        if(cpt == 0)
        {
            InitDistanceLignePredecesseurSommet(voisin);
        }
        else
        {
            MajDistanceLignePredecesseurSommet(voisin);
        }
        stmin = RechercheMin();
        cpt = cpt + 1;
    }

    m_DureeTotale = m_VecteurDistanceSommet[m_CodeStationArrivee] + m_TpsAttente;
}


void dijkstra::RecuperationPlusCourtChemin()
{
    m_ListeCodeStationPlusCourtChemin.push_back(m_CodeStationArrivee);
    int prec = m_CodeStationArrivee;
    int nbs = m_VecteurDistanceSommet.size();
    int s=0;
    while(prec != m_CodeStationDepart && s<nbs)
    {
        prec = m_VecteurPredecesseur[prec];
        m_ListeCodeStationPlusCourtChemin.push_back(prec);
        s = s+1;
    }
    std::reverse(m_ListeCodeStationPlusCourtChemin.begin(),m_ListeCodeStationPlusCourtChemin.end());
}

void dijkstra::ConstructionSortie()
{
    //init
    std::vector <double> initial(4,0.0);
    std::vector <int> CodeStationPostCorres;
    int test1 = m_ListeCodeStationPlusCourtChemin[0];
    int nbm = m_ListeCodeStationPlusCourtChemin.size();
    //construction matrice
    int m=1;
    for(m=1;m<nbm;m++)
    {

        if(m_VecteurBidimTopCorres[test1][m_ListeCodeStationPlusCourtChemin[m]] >= 0.5)
        {
            m_MatriceSortie.push_back(initial);
            CodeStationPostCorres.push_back(m_ListeCodeStationPlusCourtChemin[m]);
        }
        test1 = m_ListeCodeStationPlusCourtChemin[m];
    }

    // remplissage code stations
    m_MatriceSortie[0][0] = m_ListeCodeStationPlusCourtChemin[0];
    int test1i = m_ListeCodeStationPlusCourtChemin[0];
    int cpt=0;
    for(m=1;m<nbm;m++)
    {
        if(m_VecteurBidimTopCorres[test1i][m_ListeCodeStationPlusCourtChemin[m]] == 1.0)
        {
            cpt = cpt+1;
            double test1d = static_cast<double>(test1i);
            m_MatriceSortie[cpt-1][1] = test1d;
            m_MatriceSortie[cpt][0] = test1d;

        }
        test1i = m_ListeCodeStationPlusCourtChemin[m];
    }
    int ms = m_MatriceSortie.size();
    m_MatriceSortie[ms-1][1] = m_ListeCodeStationPlusCourtChemin[nbm-1];

    // détermination nombre de correspondances
    m_NbCorres = ms-1;

    //remplissage ligne emprunté par tronçon et durée tronçon
    int csi = static_cast<int>(m_MatriceSortie[0][1]);
    m_MatriceSortie[0][2] = m_VecteurDistanceSommet[csi];
    int h=0;
    for(h=0;h<ms;h++)
    {
        //ligne
        int recupdeb = static_cast<int>(m_MatriceSortie[h][0]);
        int recupfin = static_cast<int>(m_MatriceSortie[h][1]);
        std::vector <double> lindebtronc = m_VecteurTridimLigneAct[recupdeb][CodeStationPostCorres[h]];
        std::vector <double> linfintronc = m_VecteurTridimLigneAct[m_VecteurPredecesseur[recupfin]][recupfin];
        if( lindebtronc.size() == 1)
        {
            m_MatriceSortie[h][3] = lindebtronc[0];
        }
        else if(lindebtronc.size() == 2 && linfintronc.size() == 2)
        {
            m_MatriceSortie[h][3] = lindebtronc[0];
        }
        else if(lindebtronc.size() == 2 && linfintronc.size() == 1)
        {
            m_MatriceSortie[h][3] = linfintronc[0];

        }
        //durée
        if (h>0)
        {
        int csi = static_cast<int>(m_MatriceSortie[h][1]);
        m_MatriceSortie[h][2] = m_VecteurDistanceSommet[csi] - m_MatriceSortie[h-1][2] - m_TpsCorres ;
        }
    }
}

void dijkstra::AlgoDijkstra(int CodeStationDepart, int CodeStationArrivee)
{
    if(CodeStationDepart != CodeStationArrivee)
    {
        RebootAlgo();
        SetCodeStationDepart(CodeStationDepart);
        SetCodeStationArrivee(CodeStationArrivee);
        AlgoDuree();
        RecuperationPlusCourtChemin();
        ConstructionSortie();
    }
}

