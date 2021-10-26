import os
import sys
from supabase import create_client, Client
import subprocess
import time

pathproject = "/home/pi/sailfish"

url: str = os.environ.get("SUPABASE_URL")
key: str = os.environ.get("SUPABASE_KEY")
supabase: Client = create_client(url, key)

while True:
    temp = subprocess.check_output('{}/temperature/./sensor.out '.format(pathproject), shell=True)
    data = supabase.table('Temp').insert({'data': float(temp), 'state': False }).execute()
    assert data.get("status_code") in (200, 201)
    time.sleep(300)