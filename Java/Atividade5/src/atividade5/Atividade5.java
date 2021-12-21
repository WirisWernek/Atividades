package atividade5;

public class Atividade5 {
    
    public static void main(String[] args) {
        ContaCorrente[] Conta = new ContaCorrente[12];
        Conta[0] = new ContaCorrente("Wiris", "aggcvfkj", "bxzjhfdvbj", 124, 2126.21);
        Conta[1] = new ContaCorrenteEspecial("Rafael", "kfckihvu", "sdfgtghsrss", 244, 633.69);
        Conta[2] = new ContaCorrente("Maria", "trjjygvg", "dsfghthsdx", 365, 3251.32);
        Conta[3] = new ContaCorrente("Jõao", "uierrfgbj", "adrgaer", 631, 3622.59);
        Conta[4] = new ContaCorrenteEspecial("Rita", "dfsghbfdg", "aertdzade", 163, 966544.41);
        Conta[5] = new ContaCorrente("Marta", "juihhidsf", "eratzsag", 324, 32.89);
        Conta[6] = new ContaCorrente("Lucas", "aaeadsfg", "eswtdgsrt", 785, 3214.32);
        Conta[7] = new ContaCorrenteEspecial("Gabriela", "stgergsz", "asetryg", 321, 3622.36);
        Conta[8] = new ContaCorrente("Mirela", "saertg", "atyerdth", 695, 458.98);
        Conta[9] = new ContaCorrenteEspecial("Gean", "edsatry", "atsedryt", 962, 3622.33);
        
        for (int i = 0; i < 10; i++) {
            System.out.println("Conta "+i);
            System.out.println(Conta[i]);
        }
               
        Conta[2].Depositar(63.52);   //Conta normal     
        Conta[2].Sacar(15.00);       //Deve retornar um saldo de 3299,09
                
        Conta[4].Depositar(6588.36);  //Conta Especial      
        Conta[4].Sacar(10000.47);     //Deve retornar um saldo de 963122,3
                
        Conta[9].Sacar(1000.78);      //Conta Especial, Deve retornar um saldo de 2620.54922
                
        Conta[5].Depositar(6325.65);  //Conta Normal
        Conta[5].Sacar(1582.45);      //Deve retornar um saldo de 4768.17775
                
        Conta[7].Depositar(42.36);    //Conta Especial = 3664.72
        Conta[7].Sacar(6325.55);      //Deve retornar que não é possível
                
        Conta[3].Sacar(1000.56);      //Conta Normal, Deve retornar um saldo de 2617.0272
        
        for (int i = 0; i < 10; i++) {
            System.out.println("Conta "+i);
            System.out.println(Conta[i]);
        }

    }    
}
