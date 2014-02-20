#include "reseauparis.h"

reseauparis::reseauparis(void)
{
    int i=0;
    for(i=0;i<302;i++)
    {
        std::vector <double> A(302,0.0);
        std::vector <std::vector <double> > B(302,A);
        m_VecteurBidimTrajet.push_back(A);
        m_VecteurTridimLigneSurTrajet.push_back((B));
    }
}

reseauparis::~reseauparis(void)
{
}

std::vector <QString> reseauparis::GetTableNomStation() const
{
    return m_TableNomStation;
}

std::vector <double> reseauparis::GetTableCodeLigne() const
{
    return m_TableCodeLigne;
}

std::vector <QString> reseauparis::GetTableNomLigne() const
{
    return m_TableNomLigne;
}

std::vector <station> reseauparis::GetListeStation() const
{
    return m_ListeStation;
}

std::vector <ligne> reseauparis::GetListeLigne() const
{
    return m_ListeLigne;
}

std::vector <std::vector <double> > reseauparis::GetMatriceTrajet() const
{
    return m_VecteurBidimTrajet;
}

std::vector <std::vector <std::vector <double> > > reseauparis::GetMatriceLigneSurTrajet() const
{
    return m_VecteurTridimLigneSurTrajet;
}

std::vector <std::vector <int> > reseauparis::GetTabLigneOrdon() const
{
    return m_TabLigneOrdon;
}

// on adapte un codage pour les stations et les lignes AVEC DIRECTION (cela veut dire que :
// par exemple la ligne 14 direction Saint Lazare n'est pas la même que la 14 direction Olympiade)
// ces codages nous permettent d'éviter de complexifier la manipulation des tableaux avec de
// multiples chaines de caractères

void reseauparis::Codage(void)
{
    // Codage Station

    //ligne 1

    m_TableNomStation.push_back("La Défense");
    m_TableNomStation.push_back("Esplanade De La Défense");
    m_TableNomStation.push_back("Pont De Neuilly");
    m_TableNomStation.push_back("Les Sablons");
    m_TableNomStation.push_back("Porte Maillot");
    m_TableNomStation.push_back("Argentine");
    m_TableNomStation.push_back("Charles De Gaulle - Etoile");
    m_TableNomStation.push_back("George V");
    m_TableNomStation.push_back("Franklin D. Roosevelt");
    m_TableNomStation.push_back("Champs-Elysées - Clemenceau");
    m_TableNomStation.push_back("Concorde");
    m_TableNomStation.push_back("Tuileries");
    m_TableNomStation.push_back("Palais Royal - Musée Du Louvre");
    m_TableNomStation.push_back("Louvre - Rivoli");
    m_TableNomStation.push_back("Châtelet");
    m_TableNomStation.push_back("Hôtel De Ville");
    m_TableNomStation.push_back("Saint-Paul");
    m_TableNomStation.push_back("Bastille");
    m_TableNomStation.push_back("Gare De Lyon");
    m_TableNomStation.push_back("Reuilly - Diderot");
    m_TableNomStation.push_back("Nation");
    m_TableNomStation.push_back("Porte De Vincennes");
    m_TableNomStation.push_back("Saint-Mandé");
    m_TableNomStation.push_back("Bérault");
    m_TableNomStation.push_back("Château De Vincennes");

    //Ligne 2

    m_TableNomStation.push_back("Porte Dauphine");
    m_TableNomStation.push_back("Victor Hugo");
    //***//
    m_TableNomStation.push_back("Ternes");
    m_TableNomStation.push_back("Courcelles");
    m_TableNomStation.push_back("Monceau");
    m_TableNomStation.push_back("Villiers");
    m_TableNomStation.push_back("Rome");
    m_TableNomStation.push_back("Place De Clichy");
    m_TableNomStation.push_back("Blanche");
    m_TableNomStation.push_back("Pigalle");
    m_TableNomStation.push_back("Anvers");
    m_TableNomStation.push_back("Barbès - Rochechouart");
    m_TableNomStation.push_back("La Chapelle");
    m_TableNomStation.push_back("Stalingrad");
    m_TableNomStation.push_back("Jaurès");
    m_TableNomStation.push_back("Colonel Fabien");
    m_TableNomStation.push_back("Belleville");
    m_TableNomStation.push_back("Couronnes");
    m_TableNomStation.push_back("Ménilmontant");
    m_TableNomStation.push_back("Père Lachaise");
    m_TableNomStation.push_back("Philippe Auguste");
    m_TableNomStation.push_back("Alexandre Dumas");
    m_TableNomStation.push_back("Avron");
    //***//

    //Ligne 3

    m_TableNomStation.push_back("Pont De Levallois - Bécon");
    m_TableNomStation.push_back("Anatole France");
    m_TableNomStation.push_back("Louise Michel");
    m_TableNomStation.push_back("Porte De Champerret");
    m_TableNomStation.push_back("Pereire");
    m_TableNomStation.push_back("Wagram");
    m_TableNomStation.push_back("Malesherbes");
    //***//
    m_TableNomStation.push_back("Europe");
    m_TableNomStation.push_back("Saint-Lazare");
    m_TableNomStation.push_back("Havre - Caumartain");
    m_TableNomStation.push_back("Opéra");
    m_TableNomStation.push_back("Quatre-Septembre");
    m_TableNomStation.push_back("Bourse");
    m_TableNomStation.push_back("Sentier");
    m_TableNomStation.push_back("Réaumur - Sébastopol");
    m_TableNomStation.push_back("Arts Et Métiers");
    m_TableNomStation.push_back("Temple");
    m_TableNomStation.push_back("République");
    m_TableNomStation.push_back("Parmentier");
    m_TableNomStation.push_back("Rue Saint-Maur");
    //***//
    m_TableNomStation.push_back("Gambetta");
    m_TableNomStation.push_back("Porte De Bagnolet");
    m_TableNomStation.push_back("Gallieni");

    //Ligne 3bis

    //***//
    m_TableNomStation.push_back("Pelleport");
    m_TableNomStation.push_back("Saint-Fargeau");
    m_TableNomStation.push_back("Porte Des Lilas");

    //Ligne 4

    m_TableNomStation.push_back("Porte De Clignancourt");
    m_TableNomStation.push_back("Simplon");
    m_TableNomStation.push_back("Marcadet - Poissonniers");
    m_TableNomStation.push_back("Château Rouge");
    //***//
    m_TableNomStation.push_back("Gare Du Nord");
    m_TableNomStation.push_back("Gare De L'Est");
    m_TableNomStation.push_back("Château D'Eau");
    m_TableNomStation.push_back("Strasbourg - Saint-Denis");
    //***//
    m_TableNomStation.push_back("Etienne Marcel");
    m_TableNomStation.push_back("Les Halles");
    //***//
    m_TableNomStation.push_back("Cité");
    m_TableNomStation.push_back("Saint-Michel");
    m_TableNomStation.push_back("Odéon");
    m_TableNomStation.push_back("Saint-Germain-Des-Prés");
    m_TableNomStation.push_back("Saint-Sulpice");
    m_TableNomStation.push_back("Saint-Placide");
    m_TableNomStation.push_back("Montparnasse - Bienvenüe");
    m_TableNomStation.push_back("Vavin");
    m_TableNomStation.push_back("Raspail");
    m_TableNomStation.push_back("Denfert-Rochereau");
    m_TableNomStation.push_back("Mouton-Duvernet");
    m_TableNomStation.push_back("Alésia");
    m_TableNomStation.push_back("Porte D'Orléans");
    m_TableNomStation.push_back("Mairie De Montrouge");

    //Ligne 5

    m_TableNomStation.push_back("Bobigny - Pablo Picasso");
    m_TableNomStation.push_back("Bobigny - Pantin - Raymond Queneau");
    m_TableNomStation.push_back("Eglise De Pantin");
    m_TableNomStation.push_back("Hoche");
    m_TableNomStation.push_back("Porte De Pantin");
    m_TableNomStation.push_back("Ourcq");
    m_TableNomStation.push_back("Laumière");
    //***//
    //***//
    //***//
    //***//
    m_TableNomStation.push_back("Jacques Bonsergent");
    m_TableNomStation.push_back("Oberkampf");
    m_TableNomStation.push_back("Richard-Lenoir");
    m_TableNomStation.push_back("Bréguet - Sabin");
    //***//
    m_TableNomStation.push_back("Quai De La Rapée");
    m_TableNomStation.push_back("Gare D'Austerlitz");
    m_TableNomStation.push_back("Saint-Marcel");
    m_TableNomStation.push_back("Campo-Formio");
    m_TableNomStation.push_back("Place D'Italie");

    //Ligne 6

    //***//
    m_TableNomStation.push_back("Kléber");
    m_TableNomStation.push_back("Boissière");
    m_TableNomStation.push_back("Trocadéro");
    m_TableNomStation.push_back("Passy");
    m_TableNomStation.push_back("Bir-Hakeim");
    m_TableNomStation.push_back("Dupleix");
    m_TableNomStation.push_back("La Motte-Picquet - Grenelle");
    m_TableNomStation.push_back("Cambronne");
    m_TableNomStation.push_back("Sèvres - Lecourbe");
    m_TableNomStation.push_back("Pasteur");
    //***//
    m_TableNomStation.push_back("Edgar Quinet");
    //***//
    //***//
    m_TableNomStation.push_back("Saint-Jacques");
    m_TableNomStation.push_back("Glacière");
    m_TableNomStation.push_back("Corvisart");
    //***//
    m_TableNomStation.push_back("Nationale");
    m_TableNomStation.push_back("Chevaleret");
    m_TableNomStation.push_back("Quai De La Gare");
    m_TableNomStation.push_back("Bercy");
    m_TableNomStation.push_back("Dugommier");
    m_TableNomStation.push_back("Daumesnil");
    m_TableNomStation.push_back("Bel-Air");
    m_TableNomStation.push_back("Picpus");
    //***//

    //Ligne 7

    m_TableNomStation.push_back("La Courneuve - 8 Mai 1945");
    m_TableNomStation.push_back("Fort D'Aubervilliers");
    m_TableNomStation.push_back("Aubervilliers - Pantin - Quatre Chemins");
    m_TableNomStation.push_back("Porte De La Villette");
    m_TableNomStation.push_back("Corentin Cariou");
    m_TableNomStation.push_back("Crimée");
    m_TableNomStation.push_back("Riquet");
    //***//
    m_TableNomStation.push_back("Louis Blanc");
    m_TableNomStation.push_back("Château-Landon");
    //***//
    m_TableNomStation.push_back("Poissonnière");
    m_TableNomStation.push_back("Cadet");
    m_TableNomStation.push_back("Le Peletier");
    m_TableNomStation.push_back("Chaussée D'Antin - La Fayette");
    //***//
    m_TableNomStation.push_back("Pyramides");
    //***//
    m_TableNomStation.push_back("Pont Neuf");
    //***//
    m_TableNomStation.push_back("Pont Marie");
    m_TableNomStation.push_back("Sully - Morland");
    m_TableNomStation.push_back("Jussieu");
    m_TableNomStation.push_back("Place Monge");
    m_TableNomStation.push_back("Censier - Daubenton");
    m_TableNomStation.push_back("Les Gobelins");
    //***//
    m_TableNomStation.push_back("Tolbiac");
    m_TableNomStation.push_back("Maison Blanche");
    m_TableNomStation.push_back("Le Kremlin-Bicêtre");
    m_TableNomStation.push_back("Villejuif - Léo Lagrange");
    m_TableNomStation.push_back("Villejuif - Paul Vaillant-Couturier");
    m_TableNomStation.push_back("Villejuif - Louis Aragon");
    m_TableNomStation.push_back("Porte D'Italie");
    m_TableNomStation.push_back("Porte De Choisy");
    m_TableNomStation.push_back("Porte D'Ivry");
    m_TableNomStation.push_back("Pierre Et Marie Curie");
    m_TableNomStation.push_back("Mairie D'Ivry");

    //Ligne 7bis

    //***//
    //***//
    m_TableNomStation.push_back("Bolivar");
    m_TableNomStation.push_back("Buttes Chaumont");
    m_TableNomStation.push_back("Botzaris");
    m_TableNomStation.push_back("Danube");
    m_TableNomStation.push_back("Place Des Fêtes");
    m_TableNomStation.push_back("Pré Saint-Gervais");

    //Ligne 8

    m_TableNomStation.push_back("Balard");
    m_TableNomStation.push_back("Lourmel");
    m_TableNomStation.push_back("Boucicaut");
    m_TableNomStation.push_back("Félix Faure");
    m_TableNomStation.push_back("Commerce");
    //***//
    m_TableNomStation.push_back("Ecole Militaire");
    m_TableNomStation.push_back("La Tour-Maubourg");
    m_TableNomStation.push_back("Invalides");
    //***//
    m_TableNomStation.push_back("Madeleine");
    //***//
    m_TableNomStation.push_back("Richelieu - Drouot");
    m_TableNomStation.push_back("Grands Boulevards");
    m_TableNomStation.push_back("Bonne-Nouvelle");
    //***//
    //***//
    m_TableNomStation.push_back("Filles Du Calvaire");
    m_TableNomStation.push_back("Saint-Sébastien - Froissart");
    m_TableNomStation.push_back("Chemin Vert");
    //***//
    m_TableNomStation.push_back("Ledru-Rollin");
    m_TableNomStation.push_back("Faidherbe - Chaligny");
    //***//
    m_TableNomStation.push_back("Montgallet");
    //***//
    m_TableNomStation.push_back("Michel Bizot");
    m_TableNomStation.push_back("Porte Dorée");
    m_TableNomStation.push_back("Porte De Charenton");
    m_TableNomStation.push_back("Liberté");
    m_TableNomStation.push_back("Charenton - Ecoles");
    m_TableNomStation.push_back("Ecole Vétérinaire De Maisons-Alfort");
    m_TableNomStation.push_back("Maisons-Alfort - Stade");
    m_TableNomStation.push_back("Maisons-Alfort - Les Juillottes");
    m_TableNomStation.push_back("Créteil - L'Echat");
    m_TableNomStation.push_back("Créteil - Université");
    m_TableNomStation.push_back("Créteil - Préfecture");
    m_TableNomStation.push_back("Pointe Du Lac");

    //Ligne 9

    m_TableNomStation.push_back("Pont De Sèvres");
    m_TableNomStation.push_back("Billancourt");
    m_TableNomStation.push_back("Marcel Sembat");
    m_TableNomStation.push_back("Porte De Saint-Cloud");
    m_TableNomStation.push_back("Exelmans");
    m_TableNomStation.push_back("Michel-Ange - Molitor");
    m_TableNomStation.push_back("Michel-Ange - Auteuil");
    m_TableNomStation.push_back("Jasmin");
    m_TableNomStation.push_back("Ranelagh");
    m_TableNomStation.push_back("La Muette");
    m_TableNomStation.push_back("Rue De La Pompe");
    //***//
    m_TableNomStation.push_back("Iéna");
    m_TableNomStation.push_back("Alma - Marceau");
    //***//
    m_TableNomStation.push_back("Saint-Philippe Du Roule");
    m_TableNomStation.push_back("Miromesnil");
    m_TableNomStation.push_back("Saint-Augustin");
    //***//
    //***//
    //***//
    //***//
    //***//
    //***//
    //***//
    //***//
    m_TableNomStation.push_back("Saint-Ambroise");
    m_TableNomStation.push_back("Voltaire");
    m_TableNomStation.push_back("Charonne");
    m_TableNomStation.push_back("Rue Des Boulets");
    //***//
    m_TableNomStation.push_back("Buzenval");
    m_TableNomStation.push_back("Maraîchers");
    m_TableNomStation.push_back("Porte De Montreuil");
    m_TableNomStation.push_back("Robespierre");
    m_TableNomStation.push_back("Croix De Chavaux");
    m_TableNomStation.push_back("Mairie De Montreuil");

    //Ligne 10

   m_TableNomStation.push_back("Boulogne - Pont De Saint-Cloud");
   m_TableNomStation.push_back("Boulogne - Jean Jaurès");
   m_TableNomStation.push_back("Porte D'Auteuil");
   //***//
   //***//
   m_TableNomStation.push_back("Chardon-Lagache");
   m_TableNomStation.push_back("Eglise D'Auteuil");
   m_TableNomStation.push_back("Mirabeau");
   m_TableNomStation.push_back("Javel - André Citroën");
   m_TableNomStation.push_back("Charles Michels");
   m_TableNomStation.push_back("Avenue Emile-Zola");
   //***//
   m_TableNomStation.push_back("Ségur");
   m_TableNomStation.push_back("Duroc");
   m_TableNomStation.push_back("Vaneau");
   m_TableNomStation.push_back("Sèvres - Babylone");
   m_TableNomStation.push_back("Mabillon");
   //***//
   m_TableNomStation.push_back("Cluny - La Sorbonne");
   m_TableNomStation.push_back("Maubert - Mutualité");
   m_TableNomStation.push_back("Cardinal Lemoine");
   //***//
   //***//

   //Ligne 11

   //***//
   //***//
   m_TableNomStation.push_back("Rambuteau");
   //***//
   //***//
   m_TableNomStation.push_back("Goncourt");
   //***//
   m_TableNomStation.push_back("Pyrénées");
   m_TableNomStation.push_back("Jourdain");
   //***//
   m_TableNomStation.push_back("Télégraphe");
   //***//
   m_TableNomStation.push_back("Mairie Des Lilas");

   //Ligne 12

    m_TableNomStation.push_back("Saint-Denis - Aubervilliers Front Populaire");
    m_TableNomStation.push_back("Porte De La Chapelle");
    m_TableNomStation.push_back("Marx Dormoy");
    //***//
    m_TableNomStation.push_back("Jules Joffrin");
    m_TableNomStation.push_back("Lamarck - Caulaincourt");
    m_TableNomStation.push_back("Abbesses");
    //***//
    m_TableNomStation.push_back("Saint-Georges");
    m_TableNomStation.push_back("Notre-Dame-De-Lorette");
    m_TableNomStation.push_back("Trinité - D'Estienne D'Orves");
    //***//
    //***//
    //***//
    m_TableNomStation.push_back("Assemblée Nationale");
    m_TableNomStation.push_back("Solférino");
    m_TableNomStation.push_back("Rue Du Bac");
    //***//
    m_TableNomStation.push_back("Rennes");
    m_TableNomStation.push_back("Notre-Dame-Des-Champs");
    //***//
    m_TableNomStation.push_back("Falguière");
    //***//
    m_TableNomStation.push_back("Volontaires");
    m_TableNomStation.push_back("Vaugirard");
    m_TableNomStation.push_back("Convention");
    m_TableNomStation.push_back("Porte De Versailles");
    m_TableNomStation.push_back("Corentin Celton");
    m_TableNomStation.push_back("Mairie D'Issy");

    //Ligne 13

    m_TableNomStation.push_back("Asnières - Gennevilliers Les Courtilles");
    m_TableNomStation.push_back("Les Agnettes");
    m_TableNomStation.push_back("Gabriel Péri");
    m_TableNomStation.push_back("Mairie De Clichy");
    m_TableNomStation.push_back("Porte De Clichy");
    m_TableNomStation.push_back("Brochant");
    m_TableNomStation.push_back("Saint-Denis - Université");
    m_TableNomStation.push_back("Basilique De Saint-Denis");
    m_TableNomStation.push_back("Saint-Denis - Porte De Paris");
    m_TableNomStation.push_back("Carrefour Pleyel");
    m_TableNomStation.push_back("Mairie De Saint-Ouen");
    m_TableNomStation.push_back("Garibaldi");
    m_TableNomStation.push_back("Porte De Saint-Ouen");
    m_TableNomStation.push_back("Guy Môquet");
    m_TableNomStation.push_back("La Fourche");
    //***//
    m_TableNomStation.push_back("Liège");
    //***//
    //***//
    //***//
    //***//
    m_TableNomStation.push_back("Varenne");
    m_TableNomStation.push_back("Saint-François-Xavier");
    //***//
    //***//
    m_TableNomStation.push_back("Gaîté");
    m_TableNomStation.push_back("Pernety");
    m_TableNomStation.push_back("Plaisance");
    m_TableNomStation.push_back("Porte De Vanves");
    m_TableNomStation.push_back("Malakoff - Plateau De Vanves");
    m_TableNomStation.push_back("Malakoff - Rue Etienne-Dolet");
    m_TableNomStation.push_back("Châtillon - Montrouge");

    //Ligne 14

    //***//
    //***//
    //***//
    //***//
    //***//
    //***//
    m_TableNomStation.push_back("Cours Saint-Emilion");
    m_TableNomStation.push_back("Bibliothèque François-Mitterand");
    m_TableNomStation.push_back("Olympiades");


    // Codage Ligne Avec Direction

    m_TableNomLigne.push_back("Ligne 1 direction La Défense");
    m_TableCodeLigne.push_back(1.1);
    m_TableNomLigne.push_back("Ligne 1 direction Château De Vincennes");
    m_TableCodeLigne.push_back(1.2);

    m_TableNomLigne.push_back("Ligne 2 direction Porte Dauphine");
    m_TableCodeLigne.push_back(2.1);
    m_TableNomLigne.push_back("Ligne 2 direction Nation");
    m_TableCodeLigne.push_back(2.2);

    m_TableNomLigne.push_back("Ligne 3 direction Pont De Levallois - Bécon");
    m_TableCodeLigne.push_back(3.1);
    m_TableNomLigne.push_back("Ligne 3 direction Gallieni");
    m_TableCodeLigne.push_back(3.2);

    m_TableNomLigne.push_back("Ligne 3bis direction Porte Des Lilas");
    m_TableCodeLigne.push_back(3.3);
    m_TableNomLigne.push_back("Ligne 3bis direction Gambetta");
    m_TableCodeLigne.push_back(3.4);

    m_TableNomLigne.push_back("Ligne 4 direction Porte De Clignancourt");
    m_TableCodeLigne.push_back(4.1);
    m_TableNomLigne.push_back("Ligne 4 direction Mairie De Montrouge");
    m_TableCodeLigne.push_back(4.2);

    m_TableNomLigne.push_back("Ligne 5 direction Bobigny - Pablo Picasso");
    m_TableCodeLigne.push_back(5.1);
    m_TableNomLigne.push_back("Ligne 5 direction Place D'Italie");
    m_TableCodeLigne.push_back(5.2);

    m_TableNomLigne.push_back("Ligne 6 direction Charles De Gaulle - Etoile");
    m_TableCodeLigne.push_back(6.1);
    m_TableNomLigne.push_back("Ligne 6 direction Nation");
    m_TableCodeLigne.push_back(6.2);

    m_TableNomLigne.push_back("Ligne 7 direction La Courneuve - 8 Mai 1945");
    m_TableCodeLigne.push_back(7.1);
    m_TableNomLigne.push_back("Ligne 7 direction Villejuif - Louis Aragon");
    m_TableCodeLigne.push_back(7.2);
    m_TableNomLigne.push_back("Ligne 7 direction Mairie D'Ivry");
    m_TableCodeLigne.push_back(7.3);

    m_TableNomLigne.push_back("Ligne 7bis direction Pré Saint-Gervais");
    m_TableCodeLigne.push_back(7.4);
    m_TableNomLigne.push_back("Ligne 7bis direction Louis Blanc");
    m_TableCodeLigne.push_back(7.5);

    m_TableNomLigne.push_back("Ligne 8 direction Balard");
    m_TableCodeLigne.push_back(8.1);
    m_TableNomLigne.push_back("Ligne 8 direction Pointe Du Lac");
    m_TableCodeLigne.push_back(8.2);

    m_TableNomLigne.push_back("Ligne 9 direction Mairie De Montreuil");
    m_TableCodeLigne.push_back(9.1);
    m_TableNomLigne.push_back("Ligne 9 direction Pont De Sèvres");
    m_TableCodeLigne.push_back(9.2);

    m_TableNomLigne.push_back("Ligne 10 direction Boulogne - Pont De Saint-Cloud");
    m_TableCodeLigne.push_back(10.1);
    m_TableNomLigne.push_back("Ligne 10 direction Gare D'Austerlitz");
    m_TableCodeLigne.push_back(10.2);

    m_TableNomLigne.push_back("Ligne 11 direction Châtelet");
    m_TableCodeLigne.push_back(11.1);
    m_TableNomLigne.push_back("Ligne 11 direction Mairie Des Lilas");
    m_TableCodeLigne.push_back(11.2);

    m_TableNomLigne.push_back("Ligne 12 direction Front Populaire");
    m_TableCodeLigne.push_back(12.1);
    m_TableNomLigne.push_back("Ligne 12 direction Mairie D'Issy");
    m_TableCodeLigne.push_back(12.2);

    m_TableNomLigne.push_back("Ligne 13 direction Asnières - Gennevilliers Les Courtilles");
    m_TableCodeLigne.push_back(13.1);
    m_TableNomLigne.push_back("Ligne 13 direction Saint-Denis - Université");
    m_TableCodeLigne.push_back(13.2);
    m_TableNomLigne.push_back("Ligne 13 direction Châtillon - Montrouge");
    m_TableCodeLigne.push_back(13.3);

    m_TableNomLigne.push_back("Ligne 14 direction Saint-Lazare");
    m_TableCodeLigne.push_back(14.1);
    m_TableNomLigne.push_back("Ligne 14 direction Olympiades");
    m_TableCodeLigne.push_back(14.2);

}


