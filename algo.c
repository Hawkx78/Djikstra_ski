#include "stdlib.h"
#include "stdio.h"

#include "algo.h"


// Permet la conversion de i et j en index du tableau
int ij2tab(graphe * G, int i, int j) {
	return ((j - 1) * G->nombre_sommet + (i - 1));
}

const chemin p1 = { 1, 2, verte, "facile", 4 };

chemin plan_des_pistes[] = {
VERTE(9, 10, "celvan_s1", 2),
VERTE(10, 12, "celvan_s2", 7),
VERTE(12, 13, "celvan_s3", 1),
VERTE(13, 14, "celvan_s4", 8),
VERTE(14, 15, "celvan_s5",15),
VERTE(29, 21, "grand_alpes_s1", 3),
VERTE(28, 21, "grand_alpes_s2", 1),
VERTE(21, 18, "grand_alpes_s3", 2),
VERTE(18, 19, "grand_alpes_s4", 1),
VERTE(29, 19, "grand_serre", 7),
VERTE(99,92,"Barres_s1",1),
VERTE(92,93,"Barres_s2",5),
VERTE(94,95,"Route Frejus_s1",1),
VERTE(95,88,"Route Frejus_s2",9),
VERTE(88,95,"Route Frejus_s3",2),
VERTE(85,69,"Route Frejus_s4",3),
VERTE(96,97,"Chameant_s1",1),
VERTE(97,98,"Chameant_s2",1),
VERTE(98,92,"Chameant_s3",2),
VERTE(58,51,"Route Aravet",8),
VERTE (51,59,"Route Aravet",15),


BLEUE(1, 2, "myrtilles_s1b", 2),
BLEUE(2, 4, "myrtilles_s2b", 2),
BLEUE(4, 5, "myrtilles_s3", 3),
BLEUE(5, 8, "myrtilles_s4", 3),
BLEUE(8, 9, "myrtilles_s5", 2),
BLEUE(1, 3, "myrtilles_s1a", 3),
BLEUE(3, 4, "myrtilles_s2a", 1),
BLEUE(16, 27, "vallons_s1", 5),
BLEUE(40, 27, "vallons_s2", 8),
BLEUE(27, 18, "vallons_s3", 12),
BLEUE(18, 17, "vallons_s4", 1),
BLEUE(17, 19, "vallons_s5", 1),
BLEUE(19, 9, "vallons_s6", 4),
BLEUE(9, 20, "vallons_s7", 10),
BLEUE(20, 24, "vallons_s8", 3),
BLEUE(20, 35, "vallons_s9", 7),
BLEUE(39, 32, "combes_s1", 1),
BLEUE(32, 22, "combes_s2", 10),
BLEUE(19, 22, "combes_s3", 2),
BLEUE (76,83,"Traverse",2),
BLEUE (78,79,"Sellettes_s1",1),
BLEUE (79,80,"Sellettes_s2",1),
BLEUE (80,75,"Sellettes_s3",3),
BLEUE (75,64,"Sellettes_s4",2),
BLEUE (92,80,"Cabane",5),
BLEUE (96,91,"Pre de Jeanne_s1",2),
BLEUE (91,92,"Pre de Jeanne_s2",2),
BLEUE (62,55,"Alpage_s1",1),
BLEUE (55,56,"Alpage_s2",1),
BLEUE (53,54,"Fangeas_s1",2),
BLEUE (54,62,"Fangeas_s2",2),
BLEUE (62,64,"Fangeas_s3",1),
BLEUE (64,75,"Fangeas_s4",2),
BLEUE (75,76,"Fangeas_s5",1),
BLEUE (42,46,"Foret_s1",1),
BLEUE (44,46,"Foret_s2",2),
BLEUE (46,55,"Foret_s3",2),
BLEUE (56,52,"Marteau_s1",2),
BLEUE (52,57,"Marteau_s2",1),
BLEUE (57,58,"Marteau_s3",2),
BLEUE (58,66,"Marteau_s4",3),
BLEUE (66,67,"Marteau_s5",4),
BLEUE (42,45,"Genepi_s1",1),
BLEUE (45,54,"Genepi_s2",2),
BLEUE (40,53,"Etanis_s1",3),
BLEUE (53,41,"Etanis_s2",1),
BLEUE (41,39,"Etanis_s3",1),
BLEUE (39,42,"Etanis_s4",1),
BLEUE (52,102,"Melezes",1),
BLEUE (79,91,"Goulet_s1",1),
BLEUE (91,92,"Goulet_s2",2),
BLEUE (92,81,"Goulet_s3",4),
BLEUE (81,82,"Goulet_s4",1),
BLEUE (82,93,"Goulet_s5",1),
BLEUE (93,83,"Goulet_s6",1),
BLEUE (83,94,"Goulet_s7",1),
BLEUE (94,91,"Goulet_s8",1),

ROUGE(1, 3, "saludes_s1", 3),
ROUGE(3, 7, "saludes_s2", 7),
ROUGE(7, 9, "saludes_s3", 7),
ROUGE(6, 7, "eduits_s1", 3),
ROUGE(7, 11, "eduits_s2", 5),
ROUGE(10, 11, "eduits_s3", 1),
ROUGE(11, 12, "eduits_s4", 4),
ROUGE(12, 14, "eduits_s5",1),
ROUGE(6, 13, "aiguilette_s1", 10),
ROUGE(13, 14,"aiguilette_s2",1),
ROUGE(16, 8,"petite_alpe_s1", 8),
ROUGE(8, 9, "petite_alpe_s2", 4),
ROUGE(16, 17, "bois_des_coqs_s1", 7),
ROUGE(17, 9, "bois_des_coqs_s2", 5),
ROUGE (64,65,"Bois_s1",1),
ROUGE (65,77,"Bois_s2",3),
ROUGE (77,83,"Bois_s3",1),
ROUGE (95,86,"Prairies",1),
ROUGE (77,84,"Lacets",3),
ROUGE (94,84,"Bez_s1",1),
ROUGE (84,85,"Bez_s2",1),
ROUGE (85,86,"Bez_s3",1),
ROUGE (86,88,"Bez_s4",3),
ROUGE (88,89,"Bez_s5",3),
ROUGE (89,90,"Bez_s6",2),
ROUGE (101,100,"Cucumelle_s1",11),
ROUGE (100,94,"Cucumelle_s2",1),
ROUGE (78,73,"Clot Gauthier_s1",2),
ROUGE (73,70,"Clot Gauthier_s2",1),
ROUGE (70,71,"Clot Gauthier_s3",2),
ROUGE (71,72,"Clot Gauthier_s4",1),
ROUGE (71,74,"Clot Gauthier_s5",1),
ROUGE (72,74,"Clot Gauthier_s6",1),
ROUGE (74,75,"Clot Gauthier_s7",1),
ROUGE (53,75,"Echaillon",5),
ROUGE (53,61,"Rocher de lenfer_s1",3),
ROUGE (61,75,"Rocher de lenfer_s2",3),
ROUGE (40,41,"Draye_s1",3),
ROUGE (41,45,"Draye_s2",1),
ROUGE (45,44,"Draye_s3",1),
ROUGE (44,43,"Draye_s4",2),
ROUGE (43,33,"Draye_s5",2),
ROUGE (33,30,"Draye_s6",1),
ROUGE (30,31,"Draye_s7",1),
ROUGE (56,58,"Stade",3),


NOIRE(2, 5, "cabane du berger", 12),
NOIRE(40, 32, "mur_chevalier", 10),
NOIRE (73,72,"Super Draye",2),
NOIRE (40,39,"Mur Chevalier",5),
NOIRE (64,65,"Casse du Boeuf_s1",1),
NOIRE (65,66,"Casse du Boeuf_s2",6),
NOIRE (66,67,"Casse du Boeuf_s3",3),
NOIRE (67,69,"Casse du Boeufs_s4",1),
NOIRE (60,61,"Isolee",7),
NOIRE (60,70,"Ailefroide",4),
NOIRE (60,73,"Creux du Loup",6),

TELECABINE (90,81,"PONTILLAS",10),
TELECABINE (69,82,"FREJUS",8),
TELECABINE (59,58,"ARAVET",8),
TELECABINE (50,40,"SERRE CHEVALIER",10),

TELESIEGE(9, 1, "prorel", 10),
TELESIEGE(22, 40, "grand_serre", 10),
TELESIEGE(24, 39, "combes", 15),
TELESIEGE (75,78,"CLOT GAUTHIER",4),
TELESIEGE (94,101,"VALLONS",9),
TELESIEGE (69,64,"CASSE DU BOEUF",10),
TELESIEGE (50,43,"OREE DU BOIS",7),
TELESIEGE (58,53,"FORET",3),
TELESIEGE (76,53,"COTE CHEVALIER",5),

TELESKI(14, 6, "aiguilette", 10),
TELESKI(103, 16, "bois_des_coqs_1", 15),
TELESKI(9, 16, "bois_des_coqs_2", 15),
TELESKI(19, 28, "grand_alpe", 7),
TELESKI(19, 29, "replat", 10),
TELESKI (92,98,"CLOT",2),
TELESKI (93,99,"BARRES",4),
TELESKI (92,96,"MEA",3),
TELESKI (68,67,"MICKEY",1),
TELESKI (70,60,"EYCHAUDA",3),
TELESKI (82,80,"CRETES",4),
TELESKI (55,54,"ALPAGE",3),

FIN_DU_PLAN };

