#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include "lezioni.h"

// Struttura per rappresentare una prenotazione
typedef struct Prenotazione {
    int id_cliente;             // ID del cliente che ha prenotato
    int id_lezione;             // ID della lezione prenotata
    struct Prenotazione* next;  // Puntatore alla prossima prenotazione
} Prenotazione;

// Prototipi delle funzioni
void inizializzaPrenotazioni();
int aggiungiPrenotazione(int id_cliente, int id_lezione);
void stampaPrenotazioniCliente(int id_cliente);
void generaReport();
void liberaPrenotazioni();

#endif