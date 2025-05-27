#include "clienti.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* testa_clienti = NULL;    // Testa della lista clienti
static int prossimo_id = 1;              // Contatore per gli ID clienti

// Inizializza la lista clienti
void inizializzaClienti() {
    liberaClienti();
    testa_clienti = NULL;
    prossimo_id = 1;
}

// Aggiunge un nuovo cliente alla lista
int aggiungiCliente(const char* nome, const char* cognome, int giorni_abbonamento) {
    if (giorni_abbonamento <= 0) {
        printf("Errore: durata abbonamento non valida.\n");
        return -1;
    }

    Cliente* nuovo = malloc(sizeof(Cliente));
    if (!nuovo) {
        printf("Errore di memoria.\n");
        return -1;
    }

    nuovo->id = prossimo_id++;
    strncpy(nuovo->nome, nome, sizeof(nuovo->nome));
    strncpy(nuovo->cognome, cognome, sizeof(nuovo->cognome));
    nuovo->giorni_abbonamento = giorni_abbonamento;
    nuovo->next = testa_clienti;
    testa_clienti = nuovo;

    printf("Cliente aggiunto con ID %d.\n", nuovo->id);
    return nuovo->id;
}

// Visualizza lo stato degli abbonamenti di tutti i clienti
void verificaAbbonamenti() {
    printf("\n--- Stato Abbonamenti ---\n");
    Cliente* curr = testa_clienti;
    
    if (!curr) {
        printf("Nessun cliente registrato.\n");
        return;
    }

    while (curr) {
        printf("\nCliente %d: %s %s | Giorni restanti: %d\n",
               curr->id, curr->nome, curr->cognome, curr->giorni_abbonamento);
        curr = curr->next;
    }
}



// Verifica se un cliente ha un abbonamento valido
int verificaValiditaAbbonamento(int id_cliente) {
    Cliente* curr = testa_clienti;
    while (curr) {
        if (curr->id == id_cliente)
            return curr->giorni_abbonamento > 0;
        curr = curr->next;
    }
    return 0;
}

void stampaListaClienti() {
    Cliente* corrente = testa_clienti;
    
    printf("\n--- LISTA COMPLETA CLIENTI ---\n");
    
    if (!corrente) {
        printf("Nessun cliente registrato.\n");
        return;
    }
    
    printf("%-5s %-20s %-20s\n", "ID", "NOME", "COGNOME");
    printf("----------------------------------------\n");
    
    while (corrente) {
        printf("%-5d %-20s %-20s\n", 
               corrente->id, corrente->nome, corrente->cognome);
        corrente = corrente->next;
    }
}

// Libera la memoria occupata dalla lista clienti
void liberaClienti() {
    Cliente* curr = testa_clienti;
    while (curr) {
        Cliente* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_clienti = NULL;
}