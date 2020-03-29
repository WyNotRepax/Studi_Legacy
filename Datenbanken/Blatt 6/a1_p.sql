SELECT name
FROM country
WHERE NOT EXISTS
    (
        SELECT *
        FROM city
        WHERE population IS NOT NULL
        AND country.code = city.country
    )