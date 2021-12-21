-- Criando o banco de dados
create database db_devops;

-- Selecionando o banco de dados
use db_devops;

-- Criando uma tabela
create table tb_techs(
id_tech int not null auto_increment primary key,
nome_tech varchar(30) not null,
tipo_tech varchar(50) not null,
codigo_fonte_tech varchar(15) not null
);

-- Inserindo valores na tabela 
insert into tb_techs (nome_tech, tipo_tech, codigo_fonte_tech)
values
('Ansible','Automação','Aberto'),
('GitLab','Controle de Versão e CI/CD','Aberto'),
('Jenkins','CI','Aberto'),
('Grafana','Monitomanento','Aberto'),
('Kubernetes','Orquestração','Aberto'),
('Vagrant','Gerência de Configuração','Aberto'),
('Docker','Gerência de Configuração','Aberto');

-- Selecionando todas as colunas da tabela 
select * from tb_techs;

-- Deletando o banco de dados
-- drop database db_devops;