use world;
select * from country;

select Continent, sum(Population)
from country
group by Continent;

select Region, sum(Population)
from country
group by Region;