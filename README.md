# Masimo-Cable-Tester
This repository describes SD Cables sponsored project: “Automated multi conductor
cable break-short detector,” hereinafter referred to as the “Cable Tester.” The Cable Tester
continuously monitors a multi-conductor cable that is being subjected to destructive mechanical
testing, measuring resistance and detecting any breaks or shorts. The team is developing a
Printed Circuit Board (PCB) that will have serval inputs and outputs (I/O), including SD card
port, 20-pin connector, power switch, DC power jack, a debugger, banana jack, and a Human
Machine Interface (HMI). For the HMI, the team will be using a Liquid Crystal Display (LCD)
to display the Graphic User Interface (GUI), which is shown for use case. We will be using the
AVR128DB64 microcontroller (MCU) help to drive our device.

The Cable Tester is a device that must test and analyze the
durability and integrity of wires. The device must extract data from the wire connected to
characterize it and monitor the changes in the wire that may indicate ashort or a break in the
conductors while the wire is subjected to a destructive mechanical test, such as a bend cycle test.
All data must be captured in an SD card inserted into the device for post-test analysis. Currently,
the Cable Tester that Masimo possesses operates with preset assumptions about the wire it will
attach. The Cable Tester that we design must be universal to all wires, more specifically, it must
characterize the cable regardless of what wire is connected and then proceed with the tests. The
universalizability of the Cable Tester will assist Masimo, and potentially other companies, in the
development of electrical systems by predetermining faults in the wires before it will be
implemented into the system, which prevents future technical issues.
