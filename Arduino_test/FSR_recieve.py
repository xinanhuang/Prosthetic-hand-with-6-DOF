import serial
import  sys
import  time
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
fsr1 = 0
fsr2 = 0
fsr3 = 0
fsr4 = 0
fsr5 = 0
fsr6 = 0
joyx = 0
joyy = 0

print("\n\n\n\n\n\n\n\n\n\n\n\n")

while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if data:
		raw_list = data.split("#")
		if len(raw_list) == 8:
			fsr1 = float(raw_list[0])
			fsr2 = float(raw_list[1])
			fsr3 = float(raw_list[2])
			fsr4 = float(raw_list[3])
			fsr5 = float(raw_list[4])
			fsr6 = float(raw_list[5])
			joyx = float(raw_list[6])
			joyy = float(raw_list[7])


                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
                        print ("\033[A                             \033[A")
			

			print('fsr1: {0:.2f}'.format(fsr1))
                        print('fsr2: {0:.2f}'.format(fsr2))
                        print('fsr3: {0:.2f}'.format(fsr3))
                        print('fsr4: {0:.2f}'.format(fsr4))
                        print('fsr5: {0:.2f}'.format(fsr5))
                        print('fsr6: {0:.2f}'.format(fsr6))
                        print('joyx: {0:.2f}'.format(joyx))
                        print('joyy: {0:.2f}'.format(joyy))

