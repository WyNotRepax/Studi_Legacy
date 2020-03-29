CREATE TABLE See(
  name VARCHAR(15),
  tiefe INTEGER,
  PRIMARY KEY(name)
);

INSERT INTO See VALUES('Wannsee',10);
INSERT INTO See VALUES('Wersee',8);
INSERT INTO See VALUES('Wosee',12);

COMMIT;

SELECT * FROM See;