QString reseauparis::TCSN(int CodeStation)
{
    return m_TableNomStation[CodeStation];
}

int reseauparis::TNSC(QString NomStation)
{
    int i = 0;
    while (m_TableNomStation[i].compare(NomStation) != 0)
    {
        i = i+1;
    }
    return i;
}

QString reseauparis::TCLN(double CodeLigne)
{
    int i = 0;
    while (m_TableCodeLigne[i] != CodeLigne)
    {
        i = i+1;
    }
    return m_TableNomLigne[i];
}

double reseauparis::TNLC(QString NomLigne)
{
    int i = 0;
    while (m_TableNomLigne[i] != NomLigne)
    {
        i = i+1;
    }
    return m_TableCodeLigne[i];
}

// fonctions permettant la construction du réseau

// en effet comme nous n'importons pas le xml //
// on a décidé d'importer a la main les données sur les stations afin de construire le reseau //
// nous déduirons les données sur les lignes par des fonctions //

void reseauparis::CreationReseauStation(void)
{
    //********************Ligne 1*************************//

    station N0(TNSC("La Défense"),48.891934,2.237883);
    N0.RTabLDS(1.1);
    N0.RTabLDS(1.2);
    N0.RTabSV(TNSC("Esplanade De La Défense"));
    m_ListeStation.push_back(N0);

    station N1(TNSC("Esplanade De La Défense"),48.887843,2.250442);
    N1.RTabLDS(1.1);
    N1.RTabLDS(1.2);
    N1.RTabSV(TNSC("La Défense"));
    N1.RTabSV(TNSC("Pont De Neuilly"));
    m_ListeStation.push_back(N1);

    station N2(TNSC("Pont De Neuilly"),48.884509,2.259892);
    N2.RTabLDS(1.1);
    N2.RTabLDS(1.2);
    N2.RTabSV(TNSC("Esplanade De La Défense"));
    N2.RTabSV(TNSC("Les Sablons"));
    m_ListeStation.push_back(N2);

    station N3(TNSC("Les Sablons"),48.880902,2.272539);
    N3.RTabLDS(1.1);
    N3.RTabLDS(1.2);
    N3.RTabSV(TNSC("Pont De Neuilly"));
    N3.RTabSV(TNSC("Porte Maillot"));
    m_ListeStation.push_back(N3);

    station N4(TNSC("Porte Maillot"),48.877965,2.281836);
    N4.RTabLDS(1.1);
    N4.RTabLDS(1.2);
    N4.RTabSV(TNSC("Les Sablons"));
    N4.RTabSV(TNSC("Argentine"));
    m_ListeStation.push_back(N4);

    station N5(TNSC("Argentine"),48.875533,2.289322);
    N5.RTabLDS(1.1);
    N5.RTabLDS(1.2);
    N5.RTabSV(TNSC("Porte Maillot"));
    N5.RTabSV(TNSC("Charles De Gaulle - Etoile"));
    m_ListeStation.push_back(N5);

    station N6(TNSC("Charles De Gaulle - Etoile"),48.874408,2.295763);
    N6.RTabLDS(1.1);
    N6.RTabLDS(1.2);
    N6.RTabLDS(2.1);
    N6.RTabLDS(2.2);
    N6.RTabLDS(6.1);
    N6.RTabLDS(6.2);
    N6.RTabSV(TNSC("Argentine"));
    N6.RTabSV(TNSC("George V"));
    N6.RTabSV(TNSC("Ternes"));
    N6.RTabSV(TNSC("Victor Hugo"));
    N6.RTabSV(TNSC("Kléber"));
    m_ListeStation.push_back(N6);

    station N7(TNSC("George V"),48.871983,2.300463);
    N7.RTabLDS(1.1);
    N7.RTabLDS(1.2);
    N7.RTabSV(TNSC("Charles De Gaulle - Etoile"));
    N7.RTabSV(TNSC("Franklin D. Roosevelt"));
    m_ListeStation.push_back(N7);

    station N8(TNSC("Franklin D. Roosevelt"),48.869305,2.308309);
    N8.RTabLDS(1.1);
    N8.RTabLDS(1.2);
    N8.RTabLDS(9.1);
    N8.RTabLDS(9.2);
    N8.RTabSV(TNSC("George V"));
    N8.RTabSV(TNSC("Champs-Elysées - Clemenceau"));
    N8.RTabSV(TNSC("Alma - Marceau"));
    N8.RTabSV(TNSC("Saint-Philippe Du Roule"));
    m_ListeStation.push_back(N8);

    station N9(TNSC("Champs-Elysées - Clemenceau"),48.867411,2.313959);
    N9.RTabLDS(1.1);
    N9.RTabLDS(1.2);
    N9.RTabLDS(13.1);
    N9.RTabLDS(13.2);
    N9.RTabLDS(13.3);
    N9.RTabSV(TNSC("Franklin D. Roosevelt"));
    N9.RTabSV(TNSC("Concorde"));
    N9.RTabSV(TNSC("Invalides"));
    N9.RTabSV(TNSC("Miromesnil"));
    m_ListeStation.push_back(N9);

    station N10(TNSC("Concorde"),48.866176,2.322397);
    N10.RTabLDS(1.1);
    N10.RTabLDS(1.2);
    N10.RTabLDS(12.1);
    N10.RTabLDS(12.2);
    N10.RTabLDS(8.1);
    N10.RTabLDS(8.2);
    N10.RTabSV(TNSC("Champs-Elysées - Clemenceau"));
    N10.RTabSV(TNSC("Tuileries"));
    N10.RTabSV(TNSC("Madeleine"));
    N10.RTabSV(TNSC("Invalides"));
    N10.RTabSV(TNSC("Assemblée Nationale"));
    m_ListeStation.push_back(N10);


    station N11(TNSC("Tuileries"),48.864497,2.330314);
    N11.RTabLDS(1.1);
    N11.RTabLDS(1.2);
    N11.RTabSV(TNSC("Concorde"));
    N11.RTabSV(TNSC("Palais Royal - Musée Du Louvre"));
    m_ListeStation.push_back(N11);

    station N12(TNSC("Palais Royal - Musée Du Louvre"),48.862847,2.335817);
    N12.RTabLDS(1.1);
    N12.RTabLDS(1.2);
    N12.RTabLDS(7.1);
    N12.RTabLDS(7.2);
    N12.RTabLDS(7.3);
    N12.RTabSV(TNSC("Tuileries"));
    N12.RTabSV(TNSC("Louvre - Rivoli"));
    N12.RTabSV(TNSC("Pyramides"));
    N12.RTabSV(TNSC("Pont Neuf"));
    m_ListeStation.push_back(N12);

    station N13(TNSC("Louvre - Rivoli"),48.86108,2.340283);
    N13.RTabLDS(1.1);
    N13.RTabLDS(1.2);
    N13.RTabSV(TNSC("Palais Royal - Musée Du Louvre"));
    N13.RTabSV(TNSC("Châtelet"));
    m_ListeStation.push_back(N13);

    station N14(TNSC("Châtelet"),48.858352,2.347324);
    N14.RTabLDS(1.1);
    N14.RTabLDS(1.2);
    N14.RTabLDS(4.1);
    N14.RTabLDS(4.2);
    N14.RTabLDS(7.1);
    N14.RTabLDS(7.2);
    N14.RTabLDS(7.3);
    N14.RTabLDS(11.1);
    N14.RTabLDS(11.2);
    N14.RTabLDS(14.1);
    N14.RTabLDS(14.2);
    N14.RTabSV(TNSC("Louvre - Rivoli"));
    N14.RTabSV(TNSC("Hôtel De Ville"));
    N14.RTabSV(TNSC("Les Halles"));
    N14.RTabSV(TNSC("Cité"));
    N14.RTabSV(TNSC("Pont Neuf"));
    N14.RTabSV(TNSC("Pont Marie"));
    N14.RTabSV(TNSC("Pyramides"));
    N14.RTabSV(TNSC("Gare De Lyon"));
    m_ListeStation.push_back(N14);

    station N15(TNSC("Hôtel De Ville"),48.85677,2.351495);
    N15.RTabLDS(1.1);
    N15.RTabLDS(1.2);
    N15.RTabLDS(11.1);
    N15.RTabLDS(11.2);
    N15.RTabSV(TNSC("Châtelet"));
    N15.RTabSV(TNSC("Saint-Paul"));
    N15.RTabSV(TNSC("Rambuteau"));
    m_ListeStation.push_back(N15);

    station N16(TNSC("Saint-Paul"),48.855144,2.360653);
    N16.RTabLDS(1.1);
    N16.RTabLDS(1.2);
    N16.RTabSV(TNSC("Hôtel De Ville"));
    N16.RTabSV(TNSC("Bastille"));
    m_ListeStation.push_back(N16);


    station N17(TNSC("Bastille"),48.853082,2.369077);
    N17.RTabLDS(1.1);
    N17.RTabLDS(1.2);
    N17.RTabLDS(5.1);
    N17.RTabLDS(5.2);
    N17.RTabLDS(8.1);
    N17.RTabLDS(8.2);
    N17.RTabSV(TNSC("Saint-Paul"));
    N17.RTabSV(TNSC("Gare De Lyon"));
    N17.RTabSV(TNSC("Quai De La Rapée"));
    N17.RTabSV(TNSC("Bréguet - Sabin"));
    N17.RTabSV(TNSC("Chemin Vert"));
    N17.RTabSV(TNSC("Ledru-Rollin"));
    m_ListeStation.push_back(N17);


    station N18(TNSC("Gare De Lyon"),48.844728,2.373929);
    N18.RTabLDS(1.1);
    N18.RTabLDS(1.2);
    N18.RTabLDS(14.1);
    N18.RTabLDS(14.2);
    N18.RTabSV(TNSC("Bastille"));
    N18.RTabSV(TNSC("Reuilly - Diderot"));
    N18.RTabSV(TNSC("Châtelet"));
    N18.RTabSV(TNSC("Bercy"));
    m_ListeStation.push_back(N18);

    station N19(TNSC("Reuilly - Diderot"),48.847265,2.386702);
    N19.RTabLDS(1.1);
    N19.RTabLDS(1.2);
    N19.RTabLDS(8.1);
    N19.RTabLDS(8.2);
    N19.RTabSV(TNSC("Gare De Lyon"));
    N19.RTabSV(TNSC("Nation"));
    N19.RTabSV(TNSC("Faidherbe - Chaligny"));
    N19.RTabSV(TNSC("Montgallet"));
    m_ListeStation.push_back(N19);

    station N20(TNSC("Nation"),48.848466,2.395906);
    N20.RTabLDS(1.1);
    N20.RTabLDS(1.2);
    N20.RTabLDS(2.1);
    N20.RTabLDS(2.2);
    N20.RTabLDS(6.1);
    N20.RTabLDS(6.2);
    N20.RTabLDS(9.1);
    N20.RTabLDS(9.2);
    N20.RTabSV(TNSC("Reuilly - Diderot"));
    N20.RTabSV(TNSC("Porte De Vincennes"));
    N20.RTabSV(TNSC("Avron"));
    N20.RTabSV(TNSC("Picpus"));
    N20.RTabSV(TNSC("Rue Des Boulets"));
    N20.RTabSV(TNSC("Buzenval"));
    m_ListeStation.push_back(N20);

    station N21(TNSC("Porte De Vincennes"),48.847266,2.408884);
    N21.RTabLDS(1.1);
    N21.RTabLDS(1.2);
    N21.RTabSV(TNSC("Nation"));
    N21.RTabSV(TNSC("Saint-Mandé"));
    m_ListeStation.push_back(N21);

    station N22(TNSC("Saint-Mandé"),48.846298,2.418673);
    N22.RTabLDS(1.1);
    N22.RTabLDS(1.2);
    N22.RTabSV(TNSC("Porte De Vincennes"));
    N22.RTabSV(TNSC("Bérault"));
    m_ListeStation.push_back(N22);

    station N23(TNSC("Bérault"),48.845334,2.429238);
    N23.RTabLDS(1.1);
    N23.RTabLDS(1.2);
    N23.RTabSV(TNSC("Saint-Mandé"));
    N23.RTabSV(TNSC("Château De Vincennes"));
    m_ListeStation.push_back(N23);

    station N24(TNSC("Château De Vincennes"),48.844536,2.43951);
    N24.RTabLDS(1.1);
    N24.RTabLDS(1.2);
    N24.RTabSV(TNSC("Bérault"));
    m_ListeStation.push_back(N24);

    //********************Fin Ligne 1*************************//

    //********************Ligne 2*************************//

    station N25(TNSC("Porte Dauphine"),48.871545,2.276768);
    N25.RTabLDS(2.1);
    N25.RTabLDS(2.2);
    N25.RTabSV(TNSC("Victor Hugo"));
    m_ListeStation.push_back(N25);

    station N26(TNSC("Victor Hugo"),48.869817,2.285199);
    N26.RTabLDS(2.1);
    N26.RTabLDS(2.2);
    N26.RTabSV(TNSC("Porte Dauphine"));
    N26.RTabSV(TNSC("Charles De Gaulle - Etoile"));
    m_ListeStation.push_back(N26);

    //***//

    station N27(TNSC("Ternes"),48.878178,2.298671);
    N27.RTabLDS(2.1);
    N27.RTabLDS(2.2);
    N27.RTabSV(TNSC("Courcelles"));
    N27.RTabSV(TNSC("Charles De Gaulle - Etoile"));
    m_ListeStation.push_back(N27);

    station N28(TNSC("Courcelles"),48.879401,2.304339);
    N28.RTabLDS(2.1);
    N28.RTabLDS(2.2);
    N28.RTabSV(TNSC("Ternes"));
    N28.RTabSV(TNSC("Monceau"));
    m_ListeStation.push_back(N28);

    station N29(TNSC("Monceau"),48.880319,2.308603);
    N29.RTabLDS(2.1);
    N29.RTabLDS(2.2);
    N29.RTabSV(TNSC("Courcelles"));
    N29.RTabSV(TNSC("Villiers"));
    m_ListeStation.push_back(N29);

    station N30(TNSC("Villiers"),48.88113,2.314867);
    N30.RTabLDS(2.1);
    N30.RTabLDS(2.2);
    N30.RTabLDS(3.1);
    N30.RTabLDS(3.2);
    N30.RTabSV(TNSC("Rome"));
    N30.RTabSV(TNSC("Monceau"));
    N30.RTabSV(TNSC("Malesherbes"));
    N30.RTabSV(TNSC("Europe"));
    m_ListeStation.push_back(N30);

    station N31(TNSC("Rome"),48.882425,2.322052);
    N31.RTabLDS(2.1);
    N31.RTabLDS(2.2);
    N31.RTabSV(TNSC("Villiers"));
    N31.RTabSV(TNSC("Place De Clichy"));
    m_ListeStation.push_back(N31);


    station N32(TNSC("Place De Clichy"),48.883809,2.327625);
    N32.RTabLDS(2.1);
    N32.RTabLDS(2.2);
    N32.RTabLDS(13.1);
    N32.RTabLDS(13.2);
    N32.RTabLDS(13.3);
    N32.RTabSV(TNSC("Rome"));
    N32.RTabSV(TNSC("Blanche"));
    N32.RTabSV(TNSC("La Fourche"));
    N32.RTabSV(TNSC("Liège"));
    m_ListeStation.push_back(N32);

    station N33(TNSC("Blanche"),48.883459,2.333703);
    N33.RTabLDS(2.1);
    N33.RTabLDS(2.2);
    N33.RTabSV(TNSC("Place De Clichy"));
    N33.RTabSV(TNSC("Pigalle"));
    m_ListeStation.push_back(N33);

    station N34(TNSC("Pigalle"),48.882255,2.337573);
    N34.RTabLDS(2.1);
    N34.RTabLDS(2.2);
    N34.RTabLDS(12.1);
    N34.RTabLDS(12.2);
    N34.RTabSV(TNSC("Blanche"));
    N34.RTabSV(TNSC("Anvers"));
    N34.RTabSV(TNSC("Abbesses"));
    N34.RTabSV(TNSC("Saint-Georges"));
    m_ListeStation.push_back(N34);

    station N35(TNSC("Anvers"),48.883007,2.344849);
    N35.RTabLDS(2.1);
    N35.RTabLDS(2.2);
    N35.RTabSV(TNSC("Pigalle"));
    N35.RTabSV(TNSC("Barbès - Rochechouart"));
    m_ListeStation.push_back(N35);

    station N36(TNSC("Barbès - Rochechouart"),48.88364,2.350516);
    N36.RTabLDS(2.1);
    N36.RTabLDS(2.2);
    N36.RTabLDS(4.1);
    N36.RTabLDS(4.2);
    N36.RTabSV(TNSC("La Chapelle"));
    N36.RTabSV(TNSC("Anvers"));
    N36.RTabSV(TNSC("Château Rouge"));
    N36.RTabSV(TNSC("Gare Du Nord"));
    m_ListeStation.push_back(N36);

    station N37(TNSC("La Chapelle"),48.884411,2.360288);
    N37.RTabLDS(2.1);
    N37.RTabLDS(2.2);
    N37.RTabSV(TNSC("Barbès - Rochechouart"));
    N37.RTabSV(TNSC("Stalingrad"));
    m_ListeStation.push_back(N37);

    station N38(TNSC("Stalingrad"),48.884263,2.365824);
    N38.RTabLDS(2.1);
    N38.RTabLDS(2.2);
    N38.RTabLDS(5.1);
    N38.RTabLDS(5.2);
    N38.RTabLDS(7.1);
    N38.RTabLDS(7.2);
    N38.RTabLDS(7.3);
    N38.RTabSV(TNSC("La Chapelle"));
    N38.RTabSV(TNSC("Jaurès"));
    N38.RTabSV(TNSC("Gare Du Nord"));
    N38.RTabSV(TNSC("Riquet"));
    N38.RTabSV(TNSC("Louis Blanc"));
    m_ListeStation.push_back(N38);


    station N39(TNSC("Jaurès"),48.88179,2.370198);
    N39.RTabLDS(2.1);
    N39.RTabLDS(2.2);
    N39.RTabLDS(5.1);
    N39.RTabLDS(5.2);
    N39.RTabLDS(7.4);
    N39.RTabLDS(7.5);
    N39.RTabSV(TNSC("Stalingrad"));
    N39.RTabSV(TNSC("Laumière"));
    N39.RTabSV(TNSC("Colonel Fabien"));
    N39.RTabSV(TNSC("Louis Blanc"));
    N39.RTabSV(TNSC("Bolivar"));
    m_ListeStation.push_back(N39);

    station N40(TNSC("Colonel Fabien"),48.877136,2.37116);
    N40.RTabLDS(2.1);
    N40.RTabLDS(2.2);
    N40.RTabSV(TNSC("Jaurès"));
    N40.RTabSV(TNSC("Belleville"));
    m_ListeStation.push_back(N40);

    station N41(TNSC("Belleville"),48.872083,2.376947);
    N41.RTabLDS(2.1);
    N41.RTabLDS(2.2);
    N41.RTabLDS(11.1);
    N41.RTabLDS(11.2);
    N41.RTabSV(TNSC("Colonel Fabien"));
    N41.RTabSV(TNSC("Couronnes"));
    N41.RTabSV(TNSC("Goncourt"));
    N41.RTabSV(TNSC("Pyrénées"));
    m_ListeStation.push_back(N41);

    station N42(TNSC("Couronnes"),48.869521,2.379861);
    N42.RTabLDS(2.1);
    N42.RTabLDS(2.2);
    N42.RTabSV(TNSC("Belleville"));
    N42.RTabSV(TNSC("Ménilmontant"));
    m_ListeStation.push_back(N42);

    station N43(TNSC("Ménilmontant"),48.866248,2.383618);
    N43.RTabLDS(2.1);
    N43.RTabLDS(2.2);
    N43.RTabSV(TNSC("Couronnes"));
    N43.RTabSV(TNSC("Père Lachaise"));
    m_ListeStation.push_back(N43);

    station N44(TNSC("Père Lachaise"),48.862921,2.387388);
    N44.RTabLDS(2.1);
    N44.RTabLDS(2.2);
    N44.RTabLDS(3.1);
    N44.RTabLDS(3.2);
    N44.RTabSV(TNSC("Ménilmontant"));
    N44.RTabSV(TNSC("Philippe Auguste"));
    N44.RTabSV(TNSC("Rue Saint-Maur"));
    N44.RTabSV(TNSC("Gambetta"));
    m_ListeStation.push_back(N44);

    station N45(TNSC("Philippe Auguste"),48.858021,2.390938);
    N45.RTabLDS(2.1);
    N45.RTabLDS(2.2);
    N45.RTabSV(TNSC("Père Lachaise"));
    N45.RTabSV(TNSC("Alexandre Dumas"));
    m_ListeStation.push_back(N45);


    station N46(TNSC("Alexandre Dumas"),48.856174,2.39499);
    N46.RTabLDS(2.1);
    N46.RTabLDS(2.2);
    N46.RTabSV(TNSC("Philippe Auguste"));
    N46.RTabSV(TNSC("Avron"));
    m_ListeStation.push_back(N46);

    station N47(TNSC("Avron"),48.85194,2.397863);
    N47.RTabLDS(2.1);
    N47.RTabLDS(2.2);
    N47.RTabSV(TNSC("Alexandre Dumas"));
    N47.RTabSV(TNSC("Nation"));
    m_ListeStation.push_back(N47);

    //***//

    //********************Fin Ligne 2*************************//

    //********************Ligne 3*************************//

    station N48(TNSC("Pont De Levallois - Bécon"),48.897313,2.280787);
    N48.RTabLDS(3.1);
    N48.RTabLDS(3.2);
    N48.RTabSV(TNSC("Anatole France"));
    m_ListeStation.push_back(N48);

    station N49(TNSC("Anatole France"),48.892022,2.285536);
    N49.RTabLDS(3.1);
    N49.RTabLDS(3.2);
    N49.RTabSV(TNSC("Louise Michel"));
    N49.RTabSV(TNSC("Pont De Levallois - Bécon"));
    m_ListeStation.push_back(N49);

    station N50(TNSC("Louise Michel"),48.889273,2.288073);
    N50.RTabLDS(3.1);
    N50.RTabLDS(3.2);
    N50.RTabSV(TNSC("Anatole France"));
    N50.RTabSV(TNSC("Porte De Champerret"));
    m_ListeStation.push_back(N50);

    station N51(TNSC("Porte De Champerret"),48.885851,2.293487);
    N51.RTabLDS(3.1);
    N51.RTabLDS(3.2);
    N51.RTabSV(TNSC("Louise Michel"));
    N51.RTabSV(TNSC("Pereire"));
    m_ListeStation.push_back(N51);

    station N52(TNSC("Pereire"),48.884648,2.299211);
    N52.RTabLDS(3.1);
    N52.RTabLDS(3.2);
    N52.RTabSV(TNSC("Wagram"));
    N52.RTabSV(TNSC("Porte De Champerret"));
    m_ListeStation.push_back(N52);

    station N53(TNSC("Wagram"),48.884057,2.303668);
    N53.RTabLDS(3.1);
    N53.RTabLDS(3.2);
    N53.RTabSV(TNSC("Malesherbes"));
    N53.RTabSV(TNSC("Pereire"));
    m_ListeStation.push_back(N53);

    station N54(TNSC("Malesherbes"),48.882476,2.311002);
    N54.RTabLDS(3.1);
    N54.RTabLDS(3.2);
    N54.RTabSV(TNSC("Wagram"));
    N54.RTabSV(TNSC("Villiers"));
    m_ListeStation.push_back(N54);

    //***//

    station N55(TNSC("Europe"),48.878821,2.32238);
    N55.RTabLDS(3.1);
    N55.RTabLDS(3.2);
    N55.RTabSV(TNSC("Saint-Lazare"));
    N55.RTabSV(TNSC("Villiers"));
    m_ListeStation.push_back(N55);

    station N56(TNSC("Saint-Lazare"),48.875477,2.326001);
    N56.RTabLDS(3.1);
    N56.RTabLDS(3.2);
    N56.RTabLDS(12.1);
    N56.RTabLDS(12.2);
    N56.RTabLDS(13.1);
    N56.RTabLDS(13.2);
    N56.RTabLDS(14.1);
    N56.RTabLDS(14.2);
    N56.RTabSV(TNSC("Europe"));
    N56.RTabSV(TNSC("Havre - Caumartain"));
    N56.RTabSV(TNSC("Trinité - D'Estienne D'Orves"));
    N56.RTabSV(TNSC("Madeleine"));
    N56.RTabSV(TNSC("Liège"));
    N56.RTabSV(TNSC("Miromesnil"));
    m_ListeStation.push_back(N56);

    station N57(TNSC("Havre - Caumartain"),48.873465,2.327968);
    N57.RTabLDS(3.1);
    N57.RTabLDS(3.2);
    N57.RTabLDS(9.1);
    N57.RTabLDS(9.2);
    N57.RTabSV(TNSC("Saint-Lazare"));
    N57.RTabSV(TNSC("Opéra"));
    N57.RTabSV(TNSC("Saint-Augustin"));
    N57.RTabSV(TNSC("Chaussée D'Antin - La Fayette"));
    m_ListeStation.push_back(N57);

    station N58(TNSC("Opéra"),48.870636,2.332352);
    N58.RTabLDS(3.1);
    N58.RTabLDS(3.2);
    N58.RTabLDS(7.1);
    N58.RTabLDS(7.2);
    N58.RTabLDS(7.3);
    N58.RTabLDS(8.1);
    N58.RTabLDS(8.2);
    N58.RTabSV(TNSC("Havre - Caumartain"));
    N58.RTabSV(TNSC("Quatre-Septembre"));
    N58.RTabSV(TNSC("Chaussée D'Antin - La Fayette"));
    N58.RTabSV(TNSC("Pyramides"));
    N58.RTabSV(TNSC("Madeleine"));
    N58.RTabSV(TNSC("Richelieu - Drouot"));
    m_ListeStation.push_back(N58);

    station N59(TNSC("Quatre-Septembre"),48.869574,2.336633);
    N59.RTabLDS(3.1);
    N59.RTabLDS(3.2);
    N59.RTabSV(TNSC("Opéra"));
    N59.RTabSV(TNSC("Bourse"));
    m_ListeStation.push_back(N59);

    station N60(TNSC("Bourse"),48.868738,2.34137);
    N60.RTabLDS(3.1);
    N60.RTabLDS(3.2);
    N60.RTabSV(TNSC("Quatre-Septembre"));
    N60.RTabSV(TNSC("Sentier"));
    m_ListeStation.push_back(N60);

    station N61(TNSC("Sentier"),48.867569,2.346387);
    N61.RTabLDS(3.1);
    N61.RTabLDS(3.2);
    N61.RTabSV(TNSC("Bourse"));
    N61.RTabSV(TNSC("Réaumur - Sébastopol"));
    m_ListeStation.push_back(N61);

    station N62(TNSC("Réaumur - Sébastopol"),48.866246,2.352389);
    N62.RTabLDS(3.1);
    N62.RTabLDS(3.2);
    N62.RTabLDS(4.1);
    N62.RTabLDS(4.2);
    N62.RTabSV(TNSC("Sentier"));
    N62.RTabSV(TNSC("Arts Et Métiers"));
    N62.RTabSV(TNSC("Strasbourg - Saint-Denis"));
    N62.RTabSV(TNSC("Etienne Marcel"));
    m_ListeStation.push_back(N62);

    station N63(TNSC("Arts Et Métiers"),48.8655,2.3561);
    N63.RTabLDS(3.1);
    N63.RTabLDS(3.2);
    N63.RTabSV(TNSC("Réaumur - Sébastopol"));
    N63.RTabSV(TNSC("Temple"));
    N63.RTabSV(TNSC("Rambuteau"));
    N63.RTabSV(TNSC("République"));
    m_ListeStation.push_back(N63);

    station N64(TNSC("Temple"),48.866488,2.360595);
    N64.RTabLDS(3.1);
    N64.RTabLDS(3.2);
    N64.RTabSV(TNSC("Arts Et Métiers"));
    N64.RTabSV(TNSC("République"));
    m_ListeStation.push_back(N64);

    station N65(TNSC("République"),48.867503,2.363811);
    N65.RTabLDS(3.1);
    N65.RTabLDS(3.2);
    N65.RTabLDS(5.1);
    N65.RTabLDS(5.2);
    N65.RTabLDS(8.1);
    N65.RTabLDS(8.2);
    N65.RTabLDS(9.1);
    N65.RTabLDS(9.2);
    N65.RTabLDS(11.1);
    N65.RTabLDS(11.2);
    N65.RTabSV(TNSC("Parmentier"));
    N65.RTabSV(TNSC("Temple"));
    N65.RTabSV(TNSC("Jacques Bonsergent"));
    N65.RTabSV(TNSC("Oberkampf"));
    N65.RTabSV(TNSC("Strasbourg - Saint-Denis"));
    N65.RTabSV(TNSC("Filles Du Calvaire"));
    N65.RTabSV(TNSC("Arts Et Métiers"));
    N65.RTabSV(TNSC("Goncourt"));
    m_ListeStation.push_back(N65);

    station N66(TNSC("Parmentier"),48.865299,2.374381);
    N66.RTabLDS(3.1);
    N66.RTabLDS(3.2);
    N66.RTabSV(TNSC("Rue Saint-Maur"));
    N66.RTabSV(TNSC("République"));
    m_ListeStation.push_back(N66);

    station N67(TNSC("Rue Saint-Maur"),48.864335,2.379448);
    N67.RTabLDS(3.1);
    N67.RTabLDS(3.2);
    N67.RTabSV(TNSC("Parmentier"));
    N67.RTabSV(TNSC("Père Lachaise"));
    m_ListeStation.push_back(N67);

    //***//

    station N68(TNSC("Gambetta"),48.864947,2.398451);
    N68.RTabLDS(3.1);
    N68.RTabLDS(3.2);
    N68.RTabLDS(3.3);
    N68.RTabLDS(3.4);
    N68.RTabSV(TNSC("Porte De Bagnolet"));
    N68.RTabSV(TNSC("Père Lachaise"));
    N68.RTabSV(TNSC("Pelleport"));
    m_ListeStation.push_back(N68);

    station N69(TNSC("Porte De Bagnolet"),48.864565,2.407278);
    N69.RTabLDS(3.1);
    N69.RTabLDS(3.2);
    N69.RTabSV(TNSC("Gambetta"));
    N69.RTabSV(TNSC("Gallieni"));
    m_ListeStation.push_back(N69);

    station N70(TNSC("Gallieni"),48.864936,2.416637);
    N70.RTabLDS(3.1);
    N70.RTabLDS(3.2);
    N70.RTabSV(TNSC("Porte De Bagnolet"));
    m_ListeStation.push_back(N70);

    //********************Fin Ligne 3*************************//

    //********************Ligne 3bis*************************//

    //***//

    station N71(TNSC("Pelleport"),48.868671,2.401752);
    N71.RTabLDS(3.3);
    N71.RTabLDS(3.4);
    N71.RTabSV(TNSC("Gambetta"));
    N71.RTabSV(TNSC("Saint-Fargeau"));
    m_ListeStation.push_back(N71);

    station N72(TNSC("Saint-Fargeau"),48.872083,2.40452);
    N72.RTabLDS(3.3);
    N72.RTabLDS(3.4);
    N72.RTabSV(TNSC("Pelleport"));
    N72.RTabSV(TNSC("Porte Des Lilas"));
    m_ListeStation.push_back(N72);

    station N73(TNSC("Porte Des Lilas"),48.877183,2.406655);
    N73.RTabLDS(3.3);
    N73.RTabLDS(3.4);
    N73.RTabLDS(11.1);
    N73.RTabLDS(11.2);
    N73.RTabSV(TNSC("Télégraphe"));
    N73.RTabSV(TNSC("Mairie Des Lilas"));
    N73.RTabSV(TNSC("Saint-Fargeau"));
    m_ListeStation.push_back(N73);

    //********************Fin Ligne 3bis*************************//

    //********************Ligne 4*************************//

    station N74(TNSC("Porte De Clignancourt"),48.897287,2.344779);
    N74.RTabLDS(4.1);
    N74.RTabLDS(4.2);
    N74.RTabSV(TNSC("Simplon"));
    m_ListeStation.push_back(N74);

    station N75(TNSC("Simplon"),48.894633,2.347091);
    N75.RTabLDS(4.1);
    N75.RTabLDS(4.2);
    N75.RTabSV(TNSC("Porte De Clignancourt"));
    N75.RTabSV(TNSC("Marcadet - Poissonniers"));
    m_ListeStation.push_back(N75);

    station N76(TNSC("Marcadet - Poissonniers"),48.89151,2.34961);
    N76.RTabLDS(4.1);
    N76.RTabLDS(4.2);
    N76.RTabLDS(12.1);
    N76.RTabLDS(12.2);
    N76.RTabSV(TNSC("Simplon"));
    N76.RTabSV(TNSC("Château Rouge"));
    N76.RTabSV(TNSC("Marx Dormoy"));
    N76.RTabSV(TNSC("Jules Joffrin"));
    m_ListeStation.push_back(N76);

    station N77(TNSC("Château Rouge"),48.88716,2.34948);
    N77.RTabLDS(4.1);
    N77.RTabLDS(4.2);
    N77.RTabSV(TNSC("Barbès - Rochechouart"));
    N77.RTabSV(TNSC("Marcadet - Poissonniers"));
    m_ListeStation.push_back(N77);

    //***//

    station N78(TNSC("Gare Du Nord"),48.88036,2.35497);
    N78.RTabLDS(4.1);
    N78.RTabLDS(4.2);
    N78.RTabLDS(5.1);
    N78.RTabLDS(5.2);
    N78.RTabSV(TNSC("Barbès - Rochechouart"));
    N78.RTabSV(TNSC("Gare De L'Est"));
    N78.RTabSV(TNSC("Stalingrad"));
    m_ListeStation.push_back(N78);

    station N79(TNSC("Gare De L'Est"),48.8761,2.35793);
    N79.RTabLDS(4.1);
    N79.RTabLDS(4.2);
    N79.RTabLDS(5.1);
    N79.RTabLDS(5.2);
    N79.RTabLDS(7.1);
    N79.RTabLDS(7.2);
    N79.RTabLDS(7.3);
    N79.RTabSV(TNSC("Gare Du Nord"));
    N79.RTabSV(TNSC("Château D'Eau"));
    N79.RTabSV(TNSC("Jacques Bonsergent"));
    N79.RTabSV(TNSC("Château-Landon"));
    N79.RTabSV(TNSC("Poissonnière"));
    m_ListeStation.push_back(N79);

    station N80(TNSC("Château D'Eau"),48.8724,2.35592);
    N80.RTabLDS(4.1);
    N80.RTabLDS(4.2);
    N80.RTabSV(TNSC("Strasbourg - Saint-Denis"));
    N80.RTabSV(TNSC("Gare De L'Est"));
    m_ListeStation.push_back(N80);

    station N81(TNSC("Strasbourg - Saint-Denis"),48.86938,2.35429);
    N81.RTabLDS(4.1);
    N81.RTabLDS(4.2);
    N81.RTabLDS(8.1);
    N81.RTabLDS(8.2);
    N81.RTabLDS(9.1);
    N81.RTabLDS(9.2);
    N81.RTabSV(TNSC("Château D'Eau"));
    N81.RTabSV(TNSC("Réaumur - Sébastopol"));
    N81.RTabSV(TNSC("Bonne-Nouvelle"));
    N81.RTabSV(TNSC("République"));
    m_ListeStation.push_back(N81);

    //***//

    station N82(TNSC("Etienne Marcel"),48.86379,2.34905);
    N82.RTabLDS(4.1);
    N82.RTabLDS(4.2);
    N82.RTabSV(TNSC("Réaumur - Sébastopol"));
    N82.RTabSV(TNSC("Les Halles"));
    m_ListeStation.push_back(N82);

    station N83(TNSC("Les Halles"),48.86252,2.34609);
    N83.RTabLDS(4.1);
    N83.RTabLDS(4.2);
    N83.RTabSV(TNSC("Etienne Marcel"));
    N83.RTabSV(TNSC("Châtelet"));
    m_ListeStation.push_back(N83);

    //***//

    station N84(TNSC("Cité"),48.85574,2.3462);
    N84.RTabLDS(4.1);
    N84.RTabLDS(4.2);
    N84.RTabSV(TNSC("Saint-Michel"));
    N84.RTabSV(TNSC("Châtelet"));
    m_ListeStation.push_back(N84);

    station N85(TNSC("Saint-Michel"),48.85362,2.34395);
    N85.RTabLDS(4.1);
    N85.RTabLDS(4.2);
    N85.RTabSV(TNSC("Cité"));
    N85.RTabSV(TNSC("Odéon"));
    m_ListeStation.push_back(N85);

    station N86(TNSC("Odéon"),48.85231,2.3388);
    N86.RTabLDS(4.1);
    N86.RTabLDS(4.2);
    N86.RTabLDS(10.1);
    N86.RTabLDS(10.2);
    N86.RTabSV(TNSC("Saint-Michel"));
    N86.RTabSV(TNSC("Saint-Germain-Des-Prés"));
    N86.RTabSV(TNSC("Cluny - La Sorbonne"));
    N86.RTabSV(TNSC("Mabillon"));
    m_ListeStation.push_back(N86);

    station N87(TNSC("Saint-Germain-Des-Prés"),48.85389,2.33328);
    N87.RTabLDS(4.1);
    N87.RTabLDS(4.2);
    N87.RTabSV(TNSC("Saint-Sulpice"));
    N87.RTabSV(TNSC("Odéon"));
    m_ListeStation.push_back(N87);

    station N88(TNSC("Saint-Sulpice"),48.85149,2.33118);
    N88.RTabLDS(4.1);
    N88.RTabLDS(4.2);
    N88.RTabSV(TNSC("Saint-Placide"));
    N88.RTabSV(TNSC("Saint-Germain-Des-Prés"));
    m_ListeStation.push_back(N88);

    station N89(TNSC("Saint-Placide"),48.8469,2.32684);
    N89.RTabLDS(4.1);
    N89.RTabLDS(4.2);
    N89.RTabSV(TNSC("Saint-Sulpice"));
    N89.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    m_ListeStation.push_back(N89);

    station N90(TNSC("Montparnasse - Bienvenüe"),48.84343,2.32309);
    N90.RTabLDS(4.1);
    N90.RTabLDS(4.2);
    N90.RTabLDS(6.1);
    N90.RTabLDS(6.2);
    N90.RTabLDS(12.1);
    N90.RTabLDS(12.2);
    N90.RTabLDS(13.1);
    N90.RTabLDS(13.2);
    N90.RTabSV(TNSC("Saint-Placide"));
    N90.RTabSV(TNSC("Vavin"));
    N90.RTabSV(TNSC("Pasteur"));
    N90.RTabSV(TNSC("Edgar Quinet"));
    N90.RTabSV(TNSC("Falguière"));
    N90.RTabSV(TNSC("Notre-Dame-Des-Champs"));
    N90.RTabSV(TNSC("Duroc"));
    N90.RTabSV(TNSC("Gaîté"));
    m_ListeStation.push_back(N90);

    station N91(TNSC("Vavin"),48.84221,2.32933);
    N91.RTabLDS(4.1);
    N91.RTabLDS(4.2);
    N91.RTabSV(TNSC("Raspail"));
    N91.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    m_ListeStation.push_back(N91);

    station N92(TNSC("Raspail"),48.83899,2.33073);
    N92.RTabLDS(4.1);
    N92.RTabLDS(4.2);
    N92.RTabLDS(6.1);
    N92.RTabLDS(6.2);
    N92.RTabSV(TNSC("Vavin"));
    N92.RTabSV(TNSC("Denfert-Rochereau"));
    N92.RTabSV(TNSC("Edgar Quinet"));
    m_ListeStation.push_back(N92);

    station N93(TNSC("Denfert-Rochereau"),48.83391,2.33255);
    N93.RTabLDS(4.1);
    N93.RTabLDS(4.2);
    N93.RTabLDS(6.1);
    N93.RTabLDS(6.2);
    N93.RTabSV(TNSC("Raspail"));
    N93.RTabSV(TNSC("Mouton-Duvernet"));
    N93.RTabSV(TNSC("Saint-Jacques"));
    m_ListeStation.push_back(N93);

    station N94(TNSC("Mouton-Duvernet"),48.8321,2.33041);
    N94.RTabLDS(4.1);
    N94.RTabLDS(4.2);
    N94.RTabSV(TNSC("Denfert-Rochereau"));
    N94.RTabSV(TNSC("Alésia"));
    m_ListeStation.push_back(N94);

    station N95(TNSC("Alésia"),48.82822,2.32682);
    N95.RTabLDS(4.1);
    N95.RTabLDS(4.2);
    N95.RTabSV(TNSC("Porte D'Orléans"));
    N95.RTabSV(TNSC("Mouton-Duvernet"));
    m_ListeStation.push_back(N95);

    station N96(TNSC("Porte D'Orléans"),48.82293,2.32584);
    N96.RTabLDS(4.1);
    N96.RTabLDS(4.2);
    N96.RTabSV(TNSC("Mairie De Montrouge"));
    N96.RTabSV(TNSC("Alésia"));
    m_ListeStation.push_back(N96);

    station N97(TNSC("Mairie De Montrouge"),48.81844,2.319537);
    N97.RTabLDS(4.1);
    N97.RTabLDS(4.2);
    N97.RTabSV(TNSC("Porte D'Orléans"));
    m_ListeStation.push_back(N97);

    //********************Fin Ligne 4*************************//

    //********************Ligne 5*************************//


    // Décalage !!!!!!
    station NH(TNSC("Bobigny - Pablo Picasso"),48.906538,2.449994);
    NH.RTabLDS(5.1);
    NH.RTabLDS(5.2);
    NH.RTabSV(TNSC("Bobigny - Pantin - Raymond Queneau"));
    m_ListeStation.push_back(NH);

    station N98(TNSC("Bobigny - Pantin - Raymond Queneau"),48.895409,2.424929);
    N98.RTabLDS(5.1);
    N98.RTabLDS(5.2);
    N98.RTabSV(TNSC("Bobigny - Pablo Picasso"));
    N98.RTabSV(TNSC("Eglise De Pantin"));
    m_ListeStation.push_back(N98);

    station N99(TNSC("Eglise De Pantin"),48.893628,2.412918);
    N99.RTabLDS(5.1);
    N99.RTabLDS(5.2);
    N99.RTabSV(TNSC("Bobigny - Pantin - Raymond Queneau"));
    N99.RTabSV(TNSC("Hoche"));
    m_ListeStation.push_back(N99);

    station N100(TNSC("Hoche"),48.891494,2.403144);
    N100.RTabLDS(5.1);
    N100.RTabLDS(5.2);
    N100.RTabSV(TNSC("Porte De Pantin"));
    N100.RTabSV(TNSC("Eglise De Pantin"));
    m_ListeStation.push_back(N100);

    station N101(TNSC("Porte De Pantin"),48.888471,2.391814);
    N101.RTabLDS(5.1);
    N101.RTabLDS(5.2);
    N101.RTabSV(TNSC("Ourcq"));
    N101.RTabSV(TNSC("Hoche"));
    m_ListeStation.push_back(N101);

    station N102(TNSC("Ourcq"),48.886856,2.385747);
    N102.RTabLDS(5.1);
    N102.RTabLDS(5.2);
    N102.RTabSV(TNSC("Porte De Pantin"));
    N102.RTabSV(TNSC("Laumière"));
    m_ListeStation.push_back(N102);

    station N103(TNSC("Laumière"),48.885006,2.378524);
    N103.RTabLDS(5.1);
    N103.RTabLDS(5.2);
    N103.RTabSV(TNSC("Ourcq"));
    N103.RTabSV(TNSC("Jaurès"));
    m_ListeStation.push_back(N103);

    //***//

    //***//

    //***//

    //***//

    station N104(TNSC("Jacques Bonsergent"),48.871201,2.360607);
    N104.RTabLDS(5.1);
    N104.RTabLDS(5.2);
    N104.RTabSV(TNSC("Gare De L'Est"));
    N104.RTabSV(TNSC("République"));
    m_ListeStation.push_back(N104);

    //***//

    station N105(TNSC("Oberkampf"),48.864545,2.368877);
    N105.RTabLDS(5.1);
    N105.RTabLDS(5.2);
    N105.RTabLDS(9.1);
    N105.RTabLDS(9.2);
    N105.RTabSV(TNSC("Richard-Lenoir"));
    N105.RTabSV(TNSC("République"));
    N105.RTabSV(TNSC("Saint-Ambroise"));
    m_ListeStation.push_back(N105);

    station N106(TNSC("Richard-Lenoir"),48.859772,2.371843);
    N106.RTabLDS(5.1);
    N106.RTabLDS(5.2);
    N106.RTabSV(TNSC("Oberkampf"));
    N106.RTabSV(TNSC("Bréguet - Sabin"));
    m_ListeStation.push_back(N106);

    station N107(TNSC("Bréguet - Sabin"),48.856133,2.370094);
    N107.RTabLDS(5.1);
    N107.RTabLDS(5.2);
    N107.RTabSV(TNSC("Richard-Lenoir"));
    N107.RTabSV(TNSC("Bastille"));
    m_ListeStation.push_back(N107);

    //***//

    station N108(TNSC("Quai De La Rapée"),48.846539,2.365826);
    N108.RTabLDS(5.1);
    N108.RTabLDS(5.2);
    N108.RTabSV(TNSC("Gare D'Austerlitz"));
    N108.RTabSV(TNSC("Bastille"));
    m_ListeStation.push_back(N108);

    station N109(TNSC("Gare D'Austerlitz"),48.842626,2.364971);
    N109.RTabLDS(5.1);
    N109.RTabLDS(5.2);
    N109.RTabLDS(10.1);
    N109.RTabLDS(10.2);
    N109.RTabSV(TNSC("Quai De La Rapée"));
    N109.RTabSV(TNSC("Saint-Marcel"));
    N109.RTabSV(TNSC("Jussieu"));
    m_ListeStation.push_back(N109);

    station N110(TNSC("Saint-Marcel"),48.837988,2.360416);
    N110.RTabLDS(5.1);
    N110.RTabLDS(5.2);
    N110.RTabSV(TNSC("Gare D'Austerlitz"));
    N110.RTabSV(TNSC("Campo-Formio"));
    m_ListeStation.push_back(N110);

    station N111(TNSC("Campo-Formio"),48.835022,2.358128);
    N111.RTabLDS(5.1);
    N111.RTabLDS(5.2);
    N111.RTabSV(TNSC("Place D'Italie"));
    N111.RTabSV(TNSC("Saint-Marcel"));
    m_ListeStation.push_back(N111);

    station N112(TNSC("Place D'Italie"),48.831483,2.355692);
    N112.RTabLDS(5.1);
    N112.RTabLDS(5.2);
    N112.RTabLDS(6.1);
    N112.RTabLDS(6.2);
    N112.RTabLDS(7.1);
    N112.RTabLDS(7.2);
    N112.RTabLDS(7.3);
    N112.RTabSV(TNSC("Corvisart"));
    N112.RTabSV(TNSC("Campo-Formio"));
    N112.RTabSV(TNSC("Nationale"));
    N112.RTabSV(TNSC("Tolbiac"));
    N112.RTabSV(TNSC("Les Gobelins"));
    m_ListeStation.push_back(N112);

    //********************Fin Ligne 5*************************//

    //********************Ligne 6*************************//

    //***//

    station N113(TNSC("Kléber"),48.871138,2.293118);
    N113.RTabLDS(6.1);
    N113.RTabLDS(6.2);
    N113.RTabSV(TNSC("Charles De Gaulle - Etoile"));
    N113.RTabSV(TNSC("Boissière"));
    m_ListeStation.push_back(N113);

    station N114(TNSC("Boissière"),48.867386,2.290392);
    N114.RTabLDS(6.1);
    N114.RTabLDS(6.2);
    N114.RTabSV(TNSC("Kléber"));
    N114.RTabSV(TNSC("Trocadéro"));
    m_ListeStation.push_back(N114);

    station N115(TNSC("Trocadéro"),48.863301,2.287061);
    N115.RTabLDS(6.1);
    N115.RTabLDS(6.2);
    N115.RTabLDS(9.1);
    N115.RTabLDS(9.2);
    N115.RTabSV(TNSC("Passy"));
    N115.RTabSV(TNSC("Boissière"));
    N115.RTabSV(TNSC("Iéna"));
    N115.RTabSV(TNSC("Rue De La Pompe"));
    m_ListeStation.push_back(N115);

    station N116(TNSC("Passy"),48.857445,2.285779);
    N116.RTabLDS(6.1);
    N116.RTabLDS(6.2);
    N116.RTabSV(TNSC("Bir-Hakeim"));
    N116.RTabSV(TNSC("Trocadéro"));
    m_ListeStation.push_back(N116);

    station N117(TNSC("Bir-Hakeim"),48.853917,2.289332);
    N117.RTabLDS(6.1);
    N117.RTabLDS(6.2);
    N117.RTabSV(TNSC("Passy"));
    N117.RTabSV(TNSC("Dupleix"));
    m_ListeStation.push_back(N117);

    station N118(TNSC("Dupleix"),48.850392,2.293611);
    N118.RTabLDS(6.1);
    N118.RTabLDS(6.2);
    N118.RTabSV(TNSC("Bir-Hakeim"));
    N118.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    m_ListeStation.push_back(N118);

    station N119(TNSC("La Motte-Picquet - Grenelle"),48.849143,2.29809);
    N119.RTabLDS(6.1);
    N119.RTabLDS(6.2);
    N119.RTabLDS(8.1);
    N119.RTabLDS(8.2);
    N119.RTabLDS(10.1);
    N119.RTabLDS(10.2);
    N119.RTabSV(TNSC("Cambronne"));
    N119.RTabSV(TNSC("Dupleix"));
    N119.RTabSV(TNSC("Commerce"));
    N119.RTabSV(TNSC("Ecole Militaire"));
    N119.RTabSV(TNSC("Avenue Emile-Zola"));
    N119.RTabSV(TNSC("Ségur"));
    m_ListeStation.push_back(N119);

    station N120(TNSC("Cambronne"),48.847537,2.302937);
    N120.RTabLDS(6.1);
    N120.RTabLDS(6.2);
    N120.RTabSV(TNSC("Sèvres - Lecourbe"));
    N120.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    m_ListeStation.push_back(N120);

    station N121(TNSC("Sèvres - Lecourbe"),48.845634,2.309476);
    N121.RTabLDS(6.1);
    N121.RTabLDS(6.2);
    N121.RTabSV(TNSC("Cambronne"));
    N121.RTabSV(TNSC("Pasteur"));
    m_ListeStation.push_back(N121);

    station N122(TNSC("Pasteur"),48.842836,2.312681);
    N122.RTabLDS(6.1);
    N122.RTabLDS(6.2);
    N122.RTabLDS(12.1);
    N122.RTabLDS(12.2);
    N122.RTabSV(TNSC("Sèvres - Lecourbe"));
    N122.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    N122.RTabSV(TNSC("Falguière"));
    N122.RTabSV(TNSC("Volontaires"));
    m_ListeStation.push_back(N122);

    //***//

    station N123(TNSC("Edgar Quinet"),48.841048,2.325084);
    N123.RTabLDS(6.1);
    N123.RTabLDS(6.2);
    N123.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    N123.RTabSV(TNSC("Raspail"));
    m_ListeStation.push_back(N123);

    //***//

    //***//

    station N124(TNSC("Saint-Jacques"),48.832913,2.337081);
    N124.RTabLDS(6.1);
    N124.RTabLDS(6.2);
    N124.RTabSV(TNSC("Denfert-Rochereau"));
    N124.RTabSV(TNSC("Glacière"));
    m_ListeStation.push_back(N124);

    station N125(TNSC("Glacière"),48.83115,2.343384);
    N125.RTabLDS(6.1);
    N125.RTabLDS(6.2);
    N125.RTabSV(TNSC("Saint-Jacques"));
    N125.RTabSV(TNSC("Corvisart"));
    m_ListeStation.push_back(N125);

    station N126(TNSC("Corvisart"),48.829807,2.350508);
    N126.RTabLDS(6.1);
    N126.RTabLDS(6.2);
    N126.RTabSV(TNSC("Place D'Italie"));
    N126.RTabSV(TNSC("Glacière"));
    m_ListeStation.push_back(N126);

    //***//

    station N127(TNSC("Nationale"),48.833183,2.362718);
    N127.RTabLDS(6.1);
    N127.RTabLDS(6.2);
    N127.RTabSV(TNSC("Place D'Italie"));
    N127.RTabSV(TNSC("Chevaleret"));
    m_ListeStation.push_back(N127);

    station N128(TNSC("Chevaleret"),48.834938,2.368082);
    N128.RTabLDS(6.1);
    N128.RTabLDS(6.2);
    N128.RTabSV(TNSC("Nationale"));
    N128.RTabSV(TNSC("Quai De La Gare"));
    m_ListeStation.push_back(N128);

    station N129(TNSC("Quai De La Gare"),48.837069,2.372773);
    N129.RTabLDS(6.1);
    N129.RTabLDS(6.2);
    N129.RTabSV(TNSC("Bercy"));
    N129.RTabSV(TNSC("Chevaleret"));
    m_ListeStation.push_back(N129);

    station N130(TNSC("Bercy"),48.83993,2.380418);
    N130.RTabLDS(6.1);
    N130.RTabLDS(6.2);
    N130.RTabLDS(14.1);
    N130.RTabLDS(14.2);
    N130.RTabSV(TNSC("Dugommier"));
    N130.RTabSV(TNSC("Quai De La Gare"));
    N130.RTabSV(TNSC("Gare De Lyon"));
    N130.RTabSV(TNSC("Cours Saint-Emilion"));
    m_ListeStation.push_back(N130);

    station N131(TNSC("Dugommier"),48.839049,2.389964);
    N131.RTabLDS(6.1);
    N131.RTabLDS(6.2);
    N131.RTabSV(TNSC("Bercy"));
    N131.RTabSV(TNSC("Daumesnil"));
    m_ListeStation.push_back(N131);

    station N132(TNSC("Daumesnil"),48.839644,2.395792);
    N132.RTabLDS(6.1);
    N132.RTabLDS(6.2);
    N132.RTabLDS(8.1);
    N132.RTabLDS(8.2);
    N132.RTabSV(TNSC("Dugommier"));
    N132.RTabSV(TNSC("Bel-Air"));
    N132.RTabSV(TNSC("Montgallet"));
    N132.RTabSV(TNSC("Michel Bizot"));
    m_ListeStation.push_back(N132);

    station N133(TNSC("Bel-Air"),48.841344,2.400912);
    N133.RTabLDS(6.1);
    N133.RTabLDS(6.2);
    N133.RTabSV(TNSC("Bercy"));
    N133.RTabSV(TNSC("Picpus"));
    m_ListeStation.push_back(N133);

    station N134(TNSC("Picpus"),48.84515,2.400494);
    N134.RTabLDS(6.1);
    N134.RTabLDS(6.2);
    N134.RTabSV(TNSC("Bel-Air"));
    N134.RTabSV(TNSC("Nation"));
    m_ListeStation.push_back(N134);

    //***//

    //********************Fin Ligne 6*************************//

    //********************Ligne 7*************************//

    station N135(TNSC("La Courneuve - 8 Mai 1945"),48.92071,2.41051);
    N135.RTabLDS(7.1);
    N135.RTabLDS(7.2);
    N135.RTabLDS(7.3);
    N135.RTabSV(TNSC("Fort D'Aubervilliers"));
    m_ListeStation.push_back(N135);

    station N136(TNSC("Fort D'Aubervilliers"),48.91427,2.40412);
    N136.RTabLDS(7.1);
    N136.RTabLDS(7.2);
    N136.RTabLDS(7.3);
    N136.RTabSV(TNSC("La Courneuve - 8 Mai 1945"));
    N136.RTabSV(TNSC("Aubervilliers - Pantin - Quatre Chemins"));
    m_ListeStation.push_back(N136);

    station N137(TNSC("Aubervilliers - Pantin - Quatre Chemins"),48.90386,2.39255);
    N137.RTabLDS(7.1);
    N137.RTabLDS(7.2);
    N137.RTabLDS(7.3);
    N137.RTabSV(TNSC("Fort D'Aubervilliers"));
    N137.RTabSV(TNSC("Porte De La Villette"));
    m_ListeStation.push_back(N137);

    station N138(TNSC("Porte De La Villette"),48.89708,2.38588);
    N138.RTabLDS(7.1);
    N138.RTabLDS(7.2);
    N138.RTabLDS(7.3);
    N138.RTabSV(TNSC("Corentin Cariou"));
    N138.RTabSV(TNSC("Aubervilliers - Pantin - Quatre Chemins"));
    m_ListeStation.push_back(N138);

    station N139(TNSC("Corentin Cariou"),48.89473,2.38242);
    N139.RTabLDS(7.1);
    N139.RTabLDS(7.2);
    N139.RTabLDS(7.3);
    N139.RTabSV(TNSC("Crimée"));
    N139.RTabSV(TNSC("Porte De La Villette"));
    m_ListeStation.push_back(N139);

    station N140(TNSC("Crimée"),48.8914,2.37732);
    N140.RTabLDS(7.1);
    N140.RTabLDS(7.2);
    N140.RTabLDS(7.3);
    N140.RTabSV(TNSC("Corentin Cariou"));
    N140.RTabSV(TNSC("Riquet"));
    m_ListeStation.push_back(N140);

    station N141(TNSC("Riquet"),48.88836,2.37418);
    N141.RTabLDS(7.1);
    N141.RTabLDS(7.2);
    N141.RTabLDS(7.3);
    N141.RTabSV(TNSC("Crimée"));
    N141.RTabSV(TNSC("Stalingrad"));
    m_ListeStation.push_back(N141);

    //***//

    station N142(TNSC("Louis Blanc"),48.88139,2.36517);
    N142.RTabLDS(7.1);
    N142.RTabLDS(7.2);
    N142.RTabLDS(7.3);
    N142.RTabLDS(7.4);
    N142.RTabLDS(7.5);
    N142.RTabSV(TNSC("Château-Landon"));
    N142.RTabSV(TNSC("Stalingrad"));
    N142.RTabSV(TNSC("Jaurès"));
    m_ListeStation.push_back(N142);

    station N143(TNSC("Château-Landon"),48.87865,2.36206);
    N143.RTabLDS(7.1);
    N143.RTabLDS(7.2);
    N143.RTabLDS(7.3);
    N143.RTabSV(TNSC("Louis Blanc"));
    N143.RTabSV(TNSC("Gare De L'Est"));
    m_ListeStation.push_back(N143);

    //***//

    station N144(TNSC("Poissonnière"),48.877,2.34929);
    N144.RTabLDS(7.1);
    N144.RTabLDS(7.2);
    N144.RTabLDS(7.3);
    N144.RTabSV(TNSC("Cadet"));
    N144.RTabSV(TNSC("Gare De L'Est"));
    m_ListeStation.push_back(N144);

    station N145(TNSC("Cadet"),48.87591,2.34318);
    N145.RTabLDS(7.1);
    N145.RTabLDS(7.2);
    N145.RTabLDS(7.3);
    N145.RTabSV(TNSC("Poissonnière"));
    N145.RTabSV(TNSC("Le Peletier"));
    m_ListeStation.push_back(N145);

    station N146(TNSC("Le Peletier"),48.87492,2.34045);
    N146.RTabLDS(7.1);
    N146.RTabLDS(7.2);
    N146.RTabLDS(7.3);
    N146.RTabSV(TNSC("Cadet"));
    N146.RTabSV(TNSC("Chaussée D'Antin - La Fayette"));
    m_ListeStation.push_back(N146);

    station N147(TNSC("Chaussée D'Antin - La Fayette"),48.87289,2.33324);
    N147.RTabLDS(7.1);
    N147.RTabLDS(7.2);
    N147.RTabLDS(7.3);
    N147.RTabLDS(9.1);
    N147.RTabLDS(9.2);
    N147.RTabSV(TNSC("Opéra"));
    N147.RTabSV(TNSC("Le Peletier"));
    N147.RTabSV(TNSC("Havre - Caumartain"));
    N147.RTabSV(TNSC("Richelieu - Drouot"));
    m_ListeStation.push_back(N147);

    //***//

    station N148(TNSC("Pyramides"),48.86643,2.33395);
    N148.RTabLDS(7.1);
    N148.RTabLDS(7.2);
    N148.RTabLDS(7.3);
    N148.RTabLDS(14.1);
    N148.RTabLDS(14.2);
    N148.RTabSV(TNSC("Opéra"));
    N148.RTabSV(TNSC("Madeleine"));
    N148.RTabSV(TNSC("Châtelet"));
    N148.RTabSV(TNSC("Palais Royal - Musée Du Louvre"));
    m_ListeStation.push_back(N148);

    //***//

    station N149(TNSC("Pont Neuf"),48.85855,2.34213);
    N149.RTabLDS(7.1);
    N149.RTabLDS(7.2);
    N149.RTabLDS(7.3);
    N149.RTabSV(TNSC("Châtelet"));
    N149.RTabSV(TNSC("Palais Royal - Musée Du Louvre"));
    m_ListeStation.push_back(N149);

    //***//

    station N150(TNSC("Pont Marie"),48.85361,2.35725);
    N150.RTabLDS(7.1);
    N150.RTabLDS(7.2);
    N150.RTabLDS(7.3);
    N150.RTabSV(TNSC("Châtelet"));
    N150.RTabSV(TNSC("Sully - Morland"));
    m_ListeStation.push_back(N150);

    station N151(TNSC("Sully - Morland"),48.85121,2.3624);
    N151.RTabLDS(7.1);
    N151.RTabLDS(7.2);
    N151.RTabLDS(7.3);
    N151.RTabSV(TNSC("Pont Marie"));
    N151.RTabSV(TNSC("Jussieu"));
    m_ListeStation.push_back(N151);

    station N152(TNSC("Jussieu"),48.84596,2.35461);
    N152.RTabLDS(7.1);
    N152.RTabLDS(7.2);
    N152.RTabLDS(7.3);
    N152.RTabLDS(10.1);
    N152.RTabLDS(10.2);
    N152.RTabSV(TNSC("Place Monge"));
    N152.RTabSV(TNSC("Sully - Morland"));
    N152.RTabSV(TNSC("Gare D'Austerlitz"));
    N152.RTabSV(TNSC("Cardinal Lemoine"));
    m_ListeStation.push_back(N152);

    station N153(TNSC("Place Monge"),48.8434,2.3526);
    N153.RTabLDS(7.1);
    N153.RTabLDS(7.2);
    N153.RTabLDS(7.3);
    N153.RTabSV(TNSC("Censier - Daubenton"));
    N153.RTabSV(TNSC("Jussieu"));
    m_ListeStation.push_back(N153);

    station N154(TNSC("Censier - Daubenton"),48.84059,2.35178);
    N154.RTabLDS(7.1);
    N154.RTabLDS(7.2);
    N154.RTabLDS(7.3);
    N154.RTabSV(TNSC("Place Monge"));
    N154.RTabSV(TNSC("Les Gobelins"));
    m_ListeStation.push_back(N154);

    station N155(TNSC("Les Gobelins"),48.83659,2.35206);
    N155.RTabLDS(7.1);
    N155.RTabLDS(7.2);
    N155.RTabLDS(7.3);
    N155.RTabSV(TNSC("Censier - Daubenton"));
    N155.RTabSV(TNSC("Place D'Italie"));
    m_ListeStation.push_back(N155);

    //***//

    station N156(TNSC("Tolbiac"),48.82624,2.35708);
    N156.RTabLDS(7.1);
    N156.RTabLDS(7.2);
    N156.RTabLDS(7.3);
    N156.RTabSV(TNSC("Maison Blanche"));
    N156.RTabSV(TNSC("Place D'Italie"));
    m_ListeStation.push_back(N156);

    station N157(TNSC("Maison Blanche"),48.82213,2.35854);
    N157.RTabLDS(7.1);
    N157.RTabLDS(7.2);
    N157.RTabLDS(7.3);
    N157.RTabSV(TNSC("Tolbiac"));
    N157.RTabSV(TNSC("Le Kremlin-Bicêtre"));
    N157.RTabSV(TNSC("Porte D'Italie"));
    m_ListeStation.push_back(N157);

    station N158(TNSC("Le Kremlin-Bicêtre"),48.81027,2.36202);
    N158.RTabLDS(7.1);
    N158.RTabLDS(7.2);
    N158.RTabSV(TNSC("Villejuif - Léo Lagrange"));
    N158.RTabSV(TNSC("Place D'Italie"));
    m_ListeStation.push_back(N158);

    station N159(TNSC("Villejuif - Léo Lagrange"),48.80462,2.36363);
    N159.RTabLDS(7.1);
    N159.RTabLDS(7.2);
    N159.RTabSV(TNSC("Le Kremlin-Bicêtre"));
    N159.RTabSV(TNSC("Villejuif - Paul Vaillant-Couturier"));
    m_ListeStation.push_back(N159);

    station N160(TNSC("Villejuif - Paul Vaillant-Couturier"),48.79628,2.36809);
    N160.RTabLDS(7.1);
    N160.RTabLDS(7.2);
    N160.RTabSV(TNSC("Villejuif - Léo Lagrange"));
    N160.RTabSV(TNSC("Villejuif - Louis Aragon"));
    m_ListeStation.push_back(N160);

    station N161(TNSC("Villejuif - Louis Aragon"),48.78694,2.3673);
    N161.RTabLDS(7.1);
    N161.RTabLDS(7.2);
    N161.RTabSV(TNSC("Villejuif - Paul Vaillant-Couturier"));
    m_ListeStation.push_back(N161);

    station N162(TNSC("Porte D'Italie"),48.81908,2.35942);
    N162.RTabLDS(7.1);
    N162.RTabLDS(7.3);
    N162.RTabSV(TNSC("Maison Blanche"));
    N162.RTabSV(TNSC("Porte De Choisy"));
    m_ListeStation.push_back(N162);

    station N163(TNSC("Porte De Choisy"),48.81998,2.36436);
    N163.RTabLDS(7.1);
    N163.RTabLDS(7.3);
    N163.RTabSV(TNSC("Porte D'Italie"));
    N163.RTabSV(TNSC("Porte D'Ivry"));
    m_ListeStation.push_back(N163);

    station N164(TNSC("Porte D'Ivry"),48.82153,2.36916);
    N164.RTabLDS(7.1);
    N164.RTabLDS(7.3);
    N164.RTabSV(TNSC("Pierre Et Marie Curie"));
    N164.RTabSV(TNSC("Porte De Choisy"));
    m_ListeStation.push_back(N164);

    station N165(TNSC("Pierre Et Marie Curie"),48.81585,2.37738);
    N165.RTabLDS(7.1);
    N165.RTabLDS(7.3);
    N165.RTabSV(TNSC("Mairie D'Ivry"));
    N165.RTabSV(TNSC("Porte D'Ivry"));
    m_ListeStation.push_back(N165);

    station N166(TNSC("Mairie D'Ivry"),48.81112,2.38283);
    N166.RTabLDS(7.1);
    N166.RTabLDS(7.3);
    N166.RTabSV(TNSC("Pierre Et Marie Curie"));
    m_ListeStation.push_back(N166);

    //********************Fin Ligne 7*************************//

    //********************Ligne 7bis*************************//

    station N167(TNSC("Bolivar"),48.880502,2.374922);
    N167.RTabLDS(7.4);
    N167.RTabLDS(7.5);
    N167.RTabSV(TNSC("Jaurès"));
    N167.RTabSV(TNSC("Buttes Chaumont"));
    m_ListeStation.push_back(N167);

    station N168(TNSC("Buttes Chaumont"),48.8785,2.381772);
    N168.RTabLDS(7.4);
    N168.RTabLDS(7.5);
    N168.RTabSV(TNSC("Bolivar"));
    N168.RTabSV(TNSC("Botzaris"));
    m_ListeStation.push_back(N168);

    station N169(TNSC("Botzaris"),48.879552,2.38804);
    N169.RTabLDS(7.4);
    N169.RTabLDS(7.5);
    N169.RTabSV(TNSC("Buttes Chaumont"));
    N169.RTabSV(TNSC("Danube"));
    N169.RTabSV(TNSC("Place Des Fêtes"));
    m_ListeStation.push_back(N169);

    station N170(TNSC("Danube"),48.881808,2.394201);
    N170.RTabLDS(7.5);
    N170.RTabSV(TNSC("Botzaris"));
    N170.RTabSV(TNSC("Pré Saint-Gervais"));
    m_ListeStation.push_back(N170);

    station N171(TNSC("Place Des Fêtes"),48.87684,2.39296);
    N171.RTabLDS(7.4);
    N171.RTabSV(TNSC("Botzaris"));
    N171.RTabSV(TNSC("Pré Saint-Gervais"));
    m_ListeStation.push_back(N171);

    station N172(TNSC("Pré Saint-Gervais"),48.88025,2.398914);
    N172.RTabLDS(7.4);
    N172.RTabLDS(7.5);
    N172.RTabSV(TNSC("Place Des Fêtes"));
    N172.RTabSV(TNSC("Danube"));
    m_ListeStation.push_back(N172);

    //********************Fin Ligne 7bis*************************//

    //********************Ligne 8*************************//

    station N173(TNSC("Balard"),48.836275,2.278218);
    N173.RTabLDS(8.1);
    N173.RTabLDS(8.2);
    N173.RTabSV(TNSC("Lourmel"));
    m_ListeStation.push_back(N173);

    station N174(TNSC("Lourmel"),48.838604,2.281817);
    N174.RTabLDS(8.1);
    N174.RTabLDS(8.2);
    N174.RTabSV(TNSC("Balard"));
    N174.RTabSV(TNSC("Boucicaut"));
    m_ListeStation.push_back(N174);

    station N175(TNSC("Boucicaut"),48.841101,2.287817);
    N175.RTabLDS(8.1);
    N175.RTabLDS(8.2);
    N175.RTabSV(TNSC("Lourmel"));
    N175.RTabSV(TNSC("Félix Faure"));
    m_ListeStation.push_back(N175);

    station N176(TNSC("Félix Faure"),48.842351,2.291004);
    N176.RTabLDS(8.1);
    N176.RTabLDS(8.2);
    N176.RTabSV(TNSC("Commerce"));
    N176.RTabSV(TNSC("Boucicaut"));
    m_ListeStation.push_back(N176);

    station N177(TNSC("Commerce"),48.845093,2.294215);
    N177.RTabLDS(8.1);
    N177.RTabLDS(8.2);
    N177.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    N177.RTabSV(TNSC("Félix Faure"));
    m_ListeStation.push_back(N177);

    //***//

    station N178(TNSC("Ecole Militaire"),48.85511,2.306737);
    N178.RTabLDS(8.1);
    N178.RTabLDS(8.2);
    N178.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    N178.RTabSV(TNSC("La Tour-Maubourg"));
    m_ListeStation.push_back(N178);

    station N179(TNSC("La Tour-Maubourg"),48.857667,2.310399);
    N179.RTabLDS(8.1);
    N179.RTabLDS(8.2);
    N179.RTabSV(TNSC("Ecole Militaire"));
    N179.RTabSV(TNSC("Invalides"));
    m_ListeStation.push_back(N179);

    station N180(TNSC("Invalides"),48.860907,2.314457);
    N180.RTabLDS(8.1);
    N180.RTabLDS(8.2);
    N180.RTabLDS(13.1);
    N180.RTabLDS(13.2);
    N180.RTabLDS(13.3);
    N180.RTabSV(TNSC("Concorde"));
    N180.RTabSV(TNSC("La Tour-Maubourg"));
    N180.RTabSV(TNSC("Champs-Elysées - Clemenceau"));
    N180.RTabSV(TNSC("Varenne"));
    m_ListeStation.push_back(N180);

    //***//

    station N181(TNSC("Madeleine"),48.869846,2.324435);
    N181.RTabLDS(8.1);
    N181.RTabLDS(8.2);
    N181.RTabLDS(12.1);
    N181.RTabLDS(12.2);
    N181.RTabLDS(14.1);
    N181.RTabLDS(14.2);
    N181.RTabSV(TNSC("Opéra"));
    N181.RTabSV(TNSC("Concorde"));
    N181.RTabSV(TNSC("Saint-Lazare"));
    N181.RTabSV(TNSC("Pyramides"));
    m_ListeStation.push_back(N181);

    //***//

    station N182(TNSC("Richelieu - Drouot"),48.871987,2.338741);
    N182.RTabLDS(8.1);
    N182.RTabLDS(8.2);
    N182.RTabLDS(9.1);
    N182.RTabLDS(9.2);
    N182.RTabSV(TNSC("Opéra"));
    N182.RTabSV(TNSC("Chaussée D'Antin - La Fayette"));
    N182.RTabSV(TNSC("Grands Boulevards"));
    m_ListeStation.push_back(N182);

    station N183(TNSC("Grands Boulevards"),48.871426,2.344342);
    N183.RTabLDS(8.1);
    N183.RTabLDS(8.2);
    N183.RTabLDS(9.1);
    N183.RTabLDS(9.2);
    N183.RTabSV(TNSC("Bonne-Nouvelle"));
    N183.RTabSV(TNSC("Richelieu - Drouot"));
    m_ListeStation.push_back(N183);

    station N184(TNSC("Bonne-Nouvelle"),48.870639,2.348875);
    N184.RTabLDS(8.1);
    N184.RTabLDS(8.2);
    N184.RTabLDS(9.1);
    N184.RTabLDS(9.2);
    N184.RTabSV(TNSC("Grands Boulevards"));
    N184.RTabSV(TNSC("Strasbourg - Saint-Denis"));
    m_ListeStation.push_back(N184);

    //***//

    //***//

    station N185(TNSC("Filles Du Calvaire"),48.864072,2.366121);
    N185.RTabLDS(8.1);
    N185.RTabLDS(8.2);
    N185.RTabSV(TNSC("République"));
    N185.RTabSV(TNSC("Saint-Sébastien - Froissart"));
    m_ListeStation.push_back(N185);

    station N186(TNSC("Saint-Sébastien - Froissart"),48.86048,2.367358);
    N186.RTabLDS(8.1);
    N186.RTabLDS(8.2);
    N186.RTabSV(TNSC("Filles Du Calvaire"));
    N186.RTabSV(TNSC("Chemin Vert"));
    m_ListeStation.push_back(N186);

    station N187(TNSC("Chemin Vert"),48.856778,2.368348);
    N187.RTabLDS(8.1);
    N187.RTabLDS(8.2);
    N187.RTabSV(TNSC("Bastille"));
    N187.RTabSV(TNSC("Saint-Sébastien - Froissart"));
    m_ListeStation.push_back(N187);

    //***//

    station N188(TNSC("Ledru-Rollin"),48.851346,2.376121);
    N188.RTabLDS(8.1);
    N188.RTabLDS(8.2);
    N188.RTabSV(TNSC("Bastille"));
    N188.RTabSV(TNSC("Faidherbe - Chaligny"));
    m_ListeStation.push_back(N188);

    station N189(TNSC("Faidherbe - Chaligny"),48.850158,2.383398);
    N189.RTabLDS(8.1);
    N189.RTabLDS(8.2);
    N189.RTabSV(TNSC("Ledru-Rollin"));
    N189.RTabSV(TNSC("Reuilly - Diderot"));
    m_ListeStation.push_back(N189);

    //***//

    station N190(TNSC("Montgallet"),48.844276,2.389974);
    N190.RTabLDS(8.1);
    N190.RTabLDS(8.2);
    N190.RTabSV(TNSC("Daumesnil"));
    N190.RTabSV(TNSC("Reuilly - Diderot"));
    m_ListeStation.push_back(N190);

    //***//

    station N191(TNSC("Michel Bizot"),48.837485,2.401234);
    N191.RTabLDS(8.1);
    N191.RTabLDS(8.2);
    N191.RTabSV(TNSC("Daumesnil"));
    N191.RTabSV(TNSC("Porte Dorée"));
    m_ListeStation.push_back(N191);

    station N192(TNSC("Porte Dorée"),48.835481,2.4061);
    N192.RTabLDS(8.1);
    N192.RTabLDS(8.2);
    N192.RTabSV(TNSC("Daumesnil"));
    N192.RTabSV(TNSC("Porte De Charenton"));
    m_ListeStation.push_back(N192);

    station N193(TNSC("Porte De Charenton"),48.83278,2.4004);
    N193.RTabLDS(8.1);
    N193.RTabLDS(8.2);
    N193.RTabSV(TNSC("Liberté"));
    N193.RTabSV(TNSC("Porte Dorée"));
    m_ListeStation.push_back(N193);

    station N194(TNSC("Liberté"),48.825882,2.407022);
    N194.RTabLDS(8.1);
    N194.RTabLDS(8.2);
    N194.RTabSV(TNSC("Charenton - Ecoles"));
    N194.RTabSV(TNSC("Porte De Charenton"));
    m_ListeStation.push_back(N194);

    station N195(TNSC("Charenton - Ecoles"),48.82149,2.413862);
    N195.RTabLDS(8.1);
    N195.RTabLDS(8.2);
    N195.RTabSV(TNSC("Liberté"));
    N195.RTabSV(TNSC("Ecole Vétérinaire De Maisons-Alfort"));
    m_ListeStation.push_back(N195);

    station N196(TNSC("Ecole Vétérinaire De Maisons-Alfort"),48.81519,2.421882);
    N196.RTabLDS(8.1);
    N196.RTabLDS(8.2);
    N196.RTabSV(TNSC("Charenton - Ecoles"));
    N196.RTabSV(TNSC("Maisons-Alfort - Stade"));
    m_ListeStation.push_back(N196);

    station N197(TNSC("Maisons-Alfort - Stade"),48.808681,2.436073);
    N197.RTabLDS(8.1);
    N197.RTabLDS(8.2);
    N197.RTabSV(TNSC("Maisons-Alfort - Les Juillottes"));
    N197.RTabSV(TNSC("Ecole Vétérinaire De Maisons-Alfort"));
    m_ListeStation.push_back(N197);

    station N198(TNSC("Maisons-Alfort - Les Juillottes"),48.802567,2.446432);
    N198.RTabLDS(8.1);
    N198.RTabLDS(8.2);
    N198.RTabSV(TNSC("Créteil - L'Echat"));
    N198.RTabSV(TNSC("Maisons-Alfort - Stade"));
    m_ListeStation.push_back(N198);

    station N199(TNSC("Créteil - L'Echat"),48.795963,2.449356);
    N199.RTabLDS(8.1);
    N199.RTabLDS(8.2);
    N199.RTabSV(TNSC("Maisons-Alfort - Les Juillottes"));
    N199.RTabSV(TNSC("Créteil - Université"));
    m_ListeStation.push_back(N199);

    station N200(TNSC("Créteil - Université"),48.789754,2.450785);
    N200.RTabLDS(8.1);
    N200.RTabLDS(8.2);
    N200.RTabSV(TNSC("Créteil - L'Echat"));
    N200.RTabSV(TNSC("Créteil - Préfecture"));
    m_ListeStation.push_back(N200);

    station N201(TNSC("Créteil - Préfecture"),48.779772,2.459317);
    N201.RTabLDS(8.1);
    N201.RTabLDS(8.2);
    N201.RTabSV(TNSC("Pointe Du Lac"));
    N201.RTabSV(TNSC("Créteil - Université"));
    m_ListeStation.push_back(N201);

    station N202(TNSC("Pointe Du Lac"),48.768786,2.464811);
    N202.RTabLDS(8.1);
    N202.RTabLDS(8.2);
    N202.RTabSV(TNSC("Créteil - Préfecture"));
    m_ListeStation.push_back(N202);

    //********************Fin Ligne 8*************************//

    //********************Ligne 9************************//

    station N203(TNSC("Pont De Sèvres"),48.829747,2.231035);
    N203.RTabLDS(9.1);
    N203.RTabLDS(9.2);
    N203.RTabSV(TNSC("Billancourt"));
    m_ListeStation.push_back(N203);

    station N204(TNSC("Billancourt"),48.83209,2.238177);
    N204.RTabLDS(9.1);
    N204.RTabLDS(9.2);
    N204.RTabSV(TNSC("Pont De Sèvres"));
    N204.RTabSV(TNSC("Marcel Sembat"));
    m_ListeStation.push_back(N204);

    station N205(TNSC("Marcel Sembat"),48.83367,2.243579);
    N205.RTabLDS(9.1);
    N205.RTabLDS(9.2);
    N205.RTabSV(TNSC("Billancourt"));
    N205.RTabSV(TNSC("Porte De Saint-Cloud"));
    m_ListeStation.push_back(N205);

    station N206(TNSC("Porte De Saint-Cloud"),48.838082,2.256956);
    N206.RTabLDS(9.1);
    N206.RTabLDS(9.2);
    N206.RTabSV(TNSC("Exelmans"));
    N206.RTabSV(TNSC("Marcel Sembat"));
    m_ListeStation.push_back(N206);

    station N207(TNSC("Exelmans"),48.842405,2.259549);
    N207.RTabLDS(9.1);
    N207.RTabLDS(9.2);
    N207.RTabSV(TNSC("Michel-Ange - Molitor"));
    N207.RTabSV(TNSC("Porte De Saint-Cloud"));
    m_ListeStation.push_back(N207);

    station N208(TNSC("Michel-Ange - Molitor"),48.84496,2.261194);
    N208.RTabLDS(9.1);
    N208.RTabLDS(9.2);
    N208.RTabLDS(10.2);
    N208.RTabSV(TNSC("Exelmans"));
    N208.RTabSV(TNSC("Michel-Ange - Auteuil"));
    N208.RTabSV(TNSC("Boulogne - Jean Jaurès"));
    N208.RTabSV(TNSC("Chardon-Lagache"));
    m_ListeStation.push_back(N208);

    station N209(TNSC("Michel-Ange - Auteuil"),48.847771,2.26387);
    N209.RTabLDS(9.1);
    N209.RTabLDS(9.2);
    N209.RTabLDS(10.1);
    N209.RTabSV(TNSC("Michel-Ange - Molitor"));
    N209.RTabSV(TNSC("Jasmin"));
    N209.RTabSV(TNSC("Porte D'Auteuil"));
    N209.RTabSV(TNSC("Eglise D'Auteuil"));
    m_ListeStation.push_back(N209);

    station N210(TNSC("Jasmin"),48.851898,2.267856);
    N210.RTabLDS(9.1);
    N210.RTabLDS(9.2);
    N210.RTabSV(TNSC("Ranelagh"));
    N210.RTabSV(TNSC("Michel-Ange - Auteuil"));
    m_ListeStation.push_back(N210);

    station N211(TNSC("Ranelagh"),48.85502,2.269634);
    N211.RTabLDS(9.1);
    N211.RTabLDS(9.2);
    N211.RTabSV(TNSC("La Muette"));
    N211.RTabSV(TNSC("Jasmin"));
    m_ListeStation.push_back(N211);

    station N212(TNSC("La Muette"),48.857718,2.273719);
    N212.RTabLDS(9.1);
    N212.RTabLDS(9.2);
    N212.RTabSV(TNSC("Ranelagh"));
    N212.RTabSV(TNSC("Rue De La Pompe"));
    m_ListeStation.push_back(N212);

    station N213(TNSC("Rue De La Pompe"),48.863912,2.279052);
    N213.RTabLDS(9.1);
    N213.RTabLDS(9.2);
    N213.RTabSV(TNSC("La Muette"));
    N213.RTabSV(TNSC("Trocadéro"));
    m_ListeStation.push_back(N213);

    //***//

    station N214(TNSC("Iéna"),48.864466,2.29338);
    N214.RTabLDS(9.1);
    N214.RTabLDS(9.2);
    N214.RTabSV(TNSC("Alma - Marceau"));
    N214.RTabSV(TNSC("Trocadéro"));
    m_ListeStation.push_back(N214);

    station N215(TNSC("Alma - Marceau"),48.864904,2.300234);
    N215.RTabLDS(9.1);
    N215.RTabLDS(9.2);
    N215.RTabSV(TNSC("Iéna"));
    N215.RTabSV(TNSC("Franklin D. Roosevelt"));
    m_ListeStation.push_back(N215);

    //***//

    station N216(TNSC("Saint-Philippe Du Roule"),48.871941,2.310036);
    N216.RTabLDS(9.1);
    N216.RTabLDS(9.2);
    N216.RTabSV(TNSC("Miromesnil"));
    N216.RTabSV(TNSC("Franklin D. Roosevelt"));
    m_ListeStation.push_back(N216);

    station N217(TNSC("Miromesnil"),48.873667,2.314465);
    N217.RTabLDS(9.1);
    N217.RTabLDS(9.2);
    N217.RTabLDS(13.1);
    N217.RTabLDS(13.2);
    N217.RTabLDS(13.3);
    N217.RTabSV(TNSC("Saint-Philippe Du Roule"));
    N217.RTabSV(TNSC("Saint-Augustin"));
    N217.RTabSV(TNSC("Saint-Lazare"));
    N217.RTabSV(TNSC("Champs-Elysées - Clemenceau"));
    m_ListeStation.push_back(N217);

    station N218(TNSC("Saint-Augustin"),48.874441,2.322133);
    N218.RTabLDS(9.1);
    N218.RTabLDS(9.2);
    N218.RTabSV(TNSC("Miromesnil"));
    N218.RTabSV(TNSC("Havre - Caumartain"));
    m_ListeStation.push_back(N218);

    //***//

    //***//

    //***//

    //***//

    //***//

    //***//

    //***//

    //***//

    station N219(TNSC("Saint-Ambroise"),48.861295,2.374211);
    N219.RTabLDS(9.1);
    N219.RTabLDS(9.2);
    N219.RTabSV(TNSC("Oberkampf"));
    N219.RTabSV(TNSC("Voltaire"));
    m_ListeStation.push_back(N219);

    station N220(TNSC("Voltaire"),48.857803,2.380106);
    N220.RTabLDS(9.1);
    N220.RTabLDS(9.2);
    N220.RTabSV(TNSC("Saint-Ambroise"));
    N220.RTabSV(TNSC("Charonne"));
    m_ListeStation.push_back(N220);

    station N221(TNSC("Charonne"),48.855103,2.384639);
    N221.RTabLDS(9.1);
    N221.RTabLDS(9.2);
    N221.RTabSV(TNSC("Rue Des Boulets"));
    N221.RTabSV(TNSC("Voltaire"));
    m_ListeStation.push_back(N221);

    station N222(TNSC("Rue Des Boulets"),48.851811,2.390151);
    N222.RTabLDS(9.1);
    N222.RTabLDS(9.2);
    N222.RTabSV(TNSC("Nation"));
    N222.RTabSV(TNSC("Charonne"));
    m_ListeStation.push_back(N222);

    //***//

    station N223(TNSC("Buzenval"),48.851976,2.402045);
    N223.RTabLDS(9.1);
    N223.RTabLDS(9.2);
    N223.RTabSV(TNSC("Nation"));
    N223.RTabSV(TNSC("Maraîchers"));
    m_ListeStation.push_back(N223);

    station N224(TNSC("Maraîchers"),48.852851,2.40699);
    N224.RTabLDS(9.1);
    N224.RTabLDS(9.2);
    N224.RTabSV(TNSC("Buzenval"));
    N224.RTabSV(TNSC("Porte De Montreuil"));
    m_ListeStation.push_back(N224);

    station N225(TNSC("Porte De Montreuil"),48.853792,2.412245);
    N225.RTabLDS(9.1);
    N225.RTabLDS(9.2);
    N225.RTabSV(TNSC("Robespierre"));
    N225.RTabSV(TNSC("Maraîchers"));
    m_ListeStation.push_back(N225);

    station N226(TNSC("Robespierre"),48.855683,2.423678);
    N226.RTabLDS(9.1);
    N226.RTabLDS(9.2);
    N226.RTabSV(TNSC("Croix De Chavaux"));
    N226.RTabSV(TNSC("Porte De Montreuil"));
    m_ListeStation.push_back(N226);

    station N227(TNSC("Croix De Chavaux"),48.858055,2.435764);
    N227.RTabLDS(9.1);
    N227.RTabLDS(9.2);
    N227.RTabSV(TNSC("Robespierre"));
    N227.RTabSV(TNSC("Mairie De Montreuil"));
    m_ListeStation.push_back(N227);

    station N228(TNSC("Mairie De Montreuil"),48.862283,2.441847);
    N228.RTabLDS(9.1);
    N228.RTabLDS(9.2);
    N228.RTabSV(TNSC("Croix De Chavaux"));
    m_ListeStation.push_back(N228);

    //********************Fin Ligne 9*************************//

    //********************Ligne 10*************************//

    station N229(TNSC("Boulogne - Pont De Saint-Cloud"),48.840684,2.228331);
    N229.RTabLDS(10.1);
    N229.RTabLDS(10.2);
    N229.RTabSV(TNSC("Boulogne - Jean Jaurès"));
    m_ListeStation.push_back(N229);

    station N230(TNSC("Boulogne - Jean Jaurès"),48.842278,2.238877);
    N230.RTabLDS(10.1);
    N230.RTabLDS(10.2);
    N230.RTabSV(TNSC("Boulogne - Pont De Saint-Cloud"));
    N230.RTabSV(TNSC("Porte D'Auteuil"));
    N230.RTabSV(TNSC("Michel-Ange - Molitor"));
    m_ListeStation.push_back(N230);

    station N231(TNSC("Porte D'Auteuil"),48.848025,2.25875);
    N231.RTabLDS(10.1);
    N231.RTabSV(TNSC("Boulogne - Jean Jaurès"));
    N231.RTabSV(TNSC("Michel-Ange - Auteuil"));
    m_ListeStation.push_back(N231);

    //***//

    //***//

    station N232(TNSC("Chardon-Lagache"),48.845138,2.266214);
    N232.RTabLDS(10.2);
    N232.RTabSV(TNSC("Mirabeau"));
    N232.RTabSV(TNSC("Michel-Ange - Molitor"));
    m_ListeStation.push_back(N232);

    station N233(TNSC("Eglise D'Auteuil"),48.847169,2.26902);
    N233.RTabLDS(10.1);
    N233.RTabSV(TNSC("Javel - André Citroën"));
    N233.RTabSV(TNSC("Michel-Ange - Auteuil"));
    m_ListeStation.push_back(N233);

    station N234(TNSC("Mirabeau"),48.846739,2.271708);
    N234.RTabLDS(10.2);
    N234.RTabSV(TNSC("Chardon-Lagache"));
    N234.RTabSV(TNSC("Javel - André Citroën"));
    m_ListeStation.push_back(N234);

    station N235(TNSC("Javel - André Citroën"),48.846165,2.278716);
    N235.RTabLDS(10.1);
    N235.RTabLDS(10.2);
    N235.RTabSV(TNSC("Mirabeau"));
    N235.RTabSV(TNSC("Eglise D'Auteuil"));
    N235.RTabSV(TNSC("Charles Michels"));
    m_ListeStation.push_back(N235);

    station N236(TNSC("Charles Michels"),48.846591,2.286942);
    N236.RTabLDS(10.1);
    N236.RTabLDS(10.2);
    N236.RTabSV(TNSC("Javel - André Citroën"));
    N236.RTabSV(TNSC("Avenue Emile-Zola"));
    m_ListeStation.push_back(N236);

    station N237(TNSC("Avenue Emile-Zola"),48.846977,2.294512);
    N237.RTabLDS(10.1);
    N237.RTabLDS(10.2);
    N237.RTabSV(TNSC("Charles Michels"));
    N237.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    m_ListeStation.push_back(N237);

    //***//

    station N238(TNSC("Ségur"),48.847434,2.306853);
    N238.RTabLDS(10.1);
    N238.RTabLDS(10.2);
    N238.RTabSV(TNSC("Duroc"));
    N238.RTabSV(TNSC("La Motte-Picquet - Grenelle"));
    m_ListeStation.push_back(N238);

    station N239(TNSC("Duroc"),48.846829,2.316479);
    N239.RTabLDS(10.1);
    N239.RTabLDS(10.2);
    N239.RTabLDS(13.1);
    N239.RTabLDS(13.2);
    N239.RTabLDS(13.3);
    N239.RTabSV(TNSC("Ségur"));
    N239.RTabSV(TNSC("Vaneau"));
    N239.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    N239.RTabSV(TNSC("Saint-François-Xavier"));
    m_ListeStation.push_back(N239);

    station N240(TNSC("Vaneau"),48.848811,2.321205);
    N240.RTabLDS(10.1);
    N240.RTabLDS(10.2);
    N240.RTabSV(TNSC("Duroc"));
    N240.RTabSV(TNSC("Sèvres - Babylone"));
    m_ListeStation.push_back(N240);

    station N241(TNSC("Sèvres - Babylone"),48.85151,2.326655);
    N241.RTabLDS(10.1);
    N241.RTabLDS(10.2);
    N241.RTabLDS(12.1);
    N241.RTabLDS(12.2);
    N241.RTabSV(TNSC("Vaneau"));
    N241.RTabSV(TNSC("Mabillon"));
    N241.RTabSV(TNSC("Rue Du Bac"));
    N241.RTabSV(TNSC("Rennes"));
    m_ListeStation.push_back(N241);

    station N242(TNSC("Mabillon"),48.852775,2.335322);
    N242.RTabLDS(10.1);
    N242.RTabLDS(10.2);
    N242.RTabSV(TNSC("Odéon"));
    N242.RTabSV(TNSC("Sèvres - Babylone"));
    m_ListeStation.push_back(N242);

    //***//

    station N243(TNSC("Cluny - La Sorbonne"),48.851019,2.344583);
    N243.RTabLDS(10.1);
    N243.RTabLDS(10.2);
    N243.RTabSV(TNSC("Odéon"));
    N243.RTabSV(TNSC("Maubert - Mutualité"));
    m_ListeStation.push_back(N243);

    station N244(TNSC("Maubert - Mutualité"),48.850193,2.347936);
    N244.RTabLDS(10.1);
    N244.RTabLDS(10.2);
    N244.RTabSV(TNSC("Cluny - La Sorbonne"));
    N244.RTabSV(TNSC("Cardinal Lemoine"));
    m_ListeStation.push_back(N244);

    station N245(TNSC("Cardinal Lemoine"),48.847139,2.351203);
    N245.RTabLDS(10.1);
    N245.RTabLDS(10.2);
    N245.RTabSV(TNSC("Jussieu"));
    N245.RTabSV(TNSC("Maubert - Mutualité"));
    m_ListeStation.push_back(N245);

    //***//

    //***//

    //********************Fin Ligne 10*************************//

    //********************Ligne 11*************************//

    //***//

    //***//

    station N246(TNSC("Rambuteau"),48.861951,2.353905);
    N246.RTabLDS(11.1);
    N246.RTabLDS(11.2);
    N246.RTabSV(TNSC("Hôtel De Ville"));
    N246.RTabSV(TNSC("Arts Et Métiers"));
    m_ListeStation.push_back(N246);

    //***//

    //***//

    station N247(TNSC("Goncourt"),48.869831,2.370687);
    N247.RTabLDS(11.1);
    N247.RTabLDS(11.2);
    N247.RTabSV(TNSC("République"));
    N247.RTabSV(TNSC("Belleville"));
    m_ListeStation.push_back(N247);

    //***//

    station N248(TNSC("Pyrénées"),48.873875,2.385259);
    N248.RTabLDS(11.1);
    N248.RTabLDS(11.2);
    N248.RTabSV(TNSC("Jourdain"));
    N248.RTabSV(TNSC("Belleville"));
    m_ListeStation.push_back(N248);

    station N249(TNSC("Jourdain"),48.8752,2.389508);
    N249.RTabLDS(11.1);
    N249.RTabLDS(11.2);
    N249.RTabSV(TNSC("Pyrénées"));
    N249.RTabSV(TNSC("Place Des Fêtes"));
    m_ListeStation.push_back(N249);

    //***//

    station N250(TNSC("Télégraphe"),48.875463,2.398434);
    N250.RTabLDS(11.1);
    N250.RTabLDS(11.2);
    N250.RTabSV(TNSC("Porte Des Lilas"));
    N250.RTabSV(TNSC("Place Des Fêtes"));
    m_ListeStation.push_back(N250);

    //***//

    station N251(TNSC("Mairie Des Lilas"),48.879788,2.416289);
    N251.RTabLDS(11.1);
    N251.RTabLDS(11.2);
    N251.RTabSV(TNSC("Porte Des Lilas"));
    m_ListeStation.push_back(N251);

    //********************Fin Ligne 11*************************//

    //********************Ligne 12*************************//

    station N252(TNSC("Saint-Denis - Aubervilliers Front Populaire"),48.90678,2.36594);
    N252.RTabLDS(12.1);
    N252.RTabLDS(12.2);
    N252.RTabSV(TNSC("Porte De La Chapelle"));
    m_ListeStation.push_back(N252);

    station N253(TNSC("Porte De La Chapelle"),48.897274,2.359191);
    N253.RTabLDS(12.1);
    N253.RTabLDS(12.2);
    N253.RTabSV(TNSC("Saint-Denis - Aubervilliers Front Populaire"));
    N253.RTabSV(TNSC("Marx Dormoy"));
    m_ListeStation.push_back(N253);

    station N254(TNSC("Marx Dormoy"),48.890483,2.359968);
    N254.RTabLDS(12.1);
    N254.RTabLDS(12.2);
    N254.RTabSV(TNSC("Porte De La Chapelle"));
    N254.RTabSV(TNSC("Marcadet - Poissonniers"));
    m_ListeStation.push_back(N254);

    //***//

    station N255(TNSC("Jules Joffrin"),48.892437,2.344782);
    N255.RTabLDS(12.1);
    N255.RTabLDS(12.2);
    N255.RTabSV(TNSC("Lamarck - Caulaincourt"));
    N255.RTabSV(TNSC("Marcadet - Poissonniers"));
    m_ListeStation.push_back(N255);

    station N256(TNSC("Lamarck - Caulaincourt"),48.889849,2.338693);
    N256.RTabLDS(12.1);
    N256.RTabLDS(12.2);
    N256.RTabSV(TNSC("Jules Joffrin"));
    N256.RTabSV(TNSC("Abbesses"));
    m_ListeStation.push_back(N256);

    station N257(TNSC("Abbesses"),48.884375,2.338564);
    N257.RTabLDS(12.1);
    N257.RTabLDS(12.2);
    N257.RTabSV(TNSC("Lamarck - Caulaincourt"));
    N257.RTabSV(TNSC("Pigalle"));
    m_ListeStation.push_back(N257);

    //***//

    station N258(TNSC("Saint-Georges"),48.878449,2.337382);
    N258.RTabLDS(12.1);
    N258.RTabLDS(12.2);
    N258.RTabSV(TNSC("Notre-Dame-De-Lorette"));
    N258.RTabSV(TNSC("Pigalle"));
    m_ListeStation.push_back(N258);

    station N259(TNSC("Notre-Dame-De-Lorette"),48.876084,2.338586);
    N259.RTabLDS(12.1);
    N259.RTabLDS(12.2);
    N259.RTabSV(TNSC("Saint-Georges"));
    N259.RTabSV(TNSC("Trinité - D'Estienne D'Orves"));
    m_ListeStation.push_back(N259);

    station N260(TNSC("Trinité - D'Estienne D'Orves"),48.876302,2.333197);
    N260.RTabLDS(12.1);
    N260.RTabLDS(12.2);
    N260.RTabSV(TNSC("Notre-Dame-De-Lorette"));
    N260.RTabSV(TNSC("Saint-Lazare"));
    m_ListeStation.push_back(N260);

    //***//

    //***//

    //***//

    station N261(TNSC("Assemblée Nationale"),48.860655,2.32113);
    N261.RTabLDS(12.1);
    N261.RTabLDS(12.2);
    N261.RTabSV(TNSC("Concorde"));
    N261.RTabSV(TNSC("Solférino"));
    m_ListeStation.push_back(N261);

    station N262(TNSC("Solférino"),48.858249,2.323225);
    N262.RTabLDS(12.1);
    N262.RTabLDS(12.2);
    N262.RTabSV(TNSC("Assemblée Nationale"));
    N262.RTabSV(TNSC("Rue Du Bac"));
    m_ListeStation.push_back(N262);

    station N263(TNSC("Rue Du Bac"),48.85569,2.325607);
    N263.RTabLDS(12.1);
    N263.RTabLDS(12.2);
    N263.RTabSV(TNSC("Sèvres - Babylone"));
    N263.RTabSV(TNSC("Solférino"));
    m_ListeStation.push_back(N263);

    //***//

    station N264(TNSC("Rennes"),48.848193,2.327763);
    N264.RTabLDS(12.1);
    N264.RTabLDS(12.2);
    N264.RTabSV(TNSC("Sèvres - Babylone"));
    N264.RTabSV(TNSC("Notre-Dame-Des-Champs"));
    m_ListeStation.push_back(N264);

    station N265(TNSC("Notre-Dame-Des-Champs"),48.844568,2.328788);
    N265.RTabLDS(12.1);
    N265.RTabLDS(12.2);
    N265.RTabSV(TNSC("Rennes"));
    N265.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    m_ListeStation.push_back(N265);

    //***//

    station N266(TNSC("Falguière"),48.84449,2.317954);
    N266.RTabLDS(12.1);
    N266.RTabLDS(12.2);
    N266.RTabSV(TNSC("Pasteur"));
    N266.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    m_ListeStation.push_back(N266);

    //***//

    station N267(TNSC("Volontaires"),48.841343,2.307504);
    N267.RTabLDS(12.1);
    N267.RTabLDS(12.2);
    N267.RTabSV(TNSC("Pasteur"));
    N267.RTabSV(TNSC("Vaugirard"));
    m_ListeStation.push_back(N267);

    station N268(TNSC("Vaugirard"),48.839649,2.301491);
    N268.RTabLDS(12.1);
    N268.RTabLDS(12.2);
    N268.RTabSV(TNSC("Volontaires"));
    N268.RTabSV(TNSC("Convention"));
    m_ListeStation.push_back(N268);

    station N269(TNSC("Convention"),48.837419,2.296795);
    N269.RTabLDS(12.1);
    N269.RTabLDS(12.2);
    N269.RTabSV(TNSC("Porte De Versailles"));
    N269.RTabSV(TNSC("Vaugirard"));
    m_ListeStation.push_back(N269);

    station N270(TNSC("Porte De Versailles"),48.832328,2.287841);
    N270.RTabLDS(12.1);
    N270.RTabLDS(12.2);
    N270.RTabSV(TNSC("Corentin Celton"));
    N270.RTabSV(TNSC("Convention"));
    m_ListeStation.push_back(N270);

    station N271(TNSC("Corentin Celton"),48.826833,2.278985);
    N271.RTabLDS(12.1);
    N271.RTabLDS(12.2);
    N271.RTabSV(TNSC("Porte De Versailles"));
    N271.RTabSV(TNSC("Mairie D'Issy"));
    m_ListeStation.push_back(N271);

    station N272(TNSC("Mairie D'Issy"),48.824152,2.273434);
    N272.RTabLDS(12.1);
    N272.RTabLDS(12.2);
    N272.RTabSV(TNSC("Corentin Celton"));
    m_ListeStation.push_back(N272);

    //********************Fin Ligne 12*************************//

    //********************Ligne 13*************************//

    station N273(TNSC("Asnières - Gennevilliers Les Courtilles"),48.930606,2.283788);
    N273.RTabLDS(13.1);
    N273.RTabLDS(13.3);
    N273.RTabSV(TNSC("Les Agnettes"));
    m_ListeStation.push_back(N273);

    station N274(TNSC("Les Agnettes"),48.923039,2.285891);
    N274.RTabLDS(13.1);
    N274.RTabLDS(13.3);
    N274.RTabSV(TNSC("Asnières - Gennevilliers Les Courtilles"));
    N274.RTabSV(TNSC("Gabriel Péri"));
    m_ListeStation.push_back(N274);

    station N275(TNSC("Gabriel Péri"),48.916575,2.294388);
    N275.RTabLDS(13.1);
    N275.RTabLDS(13.3);
    N275.RTabSV(TNSC("Les Agnettes"));
    N275.RTabSV(TNSC("Mairie De Clichy"));
    m_ListeStation.push_back(N275);

    station N276(TNSC("Mairie De Clichy"),48.903959,2.305343);
    N276.RTabLDS(13.1);
    N276.RTabLDS(13.3);
    N276.RTabSV(TNSC("Porte De Clichy"));
    N276.RTabSV(TNSC("Gabriel Péri"));
    m_ListeStation.push_back(N276);

    station N277(TNSC("Porte De Clichy"),48.894345,2.313652);
    N277.RTabLDS(13.1);
    N277.RTabLDS(13.3);
    N277.RTabSV(TNSC("Brochant"));
    N277.RTabSV(TNSC("Mairie De Clichy"));
    m_ListeStation.push_back(N277);

    station N278(TNSC("Brochant"),48.890855,2.3197);
    N278.RTabLDS(13.1);
    N278.RTabLDS(13.3);
    N278.RTabSV(TNSC("Porte De Clichy"));
    N278.RTabSV(TNSC("La Fourche"));
    m_ListeStation.push_back(N278);

    station N279(TNSC("Saint-Denis - Université"),48.945799,2.363674);
    N279.RTabLDS(13.1);
    N279.RTabLDS(13.2);
    N279.RTabSV(TNSC("Basilique De Saint-Denis"));
    m_ListeStation.push_back(N279);

    station N280(TNSC("Basilique De Saint-Denis"),48.9381,2.360846);
    N280.RTabLDS(13.1);
    N280.RTabLDS(13.2);
    N280.RTabSV(TNSC("Saint-Denis - Université"));
    N280.RTabSV(TNSC("Saint-Denis - Porte De Paris"));
    m_ListeStation.push_back(N280);

    station N281(TNSC("Saint-Denis - Porte De Paris"),48.930211,2.357769);
    N281.RTabLDS(13.1);
    N281.RTabLDS(13.2);
    N281.RTabSV(TNSC("Basilique De Saint-Denis"));
    N281.RTabSV(TNSC("Carrefour Pleyel"));
    m_ListeStation.push_back(N281);

    station N282(TNSC("Carrefour Pleyel"),48.919942,2.343926);
    N282.RTabLDS(13.1);
    N282.RTabLDS(13.2);
    N282.RTabSV(TNSC("Mairie De Saint-Ouen"));
    N282.RTabSV(TNSC("Saint-Denis - Porte De Paris"));
    m_ListeStation.push_back(N282);

    station N283(TNSC("Mairie De Saint-Ouen"),48.911619,2.333753);
    N283.RTabLDS(13.1);
    N283.RTabLDS(13.2);
    N283.RTabSV(TNSC("Garibaldi"));
    N283.RTabSV(TNSC("Carrefour Pleyel"));
    m_ListeStation.push_back(N283);

    station N284(TNSC("Garibaldi"),48.906397,2.331907);
    N284.RTabLDS(13.1);
    N284.RTabLDS(13.2);
    N284.RTabSV(TNSC("Mairie De Saint-Ouen"));
    N284.RTabSV(TNSC("Porte De Saint-Ouen"));
    m_ListeStation.push_back(N284);

    station N285(TNSC("Porte De Saint-Ouen"),48.896774,2.32871);
    N285.RTabLDS(13.1);
    N285.RTabLDS(13.2);
    N285.RTabSV(TNSC("Garibaldi"));
    N285.RTabSV(TNSC("Guy Môquet"));
    m_ListeStation.push_back(N285);

    station N286(TNSC("Guy Môquet"),48.892221,2.327174);
    N286.RTabLDS(13.1);
    N286.RTabLDS(13.2);
    N286.RTabSV(TNSC("La Fourche"));
    N286.RTabSV(TNSC("Porte De Saint-Ouen"));
    m_ListeStation.push_back(N286);

    station N287(TNSC("La Fourche"),48.8869,2.325875);
    N287.RTabLDS(13.1);
    N287.RTabLDS(13.2);
    N287.RTabLDS(13.3);
    N287.RTabSV(TNSC("Brochant"));
    N287.RTabSV(TNSC("Guy Môquet"));
    N287.RTabSV(TNSC("Place De Clichy"));
    m_ListeStation.push_back(N287);

    //***//

    station N288(TNSC("Liège"),48.879626,2.326983);
    N288.RTabLDS(13.1);
    N288.RTabLDS(13.2);
    N288.RTabLDS(13.3);
    N288.RTabSV(TNSC("Saint-Lazare"));
    N288.RTabSV(TNSC("Place De Clichy"));
    m_ListeStation.push_back(N288);

    //***//

    //***//

    //***//

    //***//

    station N289(TNSC("Varenne"),48.856238,2.314921);
    N289.RTabLDS(13.1);
    N289.RTabLDS(13.2);
    N289.RTabLDS(13.3);
    N289.RTabSV(TNSC("Invalides"));
    N289.RTabSV(TNSC("Saint-François-Xavier"));
    m_ListeStation.push_back(N289);

    station N290(TNSC("Saint-François-Xavier"),48.851951,2.314475);
    N290.RTabLDS(13.1);
    N290.RTabLDS(13.2);
    N290.RTabLDS(13.3);
    N290.RTabSV(TNSC("Varenne"));
    N290.RTabSV(TNSC("Duroc"));
    m_ListeStation.push_back(N290);

    //***//

    //***//

    station N291(TNSC("Gaîté"),48.838654,2.322637);
    N291.RTabLDS(13.1);
    N291.RTabLDS(13.2);
    N291.RTabLDS(13.3);
    N291.RTabSV(TNSC("Montparnasse - Bienvenüe"));
    N291.RTabSV(TNSC("Pernety"));
    m_ListeStation.push_back(N291);

    station N292(TNSC("Pernety"),48.83421,2.318512);
    N292.RTabLDS(13.1);
    N292.RTabLDS(13.2);
    N292.RTabLDS(13.3);
    N292.RTabSV(TNSC("Gaîté"));
    N292.RTabSV(TNSC("Plaisance"));
    m_ListeStation.push_back(N292);

    station N293(TNSC("Plaisance"),48.831553,2.313741);
    N293.RTabLDS(13.1);
    N293.RTabLDS(13.2);
    N293.RTabLDS(13.3);
    N293.RTabSV(TNSC("Porte De Vanves"));
    N293.RTabSV(TNSC("Pernety"));
    m_ListeStation.push_back(N293);

    station N294(TNSC("Porte De Vanves"),48.82794,2.305884);
    N294.RTabLDS(13.1);
    N294.RTabLDS(13.2);
    N294.RTabLDS(13.3);
    N294.RTabSV(TNSC("Malakoff - Plateau De Vanves"));
    N294.RTabSV(TNSC("Plaisance"));
    m_ListeStation.push_back(N294);

    station N295(TNSC("Malakoff - Plateau De Vanves"),48.822842,2.298345);
    N295.RTabLDS(13.1);
    N295.RTabLDS(13.2);
    N295.RTabLDS(13.3);
    N295.RTabSV(TNSC("Porte De Vanves"));
    N295.RTabSV(TNSC("Malakoff - Rue Etienne-Dolet"));
    m_ListeStation.push_back(N295);

    station N296(TNSC("Malakoff - Rue Etienne-Dolet"),48.814703,2.297301);
    N296.RTabLDS(13.1);
    N296.RTabLDS(13.2);
    N296.RTabLDS(13.3);
    N296.RTabSV(TNSC("Malakoff - Plateau De Vanves"));
    N296.RTabSV(TNSC("Châtillon - Montrouge"));
    m_ListeStation.push_back(N296);

    station N297(TNSC("Châtillon - Montrouge"),48.810539,2.301826);
    N297.RTabLDS(13.1);
    N297.RTabLDS(13.2);
    N297.RTabLDS(13.3);
    N297.RTabSV(TNSC("Malakoff - Rue Etienne-Dolet"));
    m_ListeStation.push_back(N297);

    //********************Fin Ligne 13*************************//

    //********************Ligne 14*************************//

    //***//

    //***//

    //***//

    //***//

    //***//

    //***//

    station N298(TNSC("Cours Saint-Emilion"),48.833501,2.385935);
    N298.RTabLDS(14.1);
    N298.RTabLDS(14.2);
    N298.RTabSV(TNSC("Bercy"));
    N298.RTabSV(TNSC("Bibliothèque François-Mitterand"));
    m_ListeStation.push_back(N298);

    station N299(TNSC("Bibliothèque François-Mitterand"),48.829823,2.376781);
    N299.RTabLDS(14.1);
    N299.RTabLDS(14.2);
    N299.RTabSV(TNSC("Cours Saint-Emilion"));
    N299.RTabSV(TNSC("Olympiades"));
    m_ListeStation.push_back(N299);

    station N300(TNSC("Olympiades"),48.827262,2.368281);
    N300.RTabLDS(14.1);
    N300.RTabLDS(14.2);
    N300.RTabSV(TNSC("Bibliothèque François-Mitterand"));
    m_ListeStation.push_back(N300);

    //********************Fin Ligne 14*************************//
}


