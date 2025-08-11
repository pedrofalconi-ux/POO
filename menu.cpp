#include <iostream>

int main() {
    int opcao;

    do {
        std::cout << "1 - Item 1" << std::endl;
        std::cout << "2 - Item 2" << std::endl;
        std::cout << "3 - Item 3" << std::endl;
        std::cout << "4 - Sair" << std::endl;

        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Item 1" << std::endl;
                break;
            case 2:
                std::cout << "Item 2" << std::endl;
                break;
            case 3:
                std::cout << "Item 3" << std::endl;
                break;
            case 4:
                std::cout << "Sair" << std::endl;
                break;
            default:
                std::cout << "Opcao " << opcao << " Invalida" << std::endl;
                break;
        }
    } while (opcao != 4);

    return 0;
}