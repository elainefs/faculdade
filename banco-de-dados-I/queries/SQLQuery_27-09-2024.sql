-- Cria Tabela_A

CREATE TABLE Tabela_A 
(
  id CHAR(2), 
  nome VARCHAR(10)
);

INSERT into Tabela_A (id, nome) values (1,'Cão');
INSERT into Tabela_A (id, nome) values (2,'Macaco');
INSERT into Tabela_A (id, nome) values (3,'Gato');
INSERT into Tabela_A (id, nome) values (4,'Porco');
-----------------------------------------------------

-- Cria Tabela_B
CREATE TABLE Tabela_B 
(
  id CHAR(2), 
  nome VARCHAR(10)
);

INSERT into Tabela_B (id, nome) values (1,'Leão');
INSERT into Tabela_B (id, nome) values (2,'Cão');
INSERT into Tabela_B (id, nome) values (3,'Urso');
INSERT into Tabela_B (id, nome) values (4,'Gato');


-----------------------------------------------------
-- Uso do JOIN no DB SERRA
use SERRA
SELECT  SEC_DESCRICAO	as Seção,
		PRO_NOME		as Produto
FROM      SECAO,PRODUTOS 
WHERE   SEC_CODIGO = PRO_SECAO
ORDER BY  1, 2
CARLOS BENEDITO BARREIROS GUTIERREZ
08:49
SELECT	S.SEC_DESCRICAO as Secao 
		,P.PRO_NOME		as Produto
FROM SECAO as S
INNER JOIN PRODUTOS as P 
   ON  S.SEC_CODIGO = P.PRO_SECAO
   ORDER BY 1 , 2
   
-----------------------------------------------------
-- Cria a Tabela Cliente - 1
CREATE TABLE Clientes 
(
    ClienteID INT PRIMARY KEY,
    Nome NVARCHAR(100),
    Cidade NVARCHAR(100)
);

INSERT INTO Clientes (ClienteID, Nome, Cidade)
VALUES 
(1, 'João Silva', 'São Paulo'),
(2, 'Maria Souza', 'Rio de Janeiro'),
(3, 'Pedro Lima', 'Salvador'),
(4, 'Ana Costa', 'Brasília');

-- Cria a Tabela Pedidos - 2

CREATE TABLE Pedidos (
    PedidoID INT PRIMARY KEY,
    ClienteID INT,
    DataPedido DATE,
    Valor DECIMAL(10, 2),
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ClienteID)
);

INSERT INTO Pedidos (PedidoID, ClienteID, DataPedido, Valor)
VALUES
(101, 1, '2024-01-10', 500.00),
(102, 2, '2024-01-11', 150.00),
(103, 1, '2024-01-12', 200.00),
(104, 3, '2024-01-13', 300.00);

-- Cria a Tabela Produtos - 3

CREATE TABLE Produtos (
    ProdutoID INT PRIMARY KEY,
	NomeProduto NVARCHAR(100),
	Preco DECIMAL(10,2)
);

INSERT INTO Produtos(ProdutoID, NomeProduto, Preco)
VALUES (201, 'Televião', 1200),(202, 'Notebook', 2500),(203, 'Celular', 1500);

-- Cria a Tabela ItensPedidos - 4

CREATE TABLE ItensPedido (
    PedidoID INT,
    ProdutoID INT,
    Quantidade INT,
    PRIMARY KEY (PedidoID, ProdutoID),
    FOREIGN KEY (PedidoID) REFERENCES Pedidos(PedidoID),
    FOREIGN KEY (ProdutoID) REFERENCES Produtos(ProdutoID)
);

INSERT INTO ItensPedido (PedidoID, ProdutoID, Quantidade)
VALUES
(101, 201, 1),
(102, 202, 1),
(103, 203, 2),
(104, 201, 1);

-- Exercício JOIN

-- 5

SELECT c.ClienteID, c.Nome, p.PedidoID, p.Valor
FROM Clientes c
INNER JOIN Pedidos p
ON c.ClienteID = p.ClienteID;

-- 6

SELECT c.ClienteID, c.Nome, p.PedidoID, p.Valor
FROM Clientes c
LEFT JOIN Pedidos p
ON c.ClienteID = p.ClienteID;

-- 7

SELECT c.ClienteID, c.Nome, p.PedidoID, p.Valor
FROM Pedidos p
RIGHT JOIN Clientes c
ON c.ClienteID = p.ClienteID;

-- 8

SELECT c.ClienteID, c.Nome, p.PedidoID, p.Valor
FROM Clientes c
FULL JOIN Pedidos p
ON c.ClienteID = p.ClienteID;

-- 9

SELECT c.ClienteID, c.Nome, prod.NomeProduto, p.PedidoID, i.Quantidade
FROM Clientes c
INNER JOIN Pedidos p
ON c.ClienteID = p.ClienteID
INNER JOIN ItensPedido i
ON p.PedidoID = i.PedidoID
INNER JOIN Produtos prod
ON i.ProdutoID = prod.ProdutoID;

-- 10

SELECT c.ClienteID, c.Nome, p.PedidoID, prod.NomeProduto, i.Quantidade
FROM Clientes c
LEFT JOIN Pedidos p
ON c.ClienteID = p.ClienteID
LEFT JOIN ItensPedido i
ON p.PedidoID = i.PedidoID
LEFT JOIN Produtos prod
ON i.ProdutoID = prod.ProdutoID;


-- db: SERRA

SELECT SEC_DESCRICAO AS Secao, PRO_NOME AS Produto
FROM SECAO 
INNER JOIN PRODUTOS
ON SEC_CODIGO = PRO_SECAO
ORDER BY 1,2;

SELECT SEC_DESCRICAO, PRO_NOME
FROM SECAO
LEFT JOIN PRODUTOS
ON SEC_CODIGO = PRO_SECAO
ORDER BY 1,2;

SELECT SEC_DESCRICAO, PRO_NOME
FROM SECAO
RIGHT JOIN PRODUTOS
ON SEC_CODIGO = PRO_SECAO
ORDER BY 1,2;

SELECT SEC_DESCRICAO, PRO_NOME
FROM SECAO
FULL JOIN PRODUTOS
ON SEC_CODIGO = PRO_SECAO
ORDER BY 1,2;