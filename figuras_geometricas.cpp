#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FigurasGeometricas {
public:
    FigurasGeometricas(string t) : tipo(t) {}
    virtual void lerAtributosArea() = 0;
    virtual float calcular_area() = 0;
    string getNome() { return tipo; }
protected:
    string tipo;
};

class Quadrado : public FigurasGeometricas {
public:
    Quadrado() : FigurasGeometricas("Quadrado"), l(0) {}
    void lerAtributosArea() override {
        cin >> l;
    }
    float calcular_area() override {
        return l * l;
    }
private:
    float l;
};

class Retangulo : public FigurasGeometricas {
public:
    Retangulo() : FigurasGeometricas("Retângulo"), b(0), h(0) {}
    void lerAtributosArea() override {
        cin >> b >> h;
    }
    float calcular_area() override {
        return b * h;
    }
private:
    float b, h;
};

class Triangulo : public FigurasGeometricas {
public:
    Triangulo() : FigurasGeometricas("Triângulo"), b(0), h(0) {}
    void lerAtributosArea() override {
        cin >> b >> h;
    }
    float calcular_area() override {
        return (b * h) / 2;
    }
private:
    float b, h;
};

class Circulo : public FigurasGeometricas {
public:
    Circulo() : FigurasGeometricas("Círculo"), r(0) {}
    void lerAtributosArea() override {
        cin >> r;
    }
    float calcular_area() override {
        return 3.14f * r * r;
    }
private:
    float r;
};

int main() {
    vector<FigurasGeometricas*> figuras;
    while (true) {
        int tipo;
        cin >> tipo;
        if (tipo == 0) break;
        FigurasGeometricas* figura = nullptr;
        switch (tipo) {
            case 1:
                figura = new Quadrado();
                break;
            case 2:
                figura = new Retangulo();
                break;
            case 3:
                figura = new Triangulo();
                break;
            case 4:
                figura = new Circulo();
                break;
            default:
                cerr << "Tipo de figura invalido!" << endl;
                continue;
        }
        figura->lerAtributosArea();
        figuras.push_back(figura);
    }
    for (size_t i = 0; i < figuras.size(); i++) {
        cout << figuras[i]->getNome() << " de área " << figuras[i]->calcular_area() << endl;
        delete figuras[i];
    }
    return 0;
}