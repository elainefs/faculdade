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

Um banco de dados, em essência, é um sistema computadorizado de armazenamento de registros. Nele estarão presentes dados inter-relacionados, representando informações sobre um assunto específico.

O banco de dados armazena os registros em tabelas, essas são constituídas de **linhas** e **colunas**, onde em cada linha haverá um **registro** e as colunas indicarão os **campos** das tabelas.

As **tabelas** também podem ser chamadas de **entidades**, as **colunas** podem ser chamadas de **campos ou atributos** e as **linhas** podem ser chamadas de **registro ou tupla**.

Tabela = Entidade

Coluna = Campos ou Atributos

Linha = Registro ou Tupla

Um banco de dados pode ter uma ou centenas de tabelas, ficando limitado pela ferramenta de software utilizada ou por recursos de hardware.

As tabelas associam-se entre si através de regras de relacionamentos, que consistem em associar um ou vários atributos de uma tabela com um ou vários atributos de outra tabela.

> **Dado**: qualquer elemento do mundo real em sua forma bruta e que não conduz a uma compreensão de determinado fato.
>
> **Informação**: fato útil extraído da organização e processamento de um dado e que permite interpretações e fundamentação de decisões.

## Vantagens do banco de dados

- Redução ou eliminação de redundâncias
- Eliminação de inconsistências
- Compartilhamento dos dados
- Restrições de segurança
- Independência dos dados
- Manutenção da integridade

## Sistema de Gerenciamento de Banco de Dados (SGBD)

É um software que possui recursos capazes de manipular as informações do banco de dados e interagir com o usuário.

Um sistema de banco de dados possui quatro componentes: dados, hardware, software e usuários.

A abstração dos dados se da através do sistema que isola o usuário dos detalhes internos do banco de dados e promover a independência dos dados em relação às aplicações.

Para um sistema ser considerado um SGBD ele precisa ter as seguintes características:

- Auto-contenção
- Independência dos dados
- Abstração dos dados
- Visões
- Transações
- Acesso automático

Funções de um SGBD:

- Definição dos dados
- Manipulação dos dados
- Otimização e Execução
- Segurança e integridade dos dados
- Recuperação dos dados e concorrência
- Dicionário de dados

Classificação de um SGBD:

- Número de usuários
  - Monousuário ou Multiusuário
- Localização
  - Centralizado ou Distribuído
- Modelo de dados
  - De rede
  - Hierárquico
  - Relacionais
  - Orientados a objetos
  - Objetos-relacionais

Gerações de banco de dados:

- 1ª geração: modelos hierárquicos e em rede
- 2ª geração: surgimento do modelo relacional
- 3ª geração: surgimento do modelo orientado a objetos

O SGBD Objeto-Relacional combina os benefícios do modelo relacional com a capacidade de modelagem do modelo Orientado a Objetos.

O SGBD Objeto-Relacional usa a linguagem de consulta OR, que é uma extensão da linguagem SQL.

Edgar Frank Codd criou treze regras, enumeradas de 0 a 12, que um SGBD relacional precisa seguir.

[12 Regras de Codd](https://pt.wikipedia.org/wiki/12_regras_de_Codd).

## Primary Key

É um campo da tabela que possui valor único e não pode ser nulo.

A chave primária pode ser simples ou composta.

Simples: ex: matrícula

Composta: ex: agência e conta

## Foreign Key

É um campo da tabela que se refere a chave primária de outra tabela.

## Integridade referencial

A integridade referencial é um conceito que garante que todos os relacionamentos entre tabelas serão respeitados. Inclusive, impede a exclusão de um campo se ele estiver relacionado ao campo de outra tabela de forma dependente.

Por exemplo, se um campo na tabela A for chave primária e estiver relacionado a outra tabela, sendo nessa chave estrangeira, não será possível excluir esse dado na tabela A, uma vez que a segunda tabela depende dele.

- Os campos relacionados devem ter o mesmo tipo de dado
- Ambas as tabelas pertencem à mesma base de dados

## Consistência de Dados

Refere-se a fato de que sempre que um dado vier de locais diferentes eles precisam ter o mesmo valor.

## Cardinalidade

É uma forma de restrição de integridade que quantifica a quantidade mínima e máxima de relacionamentos entre entidades.

```mermaid
flowchart LR

A(Funcionário) --(1,1)--- B{Possui} --(0,N)--- C(Dependente)
```

Lê-se: Um funcionário pode ter no mínimo zero (0) ou no máximo muitos (N) dependentes, e um dependente pode ter no mínimo um (1) e no máximo um (1) funcionário associado.

Tipos de relacionamentos:

- um-para-um (1:1)
  - Uma ocorrência da entidade A está associada a no máximo uma ocorrência da entidade B, e uma ocorrência de B está associada a no máximo uma ocorrência de A.
- um-para-muitos (1:n)
  - Uma ocorrência da entidade A está associada a várias ocorrências da entidade B, porém uma ocorrência de B deve estar associada a no máximo uma ocorrência em A.
- muitos-para-muitos (n:n)
  - Uma ocorrência na entidade A está associada a qualquer número de ocorrências da entidade B, e uma ocorrência em B está associada a qualquer número de ocorrência na entidade A.
  - Todo relacionamento n:n deve ser desmembrado em dois relacionamento 1:n, pois banco de dados relacional não permite esse tipo de cardinalidade. Para isso deve ser criado uma Entidade em comum.

## Normalização

A normalização dos dados é uma série de dados que permite armazenar os dados de forma consistente e eficiente, de forma a reduzir a redundância e a inconsistência.

Edgar Frank Codd definiu três das regras usadas para normalização de dados:

- Primeira Forma Normal (1FN)
  - Os atributos precisam ser atômicos,simples e indivisíveis.
  - Passos:
    - 1ª dividir as tabelas
    - 2ª identificar as chaves
- Segunda Forma Normal (2FN)
- Terceira Forma Normal (3FN)