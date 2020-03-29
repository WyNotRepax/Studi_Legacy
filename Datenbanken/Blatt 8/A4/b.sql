SELECT name
FROM country
WHERE code NOT IN (
	SELECT country FROM geo_mountain
)
