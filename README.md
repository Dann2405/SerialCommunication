# SerialCommunication

## Descrição do Projeto

O **SerialCommunication** é um projeto demonstrativo que explora o uso de interfaces seriais no RP2040, com foco nas comunicações **UART** e **I2C**. Desenvolvido para rodar tanto no **Wokwi Simulator** (integrado ao VS Code) quanto em hardware real, onde foi utilizado a placa de desenvolvimento **BitDogLab** para a execução e testes do projeto.

---

## Principais Aspectos

- **Uso de Interrupções (IRQ):**  
  Gerencia as funções dos botões por meio de rotinas de interrupção.

- **Debouncing via Software:**  
  Implementa correção para o bouncing dos botões, garantindo leituras confiáveis.

- **Controle de LEDs:**  
  Demonstra técnicas de acionamento para LEDs comuns e para LEDs WS2812.

- **Display 128x64 SSD1306:**  
  Exibe informações (com fontes maiúsculas e minúsculas) utilizando comunicação I2C.

- **Envio de Dados via UART:**  
  Permite a transmissão e recepção de informações, ilustrando a comunicação serial.

---

## Funcionalidades Principais

### 1. Entrada de Caracteres via PC
- **Serial Monitor:**  
  Utilize o Serial Monitor do VS Code para digitar caracteres.

- **Exibição no Display:**  
  Cada caractere enviado ativa uma função e é exibido no display SSD1306.

- **Comandos Numéricos:**  
  Ao digitar um número (0 a 9), o símbolo correspondente é mostrado na matriz 5x5 de LEDs WS2812.

### 2. Interação com Botões
- **Botão A:**  
  - Alterna o estado do LED RGB **Verde**.
  - Registra a operação com:
    - Mensagem informativa exibida no display SSD1306.
    - Texto enviado ao Serial Monitor.

- **Botão B:**  
  - Alterna o estado do LED RGB **Azul**.
  - Registra a operação tanto no display quanto no Serial Monitor.

### 3. Comandos via UART
- **'0' a '9':**  
  Exibe o número correspondente na matriz 5x5 e mostra uma mensagem informativa no display.

- **'r':**  
  Alterna o estado do LED RGB **Vermelho** e exibe mensagem informativa.

- **'g':**  
  Alterna o estado do LED RGB **Verde** e exibe mensagem informativa.

- **'b':**  
  Alterna o estado do LED RGB **Azul** e exibe mensagem informativa.

- **'d':**  
  Exibe a mensagem inicial no display SSD1306.

---

## Requisitos para Rodar o Projeto

- **Microcontrolador:** Raspberry Pi Pico ou Raspberry Pi Pico W  
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

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. Recomenda-se a instalação das seguintes extensões:

- **C/C++** (Microsoft)
- **CMake Tools**
- **Wokwi Simulator** (opcional, para simulação integrada)
- **[Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)**

### 3. Configurando o VS Code

1. Abra o projeto no VS Code.
2. Verifique se todas as extensões recomendadas estão instaladas.
3. Utilize a interface da extensão do Raspberry Pi Pico para compilar o projeto (clique em **"Compile Project"**).  
   - Esse procedimento gera o arquivo `.uf2` para uso tanto no simulador quanto em hardware real.

### 4. Executando no Wokwi Simulator

1. Abra o arquivo `diagram.json` no VS Code.
2. Clique no botão **"Play"** para iniciar a simulação.
3. Interaja com os botões ou envie comandos via Serial Monitor:
   - Observe a atualização dos caracteres no display SSD1306.
   - Verifique os efeitos na matriz 5x5 de LEDs WS2812 e nos LEDs RGB.

### 5. Testando no Hardware Real

#### 5.1 Utilizando a Placa BitDogLab com Raspberry Pi Pico W

**Modo de Programação:**

- Conecte a placa ao computador.
- Para entrar no modo de programação (BOOTSEL), siga os passos:
  1. Pressione e segure o botão **BOOTSEL** (na parte traseira).
  2. Enquanto mantém pressionado, pressione o botão **RESET** (na parte frontal).
  3. Após alguns segundos, solte o **RESET** e, em seguida, o **BOOTSEL**.
  4. A placa entrará no modo de programação, pronta para receber o firmware.

**Compilação e Upload:**

1. No VS Code, com a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico) instalada, clique em **"Compile Project"**.
2. Selecione **"Run Project USB"** para fazer o upload do firmware e executar o projeto no raspbarry pi pico w.

#### 5.2 Conexões Alternativas

Caso você não utilize a BitDogLab, é possível montar o circuito em uma protoboard ou com outro microcontrolador (como o Arduino). Utilize a seguinte pinagem:

| **Periférico**      | **Pino GPIO**                     |
|---------------------|-----------------------------------|
| Botão A             | GP5                               |
| Botão B             | GP6                               |
| LED R               | GP13                              |
| LED G               | GP11                              |
| LED B               | GP12                              |
| Matriz 5x5 WS2812   | GP7                               |
| Display SSD1306     | SCL: GPIO 15 & SDA: GPIO 14       |

Após configurar as conexões, os componentes e as funcionalidades estarão prontos para serem utilizados.  

**Configuração do Serial Monitor:**

Utilize o Serial Monitor do VS Code ou o PUTTY com as seguintes configurações:

- **Monitor Mode:** Serial  
- **View Mode:** Text  
- **Porta:** Identifique a porta COM da sua Raspberry Pi Pico W (geralmente COM3 ou COM4)  
- **Baud Rate:** 115200  
- **Line Ending:** NONE  

Clique em **"Start Monitoring"** e envie os comandos conforme descrito na seção de comandos via UART.

---

## Considerações Finais

Este projeto foi desenvolvido para demonstrar técnicas avançadas de comunicação serial e controle de periféricos utilizando o RP2040.
