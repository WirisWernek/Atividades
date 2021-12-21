/*
Crie um evento capaz de atualizar anualmente o valor do salário dos
funcionários em 5% do valor atual. 
*/

use empresa;
delimiter $$
create event CorrigeSalario on schedule every 1 year do 
    begin
		update funcionario
        set salario_func = salario_func + (salario_func*0.05);
    end
$$

show events from empresa;
select * from funcionario;


update funcionario
        set salario_func = salario_func + (salario_func*0.05);
        
        
        
        