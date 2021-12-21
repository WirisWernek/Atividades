package atividade5;

public class ContaCorrenteEspecial extends ContaCorrente{

    public ContaCorrenteEspecial(String Nome, String CPF, String RG, int Numero_conta, double Saldo) {
        super(Nome, CPF, RG, Numero_conta, Saldo);
    }

    @Override 
    public void Sacar(double ValorASacar){
        if((ValorASacar + (ValorASacar*0.001)) <= getSaldo()){
            saldo = saldo - (ValorASacar + (ValorASacar*0.001));
            System.out.println("Valor Sacado:R$ " + df.format(ValorASacar) + "\nValor Restante:R$ " + df.format(getSaldo()));
        }
        else{
            System.out.println("Seu Saldo é inferior ao valor desejado. \nSaldo:R$ " + df.format(getSaldo()) + "\nValor proposto do saque:R$ " + df.format(ValorASacar));
        }
    }    
}
