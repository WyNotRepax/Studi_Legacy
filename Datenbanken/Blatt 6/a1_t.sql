SELECT name
FROM CITY
WHERE abs(latitude - (SELECT latitude FROM city WHERE name='Berlin')) < 1