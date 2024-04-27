CC = gcc
CFLAGS = -Wall
INCLUDE = ../utils/include

./bin/$(bin) : ./src/$(src).c
	@echo "=== Génération des binaires"
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE) $<