pursuit: pursuit.o
	c++ -o pursuit pursuit.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

pursuit.o: pursuit.cpp
	c++ -c pursuit.cpp

p: p.o
	c++ -o p p.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

p.o: p.cpp
	c++ -c p.cpp
 
g: g.o
	c++ -o g g.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

g.o: g.cpp
	c++ -c g.cpp
