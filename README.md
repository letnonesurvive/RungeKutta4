## Test task
Implement a program for the numerical solution of the Cauchy problem for the equation:
![image](https://user-images.githubusercontent.com/36066335/216118552-92195f4a-f04d-4dff-abe0-19f6437f160b.png)

1. Implement any numerical scheme
2. Plot a solution graph
3. To substantiate the reliability of the obtained result.

## Solution
The program represents the implementation of numerical method Runge-Kutta 4 to solve the Cauchy problem. The program was done on C++ and it is writing the result to file "myData.txt". For visualisation of obtained result the ready python script is using. The `plot.py`script get the file "myData.txt" and displays it via mathplot lib.

To get a plot please do the next steps 

1) Run the solution RK4.sln
2) Build the project and get RK4.exe executable file. 
3) Exectute RK4.exe and obtain myData.txt
4) Run a command `python plot.py myData.txt` and get the picture