char * type_chemin(chemin * c) {
	switch (c->type) {
	case verte:
		return "verte";
		break;
	case bleue:
		return "bleue";
		break;
	case rouge:
		return "rouge";
		break;
	case noire:
		return "noire";
		break;
	case teleski:
		return "téléski";
		break;
	case telecabine:
		return "télécabine";
		break;
	case telesiege:
		return "télésiège";
		break;
	case oeufs:
		return "oeufs";
		break;
	default:
		return "hors-piste";
		break;
	}
}

void affiche_chemin(chemin * c) {
	printf("%s %s", type_chemin(c), c->nom);
}

// Permet de voir tous les chemins dans le graphe
void affiche_graphe(graphe * G) {

	for (int j = 1; j <= G->nombre_sommet; j++) {
		for (int i = 1; i <= G->nombre_sommet; i++) {
			arete a = G->tab[ij2tab(G, i, j)];
			chemin ** chemins = a.chemins;
			if (chemins != (chemin **) 0) {
				printf("De %d à %d: ", i, j);
				while (*chemins) {
					affiche_chemin(*chemins);
					chemins += 1;
				}
				printf("\n");
			}
		}
	}
	printf("\n");
}



// Permet d'initialiser le graphe avec tous les chemins
void init_graphe(graphe * G) {

	G->tab = calloc(G->nombre_sommet * G->nombre_sommet, sizeof(arete));

	chemin * pistes = plan_des_pistes;
	while (pistes->type != hors_piste) {
		int i = pistes->depart;
		int j = pistes->arrivee;
		arete * a = &(G->tab[ij2tab(G, i, j)]);

		if (a->chemins == (chemin **) 0) {
			a->chemins = calloc(10, sizeof(chemin));
			a->chemins[0] = pistes;
		} else {
			chemin ** chemins = a->chemins;
			while (*chemins != NULL)
				chemins++;
			*chemins = pistes;
		}
		pistes += 1;
	}
}

