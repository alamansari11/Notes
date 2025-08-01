
sit
postgresql://raushan:root1234@10.161.173.146:5432/partner_registry

column find
SELECT table_schema, table_name, column_name
FROM information_schema.columns
WHERE column_name ILIKE '%your_column_name%';



docker run --name postgres_container -e POSTGRES_USER=myuser -e POSTGRES_PASSWORD=mypassword -e POSTGRES_DB=mydatabase -p 5432:5432 -d postgres

 psql -U myuser -d mydatabase
 
docker cp /path/to/dump1.sql <container_id>:/tmp/dump1.sql

psql -U myuser -d mydatabase -f /tmp/dump1.sql


`\l`

Or, you can use this SQL query:

`SELECT datname FROM pg_database;`

If you're already connected to a database, use:

`\list`



To list all tables in the current PostgreSQL database, use:

`\dt`

If you want to see tables in a specific schema (e.g., `public`), use:

`\dt public.*`

Alternatively, you can use this query:

`SELECT table_name  FROM information_schema.tables  WHERE table_schema = 'public';`

These commands should be run inside the `psql` shell.


docker run -d  --name pgadmin  -e PGADMIN_DEFAULT_EMAIL=admin@example.com -e PGADMIN_DEFAULT_PASSWORD=admin -p 5050:80 dpage/pgadmin4



docker network inspect bridge
 and then see the ipv4 address for the postgres container 

sequence

select last_value from lab_test_partners_id_seq

|   |   |
|---|---|
|`nextval()`|Increments and returns next value|

|   |   |
|---|---|
|`currval()`|Returns last value in _this session_|

|   |   |
|---|---|
|`getval()`|Returns last set value (but needs init)|

|   |   |
|---|---|
|`last_value`|From `your_sequence_name`, shows last assigned|


SELECT setval('lab_tests_id_seq', (SELECT MAX(id) FROM public.lab_tests));




docker run --name pg_container -e POSTGRES_USER=myuser -e POSTGRES_PASSWORD=mypassword -e POSTGRES_DB=mydatabase -p 5432:5432 -d postgres


FUM SERVICE 
ssh soijhhuser@10.161.192.20

pass :
`JND#uqr9hascoUQ38RY1^YUH`

psql "host=10.161.192.4 port=5432 dbname=healthhub_production_beta_az user=riluser password=n0Akb2f4jO8@"

`\x - to format`

SELECT * FROM images WHERE id = 705726;


to connect to database in contianer
 psql -U myuser mydatabase

### **Basic psql Commands**

- **\c database_name** – Connect to a specific database.
- **\q** – Quit psql (exit).
- **\l** – List all databases.
- **\d** – List all tables, views, sequences, and indexes in the current database.
- **\d table_name** – Describe the structure of a table (columns, types, constraints).
- **\du** – List all users and roles.
- **\dt** – List all tables in the current schema.
- **\dv** – List all views in the current schema.
- **\di** – List all indexes.
- **\df** – List all functions.
- **\x** – Toggle expanded output mode (good for displaying large query results).

### 3. **Executing Queries**

- **SELECT * FROM table_name;** – Retrieve all rows and columns from a table.
- **INSERT INTO table_name (column1, column2) VALUES ('value1', 'value2');** – Insert new data.
- **UPDATE table_name SET column = 'new_value' WHERE condition;** – Update existing data.
- **DELETE FROM table_name WHERE condition;** – Delete data.

### 4. **Database Management**

- **CREATE DATABASE database_name;** – Create a new database.
- **DROP DATABASE database_name;** – Delete a database.
- **\i file.sql** – Execute SQL commands from a file.

### 5. **User and Role Management**

- **CREATE USER username WITH PASSWORD 'password';** – Create a new user.
- **ALTER USER username WITH PASSWORD 'new_password';** – Change a user's password.
- **GRANT ALL PRIVILEGES ON DATABASE database_name TO username;** – Grant privileges to a user.
ALTER ROLE myuser WITH SUPERUSER;
- **REVOKE ALL PRIVILEGES ON DATABASE database_name FROM username;** – Revoke privileges from a user.

### 6. **Schema and Table Management**

- **CREATE TABLE table_name (column1 type1, column2 type2, ...);** – Create a new table.
- **DROP TABLE table_name;** – Delete a table.
- **ALTER TABLE table_name ADD COLUMN new_column_name type;** – Add a new column.
- **ALTER TABLE table_name DROP COLUMN column_name;** – Remove a column.

### 7. **Index Management**

- **CREATE INDEX index_name ON table_name (column_name);** – Create an index.
- **DROP INDEX index_name;** – Drop an index.

### 8. **Miscellaneous**

- **\timing** – Toggle query execution time display.
- **\watch [seconds]** – Re-run the last query every few seconds.

These commands should cover most basic tasks with PostgreSQL!