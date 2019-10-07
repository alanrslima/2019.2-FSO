Os processos filhos e netos de 1001 devem ser lançados antes ou depois de 1001 ler a string S?
- Os processos filhos e netos devem ser lançados após 1001 ler a string.

Como o processo 1001 faz para imprimir o tamanho da string S?
- De acordo com a árvore dada no exercício, o processo 1001 é vô do processo 1005 e pai do processo 103. Portanto, O processo folha (1005) irá calcular o tamanho da string e retornar este valor para seu processo pai (1003) que está aguardando o fim do processo 1005. O mesmo acontece com o processo 1001 que está aguardando o retorno do processo 1003. Desta forma o processo 1001 consegue imprimir o tamanho da string S. 
