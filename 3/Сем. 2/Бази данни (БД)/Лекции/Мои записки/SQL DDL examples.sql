/*
  
  - Create a relation:
    CREATE TABLE <table_name>
    (
      <attribute_1_name> <attribute_1_type>,
      ...
      <attribute_n_name> <attribute_n_type>,
    );
  
  - Delete a relation:
    DROP TABLE <table_name>;
    
  - Add or remove an attribute to a relation:
    ALTER TABLE <table_name>
    ADD <attribute_name> <attribute_type>;
    
    ALTER TABLE <table_name>
    DROP <attribute_name>;

    Constraints:
      - NOT NULL
        Declared only at attribute level (not  table level).
      - PRIMARY KEY
        We can have only one primary key constraint per table.
        The attributes in the primary key have to be declared NOT NULL.
      - UNIQUE
        Same as PRIMARY KEY but we can have multiple unique constraints per table.
        Also in some DBMS-es the attributes in a UNIQUE constraint can have NULL values.
      - FOREIGN KEY
        The referred attributes from the other table have to be declared PRIMARY KEY or UNIQUE.
      - CHECK 
*/

-- Example NOT NULL.
  CREATE TABLE My_table
  ( my_attribute INT NOT NULL);
  
-- Example PRIMARY KEY.
-- Note that all the attributes of the primary key have to be declared NOT NULL.
  CREATE TABLE My_table
  ( my_attribute INT NOT NULL PRIMARY KEY );  -- We can declare immediately after the attribute.
  
-- Example PRIMARY KEY.
-- If the primary key consists of more than one attribute we have to declare it at the table level.
  CREATE TABLE My_table
  ( my_attribute_1 INT NOT NULL,
    my_attribute_2 CHAR(10) NOT NULL,
    PRIMARY KEY (my_attribute_1, my_attribute_2)
  );
    
-- Example UNIQUE.
  CREATE TABLE My_table
  ( my_attribute_1 INT NOT NULL UNIQUE );
  
-- EXAMPLE UNIQIE.
  CREATE TABLE My_table
  ( my_attribute_1 INT NOT NULL,
    my_attribute_2 CHAR(10) NOT NULL,
    UNIQUE (my_attribute_1, my_attribute_2)
  );
  
-- Example FOREIGN KEY, declaration at the table level.
  CREATE TABLE My_table_1
  ( my_attribute_1 INT NOT NULL,
    my_attribute_2 CHAR(10) NOT NULL,
    UNIQUE (my_attribute_1, my_attribute_2)
  );
    
  CREATE TABLE My_table_2
  ( atr_1 INT,
    atr_2 CHAR(10),
    atr_3 VARCHAR(100),
    FOREIGN KEY (atr_1, atr_2) REFERENCES My_table_1 (my_attribute_1, my_attribute_2)  -- Declare at table level.
  );
    
-- Example FOREIGN KEY, declaration right after the attribute.    
  CREATE TABLE My_table_1
  ( my_attribute_1 INT NOT NULL PRIMARY KEY );
    
  CREATE TABLE My_table_2
  ( atr_1 INT REFERENCES My_table_1 (my_attribute_1),  -- Declare at attribute level.
    atr_3 VARCHAR(100)
  );
  
  