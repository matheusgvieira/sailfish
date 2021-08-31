sudo apt-get update
sudo apt-get upgrade
sudo apt-get install python3-dev python3-venv
python3 -m venv env
env/bin/python -m pip install –upgrade pip setuptools wheel
source env/bin/activate

sudo apt-get install portaudio19-dev libffi-dev libssl-dev
python -m pip install --upgrade google-assistant-library
python -m pip install --upgrade google-assistant-sdk[samples]
python -m pip install --upgrade google-auth-oauthlib[tool]