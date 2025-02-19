-- Active: 1729722794341@@127.0.0.1@1433@SERRA@dbo

-- Exercícios Propostos com base na estrutura da tabela CADASTROS,

-- 01-Liste o nome, fone, bairro e cidade de todos os clientes;
SELECT CAD_NOME, CAD_FONE_1, CAD_BAIRRO, CAD_CIDADE
FROM "CADASTROS";

-- 02-Liste o nome, fone, bairro e cidade de todos os clientes do bairro CENTRO, utilize a cláusula AS para renomear campos;
SELECT CAD_NOME AS 'NOME', CAD_FONE_1 AS 'TELEFONE', CAD_BAIRRO AS 'BAIRRO', CAD_CIDADE AS 'CIDADE'
FROM "CADASTROS"
WHERE CAD_BAIRRO = 'CENTRO';

-- 03-Liste o nome, fone, bairro e cidade de todos os clientes do bairro CENTRO, na ordem alfabética por cidade;
SELECT CAD_NOME AS 'NOME', CAD_FONE_1 AS 'TELEFONE', CAD_BAIRRO AS 'BAIRRO', CAD_CIDADE AS 'CIDADE'
FROM "CADASTROS"
WHERE CAD_BAIRRO = 'CENTRO'
ORDER BY CAD_CIDADE;

-- 04-Liste o nome, fone, bairro e cidade de todos os clientes do bairro CENTRO, da cidade BELEM e/ou BELÉM, na ordem alfabética por nome do cliente;
SELECT CAD_NOME AS 'NOME', CAD_FONE_1 AS 'TELEFONE', CAD_BAIRRO AS 'BAIRRO', CAD_CIDADE AS 'CIDADE'
FROM "CADASTROS"
WHERE "CAD_BAIRRO" = 'CENTRO' AND ("CAD_CIDADE" = 'BELEM' OR "CAD_CIDADE" = 'BELÉM')
-- WHERE "CAD_BAIRRO" LIKE 'CENTRO' AND "CAD_CIDADE" LIKE 'BEL[EÉ]M'
ORDER BY "CAD_NOME";

-- 05-Considere que o campo CAD_TIPO_PESSOA, guarda o caracter J ou F para pessoas Júrídicas e Físicas respectivamente. Faça duas listas, uma de pesoas físicas e outra de pessoas jurídicas;
SELECT CAD_NOME, CAD_TIPO_PESSOA
FROM "CADASTROS"
WHERE "CAD_TIPO_PESSOA" = 'F';

SELECT CAD_NOME, CAD_TIPO_PESSOA
FROM "CADASTROS"
WHERE "CAD_TIPO_PESSOA" = 'J';

-- 06-Liste o nome, fone, bairro e cidade de todos os clientes que não sejam do estado do Pará, na ordem alfabética por cidade;
SELECT CAD_NOME, CAD_FONE_1, CAD_BAIRRO, CAD_CIDADE, CAD_ESTADO
FROM "CADASTROS"
WHERE "CAD_ESTADO" != 'PA'
ORDER BY "CAD_CIDADE";

-- 07-Liste todas as MARIAS do cadastro.
SELECT CAD_NOME
FROM "CADASTROS"
WHERE CAD_NOME LIKE 'MARIA[^_]%';

-- 08-Liste todas os Estados (UF) onde a loja tem clientes.
SELECT CAD_NOME, CAD_ESTADO
FROM "CADASTROS"
-- WHERE CAD_ESTADO LIKE 'UF'
WHERE "CAD_ESTADO" != 'NULL';

-- *****************

-- Exercícios Propostos com base na estrutura da tabela PRODUTOS

-- 01-Liste o código, nome e preços de todos os produtos;
SELECT PRO_CODIGO, PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS";

-- 02-Liste o código, nome e custos de todos os produtos classificando por nome do produto;
SELECT PRO_CODIGO, PRO_NOME, PRO_CUSTO_ANTERIOR, PRO_CUSTO_MEDIO, PRO_CUSTO_ATUAL
FROM "PRODUTOS"
ORDER BY "PRO_NOME";

-- 03-Liste o código, nome, estoque atual da loja, custo atual e preço de varejo de todos os produtos, classificando do menor para o maior preço;
SELECT PRO_CODIGO, PRO_NOME, PRO_EST_ATUAL_LOJA, PRO_CUSTO_ATUAL, PRO_PRECO_VAREJO
FROM "PRODUTOS"
ORDER BY PRO_PRECO_VAREJO;

