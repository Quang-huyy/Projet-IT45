#ifndef COLLECTDATA_H
#define COLLECTDATA_H

#include <stdio.h>
#include <stdlib.h>

#define NB_CENTRE 2
#define NB_EMPLOYEES 4
#define NB_MISSIONS 30
#define NB_COMPETENCE 2
#define NB_SPECIALITE 5
#define NB_DISTANCE NB_CENTRE + NB_MISSIONS
extern const char fileEmployes[];
extern const char fileMissions[];
extern const char fileCentres[];
extern const char fileDistance[];

// Definition des structures
typedef struct
{
    int id;
    int jour;
    int heureDebut;
    int heureFin;
    char competence[50];
    char specialite[50];
} Mission;

typedef struct
{
    int id;
    int centreID;
    char competence[50];
    char specialite[50];
} Employee;

typedef struct
{
    int id;
    char centreID[10];
} Centre;

// Fonctions
void recupeInfo(const char *string1, const char *string2, const char *string3, const char *string4);

#endif // COLLECTDATA_H

extern Employee employee[NB_EMPLOYEES];
extern Mission mission[NB_MISSIONS];
extern Centre centre[NB_CENTRE];
extern double distance[NB_DISTANCE][NB_DISTANCE];

extern int nbEmployee;
extern int nbMission;
extern int nbCentre;