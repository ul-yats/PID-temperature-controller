#  An easy PID controller to control temperature of a Peltier device using Arduino.

![electronic scheme in the Proteus Design Suite](https://github.com/ul-yats/PID-temperature-controller/assets/127503480/d42711da-4120-4032-8724-30e935771ae9)
<p><b>Electronic scheme in the Proteus Design Suite</b></p>

The first step in creating a temperature control setup was to calibrate the thermistor. In the installation diagram above (fig.1) section (1) is responsible for measuring the temperature: by measuring the voltage drop across resistors with nominal resistances R<sub>1</sub> = 10.0 kOhm and R<sub>2</sub> = 1.0 kOhm, the current in the circuit is determined. Knowing the current in the circuit and the voltage drop across NTC thermistor, it is possible to calculate its resistance. Next, using the formula for the temperature sensitivity coefficient taken from the technical documentation for the NTC thermistor (B57330V2103+260), the expression for finding the temperature was established:

<b>T = T<sub>R</sub>*B/ln(R/R<sub>25</sub>)*T<sub>R</sub>+B [1]</b>

By substituting all the obtained values into formula [1], the correct temperature values were obtained.
Figure (2) shows a graph of resistance as a function of
temperature obtained experimentally:

![image](https://github.com/ul-yats/PID-temperature-controller/assets/127503480/011f882e-81e8-466f-8255-6a99574f51e3)
<p><b>A graph of resistance as a function of temperature obtained experimentally</b></p>

Next, the assembly of the cooling unit was carried out, consisting of Peltier element and an NTC thermistor attached to it, as well as from aluminum radiator and cooler, which serve to remove heat from the hotside of the Peltier element. For thermal insulation of the cold side polystyrene was used. NTC thermistor was attached to cooling side with heat conductive tape and closed at the top Styrofoam lid to prevent heating of the cold side Peltier element due to the atmosphere.

A MOSFET transistor was used to control the Peltier element, which allows currents up to 9 A to pass through itself. To control
The opening/closing of the transistor used a PWM signal. After applying voltage, the microcontroller receives from the NTC thermistor
current voltage indicator, which is subsequently converted into resistance and then to temperature. Further, the resulting temperature
is compared with the one set in the development environment, and, depending on the value errors, the PID controller generates the appropriate pulses to open Peltier element. Then the task of the PID controller is to ensure that reach the set temperature.

When creating the circuit, the following are used: resistor R = 10.0 kΩ, resistor R = 1.0 kΩ, Peltier module TEC1-07106 (1), field-effect transistor (4), NTC thermistor (B57330V2103 + 260) (3), connecting wires, solderless breadboard and Arduino UNO board (2). Figure (3) shows the assembled circuit:

![the circuit](https://github.com/ul-yats/PID-temperature-controller/assets/127503480/bacf9c93-b93f-4f81-83c8-783ae4a971c0)
<p><b>The assembled circuit</b></p>


