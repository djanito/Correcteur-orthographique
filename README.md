<p align="center">
  <strong>Welcome to this C-based Spell-checker using BK-Tree and Levenshtein-Damerau distance.</strong>
  <br><br>
  <img width="704" alt="screenshot" src="png/screenshot.png">
</p>


# Installation of CUnit and Doxygen
Type the following command in a terminal :
	sudo apt-get install libcunit1 libcunit1-dev libcunit1-doc doxygen

# Using the makefile
For the compilation of the executable, tests and documentation :

	make all

For the compilation of the executable only :

	make exe

For the compilation of the tests alone :

	make tests

For the compilation of the documentation only :

	make doc

For the cleaning of the directory :

	make clean

# Reference dictionary
The French dictionary used by our spellchecker is generated from the file dico-ref-ascii.txt.

To fill it with the French dictionary : `./bin/corrector -d fic.dico -f dico-ref-ascii.txt`

# Usage
To correct a sentence once your .dico file is generated, type in a terminal :
 	`echo "sentence to correct" | correcteur.exe -d <dictionnary.dico>`
