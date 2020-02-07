# ICOM-CI-V-Arduino-Monitor
A debug tool showing what is happening on the CI-V bus

While I am trying to built a command decoder that would add the PTT command to the older range of ICOM radios (IC706, IC756, IC7000,...)
I was building this tool to read the bus
It works

Now I want to decode a certain command state and use this to activate a open collector output.
THis part is not working yet and I don't know why I cannot use my byte3 integer status to switch an output 13

Any help appreciated.
