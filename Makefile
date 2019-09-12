all:
	@clear
	@cat README.md
	@echo "\n"
	@echo "\n"
	@echo "Avez-vous pris conscience du README? O/N"
	@read b; \
	if [ "$$b" = "N" ] || [ "$$b" = "n" ] ; then \
    	echo "Il faut le lire, merci!" ; exit 1 ; \
	fi
	@echo "\n"
	@echo 'Compilation...'
	@mkdir -p .o
	@gcc -c main.c -o .o/main.o
	@gcc -o PROJET .o/main.o
	@rm -r .o
	@echo 'Compilation terminée !'
	@echo 'Jean-Michel REMEUR & Thomas LACAZE'
	@./PROJET

clean:
	@rm -r .o
	@echo 'Netoyage effectué'

windows: 
	@clear
	@cat README.md
	@echo "\n"
	@echo "\n"
	@echo "Avez-vous pris conscience du README? O/N"
	@read b; \
	if [ "$$b" = "N" ] || [ "$$b" = "n" ] ; then \
    	echo "Il faut le lire, merci!" ; exit 1 ; \
	fi
	@echo "\n"
	@echo 'Compilation...'
	@mkdir -p .o
	@gcc -c main.c -o .o/main.o
	@gcc -o PROJET .o/main.o
	@rm -r .o
	@echo 'Compilation terminée !'
	@echo 'Jean-Michel REMEUR & Thomas LACAZE'
	@PROJET.exe

mac: 
	@clear
	@cat README.md
	@echo "\n"
	@echo "\n"
	@echo "Avez-vous pris conscience du README? O/N"
	@read b; \
	if [ "$$b" = "N" ] || [ "$$b" = "n" ] ; then \
    	echo "Il faut le lire, merci!" ; exit 1 ; \
	fi
	@echo "\n"
	@echo 'Compilation...'
	@mkdir -p .o
	@gcc-9 -c main.c -o .o/main.o
	@gcc-9 -o PROJET .o/main.o
	@rm -r .o
	@echo 'Compilation terminée !'
	@echo 'Jean-Michel REMEUR & Thomas LACAZE'
	@./PROJET