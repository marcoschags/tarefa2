# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializar o SDK do Pico
include(pico_sdk_import.cmake)

# Definir o tipo de placa como pico_w (Raspberry Pi Pico W)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Nome do projeto
project(Tarefa2 C CXX ASM)

# Inicializar o SDK do Pico
pico_sdk_init()

# Adicionar o arquivo fonte ao executável
add_executable(Tarefa2 Tarefa2.c)

# Nome e versão do programa
pico_set_program_name(Tarefa2 "Tarefa2")
pico_set_program_version(Tarefa2 "0.1")

# Configurar saída via UART ou USB
# Habilitar apenas uma opção entre UART (1) ou USB (1), ou desabilitar ambas (0).
pico_enable_stdio_uart(Tarefa2 1) # Ativar saída UART
pico_enable_stdio_usb(Tarefa2 0)  # Desativar saída USB

# Adicionar bibliotecas padrão necessárias
target_link_libraries(Tarefa2
    pico_stdlib            # Biblioteca padrão do Pico SDK
    hardware_pwm           # Controle de PWM
    hardware_timer         # Timer para tarefas
)

# Incluir o diretório atual para cabeçalhos
target_include_directories(Tarefa2 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gerar formatos adicionais de saída, como UF2
pico_add_extra_outputs(Tarefa2)
