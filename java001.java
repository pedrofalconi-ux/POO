import java.util.Scanner;

public class java001 {
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);

		System.out.println("Olá! Este é o seu primeiro codigo em Java.");
		System.out.print("Digite seu nome: ");
		String nome = entrada.nextLine();

		System.out.println("Bem-vindo(a), " + nome + "!");
		System.out.println("Parabéns por começar em Java");

		entrada.close();
	}
}
