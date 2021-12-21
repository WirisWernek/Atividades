use world;

-- Questão 2
delimiter $$
	create procedure busca_com_idioma(
		in IdiomaPassado Varchar(25)
	)
		begin
			select
			country.Name Country
			from countrylanguage 
			inner join country 
			on countrylanguage.CountryCode = country.Code and countrylanguage.Language = IdiomaPassado
			where countrylanguage.IsOfficial = "T";
		end
$$
call busca_com_idioma("Portuguese");


