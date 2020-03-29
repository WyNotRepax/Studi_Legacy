SELECT *
FROM
(
    SELECT country,name, elevation
    FROM
    (
        SELECT country,mountain
        FROM
        (
            SELECT country
                FROM encompasses
                WHERE continent='America'
        )
        JOIN
        (
            SELECT mountain,country as mountain_country
            FROM geo_mountain
        )
        ON country = mountain_country
    )
    JOIN
    (
        SELECT name,elevation
        FROM mountain
    )
    ON name=mountain
    ORDER BY elevation DESC
)
WHERE ROWNUM=1;