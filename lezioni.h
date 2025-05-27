#ifndef LEZIONI_H
#define LEZIONI_H

#include "date.h"

// Struttura per rappresentare una lezione di fitness
typedef struct LezioneFitness {
    int id;                     // ID univoco della lezione
    char nome[50];              // Nome della lezione
    char orario[20];            // Orario della lezione
    int max_partecipanti;       // Numero massimo di partecipanti
    int prenotati;              // Numero di partecipanti prenotati
    date data;                  // Data della lezione
    struct LezioneFitness* next; // Puntatore alla prossima lezione
} LezioneFitness;

// Prototipi delle funzioni
void inizializzaLezioni();
int aggiungiLezione(const char* nome, const char* orario, int max_partecipanti, date data);
void visualizzaDisponibilita();
int verificaPostiDisponibili(int id_lezione);
int incrementaPrenotati(int id_lezione);
void liberaLezioni();

#endif