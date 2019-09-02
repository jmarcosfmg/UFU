//Criar um programa em C ou C++ que leia o
//arquivo contendo CEPs no formato
//69903620\tAC\tRIO BRANCO\tTRAVESSA RAMOS FERREIRA\n

//e escreva em outro arquivo no formato

//TRAVESSA RAMOS FERREIRA|RIO BRANCO|AC|69903620\n

//Escreva uma função para busca no arquivo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void procura() {
	std::ifstream leit("cep.txt");
	if (leit.is_open()) {
		std::cout << "Insira o CEP desejado: ";
		std::string cpf, ka;
		std::cin >> cpf;
		std::size_t verif;
		while (std::getline(leit, ka)) {
			verif = ka.find("\t");
			if (cpf == ka.substr(0, verif)) {
				std::cout << ka;
				leit.close();
				return;
			}
		}
		leit.close();
		std::cout << "Registro nao encontrado" << std::endl;
	}
	else std::cerr << "Nao foi possivel ler do arquivo 'cep.txt'" << std::endl;

}
void reescreve() {
	std::string ka;
	std::vector<std::string> novo;
	std::ifstream leitor("cep.txt");
	std::ofstream escritor("novocep.txt");
	std::size_t tab, tab_ant;
	if (leitor.is_open()) {
		while (std::getline(leitor, ka)) {

			tab_ant = 0;
			tab = ka.find("\t");
			while (tab != std::string::npos) {
				novo.push_back(ka.substr(tab_ant, tab - tab_ant));
				tab_ant = tab + 1;
				tab = ka.find("\t", tab_ant);
			}
			novo.push_back(ka.substr(tab_ant, tab - tab_ant));
			for (auto it = novo.end() - 1; it != novo.begin(); --it) {
				escritor << *it << '|';
			}
			escritor << *novo.begin() << '\n';
			novo.clear();
		}
		leitor.close();
		escritor.close();
	}
	else std::cerr << "Nao foi possivel ler do arquivo 'cep.txt'" << std::endl;
}

int main()
{
	reescreve();
	procura();
	return 0;
}
