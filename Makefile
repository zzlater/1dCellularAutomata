FLAGS = -Wall

CA: CA.cpp
	g++ $(FLAGS) -o CA CA.cpp

Clean:
	rm -f CA

Test:
	./CA <<< 69
