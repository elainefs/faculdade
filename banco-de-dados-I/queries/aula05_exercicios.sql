-- Active: 1729722794341@@127.0.0.1@1433@TESTE@dbo
CREATE TABLE CLIENTES(
    ID INT PRIMARY KEY,
    NOME NVARCHAR(100),
    CIDADE NVARCHAR(100)
);

sp_rename 'CLIENTES.ID', 'CLIENTE_ID', 'COLUMN';

INSERT INTO Clientes (ID, Nome, Cidade) VALUES
(1, 'João Silva', 'São Paulo'),
(2, 'Maria Souza', 'Rio de Janeiro'),
(3, 'Pedro Lima', 'Salvador'),
(4, 'Ana Costa', 'Brasília');

SELECT * FROM "CLIENTES";

CREATE TABLE PEDIDOS(
    PEDIDO_ID INT PRIMARY KEY,
    CLIENTE_ID INT,
    DATA_PEDIDO DATE,
    VALOR DECIMAL(10,2),
    FOREIGN KEY(CLIENTE_ID) REFERENCES CLIENTES(CLIENTE_ID)
);

INSERT INTO Pedidos (PEDIDO_ID, CLIENTE_ID, DATA_PEDIDO, VALOR) VALUES
(101, 1, '2024-01-10', 500.00),
(102, 2, '2024-01-11', 150.00),
(103, 1, '2024-01-12', 200.00),
(104, 3, '2024-01-13', 300.00);

SELECT * FROM PEDIDOS;

CREATE TABLE Produtos (
Produto_ID INT PRIMARY KEY,
Nome_Produto NVARCHAR(100),
Preco DECIMAL(10, 2)
);

INSERT INTO Produtos (Produto_ID, Nome_Produto, Preco) VALUES
(201, 'Televisão', 1200),
(202, 'Notebook', 2500),
(203, 'Celular', 1500);

SELECT * FROM "Produtos";

CREATE TABLE ItensPedido (
Pedido_ID INT,
Produto_ID INT,
Quantidade INT,
PRIMARY KEY (Pedido_ID, Produto_ID),
FOREIGN KEY (Pedido_ID) REFERENCES Pedidos(Pedido_ID),
FOREIGN KEY (Produto_ID) REFERENCES Produtos(Produto_ID)
);

INSERT INTO ItensPedido (Pedido_ID, Produto_ID, Quantidade) VALUES
(101, 201, 1),
(102, 202, 1),
(103, 203, 2),
(104, 201, 1);

SELECT * FROM "ItensPedido";

-- 5) Recupere o nome dos clientes e os detalhes dos pedidos que eles fizeram, mostrando o ClienteID, Nome do cliente, PedidoID, e Valor.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, P.VALOR
FROM "CLIENTES" C
INNER JOIN PEDIDOS P
ON C."CLIENTE_ID" = P."CLIENTE_ID";

-- 6) Liste todos os clientes e seus pedidos, mesmo os clientes que não fizeram pedidos. Exiba o ClienteID, Nome, PedidoID e Valor.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, P.VALOR
FROM "CLIENTES" C
LEFT JOIN PEDIDOS P
ON C."CLIENTE_ID" = P."CLIENTE_ID"; 

-- 7) Liste todos os pedidos e os clientes que os fizeram. Caso algum pedido não esteja associado a um cliente (situação hipotética), ainda assim deve aparecer. Mostre o PedidoID, Valor, ClienteID e Nome.
SELECT P.PEDIDO_ID, P.VALOR, C.CLIENTE_ID, C.NOME
FROM PEDIDOS P
RIGHT JOIN CLIENTES C
ON P."CLIENTE_ID" = C."CLIENTE_ID";

-- 8) Liste todos os clientes e todos os pedidos, independentemente de estarem associados entre si ou não. Mostre ClienteID, Nome, PedidoID e Valor.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, P.VALOR
FROM "CLIENTES" C
FULL OUTER JOIN PEDIDOS P
ON C."CLIENTE_ID" = P."CLIENTE_ID";

