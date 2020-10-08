import sqlite3

conn = sqlite3.connect('students.db')
cursor = conn.execute("SELECT * from STUDENT")
print(cursor.fetchall())

conn.close()

"""
SELECT column1, column2, columnN FROM table_name;
SELECT column1, column2, columnN FROM table_name WHERE column_name = value;
"""
