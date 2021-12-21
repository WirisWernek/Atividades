/*
Crie uma visão para listar todos os projetos com a quantidade total de horas
trabalhadas em cada um deles.
*/

use empresa;

create view horas_por_projeto as
	select trabalha_para.nro_projeto as Projeto,
    sum(trabalha_para.horas_trabalhadas) as Horas from trabalha_para
    group by trabalha_para.nro_projeto;
    
select * from horas_por_projeto;

insert into projeto(nome_projeto, local_projeto, nro_departamento)
	values ('Banco Dados 3', 'Ifes', 1);
    
insert into trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)
       values (2, 1, 2, now()),
			  (3, 1 , 2, now()- interval 3 day);
              
insert into trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)
       values (2, 2, 2, now()),
			  (3, 2, 2, now()- interval 3 day);