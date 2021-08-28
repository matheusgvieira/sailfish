# Sinalization LEDs

## Circuit Layout
![rgb](../images/rgb.png)

## Initial Tests

After the circuit assembled, the initial test of the GPIos, to check the connections with the Raspberry Pi 3 B+.

### GPIOs

```sh
# Test GPIO 17 => Blue
echo "17" > /sys/class/gpio/export
chmod -R 777 /sys/class/gpio/gpio17
echo "out" > /sys/class/gpio/gpio17/direction
echo "1" > /sys/class/gpio/gpio17/value
echo "0" > /sys/class/gpio/gpio17/value

# Other tests with GPIO Library

# Green
gpio export 22 out
gpio -g write 22 1
gpio -g write 22 0

# Red
gpio export 6 out
gpio -g write 6 1
gpio -g write 6 0

# Buzzer
gpio export 26 out
gpio -g write 26 1
gpio -g write 26 0

```
## Library