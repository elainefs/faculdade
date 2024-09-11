package atividade02;

import java.util.Scanner;

/**
 * @author Elaine Ferreira dos Santos
 */

/**
 * O código implementa um menu interativo que permite ao usuário escolher diferentes operações matemáticas e realizar os cálculos correspondentes.
 * É utilizado a class Scanner para receber as entradas do usuário e class Math para realizar os cálculos.
 */

public class Atividade02 {

  public static void main(String[] args) {
    Scanner teclado = new Scanner(System.in);

    int i = 1;
    while (i != 0) {
      System.out.println("Digite o número da opção desejada: ");
      System.out.println("1 - Calcular delta da formula de Bhaskara");
      System.out.println("2 - Calcular seno, cosseno e tangente de um ângulo");
      System.out.println("3 - Calcular raiz quadrada de um número");
      System.out.println("4 - Calcular raiz cúbica de um número");
      System.out.println("5 - Calcular a potência de um número");
      System.out.println("6 - Gerar um número aleatório");
      System.out.println("0 - Sair");
      int escolha = teclado.nextInt();

      if (escolha == 1) {
        /**
         * Opção 1: Calcula o delta da fórmula de Bhaskara utilizando o método Math.pow() para elevar um número a uma potência.
         */
        System.out.print("Digite o valor de a: ");
        double a = teclado.nextDouble();
        System.out.print("Digite o valor de b: ");
        double b = teclado.nextDouble();
        System.out.print("Digite o valor de c: ");
        double c = teclado.nextDouble();

        double delta = Math.pow(b, 2) - 4 * a * c;

        System.out.printf("O valor de delta é: %.2f \n\n", delta);
      } else if (escolha == 2) {
        /**
         * Opção 2: Calcula o seno, cosseno e tangente de um ângulo, convertendo o ângulo de graus para radianos usando Math.toRadians() e depois aplicando as funções trigonométricas Math.sin(), Math.cos() e Math.tan().
         */
        System.out.print("Digite o valor em graus: ");
        double angulo = teclado.nextDouble();
        double sen = Math.sin(Math.toRadians(angulo));
        double cos = Math.cos(Math.toRadians(angulo));
        double tang = Math.tan(Math.toRadians(angulo));

        System.out.printf("O seno de %.0f é: %.2f \n", angulo, sen);
        System.out.printf("O cosseno de %.0f é: %.2f \n", angulo, cos);
        System.out.printf("A tangente de %.0f é: %.2f \n\n", angulo, tang);
      } else if (escolha == 3) {
        /**
         * Opção 3: Calcula a raiz quadrada de um número utilizando Math.sqrt(). Verifica se o número é positivo antes de calcular a raiz.
         */
        System.out.print("Digite o número inteiro: ");
        double numero = teclado.nextDouble();
        if (numero < 0) {
          System.out.println("O número precisa ser maior que zero!");
          return;
        }
        double raiz = Math.sqrt(numero);
        System.out.printf("A raiz quadrada de %.2f é: %.2f \n\n", numero, raiz);
      } else if (escolha == 4) {
        /**
         * Opção 4: Calcula a raiz cúbica de um número utilizando Math.cbrt().
         */
        System.out.print("Digite o número: ");
        double numero = teclado.nextDouble();

        double raiz = Math.cbrt(numero);
        System.out.printf("A raiz cúbica de %.2f é: %.2f \n\n", numero, raiz);
      } else if (escolha == 5) {
        /**
         * Opção 5: Calcula a potência de um número utilizando Math.pow().
         */
        System.out.print("Digite a base: ");
        double base = teclado.nextDouble();
        System.out.print("Digite o expoente: ");
        double expoente = teclado.nextDouble();

        double potencia = Math.pow(base, expoente);
        System.out.printf(
          "%.0f elevado a %.0f é: %.0f \n\n",
          base,
          expoente,
          potencia
        );
      } else if (escolha == 6) {
        /**
         * Opção 6: Gera um número aleatório entre 0 e 100 utilizando Math.random() e multiplica por 100 para obter um número entre 0 e 100.
         */
        double numeroAleatorio = Math.random() * 100;
        System.out.printf("Número aleatório: %.2f \n\n", numeroAleatorio);
      } else if (escolha == 0) {
        System.out.println("Saindo da Aplicação...");
        i = 0;
      }
    }

    teclado.close();
  }
}
