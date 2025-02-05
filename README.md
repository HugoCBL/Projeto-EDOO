# Projeto-EDOO
Sistema de Gerenciamento de Times de Futebol

Instruções de Uso do Código


O código implementa um sistema de gerenciamento de times de futebol, onde você pode realizar operações como contratar jogadores, trocar jogadores entre times, renovar contratos e visualizar informações sobre os times. 


1. Menu de Opções
Ao executar o programa, você verá um menu com as seguintes opções:

Escolha uma opcao:
1. Contratar Jogador
2. Troca de Jogadores
3. Renovar Contrato
4. Receber Informacao do Time
5. Sair

Digite o número correspondente à operação que deseja realizar e pressione Enter.


2. Operações Disponíveis

Opção 1: Contratar Jogador
Permite que um time contrate um jogador de outro time.

1. O programa solicitará o nome do time que vai vender o jogador.
   - Exemplo: Digite “Flamengo”.
2. Em seguida, digite o nome do jogador que será transferido.
   - Exemplo: Digite “Pedro”.
3. Depois, informe o nome do time que vai contratar o jogador.
   - Exemplo: Digite “Corinthians”.
4. Por fim, insira a nova data de contrato no formato `dd/mm/aaaa`.
   - Exemplo: Digite “31/12/2026”.

O jogador será transferido do time vendedor para o time comprador, e o contrato será atualizado com a nova data.


Opção 2: Troca de Jogadores
Permite a troca de jogadores entre dois times.

1. O programa solicitará o nome do primeiro time.
   - Exemplo: Digite “AtleticoMG”.
2. Em seguida, digite o nome do jogador do primeiro time que será trocado.
   - Exemplo: Digite “Hulk”.
3. Depois, informe o nome do segundo time.
   - Exemplo: Digite “Cruzeiro”.
4. Em seguida, digite o nome do jogador do segundo time que será trocado.
   - Exemplo: Digite “Gabriel Barbosa”.
5. Por fim, insira as novas datas de contrato para ambos os jogadores no formato “dd/mm/aaaa”.
   - Exemplo: Para o primeiro jogador, digite “31/12/2027”.
   - Exemplo: Para o segundo jogador, digite “31/12/2028”.

Os jogadores serão trocados entre os times, e os contratos serão atualizados.


Opção 3: Renovar Contrato
Permite renovar o contrato de um jogador.

1. O programa solicitará o nome do time.
   - Exemplo: Digite “Flamengo”.
2. Em seguida, digite o nome do jogador que terá o contrato renovado.
   - Exemplo: Digite “Pedro”.
3. Por fim, insira a nova data de contrato no formato “dd/mm/aaaa”.
   - Exemplo: Digite “31/12/2027”.

O contrato do jogador será atualizado com a nova data.


Opção 4: Receber Informação do Time
Permite visualizar todas as informações de um time, incluindo jogadores e seus contratos.

1. O programa solicitará o nome do time.
   - Exemplo: Digite “Corinthians”.
2. O sistema exibirá as informações do time, como:
   - Nome do time.
   - Nome do estádio.
   - Capacidade do estádio.
   - Nome do técnico.
   - Lista de jogadores com seus valores de mercado e datas de término de contrato.
   - Valor total do time (soma dos valores de mercado dos jogadores).


Opção 5: Sair
Encerra o programa.


3. Exemplos de Uso

Exemplo 1: Contratar Jogador
- Time vendedor: “Flamengo”
- Jogador: “Pedro”
- Time comprador: “Corinthians”
- Nova data de contrato: “31/12/2026”

Exemplo 2: Troca de Jogadores
- Primeiro time: “AtleticoMG”
- Jogador do primeiro time: “Hulk”
- Segundo time: “Cruzeiro”
- Jogador do segundo time: “Gabriel Barbosa”
- Nova data de contrato para o primeiro jogador: “31/12/2027”
- Nova data de contrato para o segundo jogador: “31/12/2028”

Exemplo 3: Renovar Contrato
- Time: “Flamengo”
- Jogador: “Pedro”
- Nova data de contrato: “31/12/2027”

Exemplo 4: Receber Informação do Time
- Time: “Corinthians”


4. Observações
- Certifique-se de digitar os nomes dos times e jogadores exatamente como estão definidos no código (case-sensitive).
- Ao renovar um contrato, a nova data deve ter um ano maior que o ano atual do contrato.
- O programa não salva os dados após o encerramento. Todas as alterações são perdidas quando o programa é fechado.

5. Dicas
- Use nomes de times e jogadores corretamente, conforme definidos no código.
- Para facilitar, consulte a lista de times e jogadores diretamente no código antes de realizar operações.
