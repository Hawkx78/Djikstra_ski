#ifndef ALGO_H_
#define ALGO_H_

#define MAXINT 0x7fffffff

enum t_chemin {
	verte,
	bleue,
	rouge,
	noire,
	teleski,
	telecabine,
	telesiege,
	oeufs,
	hors_piste
};
enum t_skieur {
	debutant, confirme
};

typedef struct {

	int depart;
	int arrivee;

	enum t_chemin type;
	char nom[30];
	int longueur;

} chemin;

typedef struct {

	chemin ** chemins;
} arete;

typedef struct {

	chemin * trace;
	int poids;
} trace;

typedef struct {

	int nombre_sommet;
	arete * tab;
} graphe;

#define VERTE(d,a,n,l) {d, a, verte, n, l}
#define BLEUE(d,a,n,l) {d, a, bleue, n, l}
#define ROUGE(d,a,n,l) {d, a, rouge, n, l}
#define NOIRE(d,a,n,l) {d, a, noire, n, l}

#define TELESKI(d,a,n,l) {d, a, teleski, n, l}
#define TELECABINE(d,a,n,l) {d, a, telecabine, n, l}
#define TELESIEGE(d,a,n,l) {d, a, telesiege, n, l}
#define OEUFS(d,a,n,l) {d, a, oeufs, n, l}

#define FIN_DU_PLAN {0, 0, hors_piste, "Hors piste", 0}

#endif /* ALGO_H_ */
