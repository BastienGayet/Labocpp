#.SILENT:


OBJS_QT = main.o applicgaragewindow.o moc_applicgaragewindow.o
PROGRAMS = ApplicGarage

CLASSES=Classes/
CO=g++    -g -I $(CLASSES)
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
OBJGARA=Classes/Garage.o

all:	$(PROGRAMS)

ApplicGarage:	$(OBJS_QT)	$(OBJPERS) $(OBJINTER) $(OBJCLIE)  $(OBJEMPL) $(OBJVOIT) $(OBJMOD) $(OBJOPT) $(OBJEXCP) $(OBJEXCEPOPT) $(OBJSPASSEXCEP) $(OBJVECT) $(OBJITERA) $(OBJGARA)
		echo Creation de ApplicGarage...
		$(CO) -Wl,-O1 -o ApplicGarage $(OBJPERS) $(OBJINTER) $(OBJCLIE) $(OBJEMPL) $(OBJVOIT) $(OBJMOD) $(OBJOPT) $(OBJEXCP) $(OBJEXCEPOPT) $(OBJSPASSEXCEP)	$(OBJVECT)	$(OBJITERA) $(OBJGARA) $(OBJS_QT)  /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 					
		#rm main.o

main.o:	main.cpp $(OBJGARA)
		echo Creation de main.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

applicgaragewindow.o:	applicgaragewindow.cpp applicgaragewindow.h ui_applicgaragewindow.h 
		echo Creation de applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o applicgaragewindow.o applicgaragewindow.cpp

moc_applicgaragewindow.o:	moc_applicgaragewindow.cpp applicgaragewindow.h
		echo Creation de moc_applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_applicgaragewindow.o moc_applicgaragewindow.cpp

clean:
	@rm -f $(OBJS_QT) core

clobber:	clean
	@rm -f tags $(PROGRAMS) *~ *.log




$(OBJMOD):	$(CLASSES)Modele.cpp  $(CLASSES)Modele.h 
	echo "Creation de Modele.o"
	$(CO)	 $(CLASSES)Modele.cpp -c   -o $(CLASSES)Modele.o #-D DEBUG
	


$(OBJVOIT):	$(CLASSES)Voiture.cpp  $(CLASSES)Voiture.h
	echo "Creation Voiture.o"
	$(CO)  $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o


$(OBJOPT):	$(CLASSES)Option.cpp  $(CLASSES)Option.h 
	echo "Creation de Option.o"
	$(CO)    $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o



$(OBJPERS):	$(CLASSES)Personne.cpp  $(CLASSES)Personne.h
	echo "Creation Personne.o"
	$(CO)  $(CLASSES)Personne.cpp -c -o $(CLASSES)Personne.o

$(OBJCLIE):	$(CLASSES)Client.cpp  $(CLASSES)Client.h
	echo "Creation client.o"
	$(CO)  $(CLASSES)Client.cpp -c -o $(CLASSES)Client.o

$(OBJEMPL):	$(CLASSES)Employe.cpp  $(CLASSES)Employe.h
	echo "Creation employe.o"
	$(CO)  $(CLASSES)Employe.cpp -c -o $(CLASSES)Employe.o	

$(OBJINTER):	$(CLASSES)Intervenant.cpp  $(CLASSES)Intervenant.h
	echo "Creation Intervenant.o"
	$(CO)  $(CLASSES)Intervenant.cpp -c -o $(CLASSES)Intervenant.o

$(OBJEXCP):	$(CLASSES)Exception.cpp $(CLASSES)Exception.h
	echo "Creation de Exception.o"
	$(CO)	$(CLASSES)Exception.cpp -c -o $(CLASSES)Exception.o

$(OBJEXCEPOPT):	$(CLASSES)OptionException.cpp $(CLASSES)OptionException.h
	echo "Creation de OptionException.o"
	$(CO)	$(CLASSES)OptionException.cpp -c -o $(CLASSES)OptionException.o


$(OBJSPASSEXCEP):	$(CLASSES)PasswordException.cpp $(CLASSES)PasswordException.h
	echo "Creation de PasswordException.o"
	$(CO)	$(CLASSES)PasswordException.cpp -c -o $(CLASSES)PasswordException.o



$(OBJVECT):	$(CLASSES)Vecteur.cpp $(CLASSES)Vecteur.h
	echo " Creation de Vecteur.o" 
	$(CO)	$(CLASSES)Vecteur.cpp -c -o $(CLASSES)Vecteur.o

$(OBJITERA): $(CLASSES)Iterateur.cpp $(CLASSES)Iterateur.h
	echo "Creation de Iterateur.o"
	$(CO)	$(CLASSES)Iterateur.cpp -c -o $(CLASSES)Iterateur.o

$(OBJGARA):	$(CLASSES)Garage.cpp $(CLASSES)Garage.h 
	echo "Creation de Garage.o"
	$(CO)	$(CLASSES)Garage.cpp -c -o $(CLASSES)Garage.o 






	  
