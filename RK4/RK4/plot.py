import numpy as np
import matplotlib.pyplot as plt
import sys
import os.path

def main(thePath : str):
    
    if not os.path.exists(thePath):
        print("Failed to read the file " + thePath)
        return 1
    
    file = open(thePath, "r")
    lines = file.readlines()
    file.close()
    
    step = float()
    leftBound = float()
    rightBound = float()
    
    Y = list()
    X = list()
    
    for line in lines:
        if "Step" in line:
            step = float(line[7:])
            continue
        elif "Segment" in line:
            leftBound = float(line[11])   
            rightBound = float(line[14])
            continue
        Y.append(float(line))
        if (len(X) == 0):
            X.append(leftBound)
            continue
        X.append(step + X[len(X)- 1])
             
    print("Step is " + str(step))
    print("Segment is " +  "[" + str(leftBound) + ", " + str(rightBound) + "]")
    
    plt.plot(X,Y)
    plt.title("Y(x)")
    plt.xlabel("X axis")
    plt.ylabel("Y axis")
    
    plt.show()
    
    return 0
 
 
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Enter an <input_file> with data")
        sys.exit(1) 
        
    aPath = os.path.abspath(sys.argv[1])    
    sys.exit(main(aPath))