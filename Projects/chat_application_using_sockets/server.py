import socket

CHUNK = 65535
port = 3000
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

hostname = '127.0.0.1'

s.bind((hostname, port))

print(f"server is live on {s.getsockname()}")

while True:
	data, clientAdd = s.recvfrom(CHUNK)
	message = data.decode('ascii')
	print(f"Client at {clientAdd} Says: {message}")
	
	message_send = input("Reply: ")
	data = message_send.encode('ascii')
	s.sendto(data, clientAdd)
	if message_send.lower() == "bye":
		break