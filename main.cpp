#include <vector>
#include <QString>
#include <QApplication>
#include "estimdurees.h"
#include "interface.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* PHASE 1 : Cosntruction Du Réseau : On construit le réseau parisien complet avec 302 stations et 16 lignes (De 1 à 14, 3bis et 7bis) */
    /***************************************************************************************************************************************/


    reseauparis RATP;
    RATP.CreationReseauComplet();

    /*
     * A l'issue de la construction nous obtenons donc 2 matrices :
     * l'une contient les distances en mètre entre tout les couples de station
     * - 0 entre une station et elle-même
     * - une valeur arbitrairement grande entre 2 stations qui ne sont pas en lien direct : 1 000 000
     * - la distance exacte entre 2 stations en lien direct
     * L'autre contient dans chacune de ses cases un vecteur avec les codes des "lignes avec direction"
     * qui utilisent chaque trajet.
     * Attention  :
     * les trajets sont signés : A->B différent de B->A
     */


    /* PHASE 2 : Mise en place des durée des trajet et des durées des correspondances */
    /**********************************************************************************/


    std::vector <std::vector <double> > MDistanceTrajet = RATP.GetMatriceTrajet();
    std::vector <std::vector <std::vector <double> > > MLigne= RATP.GetMatriceLigneSurTrajet();
    estimdurees Regress(MDistanceTrajet);

    /* Les coefs proviennent de l'étude d'un échantillon de trajet pour lesquels la durée a été mesuré (résultats pris comme des données) */

    /* On remplie le temps d'arrêt moyen à une station (intercept de la régression de la durée sur la distance entre 2 stations en secondes) */
    Regress.SetTempsArretMoyenStation(21.88694);

    /* On remplie le coef traduisant l'impact linéaire de la distance */
    Regress.SetCoefLinRegressionLineaire(0.078311);

    /* On remplie le coef intercept */
    Regress.SetCoefInterceptRegressionLineaire(21.740216);

    /* Temps de correspondance moyen (via la RATP en secondes) */
    Regress.SetTempsCorrespondanceMoyen(240.0);

    /* Temps attente première station moyen (via la RATP en secondes)*/
    double Tam = 150.0;

    Regress.CalculDureesTrajet();

    /*
     * En effet comme le calcul des durée est le point du projet qui peut être transformé pour
     * coller mieux à la réalité on le sépare de la construction du réseau.
     * Ainsi un utilisateur du programme pourra modifier l'algorithme permettant le calcul des
     * durées des trajet simple (trajet entre 2 stations directement liées) à partir de la distance
     * entre 2 stations (issues des coordonnées GPS)
     * Et aussi affiner les temps de correspondances que nous considerons comme unique et constant
     * et égal à 4 minutes ou 240.0 secondes
     * (valeur cohérante au vu de ce qui est dit sur le site de la RATP)
     */


    /* PHASE 3 : Mise en place de l'algorithme dijkstra */
    /****************************************************/


    std::vector <std::vector <double> > MDureeTrajet = Regress.GetMatriceDurees();
    double Tcm = Regress.GetTpsCorres();
    dijkstra DJK(MDureeTrajet, MLigne,Tcm,Tam);


    /* PHASE 4 : Recherche du trajet optimal et affichage du résultat via l'interface graphique */
    /********************************************************************************************/

    /* Concernant l'interface il y a une chose que nous avons implémenté mais qui ne fonctionne pas :
     * dans les obglets expliquant le détail du trajet, il devait y avoir sur la gauche une image du logo
     * de la ligne emprunté mais ceux-ci ne s'affichant pas nous avons laissé sans le programme
     * (le code est resté en commentaire avec l'exemple d'une photo unique et non pas d'un photo qui change
     * selon la ligne emprunté)
     */

    // nous n'avons pas utiliser QtDesigner pour l'interface mais nous avons préféré coder les fenêtres

    interface Fenetre(RATP,DJK);

    Fenetre.show();

    return a.exec();
}
