# Exemple de makefile un peu automatique
# version la plus simple, une version amelioree est proposee http://www.isima.fr/~loic/cpp/tp02.php

# compilateur
CC = g++

# options de compilation
CCFLAGS =-Wall -Wextra -ansi -pedantic -g -O2

# options de l'edition des liens
LDFLAGS =-lm

# liste des fichiers objets
OBJ =main.o neumann.o
EXE =executable

# regle finale pour la creation de l'executable
executable:$(OBJ)
	$(CC) $(LDFLAGS) -o ./exec/$@ $(OBJ)
	rm -rf $(OBJ) core *.h.gch

# compiler tous les .cpp en .o
.cpp.o: # %.o : %.cpp
	@$(CC) $(CCFLAGS) -c $<

# creation automatique des dependances
# attention : on liste tous les fichiers cpp du repertoire mais on peut affiner ;-)
dep:
	$(CC) -MM *.cpp > makefile.dep
	mkdir exec

clean:
	rm -rf $(OBJ) core *.h.gch

-include makefile.dep

# utilisation
# touch makefile.dep la premiere fois
# make dep des que les fichiers hpp et cpp sont modifies
# make comme d'habitude