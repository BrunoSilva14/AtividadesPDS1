main: build/main.o build/Funcionario.o build/Pessoa.o build/Professor.o 
	c++ build/main.o build/Funcionario.o build/Pessoa.o build/Professor.o -o vpl_execution

build/main.o: src/main.cpp
	c++ -c src/main.cpp -I include -o build/main.o

build/Funcionario.o: include/Funcionario.hpp src/entidades/Funcionario.cpp
	c++ -c src/entidades/Funcionario.cpp -I include -o build/Funcionario.o

build/Pessoa.o: include/Pessoa.hpp src/entidades/Pessoa.cpp
	c++ -c src/entidades/Pessoa.cpp -I include -o build/Pessoa.o

build/Professor.o: include/Professor.hpp src/entidades/Professor.cpp
	c++ -c src/entidades/Professor.cpp -I include -o build/Professor.o