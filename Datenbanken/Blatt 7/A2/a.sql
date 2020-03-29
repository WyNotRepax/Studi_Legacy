SELECT continent,count(*) as anzahl
FROM
(
    SELECT country as city_country
    FROM city
)
JOIN
(
    SELECT continent,country
    FROM encompasses
)
ON city_country = country
GROUP BY continent
ORDER BY continent ASC;