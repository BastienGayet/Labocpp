
CLASSES=Classes/

OBJMOD=Classes/Modele.o
OBJVOIT=Classes/Voiture.o
OBJOPT=Classes/Option.o

COMPILE= g++   -I $(CLASSES) 


all:	Test3

Test3:	Test3.cpp $(OBJVOIT) $(OBJMOD) $(OBJOPT) 
	echo "Creation Test3"
	$(COMPILE) $(OBJVOIT) $(OBJMOD) $(OBJOPT) Test3.cpp -o Test3
	



$(OBJMOD):	$(CLASSES)Modele.cpp  $(CLASSES)Modele.h 
	echo "Creation de Modele.o"
	$(COMPILE)	 $(CLASSES)Modele.cpp -c   -o $(CLASSES)Modele.o #-D DEBUG
	


$(OBJVOIT):	$(CLASSES)Voiture.cpp  $(CLASSES)Voiture.h
	echo "Creation Voiture.o"
	$(COMPILE)  $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o


$(OBJOPT):	$(CLASSES)Option.cpp  $(CLASSES)Option.h
	echo "Creation de Option.o"
	$(COMPILE)    $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o



clean:
	rm -rf Classes/*.o  