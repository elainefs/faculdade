-- Active: 1729722794341@@127.0.0.1@1433@CORRENTISTAS@dbo
-- Liste o Nome da Agência, Estado, Cidade e Nome de todos os
-- correntistas cujo nome tenha a string ‘SILVA’ em qualquer parte do nome. Utilize a
-- cláusula AS para renomear campos. Classifique a listagem em 4 níveis (Agencia,
-- Estado, Cidade, e Nome), Elimine informações nulas da listagem;
SELECT A.NOME AS AGENCIA, C.UF AS UF, C.CIDADE AS CIDADE, C.NOME AS CORRENTISTAS
FROM AGENCIA A
INNER JOIN CORR C
ON A.NUM_AGENCIA=C.AGENCIA
WHERE C.NOME LIKE '%SILVA%'
AND UF IS NOT NULL
AND CIDADE IS NOT NULL
AND UF<>''
AND CIDADE<>''
ORDER BY 1,2,3,4;

-- Liste os correntistas nessa ordem: Mês, Dia (do nascimento),
-- Nasc, Nome e Sexo. Utilize a cláusula AS para renomear campos. Liste somente as
-- mulheres nascidas após 2000. Classifique na seguinte ordem: Mês, Dia, Nome. Dica:
-- você pode usar a função SUBSTRING para extrair parte do NASC, que é do tipo VARCHAR.
SELECT SUBSTRING(NASC,4,2) AS MES, SUBSTRING(NASC,1,2) AS DIA, NASC AS NASC, NOME AS NOME, SEXO AS SEXO
FROM CORR
WHERE SEXO='F' AND SUBSTRING(NASC,7,4)>2000
ORDER BY 1,2,4;

-- Liste todos os correntistas cujo Estado Civil (ESTCIV) NÃO esteja
-- na lista que segue: ‘U’, ‘C’,’O’, ‘V’ e ‘S’.
SELECT ESTCIV,*
FROM CORR
WHERE ESTCIV NOT IN ('U','C','O','V','S');

-- Altere todos os correntistas cujo SEXO e ESTCIV estiver com
-- brancos ou nulos ou sem informação para ‘O’ e ‘P’, respectivamente.
UPDATE CORR
SET SEXO='O'
WHERE SEXO='' or SEXO is null;
---------------------
UPDATE CORR
SET ESTCIV='P'
WHERE ESTCIV='' or ESTCIV is null;

-- Liste todas as informações de todos os correntistas do SEXO masculino, cujo NOME inicie por ‘M’, ‘N’,’O’, ‘P’,’Q’ e ‘R’. Classifique em ordem alfabética por NOME.
SELECT SEXO,*
FROM CORR
WHERE SEXO='M' AND
NOME like '[M-R]%'
ORDER BY 3;

-- Criação da tabela Inscrições
CREATE TABLE Inscricoes (
    Inscr INT IDENTITY (101,1),
    Aluno CHAR(7) NOT NULL,
    Disc CHAR(7) NOT NULL,
    AnoLet CHAR(4),
    PRIMARY KEY (Inscr),
    FOREIGN KEY (Aluno)REFERENCES ALUNOS(Codigo),
    FOREIGN KEY (Disc) REFERENCES DISCIPLINAS(Codigo)
);

