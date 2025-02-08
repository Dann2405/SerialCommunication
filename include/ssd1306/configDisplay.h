#ifndef CONFIGDISPLAY_H
#define CONFIGDISPLAY_H

bool cor = true;

void config_display()
{
    // Configuração do display SSD1306
    ssd1306_t ssd;                                                // Inicializa a estrutura do display
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd);                                         // Configura o display
    ssd1306_send_data(&ssd);                                      // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);
}

void imagem_inicial()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, "  Comunicacao", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "   Serial", 20, 30); // Desenha uma string
    ssd1306_draw_string(&ssd, "Autor Daniel", 15, 48); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void led_verde_ON_display()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Botao A Press", 15, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Led Verde ON", 20, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void led_verde_OFF_display()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Botao A Press", 15, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Led Verde OFF", 20, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void led_azul_ON_display()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Botao B Press", 15, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Led Azul ON", 25, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void led_azul_OFF_display()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Botao B Press", 15, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Led Azul OFF", 25, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_zero()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "ZERO", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numeros_um()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "UM", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_dois()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "DOIS", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_tres()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "TRES", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_quatro()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "QUATRO", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_cinco()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "CINCO", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_seis()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "SEIS", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_sete()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "SETE", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_oito()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "OITO", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void numero_nove()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Numero exibido", 10, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "NOVE", 50, 35); // Desenha uma string      
    ssd1306_send_data(&ssd); // Atualiza o display
}

void comando_invalido()
{
    ssd1306_t ssd; // Declare the ssd variable
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Initialize the display

    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, " ", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Comando", 35, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "invalido", 35, 25); // Desenha uma string      
    ssd1306_draw_string(&ssd, "Tente novamente", 6, 45); // Desenha uma string   
    ssd1306_send_data(&ssd); // Atualiza o display
}

#endif