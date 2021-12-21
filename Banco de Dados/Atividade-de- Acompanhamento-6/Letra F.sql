/*
F)Crie um procedimento para listar todos os funcionários com salário superior
à 10.000 reais
*/


use empresa;

delimiter $$
	create procedure salario_superior(
    in minimo double
    )
    begin
		select cod_func as Cod,
        primeiro_nome_func as Nome,
        ultimo_nome_func as Sobrenome,
        salario_func as Salario
        from funcionario
        where salario_func > minimo;
    end
$$

call salario_superior(1000.00); 
