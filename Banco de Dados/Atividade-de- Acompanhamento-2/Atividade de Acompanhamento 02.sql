-- Cria o banco de dados
create database db_funcionario;

-- Seleciona o banco de dados
use db_funcionario;

-- Cria uma tabela no banco de dados
create table tb_funcionarios(
id_funcionarios int not null auto_increment primary key,
nome_funcionarios varchar(50) not null,
data_nascimento_funcionarios date not null,
setor_funcionarios varchar(50) not null,
uf_funcionarios char(3) not null,
salario_funcionarios float not null,
sexo_funcionarios char(2)
);

-- Insere valores na tabela 
insert into tb_funcionarios (nome_funcionarios, data_nascimento_funcionarios, setor_funcionarios, uf_funcionarios, salario_funcionarios, sexo_funcionarios) 
values
('Marcelo Mello', '2001-12-03', 'Adiministração', 'SP', '2500','M'),
('Ana Catarina', '1999-05-30', 'Contabilidade', 'ES', '2200', 'F'),
('Flavia Macedo', '2000-06-24', 'Recepção','ES', '1200', 'F'),
('Márcia Fontoura', '2001-04-04', 'TI','AM', '1900', 'F'),
('João Gabriel dos Anjos', '2000-09-26', 'Limpeza','MG', '1100', 'M'),
('Samuel Bastos','1998-07-31', 'TI', 'SC', '1700', 'M');

-- Seleciona todas as colunas da tabela
select * from tb_funcionarios;

-- Insere novos valores na tabela 
insert into tb_funcionarios (nome_funcionarios, data_nascimento_funcionarios, setor_funcionarios, uf_funcionarios, salario_funcionarios, sexo_funcionarios) values('Maros Silva', '2002-11-25', 'TI', 'BA', '2000', 'M');

-- Seleciona todas as colunas da tabela
select * from tb_funcionarios;

-- Atualiza uma entidade na tabela
update tb_funcionarios
set salario_funcionarios = 2000
where id_funcionarios = 6;

-- Seleciona todas as colunas da tabela
select * from tb_funcionarios;

-- Deleta uma entidade na tabela
delete from tb_funcionarios
where id_funcionarios = 4;

-- Seleciona todas as colunas da tabela
select * from tb_funcionarios;

-- Deleta a tabela
-- drop table tb_funcionarios;

-- Deleta o banco de dados
-- drop database db_funcionario; 
