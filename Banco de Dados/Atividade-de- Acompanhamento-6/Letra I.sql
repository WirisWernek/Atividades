/*
Implemente um mecanismo para sempre que um funcionário seja atualizado em
um projeto sua data de inicio seja atualizada para a atual. 
*/
use empresa;

create trigger AtualizarHoras
before update on trabalha_para 
for each row 
set new.data_trabalhada=now();

update trabalha_para 
set cod_func = 1
where cod_func = 3;
 
select * from trabalha_para;