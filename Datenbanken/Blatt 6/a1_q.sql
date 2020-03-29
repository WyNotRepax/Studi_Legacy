SELECT name,anzahl/(SELECT sum(population) FROM country)*100 as anteil
FROM
(
    SELECT name,sum(population*percentage/100) as anzahl
    FROM
    (
        SELECT country , percentage ,name
        FROM religion
    )
    JOIN
    (
        SELECT name as country_name,population,code
        FROM country
    )
    ON country = code
    GROUP BY name
)
