/*
D)Crie um procedimento para listar a quantidade total de horas trabalhadas por
um determinado funcionário em um projeto.
*/
use empresa;

delimiter $$
	create procedure horas_por_funcionario(
    in CodFuncionario int,
    in CodProjeto int
    )
    
    begin 
		select funcionario.cod_func as Codigo,
        funcionario.primeiro_nome_func as PrimeiroNome, 
        funcionario.ultimo_nome_func as UltimoNome,
        sum(trabalha_para.horas_trabalhadas) as Total
        from funcionario
        inner join trabalha_para
        on trabalha_para.cod_func = funcionario.cod_func 
        where trabalha_para.cod_func = CodFuncionario and trabalha_para.nro_projeto = CodProjeto
        group by trabalha_para.cod_func;
    end
$$

call horas_por_funcionario(1,1);