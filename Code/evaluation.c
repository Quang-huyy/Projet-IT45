#ifndef EVALUATION_C
#define EVALUATION_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "algorithme.h"
#include "evaluation.h"
#include "affichage.h"

void calculerFitness()
{
    somme =0.0;
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        individu[i].fitness += 0.5 * individu[i].missionAffecte;
        individu[i].fitness += 0.3 * individu[i].speBonus;
        individu[i].fitness += 0.2 * individu[i].cout;
        somme += individu[i].fitness;
    }
}

void calculerIndividu()
{
    declarationVariables();    
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        resetAmplitude();
        for (int j = 0; j < NB_MISSIONS; j++)
        {
            int value = individu[i].gene[j];
            if(value !=0)
            {
            individu[i].missionAffecte++;
            amplitude[mission[j].jour][value] += mission[j].heureFin - mission[j].heureDebut;
            if (employee[value].centreID == 1)
                individu[i].cout += 0.2 * distance[position[value]][j];
            else if (employee[value].centreID == 2)
                individu[i].cout += 0.2 * distance[position[value]][j];
            if ((strcmp(mission[j].specialite, employee[value].specialite) == 0))
                individu[i].speBonus++;
            position[value] = j;
        }
        }
    }
}
void evaluerPopulation()
{
    calculerFitness();
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        individu[i].chance = individu[i].fitness / somme;
        if (i > 0)
            individu[i].chance += individu[i - 1].chance;
    }
    srand(time(NULL));
    for (int i = 1; i < POPULATION_SIZE; i++)
    {
        int valuePrev = -1;
        while (1)
        {
            double value = (double)rand() / RAND_MAX;
            for (int j = 0; j < POPULATION_SIZE; j++)
            {
                if ((individu[j].chance > value) && (j != valuePrev))
                {
                    if (j > 0 && individu[j].chance > individu[j - 1].chance)
                    {
                        listeIndividuChoisi[i] = j;
                        valuePrev = j;
                        break;
                    }
                    else if (j == 0)
                    {
                        listeIndividuChoisi[i] = j;
                        valuePrev = j;
                        break;
                    }
                }
            }
            if (listeIndividuChoisi[i] != -1)
                break;
        }
    }
}

int generation = 0;

int trouverMeilleurIndividu()
{
    int bestNA = 0;
    double bestC = 100.0;
    int bestNS = 0;
    int bestIndividual = 0;

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        if (individu[i].missionAffecte > bestNA)
        {
            bestNA = individu[i].missionAffecte;
            bestC = individu[i].cout;
            bestNS = individu[i].speBonus;
            bestIndividual = i;
        }
        else if (individu[i].missionAffecte == bestNA)
        {
            if (individu[i].cout < bestC)
            {
                bestC = individu[i].cout;
                bestNS = individu[i].speBonus;
                bestIndividual = i;
            }
            else if (individu[i].cout == bestC && individu[i].speBonus > bestNS)
            {
                bestNS = individu[i].speBonus;
                bestIndividual = i;
            }
        }
    }

    listeIndividuChoisi[0] = bestIndividual;
    memcpy(meilleurIndividuGeneration[generation].gene, individu[bestIndividual].gene, sizeof(meilleurIndividuGeneration[generation].gene));
    meilleurIndividuGeneration[generation].id = bestIndividual;
    meilleurIndividuGeneration[generation].generation = generation+1;
    generation++;

    return bestIndividual;
}
#endif