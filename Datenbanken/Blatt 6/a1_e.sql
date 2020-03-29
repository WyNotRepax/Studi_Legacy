SELECT river,anzahllaender
FROM
(
    SELECT river,count(*) as anzahllaender
    FROM
    (
        SELECT DISTINCT river,country
        FROM geo_river
    )
    GROUP BY river
    ORDER BY anzahllaender DESC
)
WHERE ROWNUM = 1;