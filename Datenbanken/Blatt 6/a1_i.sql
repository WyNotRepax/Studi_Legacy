SELECT sum(population*percentage/100) as anzahlprotestanten
FROM
(
    SELECT country,percentage
    FROM religion
    WHERE name='Protestant'
)
JOIN
(
    SELECT name,population,code
    FROM country
)
ON country = code;