SELECT name,country,anzahlsprachen
FROM(
    SELECT name,code 
    FROM country
    )
JOIN(
    SELECT count(*) as anzahlsprachen,country
    FROM language
    GROUP BY country
    ORDER BY anzahlsprachen DESC
    )
ON country=code
WHERE rownum = 1;