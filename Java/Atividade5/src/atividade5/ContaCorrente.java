package atividade5;

import java.text.DecimalFormat;

public class ContaCorrente {
    protected String nome;
    protected String CPF;
    protected String RG;
    protected int numero_conta;
    protected double saldo;
    protected DecimalFormat df = new DecimalFormat("#.##");

    public ContaCorrente(String Nome, String CPF, String RG, int Numero_conta, double Saldo) {
            this.nome = Nome;
            this.CPF = CPF;
            this.RG = RG;
            this.numero_conta = Numero_conta;
            this.saldo = Saldo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String Nome) {
        this.nome = Nome;
    }

    public String getCPF() {
        return CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public String getRG() {
        return RG;
    }

    public void setRG(String RG) {
        this.RG = RG;
    }

    public int getNumero_conta() {
        return numero_conta;
    }

    public void setNumero_conta(int Numero_conta) {
        this.numero_conta = Numero_conta;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double Saldo) {
        this.saldo = Saldo;
    }
    
    public void Depositar(double Deposito){
        setSaldo(saldo + Deposito);
        System.out.println("Valor Depositado:R$ " + Deposito);
    }
    public void Sacar(double ValorASacar){
        if((ValorASacar + (ValorASacar*0.005)) <= getSaldo()){
             saldo = saldo - (ValorASacar + (ValorASacar*0.005));
            System.out.println("Valor Sacado:R$ " + df.format(ValorASacar) + "\nValor Restante:R$ " + df.format(getSaldo()));
        }
        else{
            System.out.println("Seu Saldo é inferior ao valor desejado. \nSaldo:R$ " + df.format(getSaldo()) + "Valor proposto do saque:R$ " + df.format(ValorASacar));
        }
    }

    @Override
    public String toString() {
        String imprimir;
        imprimir = "Nome: "+nome+"\nCPF: "+CPF+"\nRG: "+RG+"\nNúmero da conta: "+numero_conta+"\nSaldo:R$ "+df.format(saldo)+"\n";
        return imprimir; 
    }
    
    
   
}