// Calcul du temps en fonction du niveau du skieur
int calcul_temps(chemin * chemin, enum t_skieur niveau) {
	if (niveau == debutant) {
		switch (chemin->type) {
		case verte:
			return chemin->longueur;
			break;
		case bleue:
			return chemin->longueur * 2;
			break;
		case rouge:
			return chemin->longueur * 3;
			break;
		case noire:
			return chemin->longueur * 4;
			break;

		case teleski:
			return chemin->longueur * 1;
			break;
		case telecabine:
			return chemin->longueur / 4;
			break;
		case telesiege:
			return chemin->longueur / 2;
			break;
		case oeufs:
			return chemin->longueur / 3;
			break;
		default:
			return MAXINT;
			break;

		}
	} else {
		switch (chemin->type) {
		case verte:
			return chemin->longueur;
			break;
		case bleue:
			return chemin->longueur;
			break;
		case rouge:
			return chemin->longueur;
			break;
		case noire:
			return chemin->longueur;
			break;

		case teleski:
			return chemin->longueur * 1;
			break;
		case telecabine:
			return chemin->longueur / 4;
			break;
		case telesiege:
			return chemin->longueur / 2;
			break;
		case oeufs:
			return chemin->longueur / 3;
			break;
		default:
			return MAXINT;
			break;

		}
	}
}


