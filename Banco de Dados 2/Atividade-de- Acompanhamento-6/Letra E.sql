/*
E)Crie um procedimento para identificar a quantidade de horas trabalhadas ao
todo em um projeto.
*/

use empresa;

delimiter $$
	create procedure horas_totais(
    in CodProjeto int
    )
	begin
	select nro_projeto,
	sum(horas_trabalhadas)        
    from trabalha_para
    where nro_projeto =CodProjeto
    group by nro_projeto;
    end
$$

call horas_totais(1);