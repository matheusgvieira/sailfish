import os
import sys
from supabase import create_client, Client

url: str = os.environ.get("SUPABASE_URL")
key: str = os.environ.get("SUPABASE_KEY")
supabase: Client = create_client(url, key)
data = supabase.table('Temp').insert({'data': float(sys.argv[1]), 'state': bool(int(sys.argv[2])) }).execute()
assert data.get("status_code") in (200, 201)
