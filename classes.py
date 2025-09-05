class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def apresentar(self):
        print(f"Olá, meu nome é {self.nome} e eu tenho {self.idade} anos.")

if __name__ == "__main__":
    pessoa1 = Pessoa("Alice", 30)
    pessoa1.apresentar()