// Calcul de la durée minimal pour l'algorithme de Dijkstra
int calcul_duree(chemin ** chemins, enum t_skieur niveau) {
	int d = MAXINT;
	while (*chemins != (chemin *) 0) {
		int nd = calcul_temps(*chemins, niveau);
		if (nd < d)
			d = nd;
		chemins++;
	}

	return d;
}

// Affichage des différentes étapes de Dijkstra
void affiche_dijkstra(graphe * G, int * durees, int * peres) {
	return;

	printf("Durees = ");
	for (int i = 0; i < G->nombre_sommet; i++) {
		if (durees[i] == MAXINT)
		  printf("%02d-   oo|", i + 1);
		else
		  printf("%02d-% 5d|", i + 1, durees[i]);
	}
	printf("\n");
	printf("Peres  = ");
	for (int i = 0; i < G->nombre_sommet; i++) {
		printf("%02d-% 5d|", i + 1, peres[i]);
	}
	printf("\n");
}

// Permet de dire si les sommets on été vu lors de l'utilisation de Dijkstra
int deja_visite(int * parcours, int sommet) {
	int vu = 0;
	while (*parcours) {
		if (*parcours == sommet) {
			vu = 1;
			break;
		}
		parcours++;
	}
	return vu;
}

//Lis les sommets en partant de la fin pour écrire le parcours
void reverse_parcours(int * peres, int depart, int arrivee) {

	if (peres[arrivee-1] > 0)
		reverse_parcours(peres, depart, peres[arrivee-1]);
    printf("%d ",arrivee);
}

// Création d'un tableau pour pouvoir lire les sommets dans le bon ordre
int * parcours(int * peres, int depart, int arrivee) {
	int s = arrivee;
	int l = 0;
	// création d'un compteur pour créer un tableau de sommets
	while ((s > 0) && (s != depart)) {
		l += 1;
		s = peres[s-1];
	}
    s = arrivee;

    int * sommets = calloc(l+2, sizeof(int));
    sommets[l] = -1;
    //Ecriture des sommets en partant de l'arrivée dans le nouveau tableau
    while ((s > 0) && (s != depart)) {
    	sommets[l--] = s;
    	s = peres[s-1];
    }
    sommets[0] = depart;

    /*printf("Parcours inversé: ");
    for (int i = 0; sommets[i] > 0; i++) printf("%d ", sommets[i]);
    printf("\n");*/

    return sommets;
}

