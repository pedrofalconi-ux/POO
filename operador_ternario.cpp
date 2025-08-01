#include <iostream>
#include <string>
#include <vector>

class Cachorro {
public:
    Cachorro(std::string n, int i, std::string r, std::string p)
        : nome(n), idade(i), raca(r), porte(p) {}

    void exibir() const {
        std::cout << "Nome: " << nome << "\n"
                  << "Idade: " << idade << "\n"
                  << "Raca: " << raca << "\n"
                  << "Porte: " << porte << std::endl;
    }

private:
    std::string nome;
    int idade;
    std::string raca;
    std::string porte;
};

int main() {
    std::vector<Cachorro> canil;
    int quantidade_de_cachorros = 3; 

    std::cout << "CADASTRO DE " << quantidade_de_cachorros << " CACHORROS\n";

    for (int i = 0; i < quantidade_de_cachorros; ++i) {
        std::cout << "\n--- DADOS DO CACHORRO " << i + 1 << " ---\n";

        std::string nome, raca, porte;
        int idade;

        std::cout << "Nome: ";

        if (i == 0) {
             std::cin.ignore(); 
        }
        getline(std::cin, nome);
        
        std::cout << "Idade: ";
        std::cin >> idade;
        std::cin.ignore(); 

        std::cout << "Raca: ";
        getline(std::cin, raca);

        std::cout << "Porte: ";
        getline(std::cin, porte);

        canil.emplace_back(nome, idade, raca, porte);
    }

    std::cout << "\n--- LISTA DE CACHORROS CADASTRADOS ---\n";
    for (const auto& cachorro : canil) {
        cachorro.exibir();
        std::cout << "--------------------\n";
    }

    return 0;
}