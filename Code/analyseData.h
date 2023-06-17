#ifndef ANALYSEDATA_H
#define ANALYSEDATA_H

extern int listeEmployes[NB_CENTRE][NB_EMPLOYEES];
extern int nbEmployesCentre[NB_CENTRE][1];
// LSF -> LPC
extern int listeCompetence[NB_CENTRE][NB_COMPETENCE];
// Electricite -> Mecanique -> Musique
extern int listeSpecialite[NB_CENTRE][NB_SPECIALITE];
void analyse();

#endif