SELECT name as stadt,country_name as land
FROM
(
    (
        SELECT name as name_double
        FROM city 
            GROUP  BY name
            HAVING count(*) >= 2
    )
    JOIN
    (
        SELECT name,country as country_code
        FROM city
    )
    ON name=name_double
)
JOIN
(
    SELECT name as country_name,code
    FROM country
)
ON country_code = code;