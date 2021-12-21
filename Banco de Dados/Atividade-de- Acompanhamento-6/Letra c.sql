/*
C)Crie um procedimento para recuperar todos os funcionários que estão
alocados em um determinado projeto.
*/

use empresa;

delimiter $$
	create procedure funcionario_por_projeto(
    in Projeto int
    )
    begin
		select distinct funcionario.cod_func as Codigo,
        funcionario.primeiro_nome_func as PrimeiroNome, 
        funcionario.ultimo_nome_func as UltimoNome from funcionario
        inner join trabalha_para
        on trabalha_para.cod_func = funcionario.cod_func
        where nro_projeto = Projeto;
    end
    
$$

call funcionario_por_projeto(1);

