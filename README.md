# SerialCommunication

## Descrição do Projeto

O **Serial Communication** é um projeto demonstrativo que explora o uso de interfaces seriais no RP2040, com foco nas comunicações **UART** e **I2C**. Desenvolvido para rodar tanto no **Wokwi Simulator** (integrado ao VS Code) quanto em hardware real, o sistema utiliza a placa de desenvolvimento **BitDogLab** como referência.

### Principais Aspectos

- **Uso de Interrupções (IRQ):**  
  - Gerencia as funções dos botões por meio de rotinas de interrupção.
- **Debouncing via Software:**  
  - Implementação para corrigir o bouncing dos botões.
- **Controle de LEDs:**  
  - Demonstra o controle de LEDs comuns e de LEDs WS2812, evidenciando técnicas de acionamento distintas.
- **Display 128x64 SSD1306:**  
  - Exibe informações com fontes maiúsculas e minúsculas utilizando a comunicação I2C.
- **Envio de Dados via UART:**  
  - Permite a transmissão e recepção de informações, demonstrando a comunicação serial.

---

## Funcionalidades Principais

### 1. Entrada de Caracteres via PC
- **Uso do Serial Monitor:**  
  - Digite caracteres no Serial Monitor do VS Code.
- **Exibição no Display:**  
  - Cada caractere enviado ativa uma função do projeto e é exibido no display SSD1306.
- **Comandos Numéricos:**  
  - Ao digitar um número (0 a 9), o símbolo correspondente é mostrado na matriz 5x5 de LEDs WS2812.

### 2. Interação com Botões
- **Botão A:**  
  - Alterna o estado do LED RGB **Verde**.
  - A operação é registrada por:
    - Exibição de mensagem informativa no display SSD1306.
    - Envio de texto ao Serial Monitor.
- **Botão B:**  
  - Alterna o estado do LED RGB **Azul**.
  - A operação é registrada tanto no display SSD1306 quanto no Serial Monitor.

### 3. Comandos via UART
- **'0' a '9':**  
  - Exibe o número correspondente na matriz 5x5 e mostra uma mensagem informativa no display.
- **'r':**  
  - Alterna o estado do LED RGB **Vermelho** e mostra uma mensagem informativa no display.
- **'g':**  
  - Alterna o estado do LED RGB **Verde** e mostra uma mensagem informativa no display.
- **'b':**  
  - Alterna o estado do LED RGB **Azul** e mostra uma mensagem informativa no display.
- **'d':**  
  - Exibe a mensagem inicial no display SSD1306.

---

## Requisitos para Rodar o Projeto

- **Microcontrolador:** Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)  
- **Placa de Desenvolvimento:** BitDogLab (opcional)  
- **Simulador:** Conta no [Wokwi Simulator](https://wokwi.com/)
- **Editor de Código:** Visual Studio Code (VS Code)  
- **SDK do Raspberry Pi Pico:** Deve estar configurado e integrado ao VS Code

---

## Instruções de Uso

### 1. Clonando o Repositório

Abra o terminal e execute:

```bash
git clone https://github.com/Dann2405/SerialCommunication.git
cd SerialCommunication
```

### 2. Instalando as Dependências

Verifique se o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. Recomenda-se instalar as seguintes extensões:
- **C/C++** (Microsoft)
- **CMake Tools**
- **Wokwi Simulator** (opcional, para simulação integrada)
- **[Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)**

### 3. Configurando o VS Code

1. Abra o projeto no VS Code.
2. Confirme que todas as extensões recomendadas estão instaladas.
3. Utilize a interface da extensão do Raspberry Pi Pico para compilar o projeto (clique em **"Compile Project"**).  
   - Esse procedimento gera o arquivo `.uf2` para uso tanto no simulador quanto em hardware real.

### 4. Executando no Wokwi Simulator

1. Abra o arquivo `diagram.json` no VS Code.
2. Clique no botão **"Play"** para iniciar a simulação.
3. Interaja com os botões ou envie comandos via Serial Monitor:
   - Verifique a atualização dos caracteres no display SSD1306.
   - Observe os efeitos na matriz 5x5 de LEDs WS2812 e nos LEDs RGB.

### 5. Testando no Hardware Real

#### 5.1 Utilizando a Placa BitDogLab com Raspberry Pi Pico W

**Modo de Programação:**
- Conecte a placa ao computador.
- Para entrar no modo de programação (BOOTSEL), siga os passos:
  1. Pressione e segure o botão **BOOTSEL** (na parte traseira da placa).
  2. Enquanto mantém pressionado, pressione o botão **RESET** (na parte frontal).
  3. Após alguns segundos, solte primeiro o botão **RESET** e, em seguida, o **BOOTSEL**.
  4. A placa entrará no modo de programação, pronta para receber o firmware.

**Compilação e Upload:**
1. No VS Code, com a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico) instalada, clique em **"Compile Project"**.
2. Selecione **"Run Project USB"** para fazer o upload do firmware e executar o projeto.

#### 5.2 Conexões Alternativas

Se você não estiver usando a BitDogLab, é possível montar o circuito em uma protoboard ou com outro microcontrolador (como o Arduino). Utilize a seguinte pinagem:

| **Periférico**      | **Pino GPIO**                     |
|---------------------|-----------------------------------|
| Botão A             | GP5                               |
| Botão B             | GP6                               |
| LED R               | GP13                              |
| LED G               | GP11                              |
| LED B               | GP12                              |
| Matriz 5x5 WS2812   | GP7                               |
| Display SSD1306     | SCL: GPIO 15 & SDA: GPIO 14       |

Após configurar as conexões, os componentes estarão prontos para a operação do sistema.

---

## Considerações Finais

Este projeto foi desenvolvido para demonstrar técnicas avançadas de comunicação serial e controle de periféricos utilizando o RP2040.
