import sqlite3

conn = sqlite3.connect('students.db')

#manually inserting data into database table 
conn.execute("INSERT INTO STUDENT (ID,NAME,ROLL,ADDRESS,CLASS) "
             "VALUES (1, 'John', '001', 'Bangalore', '10th')")

conn.execute("INSERT INTO STUDENT (ID,NAME,ROLL,ADDRESS,CLASS) "
             "VALUES (2, 'Naren', '002', 'Hyd', '12th')")

#fetch value from a request and add it to query and execute
query = ('INSERT INTO STUDENT (ID,NAME,ROLL,ADDRESS,CLASS) '
         'VALUES (:ID, :NAME, :ROLL, :ADDRESS, :CLASS);')

params = {
        'ID': 3,
        'NAME': 'Jax',
        'ROLL': '003',
        'ADDRESS': 'Delhi',
        'CLASS': '9th'
    }

conn.execute(query, params)

conn.commit()
conn.close()



