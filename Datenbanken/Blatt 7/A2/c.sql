
CREATE  VIEW b7_a2_d (name, continent, capital, population) AS
	SELECT name, continent, capital, population
	FROM
	(
		SELECT name,continent,capital,code
		FROM
		(
			SELECT name,code,capital
			FROM country
		)
		JOIN
		(
			SELECT continent,country
			FROM encompasses
		)
		ON code=country
	)
	JOIN
	(
		SELECT name as city_name,population,country
		FROM city
	)
	ON city_name = capital AND code = country;
