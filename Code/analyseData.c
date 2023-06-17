#ifndef ANALYSEDATA_C
#define ANALYSEDATA_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "collectData.h"
#include "analyseData.h"

int listeEmployes[NB_CENTRE][NB_EMPLOYEES];
int nbEmployesCentre[NB_CENTRE][1];

// LSF -> LPC
int listeCompetence[NB_CENTRE][NB_COMPETENCE];
// Electricite -> Mecanique -> Musique
int listeSpecialite[NB_CENTRE][NB_SPECIALITE];

void analyse()
{
    for(int i=0;i<NB_CENTRE;i++)
    {
        for(int j=0;j<NB_EMPLOYEES;j++)
        {
        if (employee[j].centreID== centre[i].id) 
            {
            listeEmployes[i][j] = employee[j].id;
            nbEmployesCentre[i][0]++;
            }
        }
    }
    for(int i=0;i<NB_CENTRE;i++)
    {
        for(int j=0;j<NB_EMPLOYEES; j++)
        {
            if (employee[j].centreID== i+1) 
            {
            //Competence
            if (strcmp(employee[j].competence, "LSF") == 0)
                listeCompetence[i][0]++;
            else if (strcmp(employee[j].competence, "LPC") == 0)
                listeCompetence[i][1]++;
            //Specialite
            if (strcmp(employee[j].specialite,"Electricite")==0)
                listeSpecialite[i][0]++;
            else if (strcmp(employee[j].specialite,"Mecanique")==0)
                listeSpecialite[i][1]++;
            else if (strcmp(employee[j].specialite,"Musique")==0)
                listeSpecialite[i][2]++;
            else if (strcmp(employee[j].specialite,"Jardinage")==0)
                listeSpecialite[i][3]++;
            else if (strcmp(employee[j].specialite,"Menuiserie")==0)
                listeSpecialite[i][4]++;

        }
        }
    }
}
#endif