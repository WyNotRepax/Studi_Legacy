SELECT DISTINCT name
FROM
(
    SELECT country,n
    FROM(
        SELECT country,name,count(*) as n
        FROM CITY
        GROUP BY country,name
    )
    WHERE n >= 2
)
JOIN
(
    SELECT name,code
    FROM country
)
ON code = country;