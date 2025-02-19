-- Active: 1729722794341@@127.0.0.1@1433@SERRA@dbo
-- Elabore uma instrução SQL para exibir a descrição da seção, nome do
-- produto, qtde em estoque na loja e preço de varejo do produto, classificando a listagem
-- na ordem alfabética por descrição da seção e em cada seção na ordem alfabética por
-- nome do produto. As informações devem aparecer em caixa alta. Faça dois comando de
-- junção, uma com a cláusula WHERE e outra com JOIN;
SELECT S.SEC_DESCRICAO AS SECAO, UPPER(P.PRO_NOME) AS PRODUTO
FROM SECAO S
INNER JOIN PRODUTOS P
ON S.SEC_CODIGO = P.PRO_SECAO
ORDER BY 1, 2;

-- O departamento de contabilidade solicitou uma listagem com o código,
-- nome, estoque atual da loja, preço de varejo e total por produto (Estoque*Preço),
-- classificando do menor para o maior TOTAL. Considere apenas valores (estoque e
-- preço) positivos.
SELECT PRO_CODIGO AS CODIGO, PRO_NOME AS NOME, PRO_EST_ATUAL_LOJA AS ESTOQUE, PRO_PRECO_VAREJO AS PRECO, (PRO_EST_ATUAL_LOJA*PRO_PRECO_VAREJO) AS TOTAL
FROM PRODUTOS
WHERE PRO_EST_ATUAL_LOJA > 0
AND PRO_PRECO_VAREJO > 0
ORDER BY TOTAL;

-- Elabore uma instrução SQL que apresente como resultado a listagem dos 10
-- produtos que dariam mais retorno financeiro para loja, caso houvesse uma liquidação.
SELECT TOP 10 PRO_CODIGO AS CODIGO, PRO_NOME AS NOME, PRO_EST_ATUAL_LOJA AS ESTOQUE, PRO_PRECO_VAREJO AS PRECO,(PRO_EST_ATUAL_LOJA*PRO_PRECO_VAREJO) AS TOTAL
FROM PRODUTOS
WHERE PRO_EST_ATUAL_LOJA > 0
AND PRO_PRECO_VAREJO > 0
ORDER BY TOTAL DESC;

-- Elabore uma instrução SQL para exibir o produto com MAIOR preço de
-- varejo da seção cuja descrição é BOMBA THEBE. Considere apenas preços positivos.
SELECT TOP 1 S.SEC_DESCRICAO AS SECAO, UPPER(P.PRO_NOME) AS PRODUTO, PRO_PRECO_VAREJO AS PRECO
FROM SECAO S
INNER JOIN PRODUTOS P
ON S.SEC_CODIGO=P.PRO_SECAO
WHERE S.SEC_DESCRICAO LIKE '%THEBE%' AND PRO_PRECO_VAREJO > 0
ORDER BY 3 DESC

-- Exibir todos os atributos de 10% dos produtos cadastrados
SELECT TOP 10 PERCENT *
FROM PRODUTOS;

-- Em quais cidades nossa empresa possui clientes?
-- OBS: A cláusula GROUP BY é utilizada em conjunto com as operações MIN, MAX, SUM, COUNT e AVG.
SELECT DISTINCT CAD_CIDADE, COUNT(*) AS TOTAL
FROM "CADASTROS"
GROUP BY CAD_CIDADE
ORDER BY 1;

-- Listar a quantidade de clientes, por cidade, mas somente para cidades cujo nome inicie por ‘C’.
SELECT CAD_CIDADE, COUNT(*) AS TOTAL
FROM CADASTROS
GROUP BY CAD_CIDADE
HAVING CAD_CIDADE LIKE 'C%';

-- O departamento de contabilidade solicitou uma listagem de -- produtos com o nome, seção, estoque atual da loja, preço de varejo e total por produto (Estoque*Preço), classificando do menor para o maior TOTAL. Considere apenas valores (estoque e preço) positivos.
SELECT PRO_NOME AS NOME,
PRO_EST_ATUAL_LOJA AS ESTOQUE,
PRO_PRECO_VAREJO AS PRECO,
(PRO_EST_ATUAL_LOJA*PRO_PRECO_VAREJO)
AS TOTAL
FROM PRODUTOS
WHERE PRO_EST_ATUAL_LOJA > 0
AND PRO_PRECO_VAREJO > 0
ORDER BY TOTAL;

-- Faça uma listagem de quanto seria arrecadado, por seção, caso fossem vendidos todos os produtos do estoque. Classifique por SEÇÃO.
SELECT PRO_SECAO AS SEÇÃO, SUM(PRO_EST_ATUAL_LOJA*PRO_PRECO_VAREJO) AS TOTAL
FROM PRODUTOS
GROUP BY PRO_SECAO
ORDER BY 1;

-- ### MANIPULAÇÃO DE DATA E HORA
-- Liste os inscritos aniversariantes do mês de NOVEMBRO nessa ordem: ANO, MÊS e DIA (do nascimento), NOME. Utilize a cláusula ‘AS’ para  renomear campos que devem ser exibidos em CAIXA ALTA. Classifique na ordem do mais novo para o mais velho inscrito. Dica: você pode usar a função YEAR, MONTH e DAY para extrair parte (dia, mês, ano) do campo DATA_NASC, que é do tipo DATE.
SELECT YEAR (DATA_NASC) AS ANO,
MONTH (DATA_NASC) AS MES,
DAY (DATA_NASC) AS DIA,
UPPER(NOME) AS NOME
FROM INSCRITOS
WHERE MONTH (DATA_NASC) = 10
ORDER BY 1;
