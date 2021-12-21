use world;
--  Questão 3
delimiter $$
	create procedure busca_quantidade(
		in IdiomaPassado Varchar(25)
	)
		begin
			select
            count(country.Name)
			from countrylanguage 
			inner join country 
			on countrylanguage.CountryCode = country.Code and countrylanguage.Language = IdiomaPassado
			where countrylanguage.IsOfficial = "T";
		end
$$

call busca_quantidade("Portuguese");