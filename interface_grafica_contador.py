import tkinter as tk

class ContadorApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Pedro Henrique - Contador")
        self.root.geometry("1280x720") # Define o tamanho da janela

        self.contador = 0
        self.timer_id = None

        # Rótulo (Label) para mostrar o número do contador
        self.label_contador = tk.Label(root, text="Aperte o botão para iniciar", font=("Helvetica", 20))
        self.label_contador.pack(pady=20)

        # Botão para iniciar/reiniciar o contador
        self.botao = tk.Button(root, text="Iniciar / Reiniciar", command=self.iniciar_ou_reiniciar)
        self.botao.pack(pady=10)

    def iniciar_ou_reiniciar(self):
        # Se já existir um timer rodando, ele é cancelado
        if self.timer_id is not None:
            self.root.after_cancel(self.timer_id)

        # Zera o contador
        self.contador = 0
        self.label_contador.config(text=str(self.contador))

        # Inicia a contagem
        self.contar()

    def contar(self):
        # Incrementa o contador
        self.contador += 1
        self.label_contador.config(text=str(self.contador))

        # Agenda a próxima chamada desta função para daqui a 1 segundo (1000 ms)
        self.timer_id = self.root.after(1000, self.contar)


if __name__ == "__main__":
    janela = tk.Tk()
    app = ContadorApp(janela)
    janela.mainloop()