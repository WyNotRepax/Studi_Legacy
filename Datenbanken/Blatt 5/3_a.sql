SELECT NAME FROM CITY JOIN (SELECT CODE FROM COUNTRY WHERE NAME='Germany') ON COUNTRY=CODE;