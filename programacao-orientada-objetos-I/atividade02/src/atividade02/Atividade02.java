/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package atividade02;

import java.util.Scanner;

/**
 *
 * @author elaine ferreira
 */
public class Atividade02 {

  /**
   * O codigo implementa um menu interativo que permite ao usuario escolher diferentes opreracoes matematicas e realizar os calculos correspondentes.
   * E utilzado a class Scanner para receber as entradas do usuario e a class Math para realizar os calculos
   * @param args
   */
  public static void main(String[] args) {
    Scanner teclado = new Scanner(System.in);
    
    int i = 1;
    while(i != 0){
      System.out.println("Digite o numero da operacao desejada: ");
      System.out.println("1 - Calcular delta da formula de Bhaskara");
      System.out.println("2 - Calcular seno, cosseno e tangente de um angulo");
      System.out.println("3 - Calcular raiz quadrada de um numero");
      System.out.println("4 - Calcular raiz cubica de um numero");
      System.out.println("5 - Calcular a potencia de um numero");
      System.out.println("6 - Gerar um numero aleatorio");
      System.out.println("0 - Sair");
      
      int escolha = teclado.nextInt();
      
      if(escolha == 1){
        /* Opcao 1: calcular o delta da formula de Bhaskara utilizando a funcao Math.pow()*/
        System.out.print("Digite o valor de a: ");
        double a = teclado.nextDouble();
        System.out.print("Digite o valor de b: ");
        double b = teclado.nextDouble();
        System.out.print("Digite o valor de c: ");
        double c = teclado.nextDouble();
        
        double delta = Math.pow(b, 2) - 4 * a * c;
        
        System.out.printf("O valor de delta e: %.2f \n\n", delta);
        
      } else if(escolha == 2){
        /* Opcao 2: calcular o seno, cosseno e tangente de um angulo, convertendo o angulo de graus para radianos usando a funcao Math.toRadians()
        * Depois aplicar as classes das funcoes trigonometricas: Math.sin(), Math.cos(), Math.tan()
        */
        System.out.print("Digite o valor em graus: ");
        double angulo = teclado.nextDouble();
        double sen = Math.sin(Math.toRadians(angulo));
        double cos = Math.cos(Math.toRadians(angulo));
        double tang = Math.tan(Math.toRadians(angulo));
        
        System.out.printf("O seno de %.0f e: %.2f \n", angulo, sen);
        System.out.printf("O cosseno de %.0f e: %.2f \n", angulo, cos);
        System.out.printf("A tangente de %.0f e: %.2f \n", angulo, tang);
      } else if(escolha == 3){
        /* Opcao 3: Calcula a raiz quadrada de numero utilizando Math.sqrt()*/
        System.out.print("Digite o numero inteiro: ");
        double numero = teclado.nextDouble();
        if(numero < 0){
          System.out.println("O numero precisa ser maior que zero!");
          return;
        }
        double raiz = Math.sqrt(numero);
        System.out.printf("A raiz quadrada de %.2f e: %.2f \n\n", numero, raiz);
      } else if(escolha == 4){
        /*Opcao 4: calcula a raiz cubica de um numero utilizando Math.cbrt()*/
        System.out.print("Digite o numero: ");
        double numero = teclado.nextDouble();
        double raiz = Math.cbrt(numero);
        System.out.printf("A raiz cubica de %.2f e: %.2f \n\n", numero, raiz);
      } else if(escolha == 5){
        /*Opcao 5: calcula a potencia de um numero utilizando Math.pow()*/
        System.out.print("Digite a base: ");
        double base = teclado.nextDouble();
        System.out.print("Digite o expoente: ");
        double expoente = teclado.nextDouble();
        
        double potencia = Math.pow(base, expoente);
        System.out.printf("%.0f elevado a %.0f e: %.0f \n\n", base, expoente, potencia);
      } else if(escolha == 6){
        /*Opcao 6: gera um numero aleatorio entre 0 e 100 utilizando Math.random(()*/
        double numeroAleatorio = Math.random() * 100;
        System.out.printf("Numero aleatorio: %.2f \n\n", numeroAleatorio);
      } else if(escolha == 0){
        System.out.println("Saindo da Aplicacao...");
        i = 0;
      }
    }
    
    teclado.close();
  }
  
}
