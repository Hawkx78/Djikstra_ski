COMP=gcc -c -g3 -Wall $<
run: algo 

test: algo
	./algo

# Edition de liens
algo: algo.o 
	gcc  $^ -o algo 

# Compilation des fichiers
%.o: %.c %.h
	$(COMP)

# Ouverture des fichiers
open:
	geany makefile *.c *.h &

# Organisation des fichiers
indent:
	indent -linux *.c

clean:
	rm -rf *.o
	rm -rf algo
