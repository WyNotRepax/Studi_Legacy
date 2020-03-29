SELECT name,avg(population) as durchschnitt
FROM
(
    SELECT name,code
    FROM country
)
JOIN
(
    SELECT country,population
    FROM city
)
ON country = code
GROUP BY name
HAVING count(*) > 100

