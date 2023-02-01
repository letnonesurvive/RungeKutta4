## Test task
Implement a program for the numerical solution of the Cauchy problem for the equation:
![image](https://user-images.githubusercontent.com/36066335/216118552-92195f4a-f04d-4dff-abe0-19f6437f160b.png)

1. Implement any numerical scheme
2. Plot a solution graph
3. To substantiate the reliability of the obtained result.

## Solution
### 1.Implement any numerical scheme
The program represents the implementation of numerical method Runge-Kutta 4 to solve the Cauchy problem. The program was done on C++ and it is writing the result to file "myData.txt". For visualisation of obtained result the ready python script is using. The `plot.py`script get the file "myData.txt" and displays it via mathplot lib.

### 2.Plot a solution graph
To get a plot please do the next steps 

1) Run the solution RK4.sln
2) Build the project and get RK4.exe executable file. 
3) Exectute RK4.exe and obtain myData.txt
4) Run a command `python plot.py myData.txt` and get the picture


### 3. To substantiate the reliability of the obtained result.
The plot of obtained soultion is

![saved_solution](https://user-images.githubusercontent.com/36066335/216121602-ca01203e-bd56-45df-a34f-d566a59835b2.png)

The exact solution to this task is a function 

![image](https://user-images.githubusercontent.com/36066335/216122230-d539504d-b474-4366-832b-e9968be4d2c2.png)

We can visualisate this exact function and equal these plots

![image](https://user-images.githubusercontent.com/36066335/216122638-b65e7ea5-a7dc-4646-afb6-2b30e0463471.png)

And also the values obtained at the grid nodes coincide with the values of the function at these points.
