#include <criterion/criterion.h>
#include "clienti.h"
#include "lezioni.h"
#include "prenotazioni.h"

Test(prenotazioni, test_prenotazione_valida) {
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();
    
    // Setup
    date data = {15, 6, 2025};
    aggiungiCliente("Mario", "Rossi", 5);
    aggiungiLezione("Yoga", "18:00", 10, data);
    
    // Test
    int risultato = aggiungiPrenotazione(1, 1);
    
    // Verifiche
    cr_assert_eq(risultato, 1, "Prenotazione dovrebbe riuscire");
    
    Cliente* c = testa_clienti;
    cr_assert_eq(c->giorni_abbonamento, 4, "Giorni abbonamento dovrebbero decrementare");
    
    LezioneFitness* l = testa_lezioni;
    cr_assert_eq(l->prenotati, 1, "Posti prenotati dovrebbero incrementare");
    
    liberaClienti();
    liberaLezioni();
    liberaPrenotazioni();
}

Test(prenotazioni, test_prenotazione_senza_posti) {
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();
    
    // Setup
    date data = {15, 6, 2025};
    aggiungiCliente("Luigi", "Verdi", 3);
    aggiungiLezione("Pilates", "19:00", 1, data);
    aggiungiPrenotazione(1, 1); // Occupa l'unico posto
    
    // Test
    int risultato = aggiungiPrenotazione(1, 1);
    
    // Verifiche
    cr_assert_eq(risultato, 0, "Prenotazione dovrebbe fallire per posti esauriti");
    cr_assert_eq(testa_lezioni->prenotati, 1, "Posti prenotati non dovrebbero incrementare");
    
    liberaClienti();
    liberaLezioni();
    liberaPrenotazioni();
}