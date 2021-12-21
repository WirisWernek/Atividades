/*
funcionario (cod_funcionario, primeiro_nome_func, último_nome_func,
data_nasc_func, end_func, genero_func, salário_func, cod_supervisor_func,
nro_departamento_func,total_horas_trabalhadas) 
departamento (nro_departamento, nome_depto, cod_gerente,
data_início_gerente)
projeto (nro_projeto, nome_projeto, local_projeto, nro_departamento)
trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)
*/

create database empresa;
use empresa;
create table funcionario 
(
	cod_func int not null primary key auto_increment,
    primeiro_nome_func varchar(30) not null,
    ultimo_nome_func varchar(30) not null,
    data_nasc_func date not null,
    end_func varchar(30) not null,
    genero_func char(1) not null,
    salario_func float not null,
    cod_supervisor_func int null,
	nro_departamento_func int not null,
	total_horas_trabalhadas int not null
);

create table departamento
(
	nro_departamento int not null primary key auto_increment,
    nome_depto varchar(30) not null,
    cod_gerente int null,
	data_inicio_gerente date null
);

create table projeto
(
	nro_projeto int not null primary key auto_increment,
    nome_projeto varchar(30) not null,
    local_projeto varchar(30) not null,
    nro_departamento int null
);

create table trabalha_para
(
	cod_func int not null, 
    nro_projeto int not null, 
    horas_trabalhadas int not null, 
    data_trabalhada date not null
);

alter table funcionario add constraint fk_cod_supervisor_func 
	foreign key (cod_supervisor_func) references funcionario(cod_func);
    
alter table funcionario add constraint fk_nro_departamento 
	foreign key (nro_departamento_func) references departamento(nro_departamento);
    
alter table departamento add constraint fk_cod_gerente 
	foreign key (cod_gerente) references funcionario(cod_func);
    
alter table projeto add constraint fk_nro_departamento_projeto 
	foreign key (nro_departamento) references departamento(nro_departamento);
    
alter table trabalha_para add constraint fk_cod_func_trabalha 
	foreign key (cod_func) references funcionario(cod_func);
    
alter table trabalha_para add constraint fk_nro_projeto_trabalha 
	foreign key (nro_projeto) references projeto(nro_projeto);

insert into departamento (nome_depto)
	values ('TADS'),
		   ('CAFE'),
           ('TI');
           
    
insert into funcionario (primeiro_nome_func, ultimo_nome_func,
						data_nasc_func, end_func, genero_func, salario_func, 
						nro_departamento_func, total_horas_trabalhadas)
values ('Kayo','Santana', now(), 'Bahia', 'M', 2000, 1, 220),
	   ('Gustavo', 'Oliveira', now(), 'Espirito Santo', 'M', 1800, 3, 220),
       ('Daniel', 'Rovetta', now(), 'Espirito Santo', 'M', 2000, 2, 240);

insert into projeto(nome_projeto, local_projeto, nro_departamento)
	values ('Banco Dados 2', 'Ifes', 1);

insert into trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)
       values (1, 1, 2, now()),
			  (1, 1 , 2, now()- interval 2 day);
       
update departamento set cod_gerente = 1, data_inicio_gerente = now()
	where nro_departamento = 1;
    
update funcionario set cod_supervisor_func = 1
	where cod_func = 3;
    
    
insert into trabalha_para (cod_func, nro_projeto, horas_trabalhadas, data_trabalhada)
       values (3, 1, 2, now()),
			  (3, 1 , 2, now()- interval 2 day);