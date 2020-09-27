#!/usr/bin/python2
import serial
ser = serial.Serial('/dev/ttyAMA0', 38400)

M = [[None for _ in range(8)] for __ in range(5)]

def print_M():
    print("\t\tct1\tct2\tct3\tct4\tct5\tct6\tct7\tct8")
    for u in range(5):
        if u==0: print "Master :",
        elif u==1: print "Slave 1:",
        elif u==2: print "Slave 2:",
        elif u==3: print "Slave 3:",
        elif u==4: print "Slave 4:",
        for v in range(8):
            if M[u][v]!=None:
                print "\t%.2f" % M[u][v],
            else:
                print "\tNone",
        print
    print


ser.flushInput()

try:
       while 1:
            	# Read one line from the serial buffer
       		line = ser.readline()

       		# Remove the trailing carriage return line feed
      		line = line[:-2]

       		# Create an array of the data
       		Z = line.split(' ')
       	       
                #print(Z)

                u = int(Z[0])
                v = int(Z[1])
                if Z[2]!="err":
                    data = float(Z[2])
                else: data = None
			
                um = 7 - u
                
                ignore = False
                if v==10: vm = 0
                elif v==6: vm = 1
                elif v==7: vm = 2
                elif v==8: vm = 3
                elif v==9: vm = 4
                else:
                    ignore = True

                if not ignore:
                    M[vm][um] = data
                    print_M()
                       
except KeyboardInterrupt:
       ser.close()
