#include <iostream>
#include <string>
using namespace std;
    
class Cachorro{

    public:
    Cachorro(string n, int i, string r, string p) : nome(n), idade(i), raca(r), porte(p) {}

    string setNome(string n ){
        nome = n;
        return nome;
    }
    int setIdade(int i){
        idade = i;
        return idade;
    }
    string setRaca(string r){
        raca = r;
        return raca;
    }
    string setPorte(string p){
        porte = p;
        return porte;
    }

    void exibir(){
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Raça: " << raca << endl;
        cout << "Porte: " << porte << endl;
    }
    private:
        string nome;
        int idade;
        string raca;
        string porte;
};
int main(){
    
    

    string nome, raca, porte;
    int idade;

    getline(cin, nome);
    cin >> idade;
    cin.ignore(); 
    getline(cin, raca);
    getline(cin, porte);    
    Cachorro c(nome, idade, raca, porte);
    c.exibir();

    (idade > 8) ? cout << ("O Cachorro é adulto\n") : cout << ("Cachorro é filhote\n");
    
    return 0;
}