void reseauparis::CreationReseauLigne(void)
{
    int i = 0;
    int k = m_TableCodeLigne.size();
    for (i=0;i<k;i++)
    {
        ligne A(m_TableCodeLigne[i]);
        int j = 0;
        int l = m_TableNomStation.size();
        for(j=0;j<l;j++)
        {
            station T = m_ListeStation[j];
            A.RTabSSL(T);
        }
        m_ListeLigne.push_back(A);
    }
}



void reseauparis::CreationTabStationSurLigneOrdon()
{
    // on crée un tableau bidim avec les codes des stations ordonnées pour chaque ligne avec direction

    // ligne 1
    std::vector <int> L1D2;
    L1D2.push_back(TNSC("La Défense"));
    L1D2.push_back(TNSC("Esplanade De La Défense"));
    L1D2.push_back(TNSC("Pont De Neuilly"));
    L1D2.push_back(TNSC("Les Sablons"));
    L1D2.push_back(TNSC("Porte Maillot"));
    L1D2.push_back(TNSC("Argentine"));
    L1D2.push_back(TNSC("Charles De Gaulle - Etoile"));
    L1D2.push_back(TNSC("George V"));
    L1D2.push_back(TNSC("Franklin D. Roosevelt"));
    L1D2.push_back(TNSC("Champs-Elysées - Clemenceau"));
    L1D2.push_back(TNSC("Concorde"));
    L1D2.push_back(TNSC("Tuileries"));
    L1D2.push_back(TNSC("Palais Royal - Musée Du Louvre"));
    L1D2.push_back(TNSC("Louvre - Rivoli"));
    L1D2.push_back(TNSC("Châtelet"));
    L1D2.push_back(TNSC("Hôtel De Ville"));
    L1D2.push_back(TNSC("Saint-Paul"));
    L1D2.push_back(TNSC("Bastille"));
    L1D2.push_back(TNSC("Gare De Lyon"));
    L1D2.push_back(TNSC("Reuilly - Diderot"));
    L1D2.push_back(TNSC("Nation"));
    L1D2.push_back(TNSC("Porte De Vincennes"));
    L1D2.push_back(TNSC("Saint-Mandé"));
    L1D2.push_back(TNSC("Bérault"));
    L1D2.push_back(TNSC("Château De Vincennes"));

    std::vector <int> L1D1;
    int nbl = L1D2.size();
    int l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L1D1.push_back(L1D2[l]);
    }

    // ligne 2

    std::vector <int> L2D2;
    L2D2.push_back(TNSC("Porte Dauphine"));
    L2D2.push_back(TNSC("Victor Hugo"));
    L2D2.push_back(TNSC("Charles De Gaulle - Etoile"));
    L2D2.push_back(TNSC("Ternes"));
    L2D2.push_back(TNSC("Courcelles"));
    L2D2.push_back(TNSC("Monceau"));
    L2D2.push_back(TNSC("Villiers"));
    L2D2.push_back(TNSC("Rome"));
    L2D2.push_back(TNSC("Place De Clichy"));
    L2D2.push_back(TNSC("Blanche"));
    L2D2.push_back(TNSC("Pigalle"));
    L2D2.push_back(TNSC("Anvers"));
    L2D2.push_back(TNSC("Barbès - Rochechouart"));
    L2D2.push_back(TNSC("La Chapelle"));
    L2D2.push_back(TNSC("Stalingrad"));
    L2D2.push_back(TNSC("Jaurès"));
    L2D2.push_back(TNSC("Colonel Fabien"));
    L2D2.push_back(TNSC("Belleville"));
    L2D2.push_back(TNSC("Couronnes"));
    L2D2.push_back(TNSC("Ménilmontant"));
    L2D2.push_back(TNSC("Père Lachaise"));
    L2D2.push_back(TNSC("Philippe Auguste"));
    L2D2.push_back(TNSC("Alexandre Dumas"));
    L2D2.push_back(TNSC("Avron"));
    L2D2.push_back(TNSC("Nation"));

    std::vector <int> L2D1;
    nbl = L2D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L2D1.push_back(L2D2[l]);
    }


    // ligne 3

    std::vector <int> L3D2;
    L3D2.push_back(TNSC("Pont De Levallois - Bécon"));
    L3D2.push_back(TNSC("Anatole France"));
    L3D2.push_back(TNSC("Louise Michel"));
    L3D2.push_back(TNSC("Porte De Champerret"));
    L3D2.push_back(TNSC("Pereire"));
    L3D2.push_back(TNSC("Wagram"));
    L3D2.push_back(TNSC("Malesherbes"));
    L3D2.push_back(TNSC("Villiers"));
    L3D2.push_back(TNSC("Europe"));
    L3D2.push_back(TNSC("Saint-Lazare"));
    L3D2.push_back(TNSC("Havre - Caumartain"));
    L3D2.push_back(TNSC("Opéra"));
    L3D2.push_back(TNSC("Quatre-Septembre"));
    L3D2.push_back(TNSC("Bourse"));
    L3D2.push_back(TNSC("Sentier"));
    L3D2.push_back(TNSC("Réaumur - Sébastopol"));
    L3D2.push_back(TNSC("Arts Et Métiers"));
    L3D2.push_back(TNSC("Temple"));
    L3D2.push_back(TNSC("République"));
    L3D2.push_back(TNSC("Parmentier"));
    L3D2.push_back(TNSC("Rue Saint-Maur"));
    L3D2.push_back(TNSC("Père Lachaise"));
    L3D2.push_back(TNSC("Gambetta"));
    L3D2.push_back(TNSC("Porte De Bagnolet"));
    L3D2.push_back(TNSC("Gallieni"));

    std::vector <int> L3D1;
    nbl = L3D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L3D1.push_back(L3D2[l]);
    }



    // ligne 3bis

    std::vector <int> L3D3;
    L3D3.push_back(TNSC("Gambetta"));
    L3D3.push_back(TNSC("Pelleport"));
    L3D3.push_back(TNSC("Saint-Fargeau"));
    L3D3.push_back(TNSC("Porte Des Lilas"));

    std::vector <int> L3D4;
    nbl = L3D3.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L3D4.push_back(L3D3[l]);
    }

    // ligne 4

    std::vector <int> L4D2;
    L4D2.push_back(TNSC("Porte De Clignancourt"));
    L4D2.push_back(TNSC("Simplon"));
    L4D2.push_back(TNSC("Marcadet - Poissonniers"));
    L4D2.push_back(TNSC("Château Rouge"));
    L4D2.push_back(TNSC("Barbès - Rochechouart"));
    L4D2.push_back(TNSC("Gare Du Nord"));
    L4D2.push_back(TNSC("Gare De L'Est"));
    L4D2.push_back(TNSC("Château D'Eau"));
    L4D2.push_back(TNSC("Strasbourg - Saint-Denis"));
    L4D2.push_back(TNSC("Réaumur - Sébastopol"));
    L4D2.push_back(TNSC("Etienne Marcel"));
    L4D2.push_back(TNSC("Les Halles"));
    L4D2.push_back(TNSC("Châtelet"));
    L4D2.push_back(TNSC("Cité"));
    L4D2.push_back(TNSC("Saint-Michel"));
    L4D2.push_back(TNSC("Odéon"));
    L4D2.push_back(TNSC("Saint-Germain-Des-Prés"));
    L4D2.push_back(TNSC("Saint-Sulpice"));
    L4D2.push_back(TNSC("Saint-Placide"));
    L4D2.push_back(TNSC("Montparnasse - Bienvenüe"));
    L4D2.push_back(TNSC("Vavin"));
    L4D2.push_back(TNSC("Raspail"));
    L4D2.push_back(TNSC("Denfert-Rochereau"));
    L4D2.push_back(TNSC("Mouton-Duvernet"));
    L4D2.push_back(TNSC("Alésia"));
    L4D2.push_back(TNSC("Porte D'Orléans"));
    L4D2.push_back(TNSC("Mairie De Montrouge"));

    std::vector <int> L4D1;
    nbl = L4D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L4D1.push_back(L4D2[l]);
    }

    // ligne 5

    std::vector <int> L5D2;
    L5D2.push_back(TNSC("Bobigny - Pablo Picasso"));
    L5D2.push_back(TNSC("Bobigny - Pantin - Raymond Queneau"));
    L5D2.push_back(TNSC("Eglise De Pantin"));
    L5D2.push_back(TNSC("Hoche"));
    L5D2.push_back(TNSC("Porte De Pantin"));
    L5D2.push_back(TNSC("Ourcq"));
    L5D2.push_back(TNSC("Laumière"));
    L5D2.push_back(TNSC("Jaurès"));
    L5D2.push_back(TNSC("Stalingrad"));
    L5D2.push_back(TNSC("Gare Du Nord"));
    L5D2.push_back(TNSC("Gare De L'Est"));
    L5D2.push_back(TNSC("Jacques Bonsergent"));
    L5D2.push_back(TNSC("République"));
    L5D2.push_back(TNSC("Oberkampf"));
    L5D2.push_back(TNSC("Richard-Lenoir"));
    L5D2.push_back(TNSC("Bréguet - Sabin"));
    L5D2.push_back(TNSC("Bastille"));
    L5D2.push_back(TNSC("Quai De La Rapée"));
    L5D2.push_back(TNSC("Gare D'Austerlitz"));
    L5D2.push_back(TNSC("Saint-Marcel"));
    L5D2.push_back(TNSC("Campo-Formio"));
    L5D2.push_back(TNSC("Place D'Italie"));

    std::vector <int> L5D1;
    nbl = L5D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L5D1.push_back(L5D2[l]);
    }


    // ligne 6

    std::vector <int> L6D2;
    L6D2.push_back(TNSC("Charles De Gaulle - Etoile"));
    L6D2.push_back(TNSC("Kléber"));
    L6D2.push_back(TNSC("Boissière"));
    L6D2.push_back(TNSC("Trocadéro"));
    L6D2.push_back(TNSC("Passy"));
    L6D2.push_back(TNSC("Bir-Hakeim"));
    L6D2.push_back(TNSC("Dupleix"));
    L6D2.push_back(TNSC("La Motte-Picquet - Grenelle"));
    L6D2.push_back(TNSC("Cambronne"));
    L6D2.push_back(TNSC("Sèvres - Lecourbe"));
    L6D2.push_back(TNSC("Pasteur"));
    L6D2.push_back(TNSC("Montparnasse - Bienvenüe"));
    L6D2.push_back(TNSC("Edgar Quinet"));
    L6D2.push_back(TNSC("Raspail"));
    L6D2.push_back(TNSC("Denfert-Rochereau"));
    L6D2.push_back(TNSC("Saint-Jacques"));
    L6D2.push_back(TNSC("Glacière"));
    L6D2.push_back(TNSC("Corvisart"));
    L6D2.push_back(TNSC("Place D'Italie"));
    L6D2.push_back(TNSC("Nationale"));
    L6D2.push_back(TNSC("Chevaleret"));
    L6D2.push_back(TNSC("Quai De La Gare"));
    L6D2.push_back(TNSC("Bercy"));
    L6D2.push_back(TNSC("Dugommier"));
    L6D2.push_back(TNSC("Daumesnil"));
    L6D2.push_back(TNSC("Bel-Air"));
    L6D2.push_back(TNSC("Picpus"));
    L6D2.push_back(TNSC("Nation"));

    std::vector <int> L6D1;
    nbl = L6D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L6D1.push_back(L6D2[l]);
    }

    // ligne 7

    // il y aura deux ligne dans chaques directions (la courneuve -> villejuif, villejuif->la courneuve, la courneuve -> Ivry, Ivry -> la courneuve)

    std::vector <int> L7D2;
    L7D2.push_back(TNSC("La Courneuve - 8 Mai 1945"));
    L7D2.push_back(TNSC("Fort D'Aubervilliers"));
    L7D2.push_back(TNSC("Aubervilliers - Pantin - Quatre Chemins"));
    L7D2.push_back(TNSC("Porte De La Villette"));
    L7D2.push_back(TNSC("Corentin Cariou"));
    L7D2.push_back(TNSC("Crimée"));
    L7D2.push_back(TNSC("Riquet"));
    L7D2.push_back(TNSC("Stalingrad"));
    L7D2.push_back(TNSC("Louis Blanc"));
    L7D2.push_back(TNSC("Château-Landon"));
    L7D2.push_back(TNSC("Gare De L'Est"));
    L7D2.push_back(TNSC("Poissonnière"));
    L7D2.push_back(TNSC("Cadet"));
    L7D2.push_back(TNSC("Le Peletier"));
    L7D2.push_back(TNSC("Chaussée D'Antin - La Fayette"));
    L7D2.push_back(TNSC("Opéra"));
    L7D2.push_back(TNSC("Pyramides"));
    L7D2.push_back(TNSC("Palais Royal - Musée Du Louvre"));
    L7D2.push_back(TNSC("Pont Neuf"));
    L7D2.push_back(TNSC("Châtelet"));
    L7D2.push_back(TNSC("Pont Marie"));
    L7D2.push_back(TNSC("Sully - Morland"));
    L7D2.push_back(TNSC("Jussieu"));
    L7D2.push_back(TNSC("Place Monge"));
    L7D2.push_back(TNSC("Censier - Daubenton"));
    L7D2.push_back(TNSC("Les Gobelins"));
    L7D2.push_back(TNSC("Place D'Italie"));
    L7D2.push_back(TNSC("Tolbiac"));
    L7D2.push_back(TNSC("Maison Blanche"));
    L7D2.push_back(TNSC("Le Kremlin-Bicêtre"));
    L7D2.push_back(TNSC("Villejuif - Léo Lagrange"));
    L7D2.push_back(TNSC("Villejuif - Paul Vaillant-Couturier"));
    L7D2.push_back(TNSC("Villejuif - Louis Aragon"));

    std::vector <int> L7D1a;
    nbl = L7D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L7D1a.push_back(L7D2[l]);
    }

    std::vector <int> L7D3;
    L7D3.push_back(TNSC("La Courneuve - 8 Mai 1945"));
    L7D3.push_back(TNSC("Fort D'Aubervilliers"));
    L7D3.push_back(TNSC("Aubervilliers - Pantin - Quatre Chemins"));
    L7D3.push_back(TNSC("Porte De La Villette"));
    L7D3.push_back(TNSC("Corentin Cariou"));
    L7D3.push_back(TNSC("Crimée"));
    L7D3.push_back(TNSC("Riquet"));
    L7D3.push_back(TNSC("Stalingrad"));
    L7D3.push_back(TNSC("Louis Blanc"));
    L7D3.push_back(TNSC("Château-Landon"));
    L7D3.push_back(TNSC("Gare De L'Est"));
    L7D3.push_back(TNSC("Poissonnière"));
    L7D3.push_back(TNSC("Cadet"));
    L7D3.push_back(TNSC("Le Peletier"));
    L7D3.push_back(TNSC("Chaussée D'Antin - La Fayette"));
    L7D3.push_back(TNSC("Opéra"));
    L7D3.push_back(TNSC("Pyramides"));
    L7D3.push_back(TNSC("Palais Royal - Musée Du Louvre"));
    L7D3.push_back(TNSC("Pont Neuf"));
    L7D3.push_back(TNSC("Châtelet"));
    L7D3.push_back(TNSC("Pont Marie"));
    L7D3.push_back(TNSC("Sully - Morland"));
    L7D3.push_back(TNSC("Jussieu"));
    L7D3.push_back(TNSC("Place Monge"));
    L7D3.push_back(TNSC("Censier - Daubenton"));
    L7D3.push_back(TNSC("Les Gobelins"));
    L7D3.push_back(TNSC("Place D'Italie"));
    L7D3.push_back(TNSC("Tolbiac"));
    L7D3.push_back(TNSC("Maison Blanche"));
    L7D3.push_back(TNSC("Porte D'Italie"));
    L7D3.push_back(TNSC("Porte De Choisy"));
    L7D3.push_back(TNSC("Porte D'Ivry"));
    L7D3.push_back(TNSC("Pierre Et Marie Curie"));
    L7D3.push_back(TNSC("Mairie D'Ivry"));

    std::vector <int> L7D1b;
    nbl = L7D3.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L7D1b.push_back(L7D3[l]);
    }


    // ligne 7bis
    std::vector <int> L7D4;
    L7D4.push_back(TNSC("Louis Blanc"));
    L7D4.push_back(TNSC("Jaurès"));
    L7D4.push_back(TNSC("Bolivar"));
    L7D4.push_back(TNSC("Buttes Chaumont"));
    L7D4.push_back(TNSC("Botzaris"));
    L7D4.push_back(TNSC("Place Des Fêtes"));
    L7D4.push_back(TNSC("Pré Saint-Gervais"));

    std::vector <int> L7D5;
    L7D5.push_back(TNSC("Pré Saint-Gervais"));
    L7D5.push_back(TNSC("Danube"));
    L7D5.push_back(TNSC("Botzaris"));
    L7D5.push_back(TNSC("Buttes Chaumont"));
    L7D5.push_back(TNSC("Bolivar"));
    L7D5.push_back(TNSC("Jaurès"));
    L7D5.push_back(TNSC("Louis Blanc"));

    // ligne 8

    std::vector <int> L8D2;
    L8D2.push_back(TNSC("Balard"));
    L8D2.push_back(TNSC("Lourmel"));
    L8D2.push_back(TNSC("Boucicaut"));
    L8D2.push_back(TNSC("Félix Faure"));
    L8D2.push_back(TNSC("Commerce"));
    L8D2.push_back(TNSC("La Motte-Picquet - Grenelle"));
    L8D2.push_back(TNSC("Ecole Militaire"));
    L8D2.push_back(TNSC("La Tour-Maubourg"));
    L8D2.push_back(TNSC("Invalides"));
    L8D2.push_back(TNSC("Concorde"));
    L8D2.push_back(TNSC("Madeleine"));
    L3D2.push_back(TNSC("Opéra"));
    L8D2.push_back(TNSC("Richelieu - Drouot"));
    L8D2.push_back(TNSC("Grands Boulevards"));
    L8D2.push_back(TNSC("Bonne-Nouvelle"));
    L8D2.push_back(TNSC("Strasbourg - Saint-Denis"));
    L8D2.push_back(TNSC("République"));
    L8D2.push_back(TNSC("Filles Du Calvaire"));
    L8D2.push_back(TNSC("Saint-Sébastien - Froissart"));
    L8D2.push_back(TNSC("Chemin Vert"));
    L8D2.push_back(TNSC("Bastille"));
    L8D2.push_back(TNSC("Ledru-Rollin"));
    L8D2.push_back(TNSC("Faidherbe - Chaligny"));
    L8D2.push_back(TNSC("Reuilly - Diderot"));
    L8D2.push_back(TNSC("Montgallet"));
    L8D2.push_back(TNSC("Daumesnil"));
    L8D2.push_back(TNSC("Michel Bizot"));
    L8D2.push_back(TNSC("Porte Dorée"));
    L8D2.push_back(TNSC("Porte De Charenton"));
    L8D2.push_back(TNSC("Liberté"));
    L8D2.push_back(TNSC("Charenton - Ecoles"));
    L8D2.push_back(TNSC("Ecole Vétérinaire De Maisons-Alfort"));
    L8D2.push_back(TNSC("Maisons-Alfort - Stade"));
    L8D2.push_back(TNSC("Maisons-Alfort - Les Juillottes"));
    L8D2.push_back(TNSC("Créteil - L'Echat"));
    L8D2.push_back(TNSC("Créteil - Université"));
    L8D2.push_back(TNSC("Créteil - Préfecture"));
    L8D2.push_back(TNSC("Pointe Du Lac"));

    std::vector <int> L8D1;
    nbl = L8D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L8D1.push_back(L8D2[l]);
    }

    // ligne 9

    std::vector <int> L9D1;
    L9D1.push_back(TNSC("Pont De Sèvres"));
    L9D1.push_back(TNSC("Billancourt"));
    L9D1.push_back(TNSC("Marcel Sembat"));
    L9D1.push_back(TNSC("Porte De Saint-Cloud"));
    L9D1.push_back(TNSC("Exelmans"));
    L9D1.push_back(TNSC("Michel-Ange - Molitor"));
    L9D1.push_back(TNSC("Michel-Ange - Auteuil"));
    L9D1.push_back(TNSC("Jasmin"));
    L9D1.push_back(TNSC("Ranelagh"));
    L9D1.push_back(TNSC("La Muette"));
    L9D1.push_back(TNSC("Rue De La Pompe"));
    L9D1.push_back(TNSC("Trocadéro"));
    L9D1.push_back(TNSC("Iéna"));
    L9D1.push_back(TNSC("Alma - Marceau"));
    L9D1.push_back(TNSC("Franklin D. Roosevelt"));
    L9D1.push_back(TNSC("Saint-Philippe Du Roule"));
    L9D1.push_back(TNSC("Miromesnil"));
    L9D1.push_back(TNSC("Saint-Augustin"));
    L9D1.push_back(TNSC("Havre - Caumartain"));
    L9D1.push_back(TNSC("Chaussée D'Antin - La Fayette"));
    L9D1.push_back(TNSC("Richelieu - Drouot"));
    L9D1.push_back(TNSC("Grands Boulevards"));
    L9D1.push_back(TNSC("Bonne-Nouvelle"));
    L9D1.push_back(TNSC("Strasbourg - Saint-Denis"));
    L9D1.push_back(TNSC("République"));
    L9D1.push_back(TNSC("Oberkampf"));
    L9D1.push_back(TNSC("Saint-Ambroise"));
    L9D1.push_back(TNSC("Voltaire"));
    L9D1.push_back(TNSC("Charonne"));
    L9D1.push_back(TNSC("Rue Des Boulets"));
    L9D1.push_back(TNSC("Nation"));
    L9D1.push_back(TNSC("Buzenval"));
    L9D1.push_back(TNSC("Maraîchers"));
    L9D1.push_back(TNSC("Porte De Montreuil"));
    L9D1.push_back(TNSC("Robespierre"));
    L9D1.push_back(TNSC("Croix De Chavaux"));
    L9D1.push_back(TNSC("Mairie De Montreuil"));

    std::vector <int> L9D2;
    nbl = L9D1.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L9D2.push_back(L9D1[l]);
    }

    // ligne 10

    std::vector <int> L10D2;
    L10D2.push_back(TNSC("Boulogne - Pont De Saint-Cloud"));
    L10D2.push_back(TNSC("Boulogne - Jean Jaurès"));
    L10D2.push_back(TNSC("Michel-Ange - Molitor"));
    L10D2.push_back(TNSC("Chardon-Lagache"));
    L10D2.push_back(TNSC("Mirabeau"));
    L10D2.push_back(TNSC("Javel - André Citroën"));
    L10D2.push_back(TNSC("Charles Michels"));
    L10D2.push_back(TNSC("Avenue Emile-Zola"));
    L10D2.push_back(TNSC("La Motte-Picquet - Grenelle"));
    L10D2.push_back(TNSC("Ségur"));
    L10D2.push_back(TNSC("Duroc"));
    L10D2.push_back(TNSC("Vaneau"));
    L10D2.push_back(TNSC("Sèvres - Babylone"));
    L10D2.push_back(TNSC("Mabillon"));
    L10D2.push_back(TNSC("Odéon"));
    L10D2.push_back(TNSC("Cluny - La Sorbonne"));
    L10D2.push_back(TNSC("Maubert - Mutualité"));
    L10D2.push_back(TNSC("Cardinal Lemoine"));
    L10D2.push_back(TNSC("Jussieu"));
    L10D2.push_back(TNSC("Gare D'Austerlitz"));

    std::vector <int> L10D1;
    L10D1.push_back(TNSC("Gare D'Austerlitz"));
    L10D1.push_back(TNSC("Jussieu"));
    L10D1.push_back(TNSC("Cardinal Lemoine"));
    L10D1.push_back(TNSC("Maubert - Mutualité"));
    L10D1.push_back(TNSC("Cluny - La Sorbonne"));
    L10D1.push_back(TNSC("Odéon"));
    L10D1.push_back(TNSC("Mabillon"));
    L10D1.push_back(TNSC("Sèvres - Babylone"));
    L10D1.push_back(TNSC("Vaneau"));
    L10D1.push_back(TNSC("Duroc"));
    L10D1.push_back(TNSC("Ségur"));
    L10D1.push_back(TNSC("La Motte-Picquet - Grenelle"));
    L10D1.push_back(TNSC("Avenue Emile-Zola"));
    L10D1.push_back(TNSC("Charles Michels"));
    L10D1.push_back(TNSC("Javel - André Citroën"));
    L10D1.push_back(TNSC("Eglise D'Auteuil"));
    L10D1.push_back(TNSC("Michel-Ange - Auteuil"));
    L10D1.push_back(TNSC("Porte D'Auteuil"));
    L10D1.push_back(TNSC("Boulogne - Jean Jaurès"));
    L10D1.push_back(TNSC("Boulogne - Pont De Saint-Cloud"));



    // ligne 11

    std::vector <int> L11D2;
    L11D2.push_back(TNSC("Châtelet"));
    L11D2.push_back(TNSC("Hôtel De Ville"));
    L11D2.push_back(TNSC("Rambuteau"));
    L11D2.push_back(TNSC("Arts Et Métiers"));
    L11D2.push_back(TNSC("République"));
    L11D2.push_back(TNSC("Goncourt"));
    L11D2.push_back(TNSC("Belleville"));
    L11D2.push_back(TNSC("Pyrénées"));
    L11D2.push_back(TNSC("Jourdain"));
    L11D2.push_back(TNSC("Place Des Fêtes"));
    L11D2.push_back(TNSC("Télégraphe"));
    L11D2.push_back(TNSC("Porte Des Lilas"));
    L11D2.push_back(TNSC("Mairie Des Lilas"));

    std::vector <int> L11D1;
    nbl = L11D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L11D1.push_back(L11D2[l]);
    }


    // ligne 12

    std::vector <int> L12D2;
    L12D2.push_back(TNSC("Saint-Denis - Aubervilliers Front Populaire"));
    L12D2.push_back(TNSC("Porte De La Chapelle"));
    L12D2.push_back(TNSC("Marx Dormoy"));
    L12D2.push_back(TNSC("Marcadet - Poissonniers"));
    L12D2.push_back(TNSC("Jules Joffrin"));
    L12D2.push_back(TNSC("Lamarck - Caulaincourt"));
    L12D2.push_back(TNSC("Abbesses"));
    L12D2.push_back(TNSC("Pigalle"));
    L12D2.push_back(TNSC("Saint-Georges"));
    L12D2.push_back(TNSC("Notre-Dame-De-Lorette"));
    L12D2.push_back(TNSC("Trinité - D'Estienne D'Orves"));
    L12D2.push_back(TNSC("Saint-Lazare"));
    L12D2.push_back(TNSC("Madeleine"));
    L12D2.push_back(TNSC("Concorde"));
    L12D2.push_back(TNSC("Assemblée Nationale"));
    L12D2.push_back(TNSC("Solférino"));
    L12D2.push_back(TNSC("Rue Du Bac"));
    L12D2.push_back(TNSC("Sèvres - Babylone"));
    L12D2.push_back(TNSC("Rennes"));
    L12D2.push_back(TNSC("Notre-Dame-Des-Champs"));
    L12D2.push_back(TNSC("Montparnasse - Bienvenüe"));
    L12D2.push_back(TNSC("Falguière"));
    L12D2.push_back(TNSC("Pasteur"));
    L12D2.push_back(TNSC("Volontaires"));
    L12D2.push_back(TNSC("Vaugirard"));
    L12D2.push_back(TNSC("Convention"));
    L12D2.push_back(TNSC("Porte De Versailles"));
    L12D2.push_back(TNSC("Corentin Celton"));
    L12D2.push_back(TNSC("Mairie D'Issy"));

    std::vector <int> L12D1;
    nbl = L12D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L12D1.push_back(L12D2[l]);
    }

    // ligne 13

    std::vector <int> L13D3a;
    L13D3a.push_back(TNSC("Asnières - Gennevilliers Les Courtilles"));
    L13D3a.push_back(TNSC("Les Agnettes"));
    L13D3a.push_back(TNSC("Gabriel Péri"));
    L13D3a.push_back(TNSC("Mairie De Clichy"));
    L13D3a.push_back(TNSC("Porte De Clichy"));
    L13D3a.push_back(TNSC("Brochant"));
    L13D3a.push_back(TNSC("La Fourche"));
    L13D3a.push_back(TNSC("Place De Clichy"));
    L13D3a.push_back(TNSC("Liège"));
    L13D3a.push_back(TNSC("Saint-Lazare"));
    L13D3a.push_back(TNSC("Miromesnil"));
    L13D3a.push_back(TNSC("Champs-Elysées - Clemenceau"));
    L13D3a.push_back(TNSC("Invalides"));
    L13D3a.push_back(TNSC("Varenne"));
    L13D3a.push_back(TNSC("Saint-François-Xavier"));
    L13D3a.push_back(TNSC("Duroc"));
    L13D3a.push_back(TNSC("Montparnasse - Bienvenüe"));
    L13D3a.push_back(TNSC("Gaîté"));
    L13D3a.push_back(TNSC("Pernety"));
    L13D3a.push_back(TNSC("Plaisance"));
    L13D3a.push_back(TNSC("Porte De Vanves"));
    L13D3a.push_back(TNSC("Malakoff - Plateau De Vanves"));
    L13D3a.push_back(TNSC("Malakoff - Rue Etienne-Dolet"));
    L13D3a.push_back(TNSC("Châtillon - Montrouge"));

    std::vector <int> L13D3b;
    L13D3b.push_back(TNSC("Saint-Denis - Université"));
    L13D3b.push_back(TNSC("Basilique De Saint-Denis"));
    L13D3b.push_back(TNSC("Saint-Denis - Porte De Paris"));
    L13D3b.push_back(TNSC("Carrefour Pleyel"));
    L13D3b.push_back(TNSC("Mairie De Saint-Ouen"));
    L13D3b.push_back(TNSC("Garibaldi"));
    L13D3b.push_back(TNSC("Porte De Saint-Ouen"));
    L13D3b.push_back(TNSC("Guy Môquet"));
    L13D3b.push_back(TNSC("La Fourche"));
    L13D3b.push_back(TNSC("Place De Clichy"));
    L13D3b.push_back(TNSC("Liège"));
    L13D3b.push_back(TNSC("Saint-Lazare"));
    L13D3b.push_back(TNSC("Miromesnil"));
    L13D3b.push_back(TNSC("Champs-Elysées - Clemenceau"));
    L13D3b.push_back(TNSC("Invalides"));
    L13D3b.push_back(TNSC("Varenne"));
    L13D3b.push_back(TNSC("Saint-François-Xavier"));
    L13D3b.push_back(TNSC("Duroc"));
    L13D3b.push_back(TNSC("Montparnasse - Bienvenüe"));
    L13D3b.push_back(TNSC("Gaîté"));
    L13D3b.push_back(TNSC("Pernety"));
    L13D3b.push_back(TNSC("Plaisance"));
    L13D3b.push_back(TNSC("Porte De Vanves"));
    L13D3b.push_back(TNSC("Malakoff - Plateau De Vanves"));
    L13D3b.push_back(TNSC("Malakoff - Rue Etienne-Dolet"));
    L13D3b.push_back(TNSC("Châtillon - Montrouge"));

    std::vector <int> L13D1;
    nbl = L13D3a.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L13D1.push_back(L13D3a[l]);
    }

    std::vector <int> L13D2;
    nbl = L13D3b.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L13D2.push_back(L13D3b[l]);
    }

    // ligne 14

    std::vector <int> L14D2;
    L14D2.push_back(TNSC("Saint-Lazare"));
    L14D2.push_back(TNSC("Madeleine"));
    L14D2.push_back(TNSC("Pyramides"));
    L14D2.push_back(TNSC("Châtelet"));
    L14D2.push_back(TNSC("Gare De Lyon"));
    L14D2.push_back(TNSC("Bercy"));
    L14D2.push_back(TNSC("Cours Saint-Emilion"));
    L14D2.push_back(TNSC("Bibliothèque François-Mitterand"));
    L14D2.push_back(TNSC("Olympiades"));

    std::vector <int> L14D1;
    nbl = L14D2.size();
    l = nbl - 1;
    for(l=nbl-1;l>=0;l--)
    {
        L14D1.push_back(L14D2[l]);
    }

    m_TabLigneOrdon.push_back(L1D1);
    m_TabLigneOrdon.push_back(L1D2);
    m_TabLigneOrdon.push_back(L2D1);
    m_TabLigneOrdon.push_back(L2D2);
    m_TabLigneOrdon.push_back(L3D1);
    m_TabLigneOrdon.push_back(L3D2);
    m_TabLigneOrdon.push_back(L3D3);
    m_TabLigneOrdon.push_back(L3D4);
    m_TabLigneOrdon.push_back(L4D1);
    m_TabLigneOrdon.push_back(L4D2);
    m_TabLigneOrdon.push_back(L5D1);
    m_TabLigneOrdon.push_back(L5D2);
    m_TabLigneOrdon.push_back(L6D1);
    m_TabLigneOrdon.push_back(L6D2);
    m_TabLigneOrdon.push_back(L7D1a);
    m_TabLigneOrdon.push_back(L7D1b);
    m_TabLigneOrdon.push_back(L7D2);
    m_TabLigneOrdon.push_back(L7D3);
    m_TabLigneOrdon.push_back(L7D4);
    m_TabLigneOrdon.push_back(L7D5);
    m_TabLigneOrdon.push_back(L8D1);
    m_TabLigneOrdon.push_back(L8D2);
    m_TabLigneOrdon.push_back(L9D1);
    m_TabLigneOrdon.push_back(L9D2);
    m_TabLigneOrdon.push_back(L10D1);
    m_TabLigneOrdon.push_back(L10D2);
    m_TabLigneOrdon.push_back(L11D1);
    m_TabLigneOrdon.push_back(L11D2);
    m_TabLigneOrdon.push_back(L12D1);
    m_TabLigneOrdon.push_back(L12D2);
    m_TabLigneOrdon.push_back(L13D1);
    m_TabLigneOrdon.push_back(L13D2);
    m_TabLigneOrdon.push_back(L13D3a);
    m_TabLigneOrdon.push_back(L13D3b);
    m_TabLigneOrdon.push_back(L14D1);
    m_TabLigneOrdon.push_back(L14D2);
}


