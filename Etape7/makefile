
CLASSES=Classes/

OBJMOD=Classes/Modele.o
OBJVOIT=Classes/Voiture.o
OBJOPT=Classes/Option.o


OBJPERS=Classes/Personne.o 
OBJEMPL=Classes/Employe.o 
OBJCLIE=Classes/Client.o 
OBJINTER=Classes/Intervenant.o
OBJITERA=Classes/Iterateur.o


OBJEXCP=Classes/Exception.o 
OBJEXCEPOPT=Classes/OptionException.o
OBJSPASSEXCEP=Classes/PasswordException.o


OBJVECT=Classes/Vecteur.o


COMPILE= g++   -g -I $(CLASSES) 


all:	Test7

Test7:	Test7.cpp $(OBJPERS) $(OBJINTER) $(OBJCLIE)  $(OBJEMPL) $(OBJVOIT) $(OBJMOD) $(OBJOPT) $(OBJEXCP) $(OBJEXCEPOPT) $(OBJSPASSEXCEP) $(OBJVECT) $(OBJITERA)
	echo "Creation Test7"
	$(COMPILE) $(OBJPERS) $(OBJINTER) $(OBJCLIE) $(OBJEMPL) $(OBJVOIT) $(OBJMOD) $(OBJOPT) $(OBJEXCP) $(OBJEXCEPOPT) $(OBJSPASSEXCEP)	$(OBJVECT)	$(OBJITERA) Test7.cpp -o Test7
	



$(OBJMOD):	$(CLASSES)Modele.cpp  $(CLASSES)Modele.h 
	echo "Creation de Modele.o"
	$(COMPILE)	 $(CLASSES)Modele.cpp -c   -o $(CLASSES)Modele.o #-D DEBUG
	


$(OBJVOIT):	$(CLASSES)Voiture.cpp  $(CLASSES)Voiture.h
	echo "Creation Voiture.o"
	$(COMPILE)  $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o


$(OBJOPT):	$(CLASSES)Option.cpp  $(CLASSES)Option.h 
	echo "Creation de Option.o"
	$(COMPILE)    $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o



$(OBJPERS):	$(CLASSES)Personne.cpp  $(CLASSES)Personne.h
	echo "Creation Personne.o"
	$(COMPILE)  $(CLASSES)Personne.cpp -c -o $(CLASSES)Personne.o

$(OBJCLIE):	$(CLASSES)Client.cpp  $(CLASSES)Client.h
	echo "Creation client.o"
	$(COMPILE)  $(CLASSES)Client.cpp -c -o $(CLASSES)Client.o

$(OBJEMPL):	$(CLASSES)Employe.cpp  $(CLASSES)Employe.h
	echo "Creation employe.o"
	$(COMPILE)  $(CLASSES)Employe.cpp -c -o $(CLASSES)Employe.o	

$(OBJINTER):	$(CLASSES)Intervenant.cpp  $(CLASSES)Intervenant.h
	echo "Creation Intervenant.o"
	$(COMPILE)  $(CLASSES)Intervenant.cpp -c -o $(CLASSES)Intervenant.o

$(OBJEXCP):	$(CLASSES)Exception.cpp $(CLASSES)Exception.h
	echo "Creation de Exception.o"
	$(COMPILE)	$(CLASSES)Exception.cpp -c -o $(CLASSES)Exception.o

$(OBJEXCEPOPT):	$(CLASSES)OptionException.cpp $(CLASSES)OptionException.h
	echo "Creation de OptionException.o"
	$(COMPILE)	$(CLASSES)OptionException.cpp -c -o $(CLASSES)OptionException.o


$(OBJSPASSEXCEP):	$(CLASSES)PasswordException.cpp $(CLASSES)PasswordException.h
	echo "Creation de PasswordException.o"
	$(COMPILE)	$(CLASSES)PasswordException.cpp -c -o $(CLASSES)PasswordException.o



$(OBJVECT):	$(CLASSES)Vecteur.cpp $(CLASSES)Vecteur.h
	echo " Creation de Vecteur.o" 
	$(COMPILE)	$(CLASSES)Vecteur.cpp -c -o $(CLASSES)Vecteur.o

$(OBJITERA): $(CLASSES)Iterateur.cpp $(CLASSES)Iterateur.h
	echo "Creation de Iterateur.o"
	$(COMPILE)	$(CLASSES)Iterateur.cpp -c -o $(CLASSES)Iterateur.o







clean:
	rm -rf Classes/*.o  