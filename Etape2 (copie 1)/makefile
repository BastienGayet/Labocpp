
CLASSES=Classes/

OBJMOD=Classes/Modele.o
OBJVOIT=Classes/Voiture.o
OBJOPT=Classes/Option.o

COMPILE= g++  -I $(CLASSES) 


all:	Test2a Test2b Test2c

Test2a:	Test2a.cpp $(OBJVOIT) $(OBJMOD) $(OBJOPT) #$(CLASSEVOIT)Voiture.o $(ClASSEMOD)Modele.o
	echo "Creation de Test2a"
	$(COMPILE)  $(OBJVOIT) $(OBJMOD) $(OBJOPT) Test2a.cpp -o Test2a

Test2b:	Test2b.cpp  $(OBJOPT)
	echo "Creation de Test2b"
	$(COMPILE) $(OBJOPT) Test2b.cpp -o Test2b

Test2c: Test2c.cpp $(OBJMOD) $(OBJVOIT) $(OBJOPT)
	echo "Creation Test2c"
	$(COMPILE) $(OBJMOD) $(OBJVOIT) $(OBJOPT) Test2c.cpp -o Test2c



$(OBJMOD):	$(CLASSES)Modele.cpp  $(CLASSES)Modele.h #Classes/Modele/Modele.cpp Classes/Modele/Modele.h 
	echo "Creation de Modele.o"
	$(COMPILE)	 $(CLASSES)Modele.cpp -c   -o $(CLASSES)Modele.o #-D DEBUG
	#g++ Classes/Modele/Modele.cpp -I $(CLASSEMOD) -c -o Classes/Modele/Modele.o 


#$(CLASSEVOIT)Voiture.o:	$(CLASSEVOIT)Voiture.cpp  $(CLASSEVOIT)Voiture.h
$(OBJVOIT):	$(CLASSES)Voiture.cpp  $(CLASSES)Voiture.h
	echo "Creation Voiture.o"
	$(COMPILE)  $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o


$(OBJOPT):	$(CLASSES)Option.cpp  $(CLASSES)Option.h
	echo "Creation de Option.o"
	$(COMPILE)    $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o



clean:
	rm -rf Classes/*.o  