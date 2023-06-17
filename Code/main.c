#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "collectData.h"
#include "analyseData.h"
#include "affichage.h" 
#include "algorithme.h"
#include "evaluation.h"

int main()
{
    int bestIndividu, bestIndividuGeneration;
    recupeInfo(fileEmployes, fileMissions, fileCentres, fileDistance);
    for(int i=0;i<100000000;i++){}
    analyse();
    afficherInfo();
    affichage();
    construirePopulation();
    for (int i = 0; i < 10; i++)
    {
        printf("------------------Generation %d------------------\n", i + 1);
        afficherEvaluation();
        evaluerPopulation();
        bestIndividu = trouverMeilleurIndividu();
        printf("The best individual of generation is: %d\n", bestIndividu);
        afficherParent();
        croisementPopulation();
        mutationPopulation();
    }
    afficherEvaluation();
     for(int i=0; i<NB_GENERATION;i++)
     {
         printf("The best individual of generation %d is: %d\n", meilleurIndividuGeneration[i].generation, meilleurIndividuGeneration[i].id );
     }
    return 0;
}

#endif // MAIN_H