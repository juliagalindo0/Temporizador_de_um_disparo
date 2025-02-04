# ⏳ Temporizador de Um Disparo (One Shot) 
Este projeto implementa um sistema de temporização baseado em evento único usando a função add_alarm_in_ms() do Pico SDK. O acionamento dos LEDs ocorre após o clique em um botão (pushbutton), seguindo um comportamento programado.

A atividade será desenvolvida no ambiente VS Code, utilizando a linguagem C e o simulador Wokwi para testes. Além disso, será realizado um experimento com o LED RGB e um botão adicional usando a ferramenta BitDogLab.

## 📌 Objetivo

Utilizar a função add_alarm_in_ms() para criar um temporizador de evento único (One Shot).

Implementar um sistema de acionamento de LEDs controlado por um botão pushbutton.

Garantir que o botão só possa ser pressionado novamente após a finalização da sequência de LEDs.

Realizar testes no Wokwi e no BitDogLab.

## 🛠 Requisitos

Para executar este projeto, é necessário ter os seguintes componentes:

🎛 Hardware

Raspberry Pi Pico W

3 LEDs (azul, vermelho e verde)

3 resistores de 330 Ω

Botão pushbutton

Protoboard e fios de conexão

🖥 Software

VS Code configurado para desenvolvimento com Pico SDK

CMake e GNU Make instalados para compilação

Simulador Wokwi para testes virtuais

Ferramenta BitDogLab para experimentação com LED RGB e Botão A 

## 🔧 Funcionamento

O sistema permanece em espera até que o botão pushbutton seja pressionado.

Quando pressionado:
  
    Todos os LEDs são acesos simultaneamente.
    Após 3 segundos, um LED é apagado.
    Após mais 3 segundos, outro LED é apagado.
    Por fim, após mais 3 segundos, o último LED é apagado.

Durante a execução da sequência, o botão não pode ser pressionado novamente.

Apenas quando todos os LEDs forem apagados, o botão pode iniciar um novo ciclo.

Um experimento adicional será realizado com um LED RGB utilizando os GPIOs 11, 12 e 13, além do Botão A (GPIO 05) no BitDogLab.
