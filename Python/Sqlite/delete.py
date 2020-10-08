import sqlite3

conn = sqlite3.connect('students.db')

#Delete entry from database where student id=2
conn.execute("DELETE from STUDENT where ID = 2;")
conn.commit()

cursor = conn.execute("SELECT * from STUDENT")
print(cursor.fetchall())

conn.close()