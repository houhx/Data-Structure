allh   = list/*.h queue/*.h stack/*.h *.h
mancpp = man.cpp
cflags = -Wall -O -g -std=c++11 

run: man.o
	g++ ${cflags} -o run man.o

man.o: ${mancpp} ${allh}
	g++ ${cflags} -c $< -o $@

clean:
	rm -f man.o run