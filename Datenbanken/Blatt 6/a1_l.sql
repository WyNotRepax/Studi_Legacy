SELECT name,anzahl
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
    ORDER BY anzahl ASC
)
WHERE ROWNUM=1;
