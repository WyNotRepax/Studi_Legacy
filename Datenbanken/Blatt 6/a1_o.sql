SELECT name, effective_area / area as anteil
FROM
(
    SELECT name,continent,area*percentage as effective_area
    FROM
    (
        SELECT country,continent,percentage
        FROM encompasses
        WHERE continent='Europe'
    )
    JOIN
    (
        SELECT name,code,area
        FROM COUNTRY
    )
    ON country = code
)
JOIN
(
    SELECT name as continent_name,area
    FROM continent
)
ON continent_name = continent