-- 9) Liste os clientes, seus pedidos e os produtos que foram comprados. Mostre o ClienteID, Nome, PedidoID, NomeProduto e a Quantidade.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, PROD.NOME_PRODUTO, I.QUANTIDADE
FROM "CLIENTES" C
INNER JOIN "PEDIDOS" P ON C."CLIENTE_ID" = P."CLIENTE_ID"
INNER JOIN "ItensPedido" I ON P."PEDIDO_ID" = I."PEDIDO_ID"
INNER JOIN PRODUTOS PROD ON I."Produto_ID" = PROD."Produto_ID";

-- 10) Liste todos os clientes e seus pedidos (se houver), juntamente com os produtos adquiridos. Mesmo os clientes que não fizeram pedidos devem aparecer. Mostre o ClienteID, Nome, PedidoID, NomeProduto e Quantidade.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, PROD.NOME_PRODUTO, I.QUANTIDADE
FROM CLIENTES C
LEFT JOIN PEDIDOS P ON C."CLIENTE_ID" = P."CLIENTE_ID"
LEFT JOIN "ItensPedido" I ON P.PEDIDO_ID = I."PEDIDO_ID"
LEFT JOIN PRODUTOS PROD ON I."Produto_ID" = PROD."Produto_ID";

-- 11) Liste todos os produtos e, se houver, os pedidos em que foram incluídos, assim como os clientes que fizeram esses pedidos. Mostre o ProdutoID, NomeProduto, PedidoID, Nome do cliente e Quantidade.
SELECT PROD.PRODUTO_ID, PROD.NOME_PRODUTO, P.PEDIDO_ID, C.NOME, I.QUANTIDADE
FROM PRODUTOS PROD
RIGHT JOIN "ItensPedido" I ON PROD."Produto_ID" = I."Produto_ID"
RIGHT JOIN PEDIDOS P ON I."Pedido_ID" = P."PEDIDO_ID"
RIGHT JOIN "CLIENTES" C ON P."CLIENTE_ID" = C."CLIENTE_ID";

-- 12) Liste todos os clientes, pedidos, produtos e itens de pedidos, independentemente de estarem relacionados entre si ou não. Mostre o ClienteID, Nome, PedidoID, ProdutoID, NomeProduto e Quantidade.
SELECT C.CLIENTE_ID, C.NOME, P.PEDIDO_ID, I."Produto_ID", PROD."Nome_Produto",I."Quantidade"
FROM "CLIENTES" C
FULL JOIN "PEDIDOS" P ON C."CLIENTE_ID" = P."CLIENTE_ID"
FULL JOIN "ItensPedido" I ON P."PEDIDO_ID" = I."Pedido_ID"
FULL JOIN "Produtos" PROD ON I."Produto_ID" = PROD.PRODUTO_ID;

-- 13) Encontre todos os clientes que moram na mesma cidade. Mostre o ClienteID e o Nome de ambos os clientes que compartilham a mesma cidade.
SELECT C."CLIENTE_ID", C.NOME, C2."CLIENTE_ID", C2.NOME, C.CIDADE
FROM Clientes C
JOIN Clientes C2 ON C.Cidade = C2.Cidade AND C.Cliente_ID <> C2.Cliente_ID
ORDER BY C.Cidade, C.Cliente_ID, C2.Cliente_ID;

-- 14) Crie uma consulta que mostre a combinação de todos os produtos com todos os clientes, como uma tabela de possibilidades. Mostre o ClienteID, Nome, ProdutoID e NomeProduto.
SELECT c.Cliente_ID, c.Nome, p.Produto_ID, p."Nome_Produto"
FROM Clientes c
CROSS JOIN Produtos p
ORDER BY c.Cliente_ID, p.Produto_ID;

-- 15) Clientes que compraram mais de um tipo de produto Descrição: Liste os clientes que compraram mais de um tipo de produto em diferentes pedidos. Mostre o ClienteID, o nome do cliente e a quantidade de tipos de produtos que ele comprou.Tabelas: Clientes, Pedidos, ItensPedido, Produtos
SELECT c.Cliente_ID, c.Nome AS NomeCliente, COUNT(DISTINCT ip.Produto_ID) AS QuantidadeTiposProdutos
FROM Clientes c
JOIN Pedidos p ON c.Cliente_ID = p.Cliente_ID
JOIN ItensPedido ip ON p.Pedido_ID = ip.Pedido_ID
GROUP BY c.Cliente_ID, c.Nome
HAVING COUNT(DISTINCT ip.Produto_ID) > 1
ORDER BY c.Cliente_ID;

