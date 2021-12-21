use world; 
explain select * from countrylanguage
where countrylanguage.Language = "English";

create index idx_language on countrylanguage(Language);
explain select * from countrylanguage
where countrylanguage.Language = "English";

drop index idx_language on countrylanguage;



















-- com index = 60 linhas
-- sem index = 984 linhas



explain select * from country
where GovernmentForm = "Republic";

create index idx_GovernmentForm on country(GovernmentForm);
explain select * from country
where GovernmentForm = "Republic";

drop index idx_GovernmentForm on country; 



















-- sem = 239
-- com = 122

 

