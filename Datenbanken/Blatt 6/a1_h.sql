SELECT UNIQUE name FROM country JOIN (
SELECT country from geo_river where river='Donau'
) ON country=code;