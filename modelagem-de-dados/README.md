# Modelagem de dados

A modelagem de dados é a primeira etapa de um projeto que envolva banco de dados e tem como seu principal objetivo o desenvolvimento de um modelo que represente as especificações das informações do negócio e de como o software funcionará.

Os modelos de dados demonstram como serão construídas as estruturas de dados, como os dados estarão organizados e quais os relacionamentos que pretendemos estabelecer entre eles.

> Modelagem refere-se à descrição formal da estrutura de um banco de dados, projetando-o para que se possa aproveitar os recursos de um SGDB e que a base de dados seja consistente, permita o reaproveitamento de recursos, exija menos espaços em disco e que seja bem administrado.

Possui três perspectivas:

- Modelagem Conceitual
  - Usada como representação de alto nível e considera exclusivamente o ponto de vista do criador do dado
- Modelagem Lógica
  - Agrega alguns detalhes de implementação
- Modelagem Física
  - Demonstra como os dados são fisicamente

## Banco de dados

Um banco de dados, em essência, é apenas um sistema computadorizado de armazenamento de registros.

O banco de dados armazena os registros em tabelas, essas são constituídas de **linhas** e **colunas**, onde em cada linha haverá um **registro** e as colunas indicarão os **campos** das tabelas.

As **tabelas** também podem ser chamadas de **entidades**, as **colunas** podem ser chamadas de **campos ou atributos** e as **linhas** podem ser chamadas de **registro ou tupla**.

Um banco de dados pode ter uma ou centenas de tabelas, ficando limitado pela ferramenta de software utilizada ou por recursos de hardware.

As tabelas associam-se entre si através de regras de relacionamentos, que consistem em associar um ou vários atributos de uma tabela com um ou vários atributos de outra tabela.

> **Dado**: qualquer elemento do mundo real em sua forma bruta e que não conduz a uma compreensão de determinado fato.
>
> **Informação**: fato útil extraído da organização e processamento de um dado e que permite interpretações e fundamentação de decisões.