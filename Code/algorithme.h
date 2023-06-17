#ifndef ALGORITHME_H
#define ALGORITHME_H

#include <stdio.h>
#include <stdlib.h>

#include "collectData.h"
#include "analyseData.h"

#define NB_ITERATION 0
#define POPULATION_SIZE 10
#define AMPLITUDE_MAX 480
#define PROB_MUTATION 0.02
#define NB_GENERATION 2

typedef struct {
    int gene[NB_MISSIONS];
    int speBonus;
    int missionAffecte;
    double cout;
    double fitness;
    double chance;
} Individu;

typedef struct{
    int id;
    int gene[NB_MISSIONS];
    int generation;
}MeilleurIndividu;

extern int position[NB_EMPLOYEES];
extern int listeIndividuChoisi[POPULATION_SIZE];
extern int amplitude[5][NB_EMPLOYEES];
extern double somme;

extern Individu individu[POPULATION_SIZE];
extern MeilleurIndividu meilleurIndividuGeneration[NB_GENERATION];

void resetAmplitude();
void declarationVariables();
void construirePopulation();
void croisementPopulation();
void mutationPopulation();

#endif // ALGORITHME_H