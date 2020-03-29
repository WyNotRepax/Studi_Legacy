SELECT river as name
FROM
(
SELECT river,count(*) as anzahllaender
    FROM
    (
        SELECT DISTINCT river,country
        FROM geo_river
    )
    GROUP BY river
)
WHERE anzahllaender > 2