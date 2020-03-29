SELECT name,sum(population) as anzahleinwohner
FROM
(
    SELECT name,country
    FROM
    (
        SELECT abbreviation,name
        FROM organization
    )
    JOIN
    (
    SELECT country,organization
    FROM ismember
    )
    ON abbreviation=organization
)
JOIN
(
    SELECT code,population
    FROM country
)
ON country=code
GROUP BY name