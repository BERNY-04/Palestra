#include <criterion/criterion.h>
#include "clienti.h"

Test(abbonamenti, test_verifica_validita) {
    inizializzaClienti();
    
    // Setup
    aggiungiCliente("Anna", "Bianchi", 2);
    aggiungiCliente("Paolo", "Neri", 0);
    
    // Test e verifiche
    cr_assert_eq(verificaValiditaAbbonamento(1), 1, "Abbonamento dovrebbe essere valido");
    cr_assert_eq(verificaValiditaAbbonamento(2), 0, "Abbonamento dovrebbe essere scaduto");
    cr_assert_eq(verificaValiditaAbbonamento(99), 0, "Cliente inesistente dovrebbe restituire 0");
    
    liberaClienti();
}

Test(abbonamenti, test_decremento_automatico) {
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();
    
    // Setup
    date data = {16, 6, 2025};
    aggiungiCliente("Giulia", "Gialli", 3);
    aggiungiLezione("Zumba", "20:00", 5, data);
    
    // Test
    aggiungiPrenotazione(1, 1);
    aggiungiPrenotazione(1, 1);
    
    // Verifiche
    cr_assert_eq(testa_clienti->giorni_abbonamento, 1, "Giorni dovrebbero decrementare per ogni prenotazione");
    
    liberaClienti();
    liberaLezioni();
    liberaPrenotazioni();
}