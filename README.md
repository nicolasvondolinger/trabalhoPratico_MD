# Trabalho Pratico - Matemática Discreta

# Instruções e Ambiente Computacional Ideal

Este arquivo fornece informações sobre o ambiente computacional necessário para executar o trabalho prático do projeto da faculdade, bem como instruções para a instalação do GCC (GNU Compiler Collection) e outras dependências.

## Diretórios e Conteúdo Geral

Existem três diretórios para cada fractal desenvolvido (Espaço de Peano, Ilha de Koch e fractal autoral), com o objetivo de separar o resultado de cada um deles.

Em cada um desses 3 diretórios, existe um arquivo em C para gerar a sequência de caracteres relativas a cada fractal, e um arquivo em Python para a contagem desses caracteres.

E por último, existe uma pasta com as imagens do fractal autoral para exemplificação e comprovação da recursão.

## Ambiente Computacional

O trabalho prático foi desenvolvido no sistema operacional Ubuntu, versão 23.04. Recomenda-se utilizar essa versão do Ubuntu para garantir a compatibilidade adequada.

### 1 - Instalação do GCC (GNU Compiler Collection)

O GCC é um conjunto de compiladores de código aberto amplamente utilizado para compilar programas em C e C++. Siga as instruções abaixo para instalar o GCC:

1. Abra o terminal no Ubuntu.
2. Execute o seguinte comando para atualizar os repositórios do sistema:
    $ sudo apt update
3. Após a atualização dos repositórios, execute o comando abaixo para instalar o GCC:
    $ sudo apt install gcc
4. Aguarde até que a instalação seja concluída. Verifique se não há erros durante o processo.
5. Para verificar se o GCC foi instalado corretamente, execute o seguinte comando para exibir a versão instalada:
    $ gcc --version
Certifique-se de que a versão exibida corresponda à versão 23.04 do Ubuntu.

### 2 - Software Utilizado

Para desenhar os respectivos fractais, foi utilizado um software externo no site: [https://onlinemathtools.com/l-system-generator]. Todas as instruções para a utilização dele estão no próprio site.

Certifique-se de seguir todas as instruções mencionadas acima para configurar corretamente o ambiente de desenvolvimento e garantir que o código seja executado sem problemas no Ubuntu 23.04.

## Navegação entre Diretórios

O projeto consiste em uma pasta principal que contém quatro subpastas, cada uma contendo dois arquivos de código. Para navegar entre os diretórios e executar as ações necessárias, siga as instruções abaixo:

1. Abra o terminal no Ubuntu.
2. Para entrar em um diretório específico, utilize o comando `cd` seguido do caminho completo até o diretório desejado. Por exemplo, para entrar na pasta "Subpasta1", execute o seguinte comando:

    $ cd /caminho/completo/para/pasta_principal/Subpasta1

3. Para voltar ao diretório principal a partir de qualquer subpasta, utilize o comando `cd` sem nenhum argumento:

    $ cd

4. Para voltar apenas para o diretório anterior ao atual:

    $ cd ..

5. Para limpar o terminal:

    $ clear

6. Para sair e fechar o terminal:

    $ exit

## Compilação e Execução do Código

Para compilar e executar os códigos na linguagem C em cada subpasta, siga as instruções abaixo:

1. Após navegar para a pasta contendo os arquivos de código que você deseja compilar, utilize o seguinte comando para compilar o arquivo de código em C:

    $ gcc nome_do_arquivo.c -o nome_do_executavel -lm

    Substitua "nome_do_arquivo.c" pelo nome do arquivo de código que você deseja compilar e "nome_do_executavel" pelo nome desejado para o executável.

2. Após a compilação bem-sucedida, execute o seguinte comando para executar o programa:

    $ ./nome_do_executavel

Substitua "nome_do_executavel" pelo nome do executável que você definiu na etapa anterior.
3. Durante a execução do código para gerar a sequência de caracteres, siga as instruções exibidas no terminal para fornecer as entradas necessárias, como número do fractal, axioma, ângulo em graus e número de regras, bem como as regras específicas para cada fractal.

A seguir, seguem todas as entradas para as regras relativas aos fractais desenvolvidos nesse trabalho:

### Espaço de Peano

- Axioma: X
- Nº de Regras: 2
- Regra 1: X XFYFX+F+YFXFY-F-XFYFX
- Regra 2: Y YFXFY-F-XFYFX+F+YFXFY

### Ilha de Koch

- Axioma: F+F+F+F
- Nº de Regras: 1
- Regra: F F+F-F-FFF+F+F-F

### Fractal Personalizado

- Axioma: F
- Nº de Regras: 2
- Regra 1: X XFFX+F+YFFY-F-XFFX
- Regra 2: Y YFFY-F-XFFX+F+YFFY

Observações:
- As regras já estão prontas para serem copiadas e coladas no terminal durante a execução.
- Cada código gera por padrão 4 iterações das regras dadas.

## Entradas do Usuário

Durante a execução dos programas, podem ser necessárias algumas entradas do usuário no terminal. Essas entradas podem variar de acordo com a lógica implementada no código de cada subpasta.

Certifique-se de fornecer as entradas solicitadas pelo programa corretamente para obter os resultados desejados.

Adicionalmente, é recomendável que você leia os comentários no código-fonte de cada arquivo para obter mais informações sobre a lógica e as entradas esperadas pelo programa.

Certifique-se de seguir todas as instruções mencionadas acima para navegar pelos diretórios corretamente, compilar e executar o código do projeto com sucesso.

Se você tiver alguma dúvida ou encontrar algum problema durante o processo de navegação ou execução do código, não hesite em procurar ajuda ou consultar recursos adicionais, como documentação de linguagem de programação, fóruns ou tutoriais online.

## Saídas do Programa

As saídas do código são armazenadas em um arquivo de texto com o formato "Iteração X", onde X representa o número da iteração. Cada iteração contém uma linha com uma string correspondente.

Exemplo de estrutura do arquivo de saída:

    Iteração 1
    F

    Iteração 2
    FF

    Iteração 3 
    FFF

É importante ressaltar que as strings podem variar em conteúdo e comprimento, dependendo do processamento realizado em cada iteração do código.