-- 04-Liste o código, nome, estoque atual da loja, custos atual, preço de varejo, total dos custos e total dos preços de todos os produtos classificando por nome do produto;

SELECT PRO_CODIGO, PRO_NOME, PRO_EST_ATUAL_LOJA, PRO_CUSTO_ATUAL, PRO_PRECO_VAREJO, (PRO_CUSTO_ATUAL * PRO_EST_ATUAL_LOJA) AS CUSTO, (PRO_EST_ATUAL_LOJA * PRO_PRECO_VAREJO) AS PRECOS
FROM "PRODUTOS"
WHERE PRO_EST_ATUAL_LOJA > 0 AND PRO_PRECO_VAREJO > 0
ORDER BY 2;

-- 05-Considere que a tabela SECAO tem somente dois campos: SEC_CODIGO e SEC_DESCRICAO. Faça uma lista que mostre o produto e a descrição da seção o qual ele pertence;
SELECT PRO_NOME, SEC_DESCRICAO
FROM "PRODUTOS", "SECAO"
WHERE PRO_SECAO = SEC_CODIGO;

SELECT PRO_NOME, SEC_DESCRICAO
FROM "PRODUTOS"
INNER JOIN "SECAO"
ON "SEC_CODIGO" = "PRO_SECAO";

-- 06-Liste o nome, descrição da seção e preço de atacado de todos os produtos da seção BOMBA THEBE, classificando por nome do produto;
SELECT PRO_NOME, SEC_DESCRICAO, PRO_PRECO_ATACADO
FROM "PRODUTOS", "SECAO"
WHERE PRO_SECAO = SEC_CODIGO AND "SEC_DESCRICAO" = 'BOMBA THEBE';

-- 07-Liste o nome e preço de varejo de todos os produtos com preços entre R$ 200 e R$ 250, classificando por preço;
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" BETWEEN 200 AND 250
ORDER BY 2;

-- 08-Liste todos os produtos com preço de varejo igual a 10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90 e 100;
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" IN(10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90, 100);

-- 09-Liste o nome, descrição da seção e preço de atacado de todos os produtos que tenha no nome o string ‘moto’, classificado em ordem descendente por nome do produto;
SELECT PRO_NOME, SEC_DESCRICAO, PRO_PRECO_ATACADO
FROM "PRODUTOS", "SECAO"
WHERE PRO_NOME LIKE '%MOTO%'
ORDER BY PRO_NOME;

-- 10-Liste o nome, estoque atual da loja, preço de varejo, total dos preços e data de cadastro de todos os produtos cadastrados entre 01 e 28/02/2009, classificando pela data de cadastro do mesmo;
SELECT PRO_NOME, PRO_EST_ATUAL_LOJA, PRO_PRECO_VAREJO,  (PRO_EST_ATUAL_LOJA * PRO_PRECO_VAREJO) AS PRECOS, PRO_DATA_CADASTRO
FROM "PRODUTOS"
WHERE "PRO_DATA_CADASTRO" BETWEEN '2009-02-01' AND '2009-02-28'
ORDER BY "PRO_DATA_CADASTRO";

-- 11-Mostre quantos registros de produtos foram registrados no período de 01/01/2009 a 31/12/2009;
SELECT COUNT(PRO_NOME)
FROM "PRODUTOS"
WHERE "PRO_DATA_CADASTRO" > '2009-01-01' AND "PRO_DATA_CADASTRO" < '2009-12-31';

-- 12-Liste o produto mais caro da loja;
SELECT MAX(PRO_PRECO_VAREJO)
FROM "PRODUTOS";

SELECT TOP 1 (PRO_PRECO_VAREJO) AS MAIOR_VALOR
FROM "PRODUTOS"
ORDER BY "PRO_PRECO_VAREJO" DESC;

-- 13-Liste o produto mais barato da loja;
SELECT MIN(PRO_PRECO_VAREJO)
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" > 0;

SELECT TOP 1 (PRO_PRECO_VAREJO) AS MENOR_VALOR
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" > 0
ORDER BY PRO_PRECO_VAREJO;

-- 14-Qual a soma em valor (preço) de todos os produtos da loja;
SELECT SUM(PRO_PRECO_VAREJO * PRO_EST_ATUAL_LOJA) AS SOMA_PRECO
FROM "PRODUTOS"
WHERE PRO_PRECO_VAREJO > 0 AND PRO_EST_ATUAL_LOJA > 0;

