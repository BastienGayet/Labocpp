.SILENT:
Test1:	Test1.cpp Classes/Modele.o
	echo "Creation de Test1"
	g++ Test1.cpp Classes/Modele.o -I Classes/ -o Test1 #-D DEBUG


Classes/Modele.o:	Classes/Modele.cpp Classes/Modele.h
	echo "Creation de Modele.o"
	g++	Classes/Modele.cpp -c -o Classes/Modele.o #-D DEBUG


clean:
	rm Classes/*.o