std::vector <int> reseauparis::TransfoCodeLigne(double ll)
{
    std::vector <int> Vect;
    if(ll==1.1)
    {
        Vect.push_back(0);
    }
    if(ll==1.2)
    {
        Vect.push_back(1);
    }
    if(ll==2.1)
    {
        Vect.push_back(2);
    }
    if(ll==2.2)
    {
        Vect.push_back(3);
    }
    if(ll==3.1)
    {
        Vect.push_back(4);
    }
    if(ll==3.2)
    {
        Vect.push_back(5);
    }
    if(ll==3.3)
    {
        Vect.push_back(6);
    }
    if(ll==3.4)
    {
        Vect.push_back(7);
    }
    if(ll==4.1)
    {
        Vect.push_back(8);
    }
    if(ll==4.2)
    {
        Vect.push_back(9);
    }
    if(ll==5.1)
    {
        Vect.push_back(10);
    }
    if(ll==5.2)
    {
        Vect.push_back(11);
    }
    if(ll==6.1)
    {
        Vect.push_back(12);
    }
    if(ll==6.2)
    {
        Vect.push_back(13);
    }
    if(ll==7.1)
    {
        Vect.push_back(14);
        Vect.push_back(15);
    }
    if(ll== 7.2)
    {
        Vect.push_back(16);
    }
    if(ll== 7.3)
    {
        Vect.push_back(17);
    }
    if(ll==7.4)
    {
        Vect.push_back(18);
    }
    if(ll==7.5)
    {
        Vect.push_back(19);
    }
    if(ll==8.1)
    {
        Vect.push_back(20);
    }
    if(ll==8.2)
    {
        Vect.push_back(21);
    }
    if(ll==9.1)
    {
        Vect.push_back(22);
    }
    if(ll==9.2)
    {
        Vect.push_back(23);
    }
    if(ll==10.1)
    {
        Vect.push_back(24);
    }
    if(ll==10.2)
    {
        Vect.push_back(25);
    }
    if(ll==11.1)
    {
        Vect.push_back(26);
    }
    if(ll==11.2)
    {
        Vect.push_back(27);
    }
    if(ll==12.1)
    {
        Vect.push_back(28);
    }
    if(ll==12.2)
    {
        Vect.push_back(29);
    }
    if(ll==13.1)
    {
        Vect.push_back(30);
    }
    if(ll==13.2)
    {
        Vect.push_back(31);
    }
    if(ll==13.3)
    {
        Vect.push_back(32);
        Vect.push_back(33);
    }
    if(ll==14.1)
    {
        Vect.push_back(34);
    }
    if(ll==14.2)
    {
        Vect.push_back(35);
        Vect.push_back(36);
    }
    return Vect;
}


