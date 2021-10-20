import os
from supabase import create_client, Client

url: str = os.environ.get("SUPABASE_URL")
key: str = os.environ.get("SUPABASE_KEY")
supabase: Client = create_client(url, key)
data = supabase.table("Temp").select("*").execute()
print('########################')
print(data)
print('########################')
# Assert we pulled real data.
assert len(data.get("data", [])) > 0