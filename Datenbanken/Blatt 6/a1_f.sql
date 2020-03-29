SELECT name , COALESCE(anzahl_mit_null,0) as anzahl
FROM
(
    SELECT country,count(*) as anzahl_mit_null
    FROM city
    WHERE population > 100000 AND population < 200000
    GROUP BY country
)
RIGHT OUTER JOIN
(
    SELECT name,code
    FROM country
)
ON country=code
ORDER BY name;
