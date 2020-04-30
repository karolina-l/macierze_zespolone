#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o  obj/TMacierz.o obj/TWektor.o obj/mym.o\
													obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                					obj/TMacierz.o  obj/mym.o obj/LZespolona.o

#uklad_rownan: obj/main.o obj/UkladRownanLiniowych.o obj/TMacierz.o obj/TWektor.o obj/mym.o\
																										obj/LZespolona.o
#														g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
													                					obj/TMacierz.o obj/UkladRownanLiniowych.o obj/mym.o obj/LZespolona.o



	rm -f obj/*.o

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/TWektor.hh\
        inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

#obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
#	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/TMacierz.o: src/TMacierz.cpp inc/TMacierz.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/TMacierz.o src/TMacierz.cpp

obj/TWektor.o: src/TWektor.cpp inc/TWektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/mym.o: src/mym.cpp src/TWektor.cpp inc/TWektor.hh src/LZespolona.cpp inc/LZespolona.hh inc/TMacierz.hh src/TMacierz.cpp
	g++ ${CPPFLAGS} -o obj/mym.o src/mym.cpp


clean:
	rm -f obj/*.o uklad_rownan




#dobre nie ruszać
#
#CPPFLAGS= -c -g -Iinc -Wall -pedantic

#__start__: uklad_rownan
#	./uklad_rownan

#uklad_rownan: obj/main.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o
#	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                											obj/Macierz.o obj/UkladRownanLiniowych.o
#	rm -f obj/*.o

#obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh\
        inc/rozmiar.h
#	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

#obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
#	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

#obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/rozmiar.h
#	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

#obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
#	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

#clean:
#	rm -f obj/*.o uklad_rownan
