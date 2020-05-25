import serial
import time

port = '/dev/ttyUSB0'
serial_port = serial.Serial(port, 9600)
serial_port.flushInput()

while True:
   # serial_port.write('f'.encode())
   # time.sleep(1)
   # serial_port.write('l'.encode())
   # time.sleep(1)
   # serial_port.write('s'.encode())
   # time.sleep(10)
    msg = input('msg>>')
    if msg:
        serial_port.write(msg.encode())
    else:
        serial_port.write('s'.encode())
        exit()

