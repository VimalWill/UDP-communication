import socket
#import time 
ip_add = "192.168.43.161"
port = 5555
ip_ad = "192.168.43.162"
port_n = 57802
server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
message = "vijay"
mess = message.encode()
server.bind((ip_ad,port_n))
while(1):
    server.sendto(mess,(ip_add,port))
    addr,data = server.recvfrom(1024)
    print(addr)
    
