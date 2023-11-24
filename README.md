# estacionamento_mesh_iot
Projeto de monitoramento de vagas de estacionamento utilizando rede mesh e técnicas de IoT

# Funcionamento
O presente trabalho utilizará de microcontroladores ESP's monitorando a disponibilidade das vagas com um sensor ultrassonico e comunicando as leituras entre si através de uma rede mesh.
Cada ESP será será um node, sendo este representado por um número específico. O projeto depende que o node principal, onde as informações devem chegar, seja o "1", representado uma variável no código do arduino.

Essas informações serão então processadas por um algoritmo em python que irá monitorar as informações enviadas pela comunicação serial do ESP. Esta etapa é responsável por comunicar com o banco de dados MySQL, verificando se já existem registros para o node que enviou a informação. Caso não exista, irá criar um registro novo, caso já exista, irá atualizar o campo referente ao status.

Dessa forma, será utilizado o XAMPP para que seja disponibilizado de forma visual em uma página WEB as informações referentes a todas as vagas contidas no banco de dados. O XAMPP utiliza como servidor localhost o Apache e, na camada HTML/CSS/JAVASCRIPT utiliza PHP.
