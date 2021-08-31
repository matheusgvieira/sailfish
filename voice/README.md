scp ~/Downloads/client_secret_*.json <username>@<device-ip-address>:</path/to/assistant-sdk/project>
password: password-for-device


1. Pré Instalação
Crie os arquivos de configuração de audio (~/.asoundrc e /etc/asound.conf) com esse conteúdo: https://raw.githubusercontent.com/shi...

veja se o audio está funcionando: 
$ speaker-test
instale as dependências:
$ sudo apt-get update
$ sudo apt-get install python3-dev python3-venv
$ python3 -m venv env
$ env/bin/python -m pip install --upgrade pip setuptools wheel
$ source env/bin/activate
$ sudo apt-get install portaudio19-dev libffi-dev libssl-dev libmpg123-dev
$ python -m pip install --upgrade google-assistant-library==1.0.1
$ python -m pip install --upgrade google-assistant-sdk[samples]==0.5.1
$ python -m pip install --upgrade google-auth-oauthlib[tool]

2. Crie o projeto no Cloud do Google
Acesse esse link com as instruções de como criar o seu projeto e baixa o arquivo de credenciais: https://developers.google.com/assista...

3. Autentique o seu Raspberry Pi
$ google-oauthlib-tool --scope https://www.googleapis.com/auth/assis... \
      --scope https://www.googleapis.com/auth/gcm \
      --save --headless --client-secrets /caminho/para/client_secret_client-id.json

4. Inicie o seu Google Assistant
$ google-assistant-demo --device_model_id rpi

5. DIVIRTA-SE

Obs.: O sinais de cifrão ($) indicam que você precisa executar ese comando no console/terminal. Você não precisa usar o cifrão no comando.
Obs2.: Esse projeto só funciona para Raspberry Pi 3