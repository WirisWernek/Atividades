package atividade3;

import java.util.Scanner;
import java.util.Date;

public class Pessoa {
    private int CPF;
    private int RG; 
    private String Nome;
    private Date data_nascimento;
    private String nascimento;
    private int Idade;
    
    void calculo(Pessoa pessoa){
        Date data_atual = new Date();
        int ano_atual = data_atual.getYear();
        pessoa.Idade = ano_atual - pessoa.data_nascimento.getYear();     
    }
    void receber(Pessoa pessoa, Scanner input){
        System.out.println("Insira seu CPF: ");
        pessoa.CPF = input.nextInt();
        System.out.println("Insira seu RG");
        pessoa.RG = input.nextInt();
        System.out.println("Insira seu Nome:");
        input.nextLine();
        pessoa.Nome = input.nextLine();
        System.out.println("Insira sua Data de Nascimento:(YYYY/MM/DD)");
        pessoa.nascimento = input.nextLine();
        pessoa.data_nascimento=new Date(nascimento);
        pessoa.calculo(pessoa);
    }
    void alterar(Pessoa pessoa, Scanner input){
        int opcao;
        System.out.println("1-CPF\n2-RG\n3-Nome\n4-Data de Nascimento");
        opcao = input.nextInt();
        switch(opcao){
            case 1:
                System.out.println("Insira o novo CPF: ");
                pessoa.CPF = input.nextInt();
            break;
            case 2:
                System.out.println("Insira o novo RG");
                pessoa.RG = input.nextInt();
            break;
            case 3:
                System.out.println("Insira o novo Nome:");
                input.nextLine();
                pessoa.Nome = input.nextLine();
            break;
            case 4:
                System.out.println("Insira sua Data de Nascimento:(YYYY/MM/DD)");
                input.nextLine();
                pessoa.nascimento =input.nextLine();
                pessoa.data_nascimento = new Date(nascimento);
                pessoa.calculo(pessoa);
            break;
            default:
                System.out.println("Valor Inválido");
                break;
        }
    }
    void imprimir(Pessoa pessoa){
        System.out.println("Nome: "+pessoa.Nome);
        System.out.println("CPF: "+pessoa.CPF);
        System.out.println("RG: "+pessoa.RG);
        System.out.println("Nascimento: "+pessoa.data_nascimento);
        System.out.println("Idade: "+pessoa.Idade+" Anos");
    }
    
    public void main() {
       Pessoa pessoa = new Pessoa(); 
       Scanner input = new Scanner(System.in);
       
       while(true){ 
           System.out.println("1-Cadastrar\n2-Alterar\n3-Imprimir\n0-Sair");
           int opcao = input.nextInt();
          switch(opcao){
            case 1:
                pessoa.receber(pessoa, input);
            break;
            case 2:
                pessoa.alterar(pessoa, input);
            break;
            case 3:
                pessoa.imprimir(pessoa);
            break;
            case 0:
                return;
            default:
                System.out.println("Valor Inválido");
                break;
        } 
       }
    }
    
}