SELECT c.Cliente_ID, c.Nome AS NomeCliente, tp.QuantidadeTiposProdutos
FROM Clientes c
JOIN (SELECT p.Cliente_ID, 
     COUNT(DISTINCT ip.Produto_ID) AS QuantidadeTiposProdutos
     FROM Pedidos p
     JOIN ItensPedido ip ON p.Pedido_ID = ip.Pedido_ID
     GROUP BY p.Cliente_ID
     ) tp ON c.Cliente_ID = tp.Cliente_ID
WHERE tp.QuantidadeTiposProdutos > 1
ORDER BY c.Cliente_ID;

-- 17 - Liste os clientes que compraram produtos, o nome do produto mais comprado por cada cliente, e a quantidade total desse produto  Comprado por ele. Caso um cliente tenha comprado mais de um produto com a mesma quantidade máxima, todos esses produtos devem ser listados.Tabela: Clientes, Pedidos, ItensPedido, Produtos
SELECT c.Cliente_ID, pr."Nome_Produto" AS NomeProduto, SUM(ip.Quantidade) AS TotalQuantidade
FROM Clientes c
JOIN Pedidos p ON c.Cliente_ID = p.Cliente_ID
JOIN ItensPedido ip ON p.Pedido_ID = ip.Pedido_ID
JOIN Produtos pr ON ip.Produto_ID = pr.Produto_ID
GROUP BY c.Cliente_ID, pr."Nome_Produto"
HAVING SUM(ip.Quantidade) = (
        SELECT 
            MAX(TotalQuantidade)
        FROM (
            SELECT 
                SUM(ip2.Quantidade) AS TotalQuantidade
            FROM 
                Pedidos p2
            JOIN 
                ItensPedido ip2 ON p2.Pedido_ID = ip2.Pedido_ID
            WHERE 
                p2.Cliente_ID = c.Cliente_ID
            GROUP BY 
                ip2.Produto_ID
        ) AS Subquery
    )
ORDER BY 
    c.Cliente_ID;

-- 18 - Liste os clientes que não compraram produtos de alta demanda. Defina produtos de alta demanda como aqueles que foram vendidos em uma quantidade total superior a 1 unidade em todos os pedidos combinados.Tabela: Clientes, Pedidos, ItensPedido, Produtos
SELECT 
    c.Cliente_ID, 
    c.Nome AS NomeCliente
FROM 
    Clientes c
WHERE 
    c.Cliente_ID NOT IN (
        SELECT 
            DISTINCT p.Cliente_ID
        FROM 
            Pedidos p
        JOIN 
            ItensPedido ip ON p.Pedido_ID = ip.Pedido_ID
        JOIN 
            Produtos pr ON ip.Produto_ID = pr.Produto_ID
        WHERE 
            pr.Produto_ID IN (
                SELECT 
                    ip2.Produto_ID
                FROM 
                    ItensPedido ip2
                GROUP BY 
                    ip2.Produto_ID
                HAVING 
                    SUM(ip2.Quantidade) > 1
            )
    )
ORDER BY 
    c.Cliente_ID;

-- 19 - Liste o valor total gasto por cada cliente e o número de produtos diferentes que cada cliente comprou. Mostre também o nome do cliente.Tabela: Clientes, Pedidos, ItensPedido, Produtos
SELECT 
    c.Cliente_ID,
    c.Nome AS NomeCliente,
    SUM(ip.Quantidade * pr.Preco) AS ValorTotalGasto,
    COUNT(DISTINCT ip.Produto_ID) AS NumeroProdutosDiferentes
FROM 
    Clientes c
JOIN 
    Pedidos p ON c.Cliente_ID = p.Cliente_ID
JOIN 
    ItensPedido ip ON p.Pedido_ID = ip.Pedido_ID
JOIN 
    Produtos pr ON ip.Produto_ID = pr.Produto_ID
GROUP BY 
    c.Cliente_ID, c.Nome
ORDER BY 
    c.Cliente_ID;







