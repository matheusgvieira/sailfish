import os
from supabase import create_client, Client

url: str = os.environ.get("SUPABASE_URL")
key: str = os.environ.get("SUPABASE_KEY")
supabase: Client = create_client(url, key)
data = supabase.table("Temp").select("*").execute()

def get_all_values():
    return data

def get_pos_value(pos):
    return data['data'][pos]

def get_pos_element(pos, element):
    line =  data['data'][pos]
    return line[element]

assert len(data.get("data", [])) > 0