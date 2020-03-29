SELECT name,capital,population,continent
FROM
(
    SELECT country,continent
    FROM encompasses
    WHERE continent='America'
)
JOIN
(
    SELECT name,capital,code,population
    FROM
    (
        SELECT name,capital,code
        FROM country
    )
    JOIN
    (
    SELECT name as city_name,population,country
    FROM city
    )
    ON capital=city_name AND code=country
)
ON code=country
ORDER BY name ASC;