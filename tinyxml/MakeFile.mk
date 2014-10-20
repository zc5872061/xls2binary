all:tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o

createo:
	ar rc lib.a tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o

tinyxml.o:tinyxml.cpp tinyxml.h tinystr.h
	gcc -c tinyxml.cpp 
tinystr.o:tinystr.cpp tinystr.h
	gcc -c tinystr.cpp
tinyxmlerror.o:tinyxmlerror.cpp  tinyxml.h
	gcc -c tinyxmlerror.cpp
tinyxmlparser.o:tinyxmlparser.cpp tinyxml.h
	gcc -c tinyxmlparser.cpp