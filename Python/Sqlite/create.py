# Creating table into database!!!

import sqlite3

# Connect to sqlite database
conn = sqlite3.connect('students.db')
# cursor object
cursor = conn.cursor()
# drop query
cursor.execute("DROP TABLE IF EXISTS STUDENT")

# create query
query = """CREATE TABLE STUDENT(
        ID INT PRIMARY KEY NOT NULL,
        NAME CHAR(20) NOT NULL, 
        ROLL CHAR(20), 
        ADDRESS CHAR(50), 
        CLASS CHAR(20) )"""
cursor.execute(query)

# commit and close
conn.commit()
conn.close()

"""
CREATE TABLE table_name (
   column name datatype properity,
   ...
   ...
);
"""
