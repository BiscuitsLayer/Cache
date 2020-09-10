all:	build_all link_all run
build_main:
		g++ main.cpp -Wall -Werror -c
build_time:
		g++ time.cpp -Wall -Werror -c
build_all:	build_time build_main 

link_all:
		g++ time.o main.o -o main
run:
		./main