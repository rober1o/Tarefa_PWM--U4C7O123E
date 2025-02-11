# Atividade - Interrupções

Este projeto foi desenvolvido para aprimorar o conhecimento sobre PWM usando o **Raspberry Pi Pico W**. Foi realizado com o auxílio do simulador de eletrônica **Wokwi** e da placa **BitDogLab**.

## Componentes Utilizados

1. **LED AZUL** GPIO 12
2. **RESISTOR** 330 ohms
3. **Microcontrolador Raspberry Pi Pico W**
4. **SERVO MOTOR**

## Funcionalidade

Ao iniciar o programa, o servo motor movientará para o angulo de 180 graus, após cinco segundos, mudará para posição de 90 graus e passando mais cinco segundos mudará para a posição de 02 graus. Posteiormente, de forma suave, entrará em um ciclo infinito de movimentar de 0 graus a 180 e virse e versa.

### Teste do LED AZUL

caso queira testar o PWM do led azul, basta descomentar a linha com a rotina efeito_pisca_led(slice_led, canal_led); dentro do while(true);



### Como Usar

#### Usando o Simulador Wokwi

- Clone este repositório: git clone https://github.com/rober1o/Tarefa_PWM--U4C7O123E.git;
- Usando a extensão Raspberry Pi Pico importar o projeto;
- Compilar o código e clicar no arquivo diagram.json.

#### Usando a BitDogLab

- Clone este repositório: git clone https://github.com/rober1o/Tarefa_PWM--U4C7O123E.git;
- Usando a extensão Raspberry Pi Pico importar o projeto;
- Descomentar a linha com a rotina efeito_pisca_led(slice_led, canal_led); dentro do while(true);
- Compilar o projeto;
- Plugar a BitDogLab usando um cabo apropriado e gravar o código.

## Observação do experimento na BitDogLab

Após experimento realizado na BitDogLab, foi possível perceber que o LED varia de brilho conforme o duty cycle do PWM: quanto maior o duty cycle, mais intenso o brilho; quanto menor, mais fraco. A função efeito_pisca_led cria um efeito de pulsação, aumentando e diminuindo gradualmente a intensidade. 

## Demonstração

<!-- TODO: adicionar link do vídeo -->
Vídeo demonstrando as funcionalidades da solução implementada: [Demonstração](https://youtu.be/pDz5KutL2i4)
