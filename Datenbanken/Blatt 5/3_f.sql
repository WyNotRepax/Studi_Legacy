SELECT name FROM country JOIN(
    SELECT UNIQUE country FROM city WHERE
        longitude > -5 AND
        longitude < 5
    )ON
        code=country;