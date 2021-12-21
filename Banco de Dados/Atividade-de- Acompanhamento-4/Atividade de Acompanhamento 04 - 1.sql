use world;
--  Questão 1
create view idioma_por_pais as 
	select
	countrylanguage.Language,
	country.Name Country
	from countrylanguage 
	inner join country 
	on countrylanguage.CountryCode = country.Code and countrylanguage.IsOfficial = 'T';

select * from world.idioma_por_pais;