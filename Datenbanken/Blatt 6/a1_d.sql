SELECT countryname,lakename,area
FROM
(
    SELECT DISTINCT name as lakename, country as lake_country_code, area 
    FROM geo_lake
    JOIN lake
    ON lake=name
)
JOIN
(
    SELECT name as countryname,code
    FROM country
    JOIN encompasses
    ON country.code = encompasses.country
    WHERE continent = 'Europe'
)
ON lake_country_code = code