#include "prenotazioni.h"
#include "clienti.h"
#include "lezioni.h"
#include <stdio.h>
#include <stdlib.h>

static Prenotazione* testa_prenotazioni = NULL;  // Testa della lista prenotazioni

// Inizializza la lista prenotazioni
void inizializzaPrenotazioni() {
    liberaPrenotazioni();
    testa_prenotazioni = NULL;
}

// Aggiunge una nuova prenotazione
int aggiungiPrenotazione(int id_cliente, int id_lezione) {
    // Verifica validità abbonamento cliente
    if (!verificaValiditaAbbonamento(id_cliente)) {
        printf("Abbonamento non valido per il cliente %d.\n", id_cliente);
        return 0;
    }

    // Verifica disponibilità posti
    if (!verificaPostiDisponibili(id_lezione)) {
        printf("La lezione %d è al completo.\n", id_lezione);
        return 0;
    }

    // Trova il cliente e decrementa l'abbonamento
    Cliente* c = testa_clienti;
    while (c) {
        if (c->id == id_cliente) {
            if (c->giorni_abbonamento > 0) {
                c->giorni_abbonamento--; // DECREMENTO IMMEDIATO QUI
                break;
            } else {
                printf("Errore: abbonamento esaurito per il cliente %d.\n", id_cliente);
                return 0;
            }
        }
        c = c->next;
    }

    // Incrementa contatore prenotati nella lezione
    if (!incrementaPrenotati(id_lezione)) {
        printf("Errore durante la prenotazione.\n");
        return 0;
    }

    // Crea nuova prenotazione
    Prenotazione* nuova = malloc(sizeof(Prenotazione));
    if (!nuova) {
        printf("Errore di memoria.\n");
        return 0;
    }

    nuova->id_cliente = id_cliente;
    nuova->id_lezione = id_lezione;
    nuova->next = testa_prenotazioni;
    testa_prenotazioni = nuova;

    printf("Prenotazione registrata per cliente %d alla lezione %d.\n", id_cliente, id_lezione);
    return 1;
}

// Stampa tutte le prenotazioni di un cliente
void stampaPrenotazioniCliente(int id_cliente) {
    Prenotazione* curr = testa_prenotazioni;
    int trovato = 0;

    printf("\n--- Lezioni prenotate dal cliente %d ---\n", id_cliente);
    while (curr) {
        if (curr->id_cliente == id_cliente) {
            trovato = 1;
            printf(" - Lezione ID: %d\n", curr->id_lezione);
        }
        curr = curr->next;
    }

    if (!trovato) {
        printf("Nessuna prenotazione trovata per questo cliente.\n");
    }
}


// Genera un report delle prenotazioni
void generaReport() {
    int frequenza[100] = {0};  // Array per contare le prenotazioni per lezione
    Prenotazione* curr = testa_prenotazioni;

    // Conta le prenotazioni per ogni lezione
    while (curr) {
        if (curr->id_lezione > 0 && curr->id_lezione < 100) {
            frequenza[curr->id_lezione]++;
        }
        curr = curr->next;
    }

    // Stampa il report
    printf("\n--- Report Utilizzo Lezioni ---\n");
    for (int i = 1; i < 100; i++) {
        if (frequenza[i] > 0) {
            printf("Lezione ID %d: %d prenotazioni\n", i, frequenza[i]);
        }
    }
}

// Libera la memoria occupata dalla lista prenotazioni
void liberaPrenotazioni() {
    Prenotazione* curr = testa_prenotazioni;
    while (curr) {
        Prenotazione* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_prenotazioni = NULL;
}