int reseauparis::TestLigneSurTrajet(int lll, int SD, int SF)
{
    std::vector <int> LigneCons = m_TabLigneOrdon[lll];
    int i=0;
    int nbi = LigneCons.size();
    int test = 0;
    for(i=0;i<(nbi-1);i++)
    {
        if(LigneCons[i] == SD && LigneCons[i+1] == SF)
        {
            test = 1;
        }
    }
    return test;
}


void reseauparis::CreationMatrices()
{
    int nbs = m_ListeStation.size();
    int nbl = m_ListeLigne.size();

    /* Pour la matrice des trajets : attention on ne peut pas se contenter
     * de remplir la partie triangulaire supérieure car pour le métro parisien certain ne sont
     * effectif que dans un seul sens : cf ligne 10 vers Auteuil ou ligne 7bis
     * la matrice n'est donc pas symétrique
     */

    /* Pour la matrice des vecteur contenant les ligne utilisant chaque trajet
     * Cell-ci n'est pas non plus symétrique et pour la diagonale on reporte le vecteur
     * contenant les ligne passant dans chaque station
     */


    int i=0;
    int j=0;
    for(i=0;i<nbs;i++)
    {
        for(j=0;j<nbs;j++)
        {
            trajetunit A(m_ListeStation[i],m_ListeStation[j]);
            //depart en i et arrivée en j
            // Trajet i->j case [i][j]
            // Trajet j->i case [j][i]
            m_VecteurBidimTrajet[i][j] = A.CalculDistance();
            int l=0;
            for(l=0;l<nbl;l++)
            {
                A.LigneSurTajet(m_ListeLigne[l]);
            }
            m_VecteurTridimLigneSurTrajet[i][j] = A.GetTabLigneSurTrajet();
        }
     }
}


