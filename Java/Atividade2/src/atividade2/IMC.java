package atividade2;

import java.util.Scanner;
/**
 *
 * @author wiris
 */
public class IMC{
 
    public void IMC() {
        Scanner receber = new Scanner(System.in);
        float peso;
        float altura;
        
        System.out.println("Insira sua altura em m");
        altura = receber.nextFloat();
        
        System.out.println("Insira seu peso em kg");
        peso = receber.nextFloat();
        
        float imc;
        imc = peso / (altura * altura);
         
        if(imc >= 18.5 && imc <= 24.9){
            System.out.println("Você está com um IMC de "+imc+" você esta com um IMC normal");
        }else if(imc < 18.5){
             System.out.println("Você está com um IMC de "+imc+" você esta com um IMC abaixo do normal");
        }else if(imc >= 25 && imc <= 29.9){
             System.out.println("Você está com um IMC de "+imc+" você esta com um IMC de sobrepeso");
        }else if(imc >= 30 && imc <= 34.9){
             System.out.println("Você está com um IMC de "+imc+" você esta com um IMC de Obesidade grau 1");
        }else if(imc >= 35 && imc <= 39.9){
             System.out.println("Você está com um IMC de "+imc+" você esta com um IMC de Obesidade grau 2");
        }else if(imc >= 40){
             System.out.println("Você está com um IMC de "+imc+" você esta com um IMC de Obesidade grau 3");
        }else{
             System.out.println("Valor não reconhecido");
        }
    }   
}
    

