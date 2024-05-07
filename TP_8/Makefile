CC = gcc
CFLAGS = -Wall -lrt -pthread
INCLUDE = ../utils/include

./bin/$(bin) : ./src/$(src).c
	@echo "=== Génération des binaires"
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE) $<
