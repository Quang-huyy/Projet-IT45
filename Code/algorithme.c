#ifndef ALGORITHME_C
#define ALGORITHME_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "algorithme.h"
#include "evaluation.h"

int position[NB_EMPLOYEES];
int listeIndividuChoisi[POPULATION_SIZE];
int amplitude[5][NB_EMPLOYEES];

Individu individu[POPULATION_SIZE];
MeilleurIndividu meilleurIndividuGeneration[NB_GENERATION];
double somme;

void declarationVariables()
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        individu[i].speBonus = 0;
        individu[i].missionAffecte = 0;
        individu[i].cout = 0.0;
        individu[i].fitness = 0.0;
        individu[i].chance = 0.0;
    }
}
void resetAmplitude()
{
    for (int x = 0; x < NB_EMPLOYEES; x++)
    {
        if (employee[x].centreID == 1)
            position[x] = 0;
        else if (employee[x].centreID == 2)
            position[x] = 1;
    }
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < NB_EMPLOYEES; y++)
        {
            amplitude[x][y] = 0;
        }
    }

}

void construirePopulation()
{
    declarationVariables();
    srand(time(NULL));
    int iteration;        
    int value;
    for(int i=0;i<POPULATION_SIZE;i++)
    {
    resetAmplitude();
    for (int j = 0; j < NB_MISSIONS; j++)
    {
        iteration = 0;
        while (1)
        {
            value = rand() % NB_EMPLOYEES;
            if ((strcmp(mission[j].competence, employee[value].competence) == 0) &&
                ((amplitude[mission[j].jour][value] <= AMPLITUDE_MAX) &&
                 (amplitude[mission[j].jour][value] >= 0)))
            {
                individu[i].missionAffecte++;
                amplitude[mission[j].jour][value] += mission[j].heureFin - mission[j].heureDebut;
                individu[i].gene[j] = employee[value].id;
                if (employee[value].centreID == 1)
                    individu[i].cout += 0.2 * distance[position[value]][j];
                else if (employee[value].centreID == 2)
                    individu[i].cout += 0.2 * distance[position[value]][j];
                if ((strcmp(mission[j].specialite, employee[value].specialite) == 0))
                    individu[i].speBonus++;
                position[value] = j;

                break;
            }
            else
            {
                iteration++;
                if (iteration >= NB_ITERATION)
                {
                    individu[i].gene[j] = 0;
                    break;
                }
            }
        }
    //     for (int x = 0; x < 5; x++)
    //     {
    //     for (int y = 0; y < NB_EMPLOYEES; y++)
    //     {
    //         printf("%d  ", amplitude[x][y]);
    //     }
    //     }
    // }
    // printf("\n\n");
    }
    calculerFitness();
}
}

void croisementPopulation()
{
    int paireParent[POPULATION_SIZE][NB_MISSIONS];
    srand(time(NULL));

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NB_MISSIONS; j++)
        {
            paireParent[i][j] = individu[listeIndividuChoisi[i]].gene[j];
        }
    }

    int pointCroisement1, pointCroisement2;
    while (1)
    {
        pointCroisement1 = rand() % (NB_MISSIONS);
        pointCroisement2 = rand() % (NB_MISSIONS);

        if (pointCroisement1 != pointCroisement2)
            break;
    }

    if (pointCroisement1 > pointCroisement2)
    {
        int temp = pointCroisement1;
        pointCroisement1 = pointCroisement2;
        pointCroisement2 = temp;
    }

    for (int i = 0; i < POPULATION_SIZE; i += 2)
    {
        for (int j = 0; j < pointCroisement1; j++)
        {
            individu[i].gene[j] = paireParent[i][j];
            individu[i + 1].gene[j] = paireParent[i + 1][j];
        }

        for (int j = pointCroisement1; j < pointCroisement2; j++)
        {
            individu[i].gene[j] = paireParent[i + 1][j - pointCroisement1];
            individu[i + 1].gene[j] = paireParent[i][j - pointCroisement1];
        }

        for (int j = pointCroisement2; j < NB_MISSIONS; j++)
        {
            individu[i].gene[j] = paireParent[i][j];
            individu[i + 1].gene[j] = paireParent[i + 1][j];
        }
    }
    for(int i=0;i<POPULATION_SIZE;i++)
    {
        for(int j=0;j<NB_MISSIONS;j++)
        {
                if ((strcmp(mission[j].competence, employee[individu[i].gene[j]].competence) != 0) &&
                ((amplitude[mission[j].jour][individu[i].gene[j]] > AMPLITUDE_MAX) &&
                 (amplitude[mission[j].jour][individu[i].gene[j]] < 0)))
                continue;
            else
                break;
        }
    }

    printf("Les points de croisement sont: %d, %d\n", pointCroisement1, pointCroisement2);
}
void mutationPopulation()
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NB_MISSIONS; j++)
        {
            float chanceMutation = (float)rand() / RAND_MAX;
            if (chanceMutation <= PROB_MUTATION)
            {
                while (1)
                {
                    int value = 1 + rand() % NB_EMPLOYEES;
                    amplitude[mission[j].jour][individu[i].gene[j]]-=mission[j].heureFin-mission[j].heureDebut;
                    amplitude[mission[j].jour][value-1]+=mission[j].heureFin-mission[j].heureDebut;
                    if ((strcmp(mission[j].competence, employee[value - 1].competence) == 0) &&
                        ((amplitude[mission[j].jour][value - 1] <= AMPLITUDE_MAX) &&
                         (amplitude[mission[j].jour][value - 1] >= 0)) &&
                        (value != individu[i].gene[j]))
                    {
                        printf("For the individual number %d, the mission %d is mutated from %d to %d\n", i, j, individu[i].gene[j], value);
                        individu[i].gene[j] = value;
                        break;
                    }
                    else 
                    {
                        continue;
                    }
                }
            }
        }
    }
    calculerFitness();
    calculerIndividu();
}
#endif

