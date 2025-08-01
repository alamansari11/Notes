 docker cp "C:\Users\Alam1.Ansari\Downloads\partner_regis.sql" mysql_container:/partner_dump.sql


pretty output mysql
 select * from facility_service limit 10 \G


ALTER TABLE employees ALTER COLUMN is_Active RENAME TO active;





  

```markdown

# MySQL Container Setup and Data Import

  

## Step 1: Create the MySQL Container

```bash

docker run -p 3307:3306 --name mysql_container \

    -e MYSQL_DATABASE=partner_registry \

    -e MYSQL_USER=bifrostadmin \

    -e MYSQL_PASSWORD="Password@2022" \

    -e MYSQL_ROOT_PASSWORD="admin" \

    --restart on-failure -d mysql/mysql-server \

    --lower_case_table_names=1

```

  

## Step 2: Copy SQL Dump Files into the Container

```bash

docker cp "C:\Users\Alam1.Ansari\Downloads\partner_registry_replica_27Mar241.sql" mysql_container:dump.sql

docker cp "C:\Users\Alam1.Ansari\Downloads\dump_integration.sql" mysql_container:integr.sql

```

## dump sql
  
```bash
   mysqldump -u root -padmin partner_registry > partner_registry_dump.sql
```
   
- note:- after -p don't give spaces




## Step 3: Access the MySQL Container Terminal

```bash

docker exec -it mysql_container bash

```

  

### Step 4: Import SQL Dump Files

- **Log in as Admin** (password: `admin`)

    ```bash

    mysql partner_registry < dump.sql -p

    mysql integration < integr.sql -p

    ```

  

- **Log in with bifrostadmin** (password: `Password@2022`)

    ```bash

    mysql -u bifrostadmin -p

    ```

  

### Step 5: Show Databases and Tables

```sql

SHOW DATABASES;

USE partner_registry;

SHOW TABLES;

DESCRIBE [table_name];

```

  

## Step 6: Run phpMyAdmin (Optional)

```bash

docker run --name my-phpmyadmin -d --link mysql_container:db -p 8080:80 phpmyadmin/phpmyadmin

```

  

## Step 7: Grant Access to `bifrostadmin` via Root

- **Log in as root**

    ```bash

    mysql -p

    ```

- **Run the following commands**

    ```sql

    ALTER USER 'bifrostadmin'@'%' IDENTIFIED BY 'Password@2022';

    GRANT ALL PRIVILEGES ON integration.* TO 'bifrostadmin'@'%';

    FLUSH PRIVILEGES;

    ```

  

## Step 8: Import Protocol Mapper SQL File

```bash

docker cp "C:\Users\Alam1.Ansari\Downloads\protocol_mapper_replica_27Mar24 1.sql" mysql_container:pm.sql

mysql protocol_mapper < pm.sql -p

```

  

## Step 9: Database uri

```
mysql+pymysql://bifrostadmin:Password%402022@localhost:3307/partner_registry
```




Create a new user:


CREATE USER 'mttms_user'@'localhost' IDENTIFIED BY 'mttms_password';


get all user :

SELECT User, Host FROM mysql.user;