void reseauparis::CorrectionMatriceLigneSurTrajet()
{
    int nbz = m_VecteurTridimLigneSurTrajet.size();
    int z=0;
    for(z=0;z<nbz;z++)
    {
        int y=0;
        for(y=0;y<nbz;y++)
        {
            if(m_VecteurTridimLigneSurTrajet[z][y][0] > 1.0)
            {
               std::vector <double> AAA = m_VecteurTridimLigneSurTrajet[z][y];
               int BBB = AAA.size();
               std::vector <int> DDD(BBB,0);
               int ccc = 0;
               for(ccc=0;ccc<BBB;ccc++)
               {
                   std::vector <int> lat = TransfoCodeLigne(AAA[ccc]);
                   int nlat = lat.size();
                   int k = 0;
                   int cpt = 0;
                   for(k=0;k<nlat;k++)
                   {
                        int HHH = lat[k];
                        int FFF = TestLigneSurTrajet(HHH,z,y);
                        cpt = cpt + FFF;
                   }

                   DDD[ccc] = cpt;
                }
                std::vector <double> newAAA;
                int ii=0;
                for(ii=0;ii<BBB;ii++)
                {
                   if(DDD[ii]>0)
                   {
                       newAAA.push_back(AAA[ii]);
                   }
                }
            m_VecteurTridimLigneSurTrajet[z][y] = newAAA;
            }
        }
    }
}


void reseauparis::CreationReseauComplet()
{
    Codage();
    CreationReseauStation();
    CreationReseauLigne();
    CreationMatrices();
    CreationTabStationSurLigneOrdon();
    CorrectionMatriceLigneSurTrajet();
}
