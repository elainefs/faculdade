-- Aula: 13-09-2024
-- DB: SERRA
SELECT pro_codigo, pro_nome, pro_preco_varejo, (pro_preco_varejo * 1.1) AS Preco_Majorado
FROM produtos
WHERE pro_preco_varejo > 1000
ORDER BY pro_preco_varejo;

-- #####
SELECT pro_nome, pro_preco_varejo * 0.9 AS Preco_Calculado, ROUND(pro_preco_varejo * 0.9, 2) AS Preco_Arredondado
FROM produtos;

-- #####
SELECT ROUND(PI(), 3) AS PI_Arredondado;

-- #####
SELECT pro_codigo, pro_nome, pro_preco_varejo
FROM produtos
WHERE pro_preco_varejo BETWEEN 100 AND 150;

-- #####
SELECT pro_nome AS Nome, pro_preco_varejo AS Preco
FROM produtos
WHERE pro_preco_varejo IN (10, 20, 30, 40, 50, 60, 70, 80, 90);

-- #####
SELECT pro_nome, pro_preco_varejo
FROM produtos
WHERE pro_nome LIKE '%f_t%';

SELECT cad_nome, cad_fone_1
FROM cadastros
WHERE cad_nome LIKE '%f_t%';

-- #####
SELECT *
FROM cadastros
WHERE cad_nome LIKE 'Maria%' AND cad_data_cadastro > '12/01/2003'
ORDER BY cad_data_cadastro

-- #####
-- A ou B
SELECT *
FROM cadastros
WHERE cad_nome LIKE '[AB]%';

-- A ate C
SELECT *
FROM cadastros
WHERE cad_nome LIKE '[A-C]%';

-- Nao inicia com V
SELECT *
FROM cadastros
WHERE cad_nome LIKE '[^V]%';

-- #####
SELECT s.sec_descricao, p.pro_nome, p.pro_preco_varejo
FROM produtos AS p, secao AS s
WHERE s.sec_codigo = p.pro_secao
ORDER BY s.sec_descricao, p.pro_nome;

SELECT s.sec_descricao, p.pro_nome, p.pro_preco_varejo
FROM produtos AS p, secao AS s
WHERE s.sec_codigo = p.pro_secao
ORDER BY 1, 3; -- Indica a posi��o no SELECT

-- #####
SELECT MAX(pro_preco_varejo) AS MAX, MIN(pro_preco_varejo) AS MIN, AVG(pro_preco_varejo) AS AVG
FROM produtos
WHERE pro_preco_varejo > 0;

SELECT SUM(pro_est_atual_loja * pro_preco_varejo) AS Total
FROM produtos
WHERE pro_preco_varejo > 0 AND pro_est_atual_loja > 0;

-- DB: SERRA
-- Exercicios

-- 04 - Cadastro
SELECT cad_nome as Nome, cad_fone_1 as Fone, cad_bairro as Bairro, cad_cidade as Cidade
FROM cadastros
WHERE cad_bairro LIKE 'CENTRO' AND cad_cidade LIKE 'BEL[E�]M';

SELECT DISTINCT cad_estado AS estados
FROM cadastros
ORDER BY 1;

-- 04 - Produtos
SELECT pro_codigo AS codigo,
		pro_nome AS nome,
		pro_est_atual_loja AS est_atual,
		pro_custo_atual AS custo_atual,
		(pro_est_atual_loja * pro_custo_atual) as total_custo,
		pro_preco_varejo AS preco,
		(pro_est_atual_loja * pro_preco_varejo) as total_preco
FROM produtos
WHERE pro_preco_varejo > 0 AND pro_est_atual_loja > 0
ORDER BY 2;
