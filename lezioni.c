#include "lezioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static LezioneFitness* testa_lezioni = NULL;    // Testa della lista lezioni
static int prossimo_id_lezione = 1;             // Contatore per gli ID lezioni

// Inizializza la lista lezioni
void inizializzaLezioni() {
    liberaLezioni();
    testa_lezioni = NULL;
    prossimo_id_lezione = 1;
}

// Aggiunge una nuova lezione alla lista
int aggiungiLezione(const char* nome, const char* orario, int max_partecipanti, date data) {
    // Validazione input
    if (max_partecipanti <= 0) {
        printf("Errore: numero massimo partecipanti non valido.\n");
        return -1;
    }

    // Validazione data (semplificata)
    if (data.aa < 2023 || data.mm < 1 || data.mm > 12 || data.gg < 1 || data.gg > 31) {
        printf("Errore: data non valida.\n");
        return -1;
    }

    LezioneFitness* nuova = malloc(sizeof(LezioneFitness));
    if (!nuova) {
        printf("Errore di memoria.\n");
        return -1;
    }

    // Inizializzazione nuova lezione
    nuova->id = prossimo_id_lezione++;
    strncpy(nuova->nome, nome, sizeof(nuova->nome));
    strncpy(nuova->orario, orario, sizeof(nuova->orario));
    nuova->max_partecipanti = max_partecipanti;
    nuova->prenotati = 0;
    nuova->data = data;
    nuova->next = testa_lezioni;
    testa_lezioni = nuova;

    printf("Lezione aggiunta con ID %d.\n", nuova->id);
    return nuova->id;
}

// Visualizza tutte le lezioni con disponibilità
void visualizzaDisponibilita() {
    printf("\n--- Disponibilità Lezioni ---\n");
    LezioneFitness* curr = testa_lezioni;
    
    if (!curr) {
        printf("Nessuna lezione disponibile.\n");
        return;
    }

    while (curr) {
        printf("ID: %d | %s alle %s | Posti: %d/%d | Data: %02d/%02d/%d\n",
               curr->id, curr->nome, curr->orario, curr->prenotati,
               curr->max_partecipanti, curr->data.gg, curr->data.mm, curr->data.aa);
        curr = curr->next;
    }
}

// Verifica se ci sono posti disponibili per una lezione
int verificaPostiDisponibili(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione) {
            return curr->prenotati < curr->max_partecipanti;
        }
        curr = curr->next;
    }
    return 0;
}

// Incrementa il contatore dei prenotati per una lezione
int incrementaPrenotati(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione && curr->prenotati < curr->max_partecipanti) {
            curr->prenotati++;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

// Libera la memoria occupata dalla lista lezioni
void liberaLezioni() {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        LezioneFitness* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_lezioni = NULL;
}