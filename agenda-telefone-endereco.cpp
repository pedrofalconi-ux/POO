#include <iostream>
#include <string> 

using namespace std;

class Endereco {
public:
    Endereco() {
        rua = ""; 
        numero = "";
        bairro = "";
        cidade = "";
        estado = "";
        cep = "";
    }

    Endereco(string r, string num, string b, string c, string e, string ce) {
        rua = r;
        numero = num;
        bairro = b;
        cidade = c; 
        estado = e;
        cep = ce;
    }

    void exibir() {
        cout << rua << ", " << numero << ", " << bairro << ". " << cidade << " - " << estado << ". " << "CEP: " << cep << "\n" << endl;
    }

private:
    string rua;
    string numero;
    string bairro;
    string cidade; 
    string estado;
    string cep;
};

class Pessoa {
public:
    Pessoa(string n){
        nome = n;
        telefone = ""; 
    }

   
    Pessoa(string n, Endereco e, string t) : endereco(e) { 
        nome = n;
        telefone = t;
    }

    void exibirPessoa() {
        cout << nome << ", " << telefone << endl; 
        endereco.exibir(); 
    }

private:
    string nome;
    string telefone;
    Endereco endereco;
};

int main() {
    int numPessoas;
    cin >> numPessoas;
    cin.ignore(); 

    for (int i = 0; i < numPessoas; i++) {
        string nome;
        getline(cin, nome);

        string telefone;
        getline(cin, telefone);

        string rua;
        getline(cin, rua);

        string numero;
        getline(cin, numero);

        string bairro;
        getline(cin, bairro);

        string cidade;
        getline(cin, cidade);

        string estado;
        getline(cin, estado);

        string cep;
        getline(cin, cep);

        Endereco e = Endereco(rua, numero, bairro, cidade, estado, cep);
        Pessoa p = Pessoa(nome, e, telefone);
        p.exibirPessoa();
    }

    return 0;
}