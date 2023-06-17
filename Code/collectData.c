#ifndef COLLECTDATA_C
#define COLLECTDATA_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "collectData.h"

const char fileEmployes[] = "D:\\IT45\\Projet\\Code\\instances\\30Missions-2centres\\Employees.csv";
const char fileMissions[] = "D:\\IT45\\Projet\\Code\\instances\\30Missions-2centres\\Missions.csv";
const char fileCentres[] = "D:\\IT45\\Projet\\Code\\instances\\30Missions-2centres\\centers.csv";
const char fileDistance[] = "D:\\IT45\\Projet\\Code\\instances\\30Missions-2centres\\distances.csv";

Employee employee[NB_EMPLOYEES];
Mission mission[NB_MISSIONS];
Centre centre[NB_CENTRE];
double distance[NB_DISTANCE][NB_DISTANCE];

int nbEmployee;
int nbMission;
int nbCentre;

void recupeInfo(const char *string1, const char *string2, const char *string3, const char *string4) {
    FILE *file1 = fopen(string1, "r"); // employees
    if (file1 == NULL) {
        printf("Failed to open the employees file.\n");
        return;
    }

    // Read employee data
    nbEmployee = 0;
    while (!feof(file1) && nbEmployee < NB_EMPLOYEES) {
        fscanf(file1, "%d,%d,%[^,],%[^\n]\n",
               &employee[nbEmployee].id,
               &employee[nbEmployee].centreID,
               employee[nbEmployee].competence,
               employee[nbEmployee].specialite);
        nbEmployee++;
    }
    fclose(file1);

    FILE *file2 = fopen(string2, "r"); // missions
    if (file2 == NULL) {
        printf("Failed to open the missions file.\n");
        return;
    }

    // Read mission data
    nbMission = 0;
    while (!feof(file2) && nbMission < NB_MISSIONS) {
        fscanf(file2, "%d,%d,%d,%d,%[^,],%[^\n]",
               &mission[nbMission].id,
               &mission[nbMission].jour,
               &mission[nbMission].heureDebut,
               &mission[nbMission].heureFin,
               mission[nbMission].competence,
               mission[nbMission].specialite);
        nbMission++;
    }
    fclose(file2);

    FILE *file3 = fopen(string3, "r"); // centres
    if (file3 == NULL) {
        printf("Failed to open the centers file.\n");
        return;
    }

    // Read centre data
    nbCentre = 0;
    while (!feof(file3) && nbCentre < NB_CENTRE) {
        fscanf(file3, "%d,%[^\n]", &centre[nbCentre].id, centre[nbCentre].centreID);
        nbCentre++;
    }
    fclose(file3);

    FILE *file4 = fopen(string4, "r"); // distances
    if (file4 == NULL) {
        printf("Failed to open the distances file.\n");
        return;
    }
    // Read distance data
    while(!feof(file4)) {
        for (int i = 0; i < NB_DISTANCE; i++) {
            for (int j = 0; j < NB_DISTANCE; j++) {
                fscanf(file4, "%lf,", &distance[i][j]);
            }
        }
    }

    fclose(file4);
}

#endif