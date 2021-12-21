/*
B)Crie um procedimento para recuperar todos os funcionários que são
supervisionados por um determinado supervisor.
*/

use empresa;


delimiter $$
create procedure funcionarios_por_supervisor(
	in Supervisor int
)
	begin
		select cod_func, primeiro_nome_func from funcionario where cod_supervisor_func = Supervisor;		
    end
$$

call funcionarios_por_supervisor(1);

select * from funcionario;