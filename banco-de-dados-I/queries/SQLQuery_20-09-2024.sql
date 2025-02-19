CREATE DATABASE "TESTE";

CREATE TABLE MinhaTabela1 (
	MeuDecimal DECIMAL(5,2),
	MeuNumeric NUMERIC(10,5)
);

INSERT INTO MinhaTabela1 VALUES (123, 12345.12);

INSERT INTO MinhaTabela1 VALUES (12345.67, 12345.12);

SELECT MeuDecimal, MeuNumeric
FROM MinhaTabela1;

-----------------

CREATE TABLE MinhaTabela2 (
	MeuFloat FLOAT,
	MeuReal REAL
);

INSERT INTO MinhaTabela2 VALUES (123.45, 12345.678);

SELECT MeuFloat, MeuReal
FROM MinhaTabela2;

-----------------

CREATE TABLE MinhaTabela3 (
	MeuMoney MONEY,
	MeuSmallMoney SMALLMONEY
);

INSERT INTO MinhaTabela3 VALUES (123, 12345);

SELECT MeuMoney, MeuSmallMoney
FROM MinhaTabela3;

----------------

DECLARE @date date = GETDATE();
DECLARE @time time = GETDATE();
DECLARE @datetime datetime = GETDATE();
DECLARE @datetime2 datetime2(4) = GETDATE();
DECLARE @smalldatetime smalldatetime = GETDATE();

SELECT @datetime AS datetime,
       @datetime2 AS datetime2,
	   @smalldatetime AS smalldatetime,
	   @date AS date,
	   @time AS time;

----------------

DECLARE @char char(5), @varchar varchar(20);

SET @char = 'GUTIERREZ'
SET @varchar = 'GUTIERREZ'

SELECT @char, @varchar;

----------------

DECLARE @g geography;

SET @g = geography::Point(47.65100, - 122.34900, 4326);

SELECT @g.ToString();

----------------

DROP TABLE  MinhaTabela1;

----------------

CREATE TABLE Alunos (
	codigo CHAR(7) NOT NULL,
	nome VARCHAR(30) NOT NULL,
	dtNasc DATE,
	endereco VARCHAR(30),
	PRIMARY KEY (codigo)
);

SELECT * FROM Alunos;

ALTER TABLE Alunos
ALTER COLUMN nome VARCHAR(50) NOT NULL;

ALTER TABLE Alunos
ADD email VARCHAR(30);

ALTER TABLE Alunos
DROP COLUMN email;

INSERT INTO Alunos(codigo, nome, dtNasc, endereco)
VALUES (1, 'Maria das Dores', '30/12/1995', 'Av. Alte Barroso 1500');

INSERT INTO Alunos(codigo, nome, dtNasc, endereco)
VALUES (2, 'Paula Soares', '01/04/2002', 'Av. Alte Barroso 1500');

INSERT INTO Alunos(codigo, nome, dtNasc, endereco)
VALUES (3, 'Dione Gomes', '03/04/2003', 'Av. Alte Barroso 1500');

INSERT INTO Alunos(codigo, nome, dtNasc, endereco)
VALUES (4, 'Jose Maria', '04/04/2003', 'Av. Alte Barroso 1500');

INSERT INTO Alunos(codigo, nome, dtNasc, endereco)
VALUES (5, 'Maria das Dores', '02/04/2002', 'Av. Alte Barroso 1500');

----------------

UPDATE Alunos
SET endereco = 'Av. Nazaré 1315';

UPDATE Alunos
SET endereco ='Av. Nazaré 1315'
WHERE nome = 'Maria das Dores';

---------------

DELETE FROM Alunos
WHERE codigo = 1;