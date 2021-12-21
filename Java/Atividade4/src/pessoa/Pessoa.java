package pessoa;

import java.util.Date;
import java.util.Scanner;

public class Pessoa {
    
    private int CPF;
    private int RG; 
    private String Nome;
    private Date data_nascimento;
    private String nascimento;
    private int Idade;
    private int ID;
    
    void calculo(Pessoa pessoa){
        Date data_atual = new Date();
        int ano_atual = data_atual.getYear();
        pessoa.Idade = ano_atual - pessoa.data_nascimento.getYear();     
    }
    void receber(Pessoa pessoa, Scanner input, int i){
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
        pessoa.ID = i+1;
        System.out.println("O ID dessa Pessoa é: "+pessoa.ID);
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
        System.out.println("ID: "+pessoa.ID);
    }
    
    public static void main(String[] args) {
       Pessoa pessoa[]; 
       pessoa = new Pessoa[12];
       Scanner input = new Scanner(System.in);
       int indice;
       int i = 0;
       while(true){ 
           System.out.println("1-Cadastrar\n2-Alterar\n3-Imprimir\n0-Sair");
           int opcao;
           opcao = input.nextInt();
           
          switch(opcao){
            case 1:
                if(i >= 10){
                    System.out.println("Máximo de pessoas atngido"+i+"/10");
                    break;
                }else{
                    System.out.println("\n\n");
                    pessoa[i] = new Pessoa();
                    pessoa[i].receber(pessoa[i], input, i);
                    i++;
                }
               
            break;
            case 2:
                System.out.println("Qual o ID da pessoa que vc deseja alterar");
                indice = input.nextInt();
                if(indice > 10 || indice < 0){
                    System.out.println("Indice inválido! Valor inferior à 0 ou superior à 10");
                    break;
                }else{
                    pessoa[indice-1].alterar(pessoa[indice-1], input);
                }
                System.out.println("Alterado com sucesso");
                
            break;
            case 3:
                for (int j = 0; j <= pessoa.length ; j++) {
                    if (pessoa[j] == null) {
                        break;
                    }
                    else{
                        System.out.println("\n\nPessoa "+(j+1));
                        pessoa[j].imprimir(pessoa[j]);
                    }
                    
                }
                
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
