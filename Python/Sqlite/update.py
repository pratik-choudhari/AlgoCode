import sqlite3

conn = sqlite3.connect('students.db')
conn.execute("UPDATE STUDENT set ROLL = 005 where ID = 1")
conn.commit()

cursor = conn.execute("SELECT * from STUDENT")
print(cursor.fetchall())

conn.close()