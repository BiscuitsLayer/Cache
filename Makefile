all:	build_all link_all run
build_main:
		g++ main.cpp -Wall -Werror -c
build_cache_except:
		g++ cache_exception.cpp -Wall -Werror -c
build_tester:
		g++ tester.cpp -Wall -Werror -c
build_time:
		g++ time.cpp -Wall -Werror -c
build_all:	build_cache_except build_tester build_time build_main 

link_all:
		g++ cache_exception.o tester.o time.o main.o -o main
run:
		./main