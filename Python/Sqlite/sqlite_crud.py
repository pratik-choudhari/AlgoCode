import sqlite3
import subprocess as sp

"""
database code
"""



def create_table():
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    CREATE TABLE IF NOT EXISTS student(
	    	id INTEGER PRIMARY KEY, 
	    	roll INTEGER, 
	    	name TEXT,
	        phone TEXT
	    )
	'''

	cursor.execute(query)

	conn.commit()
	conn.close()



def add_student(roll,name,phone):
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    INSERT INTO student( roll, name, phone )
	    	        VALUES ( ?,?,? )
	'''

	cursor.execute(query,(roll,name,phone))

	conn.commit()
	conn.close()



def get_students():
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    SELECT roll, name, phone
	    FROM student
	'''

	cursor.execute(query)
	all_rows = cursor.fetchall()

	conn.commit()
	conn.close()

	return all_rows

def get_student_by_roll(roll):
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    SELECT roll, name, phone
	    FROM student
	    WHERE roll = {}
	''' .format(roll)

	cursor.execute(query)
	all_rows = cursor.fetchall()

	conn.commit()
	conn.close()

	return all_rows

def update_student(roll,name,phone):
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    UPDATE student
	    SET name = ?, phone = ?
	    WHERE roll = ?
	'''

	cursor.execute(query,(name,phone,roll))

	conn.commit()
	conn.close()


def delete_student(roll):
	conn = sqlite3.connect('testdb.sqlite')

	cursor = conn.cursor()

	query = '''
	    DELETE
	    FROM student
	    WHERE roll = {}
	''' .format(roll)

	cursor.execute(query)
	all_rows = cursor.fetchall()

	conn.commit()
	conn.close()

	return all_rows



create_table()



"""
main code
"""



def add_data(id_,name,phone):
	add_student(id_,name,phone)
def get_data():
	return get_students()

def show_data():
	students = get_data()
	for student in students:
		print(student)

def show_data_by_id(id_):
	students = get_student_by_roll(id_)
	if not students:
		print("No data found at roll",id_)
	else:
		print (students)

def select():
	sp.call('clear',shell=True)
	sel = input("1. Add data\n2.Show Data\n3.Search\n4.Update\n5.Delete\n6.Exit\n\n")

	
	if sel=='1':
		sp.call('clear',shell=True)
		id_ = int(input('id: '))
		name = input('Name: ')
		phone = input('phone: ')
		add_data(id_,name,phone)
	elif sel=='2':
		sp.call('clear',shell=True)
		show_data()
		input("\n\npress enter to back:")
	elif sel=='3':
		sp.call('clear',shell=True)
		id__ = int(input('Enter Id: '))
		show_data_by_id(id__)
		input("\n\npress enter to back:")
	elif sel=='4':
		sp.call('clear',shell=True)
		id__ = int(input('Enter Id: '))
		show_data_by_id(id__)
		print()
		name = input('Name: ')
		phone = input('phone: ')
		update_student(id__,name,phone)
		input("\n\nYour data has been updated \npress enter to back:")
	elif sel=='5':
		sp.call('clear',shell=True)
		id__ = int(input('Enter Id: '))
		show_data_by_id(id__)
		delete_student(id__)
		input("\n\nYour data has been deleted \npress enter to back:")
	else:
		return 0;
	return 1;

while(select()):
	pass