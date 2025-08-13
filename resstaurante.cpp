#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pedido {
public:
    Pedido(int n, string d, int q, float p) {
        numero = n;
        descricao = d;
        quantidade = q;
        preco = p;
    }
    
    float getTotal() {
        return quantidade * preco; 
    }
    
    void setNumero(int c) {
        numero = c;
    }

    void setDescricao(string v) {
        descricao = v;
    }

    void setQuantidade(int b) {
        if(b == -1) {
            quantidade = quantidade - 1;  
        } else {
            quantidade = b;
        }
    }

    void setPreco(float x) {
        preco = x; 
    }

private:
    int numero;
    string descricao;
    int quantidade;
    float preco;
};

class MesaDeRestaurante {
private:
    vector<Pedido> pedidos;
    
public:
    void adicionarPedido(Pedido p) {
        pedidos.push_back(p);
    }
    
    float calcularTotalMesa() {
        float total = 0;
        for(auto& pedido : pedidos) {
            total += pedido.getTotal();
        }
        return total;
    }
};

class Restaurante {
private:
    vector<MesaDeRestaurante> mesas;
    
public:
    Restaurante(int numMesas) {
        mesas.resize(numMesas);
    }
    
    void adicionarPedido(Pedido p, int indMesa) {
        if(indMesa >= 0 && indMesa < mesas.size()) {
            mesas[indMesa].adicionarPedido(p);
        }
    }

    float calculaTotalRestaurante() {
        float total = 0;
        for(auto& mesa : mesas) {
            total += mesa.calcularTotalMesa();
        }
        return total;
    }
    
    MesaDeRestaurante getMesa(int indMesa) {
        return mesas[indMesa];
    }
};