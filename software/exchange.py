import sys
import select

# Set up the poll object
# See https://docs.micropython.org/en/latest/library/select.html
poll_obj = select.poll()
poll_obj.register(sys.stdin, select.POLLIN)
def loop_exchange_usb(timer):
    """This function is a machine.Timer callback. See https://www.micropython.fr/port_pi_pico/04.micropython/04.fonctions_dediees/timers/
    Read data coming and write data with usb communication.
    """
    if poll_obj.poll(0):
        # Read the data from stdin (read data coming from USB opened connection).
        data = sys.stdin.readline().strip()
        # Write data to standard out. The standard out is USB opened connection.
        # sys.stdout.write() send data with USB communication.
        sys.stdout.write("received data: " + data + "\r")
