CREATE TABLE Gebinde (
    ID NUMBER(10) NOT NULL,
    Sorte VARCHAR2(1 CHAR),
    Groesse FLOAT(24)
		CHECK (Groesse >= '0'),
    Gewicht FLOAT(24)
		CHECK (Gewicht >= '0'),
    Stearkegehalt NUMBER(4,3)
		CHECK (Stearkegehalt <= '1' AND Stearkegehalt >= '0'),
    Fleckigkeit NUMBER(4,3)
		CHECK (Fleckigkeit <= '1' AND Fleckigkeit >= '0'),
	Ort_ID NUMBER(10) NOT NULL,
    PRIMARY KEY (ID)
);
 
CREATE TABLE Ort (
    ID NUMBER(10) NOT NULL,
    Kapazitaet NUMBER(10),
    Adresse VARCHAR2(1 CHAR),
    TYPE NUMBER(10) NOT NULL,
    PRIMARY KEY (ID)
);
 
CREATE TABLE Bunker (
    Sorte VARCHAR2(1 CHAR),
    Groesse FLOAT(24) 
		CHECK (Groesse >= '0'),
    ID NUMBER(10) NOT NULL,
	PRIMARY KEY(ID)
);
 
CREATE TABLE Stelle (
    Zeile NUMBER(10),
    Spalte NUMBER(10),
    Groesse FLOAT(24) 
		CHECK (Groesse >= '0'),
    Einlagerungszeitpunkt DATE,
    ID NUMBER(10) NOT NULL,
    PRIMARY KEY (Zeile, Spalte)
);
 
ALTER TABLE Gebinde
	ADD FOREIGN KEY (Ort_ID)
	REFERENCES Ort (ID);
 
 
ALTER TABLE Stelle
	ADD FOREIGN KEY (ID)
	REFERENCES Ort (ID);
	
	
ALTER TABLE Bunker
	ADD FOREIGN KEY (ID)
	REFERENCES Ort (ID);