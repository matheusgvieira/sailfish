# Integration RPis

> For integration between two RPis in environment diferent and network, it's need to use supabase. Supabase is a plataform open source for APIs and databases.

## Tests

1. Run below code as sudo

```shell
chmod +x *.sh
./install.sh
```

2. Get temperature values in database :

```shell
python3 get_temp.py
```

3. Insert temperature values in database:
```shell
python3 insert_temp.py VALUE_TEMPERATURE
# Example: python3 insert_temp.py 25.4
```

