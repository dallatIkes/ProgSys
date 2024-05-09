CC = gcc
CFLAGS = -Wall -std=c99
INCLUDE = ../utils/include

./bin/$(bin) : ./src/$(src).c
	@echo "=== Génération des binaires"
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE) $< -lncurses
