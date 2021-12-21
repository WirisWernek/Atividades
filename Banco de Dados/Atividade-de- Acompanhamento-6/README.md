# Objetivo
Considere os seguintes esquemas de relações:

funcionario (cod_funcionario, primeiro_nome_func, último_nome_func,data_nasc_func, end_func, genero_func, salário_func, cod_supervisor_func, nro_departamento_func, total_horas_trabalhadas)

departamento (nro_departamento, nome_depto, cod_gerente, data_início_gerente)

projeto (nro_projeto, nome_projeto, local_projeto, nro_departamento)

trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)

a) Implemente o script para criação do banco.

b) Crie um procedimento para recuperar todos os funcionários que são
supervisionados por um determinado supervisor.

c) Crie um procedimento para recuperar todos os funcionários que estão
alocados em um determinado projeto.

d) Crie um procedimento para listar a quantidade total de horas trabalhadas por
um determinado funcionário em um projeto.

e) Crie um procedimento para identificar a quantidade de horas trabalhadas ao
todo em um projeto.

f) Crie um procedimento para listar todos os funcionários com salário superior
à 10.000 reais.

g) Crie uma visão para listar todos os projetos com a quantidade total de horas
trabalhadas em cada um deles.

h) Crie um evento capaz de atualizar anualmente o valor do salário dos
funcionários em 5% do valor atual.

i) Implemente um mecanismo para sempre que um funcionário seja alocado em
um novo projeto sua quantidade de horas trabalhadas seja atualizada. 