// Algorithme de Dijkstra
int * calcule_parcours(graphe * G, int depart, int arrivee, enum t_skieur niveau) {
	printf("Depart = %d, arrivée = %d, niveau = %d\n", depart, arrivee, niveau);

	int * visites = calloc(G->nombre_sommet + 1, sizeof(int));
	int * durees = calloc(G->nombre_sommet, sizeof(int));
	int * peres = calloc(G->nombre_sommet, sizeof(int));

	int * trace = visites;
	*(trace++) = depart;
	int nb_visites = 1;
	// Phase d'initialisation
	for (int i = 0; i < G->nombre_sommet; i++)
		if (i + 1 != depart) {
			arete * a = &(G->tab[ij2tab(G, depart, i + 1)]);
			if (a->chemins != (chemin **) 0) {
				durees[i] = calcul_duree(a->chemins, niveau);
				peres[i] = depart;
			} else
				durees[i] = MAXINT;
		}

	//affiche_dijkstra(G, durees, peres);
	//int lt = depart;

	// Boucle d'éxécution de l'algorithme
	while (1) {

		int dm = MAXINT;
		int t = 0;
		for (int i = 0; i < G->nombre_sommet; i++)
			if (!deja_visite(visites, i + 1))
				if (durees[i] < dm) {
					t = i + 1;
					dm = durees[i];
				}
		//printf("dm=%d t=%d\n", dm, t);
		if (t == 0) {
			//printf("Plus aucun sommet non visité!\n");
			break;
		}
		*(trace++) = t;
		nb_visites++;
		//lt = t;

		for (int i = 0; i < G->nombre_sommet; i++)
			if (!deja_visite(visites, i + 1)) {
				arete * a = &(G->tab[ij2tab(G, t, i + 1)]);
				//chemin ** tmp = a->chemins;
				if (a->chemins != (chemin **) 0) {
					durees[i] = dm + calcul_duree(a->chemins, niveau);
					peres[i] = t;
				}
				//if (a->chemins != tmp) printf("Bug\n");
			}
		//affiche_dijkstra(G, durees, peres);
		//printf("Sommets visités = ");
		//for (int * pt = visites; *pt != (int *)0; pt++) printf("%d ", *pt);
		//printf("\n");
	}
	printf("La durée de votre parcours est estimé à : %d minutes \n", durees[arrivee-1]);
	/*
	printf("Parcours trouvé : ");
	reverse_parcours(peres, depart, arrivee);
	printf("\n");
	*/
	return parcours(peres, depart, arrivee);
}

//Affichage du parcours avec le noms des chemins
void afficher_parcours(int * parcours, graphe * G, int n) {

	int d = *(parcours++);
	int a = -1;
	while ((a = *(parcours++)) > 0) {
		arete ar = G->tab[ij2tab(G, d, a)];
		chemin ** chemins = ar.chemins;
		if (chemins != (chemin **) 0) {
			printf("- %2d à %2d : ", d, a);
			while (*chemins) {
				int e = 0;
				e = calcul_duree(chemins, n);
				affiche_chemin(*chemins);
				chemins += 1;
				if (*chemins){
					if(e != calcul_duree(chemins++, n)){}
					else {printf(" ou "); chemins--;}
				}
			}
			printf("\n");
		}
		d = a;
	}
	printf("Arrivé!");
	printf("\n");
}

int main(int argc, char **argv) {

	graphe G = { 106, NULL };
	init_graphe(&G);

	//affiche_graphe(&G);

	int a = -1;
	int sommet_depart = 0;
	int sommet_arrivee = 0;
	
	printf("Quel skieur êtes-vous ?\n Si vous êtes debutant(e) entré(e) 0,\n Si vous êtes confirmé(e) entré(e) 1.");
	scanf("%d", &a);

	if ((a != 0) && (a != 1)) {
	  printf("vous n'avez pas entré(e) le niveau correct\n");
	  exit(99);
	}
	
	printf("D'où voulez-vous partir ? (regarder la map)");
	printf("\n");
	scanf("%d", &sommet_depart);
	if(sommet_depart > 105 || sommet_depart < 1){printf("sommet non valable"); exit(99);}
	printf("Où voulez-vous arriver ? (regarder la map)");
	printf("\n");
	scanf("%d", &sommet_arrivee);
	if(sommet_arrivee > 105 || sommet_arrivee < 1){printf("sommet non valable"); exit(99);}

	int * par = calcule_parcours(&G, sommet_depart, sommet_arrivee, a == 0 ? debutant : confirme);
    afficher_parcours(par, &G, a);

    free(par);
	return 0;
}
