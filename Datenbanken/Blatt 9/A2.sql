-- Benno:
GRANT ALL ON See TO ojohneuha;
COMMIT;
CREATE SYNONYM other_see FOR ojohneuha.see;
-- Johann:
GRANT ALL ON See TO obsteinka;
COMMIT;
CREATE SYNONYM other_see FOR obsteinka.see;
-- Beide:
(
    SELECT * FROM see
    MINUS
    SELECT * FROM other_see
)
UNION
(
    SELECT * FROM other_see
    MINUS
    SELECT * FROM see
);
--> Gibt Unterschiedliche Zeilen zurück

--Johann:
INSERT INTO See VALUES('Baggersee',1);

--Benno:
SELECT * FROM See; ->
NAME                 TIEFE
--------------- ----------
Wannsee                 10
Wersee                   8
Wosee                   12

--Johann:
SELECT * FROM See; ->
NAME                 TIEFE
--------------- ----------
Wannsee                 10
Wersee                   8
Wosee                   12
Baggersee                1

--Benno:
INSERT INTO Other_See VALUES('Baggersee',1);
-> Es Lädt
--Johann:
COMMIT; ->
Commit abgeschlossen.
--Benno:
->
Fehlerbericht -
ORA-00001: Unique Constraint (OJOHNEUHA.SYS_C00261276) verletzt
--Johann:
UPDATE See SET TIEFE = TIEFE + 1 WHERE NAME = 'Baggersee'; ->
1 Zeile aktualisiert.
--Benno:
UPDATE Other_See SET TIEFE = TIEFE + 1 WHERE NAME = 'Baggersee';
-> Es Lädt
--Johann
COMMIT; ->
Commit abgeschlossen.
--Benno:
1 Zeile aktualisiert.
--Johann:
SELECT * FROM See; ->
NAME                 TIEFE
--------------- ----------
Wannsee                 10
Wersee                   8
Wosee                   12
Baggersee                2
--Benno:
SELECT * FROM Other_See; ->
NAME                 TIEFE
--------------- ----------
Wannsee                 10
Wersee                   8
Wosee                   12
Baggersee                3
COMMIT; ->
Commit abgeschlossen.
--Johann:
SELECT * FROM See; ->
NAME                 TIEFE
--------------- ----------
Wannsee                 10
Wersee                   8
Wosee                   12
Baggersee                3
--Benno:
CREATE VIEW see_view AS SELECT NAME FROM See; ->
View SEE_VIEW erstellt.
GRANT ALL ON See_View TO ojohneuha; ->
Grant erfolgreich;
REVOKE ALL ON SEE FROM ojohneuha; ->
Revoke erfolgreich.
COMMIT; ->
Commit abgeschlossen.
--Johann:
SELECT * FROM obsteinka.See_View; ->
NAME           
---------------
Wannsee
Wersee
Wosee
UPDATE obsteinka.See_View SET NAME = 'Test' WHERE NAME = 'Wosee'; -> 
1 Zeile aktualisiert.
COMMIT; ->
Commit abgeschlossen.
SELECT * FROM obsteinka.See_View; ->
NAME           
---------------
Test
Wannsee
Wersee
