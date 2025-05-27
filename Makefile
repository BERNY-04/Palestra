# Makefile per il progetto di gestione palestra


# Makefile per il progetto di gestione palestra

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = palestra
SRC = main.c clienti.c lezioni.c prenotazioni.c
OBJ = $(SRC:.c=.o)
HEADERS = clienti.h lezioni.h prenotazioni.h date.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run