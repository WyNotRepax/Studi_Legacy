SELECT name 
FROM country
WHERE EXISTS(
    SELECT name
    FROM city
    WHERE population < 500000
    AND country = code
    AND city.name = capital
)
AND
(
        SELECT count(*)
        FROM city
        WHERE country = code
        GROUP BY country
) > 5