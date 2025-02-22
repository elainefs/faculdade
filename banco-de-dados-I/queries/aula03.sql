-- Active: 1729722794341@@127.0.0.1@1433@SERRA@dbo
-- SELECIONAR CAMPOS
SELECT CAD_NOME, CAD_FONE_1
FROM "CADASTROS";

-- SELECIONAR CAMPOS FILTRANDO POR BAIRRO E NOME
SELECT CAD_CPF, CAD_NOME, CAD_ENDERECO, CAD_BAIRRO, CAD_CIDADE, CAD_ESTADO
FROM "CADASTROS"
WHERE "CAD_CIDADE" = 'BELEM' AND "CAD_BAIRRO" = 'PEDREIRA';

-- USO DO LIKE
SELECT PRO_NOME AS NOME, (PRO_PRECO_VAREJO * 1.1) AS PRECO
FROM "PRODUTOS"
WHERE PRO_NOME LIKE 'T%';

SELECT CAD_NOME, CAD_FONE_1
FROM "CADASTROS"
WHERE "CAD_NOME" LIKE '%MARIA%';

-- USO DO UNDERSCORE PARA SUBSTITUIR CARACTERES
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_NOME" LIKE '%f_t%';

-- COMECE COM C OU M
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_NOME" LIKE '[CM]%';

-- COMECE COM C ATÉ X
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_NOME" LIKE '[C-X]%';

-- COMECE COM M E NÃO TENHA O COMO SEGUNDA LETRA
SELECT PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_NOME" LIKE 'M[^O]%';

-- AUMENTO DE 10%
Select pro_codigo, pro_nome, pro_preco_varejo, (pro_preco_varejo*1.1)
From produtos;

-- USO DO ROUND
SELECT pro_nome, pro_preco_varejo*0.9 as PRECO_CALCULADO, ROUND(pro_preco_varejo*0.9,2) as PRECO_ARREDONDADO
FROM PRODUTOS;

-- USO BETWEEN
SELECT PRO_CODIGO, PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" BETWEEN 100 AND 150;

-- USO DO IN
SELECT PRO_CODIGO, PRO_NOME, PRO_PRECO_VAREJO
FROM "PRODUTOS"
WHERE "PRO_PRECO_VAREJO" IN(10, 15);

-- FUNÇÕES DE AGREGAÇÃO
SELECT COUNT(*) AS CLIENTES, MAX(pro_preco_varejo) AS MAXIMO, MIN(pro_preco_varejo) AS MINIMO, AVG(pro_preco_varejo) AS MEDIA, SUM(pro_preco_varejo) AS SOMA
FROM produtos;