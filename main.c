#include "clienti.h"
#include "lezioni.h"
#include "date.h"
#include "prenotazioni.h"
#include <stdio.h>

int main() {
    // Inizializzazione liste
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();

    int scelta, scelta2;
    
    do {
        // Menu principale
        printf("\n--- MENU PRINCIPALE ---\n");
        printf("1. Gestione clienti\n");
        printf("2. Gestione lezioni\n");
        printf("3. Prenotazioni\n");
        printf("4. Verifica abbonamenti\n");
        printf("5. Genera report\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:  // Gestione clienti
                printf("\n--- GESTIONE CLIENTI ---\n");
                printf("1. Aggiungi cliente\n");
                printf("2. Visualizza prenotazioni cliente\n");
				printf("3. Lista completa clienti\n"); 
				printf("--------\n");
                printf("Scelta: ");
                scanf("%d", &scelta2);

                if (scelta2 == 1) {
                    char nome[50], cognome[50];
                    int giorni;
                    printf("Nome: "); 
                    scanf("%s", nome);
                    printf("Cognome: "); 
                    scanf("%s", cognome);
                    printf("Durata abbonamento (giorni): "); 
                    scanf("%d", &giorni);
                    aggiungiCliente(nome, cognome, giorni);
                } 
                else if (scelta2 == 2) {
                    int id_cliente;
                    printf("ID Cliente: "); 
                    scanf("%d", &id_cliente);
                    stampaPrenotazioniCliente(id_cliente);
                }else if (scelta2 == 3)
					{
						stampaListaClienti();
					}
                break;

            case 2:  // Gestione lezioni
                printf("\n--- GESTIONE LEZIONI ---\n");
                printf("1. Aggiungi lezione\n");
                printf("2. Visualizza disponibilità\n");
				printf("--------\n");
                printf("Scelta: ");
                scanf("%d", &scelta2);

                if (scelta2 == 1) {
                    char nome[50], orario[20];
                    int max;
                    date data;
                    printf("Nome lezione: "); 
                    scanf("%s", nome);
                    printf("Orario: "); 
                    scanf("%s", orario);
                    printf("Max partecipanti: "); 
                    scanf("%d", &max);
                    printf("Data (gg/mm/aaaa): "); 
                    scanf("%d/%d/%d", &data.gg, &data.mm, &data.aa);
                    aggiungiLezione(nome, orario, max, data);
                } 
                else if (scelta2 == 2) {
                    visualizzaDisponibilita();
                }
                break;

            case 3:  // Prenotazioni
                printf("\n--- PRENOTAZIONI ---\n");
                int id_cliente, id_lezione;
                printf("ID Cliente: "); 
                scanf("%d", &id_cliente);
                printf("ID Lezione: "); 
                scanf("%d", &id_lezione);
                aggiungiPrenotazione(id_cliente, id_lezione);
                break;

            case 4:  // Verifica abbonamenti
                verificaAbbonamenti();
                break;

            case 5:  // Genera report
                generaReport();
                break;

            case 0:  // Uscita
                printf("Uscita dal programma...\n");
                break;

            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    // Pulizia memoria
    liberaClienti();
    liberaLezioni();
    liberaPrenotazioni();

    return 0;
}