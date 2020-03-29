SELECT name
FROM
    country
JOIN
    (
        SELECT country1 as country
        FROM BORDERS
        WHERE country2 = 'D'
        UNION
        SELECT country2 as country
        FROM BORDERS
        WHERE country1 = 'D'
    )
ON country = code;