SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CFLAGS=-Wall  -pedantic -g -std=c99 -I$(INCLUDEDIR)
EXEC=correcteur
CC=gcc
LDFLAGS=-L$(LIBDIR)
AR=ar
DOCDIR = doc
all : $(BINDIR)/$(EXEC)

doc :
	doxygen ./Doxyfile

tests: $(SRCDIR)/mot.o $(SRCDIR)/testMot.o $(SRCDIR)/levenshtein.o $(SRCDIR)/testLevenshtein.o $(SRCDIR)/listeDeMot.o $(SRCDIR)/testListeDeMot.o $(SRCDIR)/motCorrige.o $(SRCDIR)/listeDeMotCorrige.o $(SRCDIR)/testListeMotCorrige.o
	gcc -o $(TESTDIR)/testMot $(SRCDIR)/mot.o $(SRCDIR)/testMot.o -lcunit
	gcc -o $(TESTDIR)/testLevenshtein $(SRCDIR)/levenshtein.o $(SRCDIR)/testLevenshtein.o $(LDFLAGS) -lcunit
	gcc -o $(TESTDIR)/testListeDeMot $(SRCDIR)/testListeDeMot.o $(SRCDIR)/listeDeMot.o $(SRCDIR)/mot.o $(LDFLAGS) -lcunit
	gcc -o $(TESTDIR)/testListeMotCorrige $(SRCDIR)/motCorrige.o $(SRCDIR)/mot.o $(SRCDIR)/listeDeMot.o $(SRCDIR)/listeDeMotCorrige.o $(SRCDIR)/testListeMotCorrige.o $(LDFLAGS) -lcunit

$(BINDIR)/$(EXEC) : $(SRCDIR)/dictionnaire.o $(SRCDIR)/levenshtein.o $(SRCDIR)/main.o $(SRCDIR)/affichage.o $(SRCDIR)/mot.o $(SRCDIR)/listeDeMot.o $(SRCDIR)/listeDeMotCorrige.o $(SRCDIR)/utils.o $(SRCDIR)/motCorrige.o $(SRCDIR)/correcteurOrthographique.o
	$(CC)  -o $@ $^ 


clean :
	rm -f $(BINDIR)/*
	rm -f $(TESTDIR)/*
	rm -f $(LIBDIR)/*
	rm -f $(SRCDIR)/*.o
	rm -rf $(DOCDIR)

