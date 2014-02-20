#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <numeric>

class dijkstra
{
public:

    dijkstra(void);
    dijkstra(std::vector <std::vector <double> > const& MatriceDureeTrajet, std::vector <std::vector <std::vector <double> > > const& MatriceLigneSurTrajet, double const& TpsCorres, double const& Ta);
    ~dijkstra(void);

    void SetCodeStationDepart(int CSD);
    void SetCodeStationArrivee(int CSA);
    void SetMatricePoidsArete(std::vector <std::vector <double> > MPA);
    void SetMatriceLigneSurTrajet(std::vector <std::vector <std::vector <double> > > MLST);
    void SetTpsCorres(double Tps);
    void SetTpsAttente(double Ta);

    double GetDureeTotale(void) const;
    int GetNbCorres(void) const;
    std::vector <std::vector <double> > GetMatriceSortie(void) const;
    double GetTpsCorres(void);
    double GetTpsAttente(void);

    // fonction interne à l'algorithme

   void RebootAlgo(void);
   void InitDijk(void);
   int AppartAVecteurNoeudATester(int CodeStationATester);
   std::vector <int> RechercheVoisin(int CodeStationAct);
   void LignePossibleTrajetAvecVoisin(std::vector <int> const& voisin);
   void InitDistanceLignePredecesseurSommet(std::vector <int> const& voisin);
   void MajDistanceLignePredecesseurSommet(std::vector <int> const& voisin);
   int RechercheMin(void);
   void AlgoDuree(void);
   void RecuperationPlusCourtChemin(void);
   void ConstructionSortie(void);

   //fonction génrale pour execution de l'algorithme

   void AlgoDijkstra(int CodeStationDepart, int CodeStationArrivee);

private:

    // Champs d'entrées
    int m_CodeStationDepart;
    int m_CodeStationArrivee;
    double m_TpsCorres;
    double m_TpsAttente;
    std::vector <std::vector <double> > m_MatricePoidsArete;
    std::vector <std::vector <std::vector <double> > > m_MatriceLigneSurTrajet;

    // Champs interne de travail
    std::vector <double> m_VecteurDistanceSommet;
    std::vector <int> m_VecteurNoeudATester;
    std::vector <int> m_ListeCodeStationPlusCourtChemin;
    std::vector <int> m_VecteurPredecesseur;

    std::vector <std::vector <double> > m_VecteurBidimTopCorres;
    /* Il vaut 1.0 si il y a crrespondance au début d'un trajet (lors du chemin optimal)
     * 0.0 si il n'y a pas de coorespondance
     * 0.5 si c'est un trajet partant de la station de départ choisie
     */

    std::vector <std::vector <int> > m_VecteurBidimNoeudVoisin;
    /* Vecteur Bi-dimensionnel :
     * Echelle 1 (extérieure) : nombre de recherche de voisin = nombre itération de l'algorithme dijkstra
     * Echelle 2 : nombre de voisin et donc de trajet possible pour chaque recherche de voisin
     */

    std::vector <std::vector <std::vector <double> > > m_VecteurTridimLigneAct;

    // Champs de Sorties
    int m_NbCorres;
    double m_DureeTotale;
    std::vector <std::vector <double> > m_MatriceSortie;

};

#endif // DIJKSTRA_H

