#ifndef AFFICHAGE_C
#define AFFICHAGE_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "collectData.h"
#include "analyseData.h"
#include "algorithme.h"

void afficherInfo() {
    printf("nbEmployee: %d\n", nbEmployee);
    printf("nbMission: %d\n", nbMission);
    printf("nbCentre: %d\n", nbCentre);

    for (int i = 0; i < nbEmployee; i++) {
        printf("%d,%d,%s,%s\n",
               employee[i].id,
               employee[i].centreID,
               employee[i].competence,
               employee[i].specialite);
    }
    printf("\n");
    for (int i = 0; i < nbMission; i++) {
        printf("%d,%d,%d,%d,%s,%s\n",
               mission[i].id,
               mission[i].jour,
               mission[i].heureDebut,
               mission[i].heureFin,
               mission[i].competence,
               mission[i].specialite);
    }
    printf("\n");
    for (int i = 0; i < nbCentre; i++) {
        printf("%d,%s\n",
               centre[i].id,
               centre[i].centreID);
    }
    printf("\n");
    for (int j = 0; j < NB_DISTANCE; j++) {
        printf("%d:", j);
        for (int i = 0; i < NB_DISTANCE; i++) {
            printf("%lf  ", distance[j][i]);
        }
        printf("\n");
    }
}

void affichage()
{
    for(int i=0;i<NB_CENTRE;i++)
    {
        printf("Centre %d:\n",i+1);
        printf("Nombre d'employes: %d\n",nbEmployesCentre[i][0]);
        printf("Nombre de competences:\n");
        printf("LSF: %d\n",listeCompetence[i][0]);
        printf("LPC: %d\n",listeCompetence[i][1]);
        printf("Nombre de specialites:\n");
        printf("Electricite: %d\n",listeSpecialite[i][0]);
        printf("Mecanique: %d\n",listeSpecialite[i][1]);
        printf("Musique: %d\n",listeSpecialite[i][2]);
        printf("Jardinage: %d\n",listeSpecialite[i][3]);
        printf("Menuiserie: %d\n",listeSpecialite[i][4]);
        printf("\n");
        
    }
}

void afficherEvaluation()
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NB_MISSIONS; j++)
        {
            printf("%d ", individu[i].gene[j]);
        }
        printf("    %f    ", individu[i].cout);
        printf("%d    ", individu[i].speBonus);
        printf("%d    ", individu[i].missionAffecte);
        printf("\n");
    }
    printf("Evaluation de cette génération est: %f\n", somme);
}


void afficherParent()
{
    printf("Les paires de parent choisi sont:\n");
    for (int i = 0; i < POPULATION_SIZE; i += 2)
    {
        printf("%d %d | ", listeIndividuChoisi[i], listeIndividuChoisi[i + 1]);
    }
    printf("\n");
}

#endif