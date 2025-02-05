# Projeto-EDOO

# Sistema de Gerenciamento de Times de Futebol ⚽📘

Este documento apresenta as instruções para utilizar o sistema de gerenciamento de times de futebol. A seguir, você encontrará detalhes sobre como realizar operações como contratação de jogadores, troca de jogadores entre times, renovação de contratos e visualização de informações sobre os times.

## 🚀 Instruções de Uso

### Menu de Opções

Ao acessar o sistema, você será apresentado a um menu interativo com as seguintes opções:  

1. **Contratar Jogador**  
2. **Troca de Jogadores**  
3. **Renovar Contrato**  
4. **Receber Informação do Time**  
5. **Sair**  

Digite o número correspondente à operação desejada e pressione **Enter** para prosseguir.

## ⚙️ Operações Disponíveis

### 1️⃣ Contratar Jogador  
Permite a transferência de um jogador de um time para outro.  

**Como utilizar:**  
1. Informe o nome do time vendedor.  
   *Exemplo*: `Flamengo`  
2. Informe o nome do jogador a ser transferido.  
   *Exemplo*: `Pedro`  
3. Insira o nome do time comprador.  
   *Exemplo*: `Corinthians`  
4. Insira a nova data de contrato no formato **dd/mm/aaaa**.  
   *Exemplo*: `31/12/2026`  

**Resultado:** O jogador será transferido para o time comprador, e o contrato será atualizado com a nova data.

---

### 2️⃣ Troca de Jogadores  
Permite a troca de jogadores entre dois times.  

**Como utilizar:**  
1. Informe o nome do primeiro time.  
   *Exemplo*: `AtleticoMG`  
2. Insira o nome do jogador do primeiro time.  
   *Exemplo*: `Hulk`  
3. Informe o nome do segundo time.  
   *Exemplo*: `Cruzeiro`  
4. Insira o nome do jogador do segundo time.  
   *Exemplo*: `Gabriel Barbosa`  
5. Insira as novas datas de contrato para ambos os jogadores no formato **dd/mm/aaaa**.  
   *Exemplo para o primeiro jogador*: `31/12/2027`  
   *Exemplo para o segundo jogador*: `31/12/2028`  

**Resultado:** Os jogadores serão trocados entre os times, e os contratos serão atualizados.

---

### 3️⃣ Renovar Contrato  
Permite atualizar a data de contrato de um jogador.  

**Como utilizar:**  
1. Informe o nome do time.  
   *Exemplo*: `Flamengo`  
2. Insira o nome do jogador.  
   *Exemplo*: `Pedro`  
3. Informe a nova data de contrato no formato **dd/mm/aaaa**.  
   *Exemplo*: `31/12/2027`  

**Resultado:** O contrato do jogador será atualizado com a nova data.

---

### 4️⃣ Receber Informação do Time  
Permite visualizar detalhes sobre um time e seus jogadores.  

**Como utilizar:**  
1. Insira o nome do time.  
   *Exemplo*: `Corinthians`  

**Resultado:** O sistema exibirá informações como:  
- Nome do time  
- Estádio e sua capacidade  
- Técnico do time  
- Lista de jogadores com seus valores de mercado e contratos  
- Valor total do time (soma dos valores de mercado dos jogadores)

---

## 📝 Exemplos de Uso

- **Contratar Jogador**  
  - Time vendedor: `Flamengo`  
  - Jogador: `Pedro`  
  - Time comprador: `Corinthians`  
  - Nova data de contrato: `31/12/2026`

- **Troca de Jogadores**  
  - Primeiro time: `AtleticoMG`  
  - Jogador do primeiro time: `Hulk`  
  - Segundo time: `Cruzeiro`  
  - Jogador do segundo time: `Gabriel Barbosa`  
  - Nova data de contrato para o primeiro jogador: `31/12/2027`  
  - Nova data de contrato para o segundo jogador: `31/12/2028`

- **Renovar Contrato**  
  - Time: `Flamengo`  
  - Jogador: `Pedro`  
  - Nova data de contrato: `31/12/2027`

---

## 📌 Observações

- Certifique-se de digitar corretamente os nomes dos times e jogadores, respeitando letras maiúsculas e minúsculas (case-sensitive).  
- As alterações realizadas no sistema não são persistidas após o encerramento do programa.  

## 💡 Dicas

- Consulte a lista de times e jogadores diretamente no código para evitar erros de digitação.  
- Sempre insira datas de contrato válidas e coerentes com os anos atuais dos jogadores.  
