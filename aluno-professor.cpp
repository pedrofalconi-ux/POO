#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class Pessoa{
    public: 
        Pessoa(string n, string t, string c){
            nome = n;
            tel = t; 
            cpf = c;
}
        void exibir(){
            cout << nome << " - " << tel << " - " << "CPF: " << cpf << endl;}
    protected:
        string nome, tel, cpf;
};
class Aluno : public Pessoa
{
    public:
        Aluno(string n, string t, string c, float cr, int s) : Pessoa(n, t, c){
            cra = cr;
            semestre = s;
        }
        void exibir(){
            Pessoa::exibir(); 
            cout << "CRA: " << cra << " - Semestre: " << semestre << endl;
        } 
    private:
    float cra;
    int semestre;
};

class Funcionario : public Pessoa
{
    public:
        Funcionario(string n, string t, string c, int di, string d) : Pessoa(n, t, c){
            disciplinas = di;
            departamento = d;
        }
        void exibir(){
            Pessoa::exibir();
            cout << "Qtd: " << disciplinas << " - " << departamento << endl;}
    private:
        int disciplinas;
        string departamento;

};
int main(){

    string nome, tel, cpf;
    float cra;
    int sem; 
    int disciplinas;
    string departamento;

    getline(cin, nome);
    getline(cin, tel);
    getline(cin, cpf);
    Pessoa p = Pessoa(nome, tel, cpf); 

    getline(cin, nome);
    getline(cin, tel);
    getline(cin, cpf);
    cin >> cra;
    cin >> sem;
    Aluno a = Aluno(nome, tel, cpf, cra, sem);
    cin.ignore();

    getline(cin, nome);
    getline(cin, tel);
    getline(cin, cpf);
    cin >> disciplinas;
    cin.ignore();
    getline(cin, departamento);
    Funcionario f = Funcionario(nome, tel, cpf, disciplinas, departamento);
    
    p.exibir();
    a.exibir();
    f.exibir();

    return 0;
}
