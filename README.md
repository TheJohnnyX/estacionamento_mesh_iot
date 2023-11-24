# estacionamento_mesh_iot
Projeto de monitoramento de vagas de estacionamento utilizando rede mesh e técnicas de IoT

# Funcionamento
O presente trabalho utilizará de microcontroladores ESP's monitorando a disponibilidade das vagas com um sensor ultrassonico e comunicando as leituras entre si através de uma rede mesh.
Cada ESP será será um node, sendo este representado por um número específico. O projeto depende que o node principal, onde as informações devem chegar, seja o "1", representado por uma variável no código do arduino.

Essas informações serão então processadas por um algoritmo em python que irá monitorar as informações enviadas pela comunicação serial do ESP. Esta etapa é responsável por comunicar com o banco de dados MySQL, verificando se já existem registros para o node que enviou a informação. Caso não exista, irá criar um registro novo, caso já exista, irá atualizar o campo referente ao status.

Dessa forma, será utilizado o XAMPP para que seja disponibilizado de forma visual em uma página WEB as informações referentes a todas as vagas contidas no banco de dados. O XAMPP utiliza como servidor localhost o Apache e, na camada HTML/CSS/JAVASCRIPT utiliza PHP.

# Preparação de ambiente
## Arduino
Para rodar o código de Arduino, basta baixar o arquivo "Algoritmo Arduino" e executá-lo na sua IDE de preferência. A utilizada para validar o projeto foi a ARDUINO IDE.

## Python
Para executar o código de Python, basta baixar o arquivo "Algoritmo Python" e executar na sua IDE de preferência. A utilizada para validar o projeto foi a plataforma Jupyter Notebook.

## PHP
Para executar o código de PHP, é necessário primeiramente instalar o XAMPP. Ao executar o instalador, todas as dependências e configurações serão ajustadas na máquina. Após instalado, baixar o arquivo "Algoritmo PHP" e inserir dentro do diretório do XAMPP, na pasta "HTDOCS". Após isso, é apenas necessário subir o servidor "Apache" e "MySQL" clicando no botão "Start" referente ao servidor, no "XAMPP Control Panel". Dessa forma, o servidor já está disponível para utilização através da URL de localhost.

# Prototipação
Para que todas as camadas do projeto funcionem de forma integral e em tempo real, é necessário, após gravar o algoritmo do ESP32, garantir que a "serial monitor" esteja fechada na Arduino IDE, para que não deixa a porta COM ocupada.
Na camada Python, garantir que o algoritmo esteja sendo executado.
Na camada Web, garantir que os sevidor Apache e Mysql estejam em execução.
