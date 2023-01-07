
CLASSES=Classes/

OBJMOD=Classes/Modele.o
OBJVOIT=Classes/Voiture.o
OBJOPT=Classes/Option.o


OBJPERS=Classes/Personne.o 
OBJEMPL=Classes/Employe.o 
OBJCLIE=Classes/Client.o 
OBJINTER=Classes/Intervenant.o

COMPILE= g++  -D DEBUG -I $(CLASSES) 


all:	Test4

Test4:	Test4.cpp $(OBJPERS) $(OBJINTER) $(OBJCLIE)  $(OBJEMPL)
	echo "Creation Test4"
	$(COMPILE) $(OBJPERS) $(OBJINTER) $(OBJCLIE) $(OBJEMPL) Test4.cpp -o Test4
	



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


clean:
	rm -rf Classes/*.o  