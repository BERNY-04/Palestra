#ifndef CLIENTI_H
#define CLIENTI_H

// Struttura per rappresentare un cliente
typedef struct Cliente {
    int id;                      // ID univoco del cliente
    char nome[50];               // Nome del cliente
    char cognome[50];            // Cognome del cliente
    int giorni_abbonamento;      // Giorni rimanenti dell'abbonamento
    struct Cliente* next;        // Puntatore al prossimo cliente nella lista
} Cliente;

extern Cliente* testa_clienti;


// Prototipi delle funzioni
void inizializzaClienti();
int aggiungiCliente(const char* nome, const char* cognome, int giorni_abbonamento);
void verificaAbbonamenti();
int verificaValiditaAbbonamento(int id_cliente);
void decrementaAbbonamenti();
void liberaClienti();
void stampaListaClienti();

#endif