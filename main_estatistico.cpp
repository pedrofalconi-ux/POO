#include <iostream>
#include <iomanip>
#include "Estatisticas.h"
#include "Pedido.h"
#include "Livro.h"
using namespace std;

int main() {
    // Processamento dos Pedidos
    int nPedidos;
    cin >> nPedidos;
    
    Estatisticas<Pedido> estatPedidos;
    
    for (int i = 0; i < nPedidos; i++) {
        float valor;
        int quant;
        cin >> valor >> quant;
        Pedido pedido(valor, quant);
        estatPedidos.addEl(pedido);
    }
    
    // Processamento dos Livros
    int nLivros;
    cin >> nLivros;
    cin.ignore(); // Limpar buffer
    
    Estatisticas<Livro> estatLivros;
    
    for (int i = 0; i < nLivros; i++) {
        string titulo;
        int paginas;
        getline(cin, titulo);
        cin >> paginas;
        cin.ignore(); // Limpar buffer após leitura de inteiro
        
        Livro livro(titulo, paginas);
        estatLivros.addEl(livro);
    }
    
    // Exibição dos resultados para Pedidos (com casas decimais)
    cout << fixed << setprecision(2);
    
    int maiorPedidoIndex = estatPedidos.indexOfMaior();
    int menorPedidoIndex = estatPedidos.indexOfMenor();
    
    cout << "Maior: ";
    estatPedidos.getEl(maiorPedidoIndex).print();
    cout << endl;
    
    cout << "Menor: ";
    estatPedidos.getEl(menorPedidoIndex).print();
    cout << endl;
    
    cout << "Média: " << estatPedidos.media() << endl;
    
    // Exibição dos resultados para Livros (sem casas decimais)
    cout << fixed << setprecision(0); // Usar fixed com 0 casas decimais
    
    int maiorLivroIndex = estatLivros.indexOfMaior();
    int menorLivroIndex = estatLivros.indexOfMenor();
    
    cout << "Maior: ";
    estatLivros.getEl(maiorLivroIndex).print();
    cout << endl;
    
    cout << "Menor: ";
    estatLivros.getEl(menorLivroIndex).print();
    cout << endl;
    
    cout << "Média: " << estatLivros.media() << endl;
    
    return 0;
}