#!/bin/bash
g++ main.o -o main -L sfml/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
./main
